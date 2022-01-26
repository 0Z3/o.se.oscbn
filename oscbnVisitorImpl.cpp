#include <iostream>

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

int oscbnVisitorImpl::getNErrors()
{
    return nerrors;
}

void oscbnVisitorImpl::incNErrors()
{
    ++nerrors;
}

oscbnVisitorImpl::oscbnVisitorImpl(ose_bundle b)
{
    bundle = b;
    nerrors = 0;
    incomplete_input = false;
}

oscbnVisitorImpl::oscbnVisitorImpl(int32_t nbytes, char *bytes)
{
    bundle = ose_newBundleFromCBytes(nbytes, bytes);
}

Any oscbnVisitorImpl::visitOsc(
    oscbnParser::OscContext *context)
{
    return visitChildren(context);
}

// Any oscbnVisitorImpl::visitOscBundle(
//     oscbnParser::OscBundleContext *context)
// {
//     ose_pushBundle(bundle);
//     for(const auto& e: context->oscBundleElem())
//     {
//         visit(e);
//         ose_push(bundle);
//     }
//     return context;
// }

Any oscbnVisitorImpl::visitEmptyBundle(
    oscbnParser::EmptyBundleContext *context)
{
    ose_pushBundle(bundle);
    return context;
}

Any oscbnVisitorImpl::visitNonEmptyBundle(
    oscbnParser::NonEmptyBundleContext *context)
{
    ose_pushBundle(bundle);
    for(const auto& e: context->oscBundleElem())
    {
        visit(e);
        ose_push(bundle);
    }
    return context;
}

Any oscbnVisitorImpl::visitUnclosedEmptyBundle(
    oscbnParser::UnclosedEmptyBundleContext *context)
{
    ++nerrors;
    ose_pushBundle(bundle);
    return context;
}

Any oscbnVisitorImpl::visitUnclosedNonEmptyBundle(
    oscbnParser::UnclosedNonEmptyBundleContext *context)
{
    ++nerrors;
    ose_pushBundle(bundle);
    for(const auto& e: context->oscBundleElem())
    {
        visit(e);
        ose_push(bundle);
    }
    return context;
}

Any oscbnVisitorImpl::visitOscBundleElem(
    oscbnParser::OscBundleElemContext *context)
{
    return visitChildren(context);
}

Any oscbnVisitorImpl::visitOscMessage(
    oscbnParser::OscMessageContext *context)
{
    if(context->OSCADDRESS())
    {
        const std::string str = context->OSCADDRESS()->getText();
        ose_pushMessage(bundle, str.c_str(), str.length(), 0);
    }
    else
    {
        ose_pushMessage(bundle, OSE_ADDRESS_ANONVAL,
                        OSE_ADDRESS_ANONVAL_LEN, 0);
    }
    if(context->oscMessageItems())
    {
        for(const auto& e:
                context->oscMessageItems()->oscMessageItem())
        {
            visit(e);
            ose_push(bundle);
        }
    }
    return context;
}

Any oscbnVisitorImpl::visitOscMessageItems(
    oscbnParser::OscMessageItemsContext *context)
{
    return visitChildren(context);
}

Any oscbnVisitorImpl::visitOscMessageItem(
    oscbnParser::OscMessageItemContext *context)
{
    if(context->INT32())
    {
        ose_pushInt32(bundle, std::stol(context->getText()));
    }
    else if(context->FLOAT())
    {
        ose_pushFloat(bundle, std::stof(context->getText()));
    }
    else if(context->STRING())
    {
        const std::string str = context->getText();
        const int32_t len = str.length();
        const std::string strq = str.substr(1, len - 2);
        // process escapes here
        ose_pushString(bundle, strq.c_str());
    }
    else if(context->BLOB())
    {
        std::string str = context->getText();
        const int32_t n = str.length() - 1;
        ose_assert(n % 2 == 0);
        ose_pushBlob(bundle, n / 2, NULL);
        char *bp = ose_peekBlob(bundle);
        bp += 4;
        for(int i = 1; i < n + 1; i += 2)
        {
            char buf[3] = {str[i], str[i + 1], 0};
            char c = (char)strtol(buf, NULL, 16);
            *bp++ = c;
        }
    }
    else if(context->oscBundle())
    {
        Any ret = visitChildren(context);
        return ret;
    }
    return context;
}
