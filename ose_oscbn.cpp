#include "ose_conf.h"
#include "ose.h"
#include "ose_context.h"
#include "ose_util.h"
#include "ose_stackops.h"
#include "ose_assert.h"

#include "antlr4-runtime.h"
#include "oscbnLexer.h"
#include "oscbnParser.h"
#include "oscbnVisitorImpl.h"

using namespace std;
using namespace antlr4;
using namespace antlrcpp;
using namespace oscbn;

class ParserErrorListener : public BaseErrorListener {
private:
    oscbnVisitorImpl *visitor = NULL;
public:
    ParserErrorListener(oscbnVisitorImpl *_visitor) : visitor(_visitor){}
    void syntaxError(Recognizer *recognizer,
                     Token *offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string &msg,
                     std::exception_ptr e)
    {
        visitor->incNErrors();
        cerr << "Parse error " << line << ":" <<
            charPositionInLine << " " << msg << "\n";
        if(offendingSymbol)
        {
            cerr << "Symbol: " << offendingSymbol->getText() << "\n";
        }
    }
};

class LexerErrorListener : public BaseErrorListener {
private:
    oscbnVisitorImpl *visitor = NULL;
public:
    LexerErrorListener(oscbnVisitorImpl *_visitor) : visitor(_visitor){}
    void syntaxError(Recognizer *recognizer,
                     Token *offendingSymbol,
                     size_t line,
                     size_t charPositionInLine,
                     const std::string &msg,
                     std::exception_ptr e)
    {
        visitor->incNErrors();
        cerr << "Parse error " << line << ":" <<
            charPositionInLine << " " << msg << "\n";
        if(offendingSymbol)
        {
            cerr << "Symbol: " << offendingSymbol->getText() << "\n";
        }
    }
};

static void oscbn_parseOsc_impl(const char * const str,
                                const int32_t len,
                                ose_bundle bundle)
{
    ANTLRInputStream input(str, len);
    oscbnLexer lexer(&input);
    
    CommonTokenStream tokens(&lexer);
    
    oscbnVisitorImpl *visitor = new oscbnVisitorImpl(bundle);

    lexer.removeErrorListeners();
    LexerErrorListener lexerErrorListener(visitor);
    lexer.addErrorListener(&lexerErrorListener);

    oscbnParser parser(&tokens);
    parser.removeParseListeners();
    parser.removeErrorListeners();
    ParserErrorListener parserErrorListener(visitor);
    parser.addErrorListener(&parserErrorListener);

    oscbnParser::OscContext *tree = parser.osc();
    Any a = visitor->visitOsc(tree);
    // cout << "nerrors: " << visitor->getNErrors() << "\n";
}

#ifdef __cplusplus
extern "C" {
#endif

void oscbn_parseOsc(ose_bundle bundle)
{
    ose_assert(ose_bundleHasAtLeastNElems(bundle, 1));
    ose_assert(ose_peekType(bundle) == OSETT_MESSAGE);
    ose_assert(ose_isStringType(ose_peekMessageArgType(bundle)));
    const char * const str = ose_peekString(bundle);
    const int32_t len = strlen(str);
    if(len == 0)
    {
        ose_pushBundle(bundle);
    }
    else
    {
        oscbn_parseOsc_impl(str, len, bundle);
    }
}

/**************************************************
 * pretty printing
 **************************************************/
#define INCP(bufp, amt) ((bufp) ? ((bufp) += (amt)) : (bufp))
#define INCL(bufp, bufl, amt) ((bufp) ? ((bufl) -= (amt)) : (bufl))

static int32_t _oscbn_fmtBundle(ose_bundle bundle,
                                int32_t offset,
                                char *buf,
                                int32_t buflen,
                                int32_t indent);

static int32_t oscbn_fmtMessageAddr(ose_bundle bundle,
                                    int32_t offset,
                                    int32_t ao,
                                    char *buf,
                                    int32_t buflen)
{
    const char * const addr = ose_readString(bundle, ao);
    return snprintf(buf, buflen, "%s", addr);
}

static int32_t oscbn_fmtMessageArg(ose_bundle bundle,
                                   int32_t offset,
                                   int32_t tto,
                                   int32_t plo,
                                   char *buf,
                                   int32_t buflen)
{
    char tt = ose_readByte(bundle, tto);
    switch(tt){
    case OSETT_INT32:
        return snprintf(buf, buflen,
                        "%d",
                        ose_readInt32(bundle, plo));
    case OSETT_FLOAT:
        return snprintf(buf, buflen,
                        "%f",
                        ose_readFloat(bundle, plo));
    case OSETT_STRING:
        return snprintf(buf, buflen,
                        "\"%s\"",
                        ose_readString(bundle, plo));
    case OSETT_BLOB:
    {
        int32_t blobsize = ose_readInt32(bundle, plo);
        int32_t n =  snprintf(buf, buflen, "b");
        int32_t nn = n;
        INCP(buf, n);
        INCL(buf, buflen, n);
        const char * const p = ose_readString(bundle, plo + 4);
        for(int k = 0; k < blobsize; k++){
            n = snprintf(buf, buflen, "%02X", p[k]);
            nn += n;
            INCP(buf, n);
            INCL(buf, buflen, n);
        }
        return nn;
    }
#ifdef OSE_PROVIDE_TYPE_DOUBLE
    case OSETT_DOUBLE:
        return snprintf(buf, buflen,
                        "%f",
                        ose_readDouble(bundle, plo));
#endif
    default:
    {
        return 0;
    }
    }
}

static int32_t oscbn_fmtBundleElem_msg(ose_bundle bundle,
                                       int32_t offset,
                                       char *buf,
                                       int32_t buflen,
                                       int32_t indent)
{
    char *b = ose_getBundlePtr(bundle);
    int32_t s = ose_readInt32(bundle, offset);
    int32_t ao = offset + 4;
    int32_t tto = ao + ose_pstrlen(b + ao);
    const int32_t ntt = strlen(b + tto) - 1;
    int32_t plo = tto + ose_pstrlen(b + tto);
    tto++;
    int32_t n = 0;
    int32_t nn = 0;
    char *bufp = buf;
    int32_t bufl = buflen;
    {
        /* address */
        n = oscbn_fmtMessageAddr(bundle,
                                 offset,
                                 ao,
                                 bufp,
                                 bufl);
        nn += n;
        INCP(bufp, n);
        INCL(bufp, bufl, n);
    }
    if(n)
    {
        n = snprintf(bufp, bufl, " : ");
    }
    else
    {
        n = snprintf(bufp, bufl, ": ");
    }
    nn += n;
    INCP(bufp, n);
    INCL(bufp, bufl, n);
    /* payload */
    if(ntt == 0)
    {
    }
    else if(ntt == 1)
    {
        n = oscbn_fmtMessageArg(bundle,
                                offset,
                                tto,
                                plo,
                                bufp,
                                bufl);
        nn += n;
        INCP(bufp, n);
        INCL(bufp, bufl, n);
    }
    else
    {
        n = snprintf(bufp, bufl, "[ ");
        nn += n;
        INCP(bufp, n);
        INCL(bufp, bufl, n);
        while(plo < (offset + 4 + s) && ose_readByte(bundle, tto))
        {
            char tt = ose_readByte(bundle, tto);
            n = oscbn_fmtMessageArg(bundle,
                                    offset,
                                    tto,
                                    plo,
                                    bufp,
                                    bufl);
            nn += n;
            INCP(bufp, n);
            INCL(bufp, bufl, n);
            if(ose_readByte(bundle, tto + 1))
            {
                n = snprintf(bufp, bufl, ", ");
                nn += n;
                INCP(bufp, n);
                INCL(bufp, bufl, n);
            }
            if(ose_isKnownTypetag(tt))
            {
                plo += ose_getPayloadItemSize(bundle, tt, plo);
            }
            else
            {
                if(ose_readByte(bundle, tt + 1) == 0)
                {
                    plo = offset + s + 4;
                }
                else
                {
                    break;
                }
            }
            tto++;
        }
        n = snprintf(bufp, bufl, " ]");
        nn += n;
        INCP(bufp, n);
        INCL(bufp, bufl, n);
    }
    return nn;
}

static int32_t oscbn_fmtBundleElem(ose_bundle bundle,
                                   int32_t offset,
                                   char *buf,
                                   int32_t buflen,
                                   int32_t indent)
{
    int32_t nn = 0;
    char *bufp = buf;
    int32_t bufl = buflen;
    int n = 0;
    char betype = ose_getBundleElemType(bundle, offset);
    if(betype == OSETT_MESSAGE)
    {
        n = oscbn_fmtBundleElem_msg(bundle,
                                    offset,
                                    bufp,
                                    bufl,
                                    indent);
        return n;
    }
    else if(betype == OSETT_BUNDLE)
    {
        if(ose_getBundleElemElemCount(bundle, offset) == 0)
        {
            n = snprintf(bufp, bufl, "{}");
            nn += n;
            INCP(bufp, n);
            INCL(bufp, bufl, n);
        }
        else
        {
            n = snprintf(bufp, bufl, "{\n");
            nn += n;
            INCP(bufp, n);
            INCL(bufp, bufl, n);
            
            n = _oscbn_fmtBundle(bundle,
                                 offset + 4,
                                 bufp,
                                 bufl,
                                 indent + 1);
            nn += n;
            INCP(bufp, n);
            INCL(buf, bufl, n);

            char indentstr[indent + 1];
            for(int i = 0; i < indent; i++)
            {
                indentstr[i] = ' ';
            }
            indentstr[indent] = 0;
            n = snprintf(bufp, bufl, "\n%s}", indentstr);
            nn += n;
            INCP(bufp, n);
            INCL(buf, bufl, n);
        }
        return nn;
    }
    else
    {
        ose_assert(0 &&
                   "bundle elem is neither a message nor a bundle");
    }
    return 0;
}

static int32_t _oscbn_fmtBundle(ose_bundle bundle,
                                int32_t offset,
                                char *buf,
                                int32_t buflen,
                                int32_t indent)
{
    ose_assert(ose_isBundle(bundle));
    int32_t nn = 0;
    int32_t ss = ose_readInt32(bundle, offset - 4);
    char *bufp = buf;
    int32_t bufl = buflen;
    int32_t o = OSE_BUNDLE_HEADER_LEN;
    offset += OSE_BUNDLE_HEADER_LEN;
    char indentstr[indent + 1];
    for(int i = 0; i < indent; i++)
    {
        indentstr[i] = ' ';
    }
    indentstr[indent] = 0;
    while(o < ss)
    {
        int n = 0;
        n = snprintf(bufp, bufl, "%s", indentstr);
        nn += n;
        INCP(bufp, n);
        INCL(bufp, bufl, n);

        int32_t s = ose_readInt32(bundle, offset);
        n = oscbn_fmtBundleElem(bundle,
                                offset,
                                bufp,
                                bufl,
                                indent);
        nn += n;
        INCP(bufp, n);
        INCL(bufp, bufl, n);
        o += s + 4;
        offset += s + 4;
        if(o < ss)
        {
            n = snprintf(bufp, bufl, ",\n");
            INCP(bufp, n);
            INCL(bufp, bufl, n);
            nn += n;
        }
    }
    return nn;
}

static void oscbn_printOscBundle(ose_bundle bundle)
{
    int32_t o = ose_getLastBundleElemOffset(bundle);
    int32_t len = oscbn_fmtBundleElem(bundle, o, NULL, 0, 0);
    len = ose_pnbytes(len);
    ose_pushBlob(bundle, len, NULL);
    char *p = ose_peekBlob(bundle) + 4;
    oscbn_fmtBundleElem(bundle, o, p, len, 0);
    ose_pushInt32(bundle, OSETT_STRING);
    ose_blobToType(bundle);
}

static void oscbn_printlnOscBundle(ose_bundle bundle)
{
    int32_t o = ose_getLastBundleElemOffset(bundle);
    int32_t tlen = oscbn_fmtBundleElem(bundle, o, NULL, 0, 0);
    int32_t tnrlen = tlen + 1;                   // \n
    int32_t ptnrlen = ose_pnbytes(tnrlen);
    ose_pushBlob(bundle, ptnrlen, NULL);
    char *p = ose_peekBlob(bundle) + 4;
    oscbn_fmtBundleElem(bundle, o, p, ptnrlen, 0);
    p[tlen] = '\n';
    ose_pushInt32(bundle, OSETT_STRING);
    ose_blobToType(bundle);
}

static void oscbn_printOscMessage(ose_bundle bundle)
{
    int32_t o = ose_getLastBundleElemOffset(bundle);
    int32_t len = oscbn_fmtBundleElem_msg(bundle, o, NULL, 0, 0);
    len = ose_pnbytes(len);
    ose_pushBlob(bundle, len, NULL);
    char *p = ose_peekBlob(bundle) + 4;
    oscbn_fmtBundleElem_msg(bundle, o, p, len, 0);
    ose_pushInt32(bundle, OSETT_STRING);
    ose_blobToType(bundle);
}

static void oscbn_printlnOscMessage(ose_bundle bundle)
{
    int32_t o = ose_getLastBundleElemOffset(bundle);
    int32_t tlen = oscbn_fmtBundleElem_msg(bundle, o, NULL, 0, 0);
    int32_t tnrlen = tlen + 1;  // \n
    int32_t ptnrlen = ose_pnbytes(tnrlen);
    ose_pushBlob(bundle, ptnrlen, NULL);
    char *p = ose_peekBlob(bundle) + 4;
    oscbn_fmtBundleElem_msg(bundle, o, p, ptnrlen, 0);
    p[tlen] = '\n';
    ose_pushInt32(bundle, OSETT_STRING);
    ose_blobToType(bundle);
}

// module
#include "ose_vm.h"

void oscbn_parse(ose_bundle osevm)
{
    ose_bundle vm_s = OSEVM_STACK(osevm);
    oscbn_parseOsc(vm_s);
    ose_nip(vm_s);
}

void oscbn_print(ose_bundle osevm)
{
    ose_bundle vm_s = OSEVM_STACK(osevm);
    char t = ose_peekType(vm_s);
    if(t == OSETT_MESSAGE)
    {
        oscbn_printOscMessage(vm_s);
    }
    else if(t == OSETT_BUNDLE)
    {
        oscbn_printOscBundle(vm_s);
    }
    else
    {
        ose_assert(0 && "found something that is neither a bundle nor a message");
    }
}

void oscbn_println(ose_bundle osevm)
{
    ose_bundle vm_s = OSEVM_STACK(osevm);
    if(!ose_bundleHasAtLeastNElems(vm_s, 1))
    {
        ose_pushString(vm_s, "\n");
        return;
    }
    char t = ose_peekType(vm_s);
    if(t == OSETT_MESSAGE)
    {
        oscbn_printlnOscMessage(vm_s);
    }
    else if(t == OSETT_BUNDLE)
    {
        oscbn_printlnOscBundle(vm_s);
    }
    else
    {
        ose_assert(0 && "found something that is neither a bundle nor a message");
    }
}

__attribute__((visibility("default")))
void ose_main(ose_bundle osevm)
{
    ose_bundle vm_s = OSEVM_STACK(osevm);
    ose_pushBundle(vm_s);
    ose_pushMessage(vm_s, "/oscbn/parse", strlen("/oscbn/parse"),
                    1, OSETT_ALIGNEDPTR, oscbn_parse);
    ose_push(vm_s);
    ose_pushMessage(vm_s, "/oscbn/print", strlen("/oscbn/print"),
                    1, OSETT_ALIGNEDPTR, oscbn_print);
    ose_push(vm_s);
    ose_pushMessage(vm_s, "/oscbn/println", strlen("/oscbn/println"),
                    1, OSETT_ALIGNEDPTR, oscbn_println);
    ose_push(vm_s);
}

} // extern "C"
