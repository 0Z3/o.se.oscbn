
// Generated from oscbn.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "oscbnParser.h"


namespace oscbn {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by oscbnParser.
 */
class  oscbnVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by oscbnParser.
   */
    virtual antlrcpp::Any visitOsc(oscbnParser::OscContext *context) = 0;

    virtual antlrcpp::Any visitEmptyBundle(oscbnParser::EmptyBundleContext *context) = 0;

    virtual antlrcpp::Any visitNonEmptyBundle(oscbnParser::NonEmptyBundleContext *context) = 0;

    virtual antlrcpp::Any visitUnclosedEmptyBundle(oscbnParser::UnclosedEmptyBundleContext *context) = 0;

    virtual antlrcpp::Any visitUnclosedNonEmptyBundle(oscbnParser::UnclosedNonEmptyBundleContext *context) = 0;

    virtual antlrcpp::Any visitOscBundleElem(oscbnParser::OscBundleElemContext *context) = 0;

    virtual antlrcpp::Any visitOscMessage(oscbnParser::OscMessageContext *context) = 0;

    virtual antlrcpp::Any visitOscMessageItems(oscbnParser::OscMessageItemsContext *context) = 0;

    virtual antlrcpp::Any visitOscMessageItem(oscbnParser::OscMessageItemContext *context) = 0;


};

}  // namespace oscbn
