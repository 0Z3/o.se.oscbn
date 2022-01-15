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

ANTLR4_DIR=../lib/antlr4
ANTLR4_RUNTIME_DIR=$(ANTLR4_DIR)/runtime/Cpp
ANTLR4_INCLUDE_DIR=$(ANTLR4_RUNTIME_DIR)/run/usr/local/include/antlr4-runtime
ANTLR4_LIB_DIR=$(ANTLR4_RUNTIME_DIR)/run/usr/local/lib

INCLUDES=-I. -I$(OSE_DIR) -I$(ANTLR4_INCLUDE_DIR)

DEFINES=-DHAVE_OSE_ENDIAN_H

CFLAGS_DEBUG=-Wall -DOSE_CONF_DEBUG -O0 -glldb -fPIC
CFLAGS_RELEASE=-Wall -O3 -fPIC

CPPFLAGS_DEBUG=-Wall -DOSE_CONF_DEBUG -O0 -glldb --std=c++17 -fPIC
CPPFLAGS_RELEASE=-Wall -O3 --std=c++17 -fPIC

ifeq ($(shell uname), Darwin)
LDFLAGS=-fvisibility=hidden -shared -Wl,-exported_symbol,_ose_main
else
LDFLAGS=-fvisibility=hidden -shared
endif

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
	$(CPP) $(LDFLAGS) -o $@ $^ $(ANTLR4_LIB_DIR)/libantlr4-runtime.a

$(OSE_DIR)/sys/ose_endian.h:
	cd $(OSE_DIR) && $(MAKE) sys/ose_endian.h

oscbntest: oscbntest.cpp $(OSE_FILES:=.o) $(MOD_FILES:=.o)
	$(CPP) $(CPPFLAGS_DEBUG) $(INCLUDES) $(DEFINES) -o $@ $^ $(ANTLR4_LIB_DIR)/libantlr4-runtime.a

ifndef ANTLR4
ANTLR4=/usr/local/lib/antlr-4.9.3-complete.jar
endif

.PHONY: antlr
antlr: 
	java -jar $(ANTLR4) -Dlanguage=Cpp -package oscbn -visitor -no-listener $(BASENAME).g4

.PHONY: clean
clean:
	rm -rf *.o *.so
