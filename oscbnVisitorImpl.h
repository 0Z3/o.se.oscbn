#pragma once

#include "antlr4-runtime.h"
#include "oscbnVisitor.h"
#include "oscbnParser.h"

#include "ose_conf.h"
#include "ose.h"

class  oscbnVisitorImpl : oscbnVisitor {
 private:
	ose_bundle bundle;
    int nerrors;
    bool incomplete_input;
 public:
    int getNErrors();
    void incNErrors();
	oscbnVisitorImpl(ose_bundle b);
	oscbnVisitorImpl(int32_t nbytes, char *bytes);
	// antlrcpp::Any visitTopLevelBundle(oscbnParser::TopLevelBundleContext *context);
    antlrcpp::Any visitOsc(oscbnParser::OscContext *context);
	// antlrcpp::Any visitOscBundle(oscbnParser::OscBundleContext *context);
    antlrcpp::Any visitEmptyBundle(oscbnParser::EmptyBundleContext *context);
    antlrcpp::Any visitNonEmptyBundle(oscbnParser::NonEmptyBundleContext *context);
    antlrcpp::Any visitUnclosedEmptyBundle(oscbnParser::UnclosedEmptyBundleContext *context);
    antlrcpp::Any visitUnclosedNonEmptyBundle(oscbnParser::UnclosedNonEmptyBundleContext *context);
	antlrcpp::Any visitOscBundleElem(oscbnParser::OscBundleElemContext *context);
	antlrcpp::Any visitOscMessage(oscbnParser::OscMessageContext *context);
	antlrcpp::Any visitOscMessageItems(oscbnParser::OscMessageItemsContext *context);
	antlrcpp::Any visitOscMessageItem(oscbnParser::OscMessageItemContext *context);
	ose_bundle getBundle();
};

