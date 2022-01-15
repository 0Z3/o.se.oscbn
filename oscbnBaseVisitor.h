
// Generated from oscbn.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "oscbnVisitor.h"


namespace oscbn {

/**
 * This class provides an empty implementation of oscbnVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  oscbnBaseVisitor : public oscbnVisitor {
public:

  virtual antlrcpp::Any visitOsc(oscbnParser::OscContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyBundle(oscbnParser::EmptyBundleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonEmptyBundle(oscbnParser::NonEmptyBundleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnclosedEmptyBundle(oscbnParser::UnclosedEmptyBundleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnclosedNonEmptyBundle(oscbnParser::UnclosedNonEmptyBundleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOscBundleElem(oscbnParser::OscBundleElemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOscMessage(oscbnParser::OscMessageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOscMessageItems(oscbnParser::OscMessageItemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOscMessageItem(oscbnParser::OscMessageItemContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace oscbn
