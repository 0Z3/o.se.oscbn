#include "ose_conf.h"
#include "ose.h"

void oscbn_parseTopLevelBundle(ose_bundle bundle);
void oscbn_printTopLevelBundle(ose_bundle bundle);

void oscbn_parseTopLevelBundle_impl(const char * const str,
                                    const int32_t len,
                                    ose_bundle bundle);
int32_t oscbn_printTopLevelBundle_impl(char *buf,
                                       int32_t buflen,
                                       ose_bundle bundle_elem);
