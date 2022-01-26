BASENAME=oscbn
G4=$(BASENAME:=.g4)

CC=clang
CPP=clang++

LIBOSE_DIR=../libose
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

ANTLR4_DIR=antlr4
ANTLR4_RUNTIME_DIR=$(ANTLR4_DIR)/runtime/Cpp
ANTLR4_INCLUDE_DIR=$(ANTLR4_RUNTIME_DIR)/run/usr/local/include/antlr4-runtime
ANTLR4_LIB_DIR=$(ANTLR4_RUNTIME_DIR)/run/usr/local/lib

INCLUDES=-I. -I$(LIBOSE_DIR) -I$(ANTLR4_INCLUDE_DIR)

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
release: $(LIBOSE_DIR)/sys/ose_endian.h ose_$(BASENAME).so

debug: CFLAGS=$(CFLAGS_DEBUG)
debug: CPPFLAGS=$(CPPFLAGS_DEBUG)
debug: $(LIBOSE_DIR)/sys/ose_endian.h ose_$(BASENAME).so

$(OSE_FILES:=.o): %.o: $(LIBOSE_DIR)/%.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $(DEFINES) $< -o $(notdir $@)

$(MOD_FILES:=.o): %.o: %.cpp $(ANTLR4_INCLUDE_DIR)
	$(CPP) -c $(CPPFLAGS) $(INCLUDES) $(DEFINES) $< -o $@

ose_$(BASENAME).so: $(OSE_FILES:=.o) $(MOD_FILES:=.o)
	$(CPP) $(LDFLAGS) -o o.se.$(BASENAME).so $^ $(ANTLR4_LIB_DIR)/libantlr4-runtime.a

$(LIBOSE_DIR)/sys/ose_endian.h:
	cd $(LIBOSE_DIR) && $(MAKE) sys/ose_endian.h

$(ANTLR4_INCLUDE_DIR):
	./make_antlr4_Cpp_runtime.sh

ifndef ANTLR4
ANTLR4=/usr/local/lib/antlr-4.9.3-complete.jar
endif

.PHONY: antlr
antlr: 
	java -jar $(ANTLR4) -Dlanguage=Cpp -package oscbn -visitor -no-listener $(BASENAME).g4

.PHONY: clean
clean:
	rm -rf *.o *.so *.interp *.tokens
