BASENAME=oscbn
G4=$(BASENAME:=.g4)

CC=clang
CPP=clang++

OSE_DIR=../../..
OSE_FILES=\
	ose\
	ose_util\
	ose_stackops\
	ose_match\
	ose_context\
	ose_assert

MOD_FILES=\
	$(BASENAME)VisitorImpl\
	$(BASENAME)Lexer\
	$(BASENAME)Parser\
	ose_$(BASENAME)

ANTLR4_DIR=$(OSE_DIR)/../antlr4
ANTLR4_RUNTIME_DIR=$(ANTLR4_DIR)/runtime/Cpp/runtime

INCLUDES=-I. -I$(OSE_DIR) -I$(ANTLR4_RUNTIME_DIR)/src

DEFINES=-DHAVE_OSE_ENDIAN_H

CFLAGS_DEBUG=-Wall -DOSE_CONF_DEBUG -O0 -glldb
CFLAGS_RELEASE=-Wall -O3

CPPFLAGS_DEBUG=-Wall -DOSE_CONF_DEBUG -O0 -glldb --std=c++17
CPPFLAGS_RELEASE=-Wall -O3 --std=c++17

release: CFLAGS=$(CFLAGS_RELEASE)
release: CPPFLAGS=$(CPPFLAGS_RELEASE)
release: ose_$(BASENAME).so

debug: CFLAGS=$(CFLAGS_DEBUG)
debug: CPPFLAGS=$(CPPFLAGS_DEBUG)
debug: ose_$(BASENAME).so

$(OSE_FILES:=.o): %.o: $(OSE_DIR)/%.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $(DEFINES) $< -o $(notdir $@)

$(MOD_FILES:=.o): %.o: %.cpp
	$(CPP) -c $(CPPFLAGS) $(INCLUDES) $(DEFINES) $< -o $@

ose_$(BASENAME).so: $(OSE_FILES:=.o) $(MOD_FILES:=.o)
	$(CPP) -shared -o $@ $^ $(ANTLR4_RUNTIME_DIR)/libantlr4-runtime.a

$(OSE_DIR)/sys/ose_endian.h:
	cd $(OSE_DIR) && $(MAKE) sys/ose_endian.h

oscbntest: oscbntest.cpp $(OSE_FILES:=.o) $(MOD_FILES:=.o)
	$(CPP) $(CPPFLAGS_DEBUG) $(INCLUDES) $(DEFINES) -o $@ $^ $(ANTLR4_RUNTIME_DIR)/libantlr4-runtime.a

ANTLR4=java -jar /usr/local/lib/antlr-4.9.1-complete.jar
.PHONY: antlr
antlr: 
	$(ANTLR4) -Dlanguage=Cpp -visitor -no-listener $(BASENAME).g4

.PHONY: clean
clean:
	rm -rf *.o *.so
