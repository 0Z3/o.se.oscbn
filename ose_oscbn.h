#ifndef OSE_OSCBN_H
#define OSE_OSCBN_H

#include "ose_conf.h"
#include "ose.h"

#ifdef __cplusplus
extern "C" {
#endif

void oscbn_parseOsc(ose_bundle bundle);
void oscbn_parse(ose_bundle osevm);
void oscbn_print(ose_bundle osevm);
void oscbn_println(ose_bundle osevm);

#ifdef __cplusplus
}
#endif

#endif
