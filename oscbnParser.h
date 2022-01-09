
// Generated from oscbn.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  oscbnParser : public antlr4::Parser {
public:
  enum {
    OSCPATTERN = 1, OSCADDRESS = 2, INT32 = 3, FLOAT = 4, DigitSequence = 5, 
    STRING = 6, BLOB = 7, BIND = 8, LBRACKET = 9, RBRACKET = 10, LBRACE = 11, 
    RBRACE = 12, SEQSEP = 13, COMMENT = 14, WHITESPACE = 15
  };

  enum {
    RuleOsc = 0, RuleOscBundle = 1, RuleOscUnclosedBundle = 2, RuleOscBundleElem = 3, 
    RuleOscMessage = 4, RuleOscMessageItems = 5, RuleOscMessageItem = 6
  };

  explicit oscbnParser(antlr4::TokenStream *input);
  ~oscbnParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class OscContext;
  class OscBundleContext;
  class OscUnclosedBundleContext;
  class OscBundleElemContext;
  class OscMessageContext;
  class OscMessageItemsContext;
  class OscMessageItemContext; 

  class  OscContext : public antlr4::ParserRuleContext {
  public:
    OscContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OscBundleContext *oscBundle();
    OscMessageContext *oscMessage();
    OscUnclosedBundleContext *oscUnclosedBundle();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OscContext* osc();

  class  OscBundleContext : public antlr4::ParserRuleContext {
  public:
    OscBundleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OscBundleContext() = default;
    void copyFrom(OscBundleContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  EmptyBundleContext : public OscBundleContext {
  public:
    EmptyBundleContext(OscBundleContext *ctx);

    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NonEmptyBundleContext : public OscBundleContext {
  public:
    NonEmptyBundleContext(OscBundleContext *ctx);

    oscbnParser::OscBundleElemContext *first = nullptr;
    oscbnParser::OscBundleElemContext *rest = nullptr;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<OscBundleElemContext *> oscBundleElem();
    OscBundleElemContext* oscBundleElem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEQSEP();
    antlr4::tree::TerminalNode* SEQSEP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  OscBundleContext* oscBundle();

  class  OscUnclosedBundleContext : public antlr4::ParserRuleContext {
  public:
    OscUnclosedBundleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OscUnclosedBundleContext() = default;
    void copyFrom(OscUnclosedBundleContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnclosedEmptyBundleContext : public OscUnclosedBundleContext {
  public:
    UnclosedEmptyBundleContext(OscUnclosedBundleContext *ctx);

    antlr4::tree::TerminalNode *LBRACE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnclosedNonEmptyBundleContext : public OscUnclosedBundleContext {
  public:
    UnclosedNonEmptyBundleContext(OscUnclosedBundleContext *ctx);

    oscbnParser::OscBundleElemContext *first = nullptr;
    oscbnParser::OscBundleElemContext *rest = nullptr;
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<OscBundleElemContext *> oscBundleElem();
    OscBundleElemContext* oscBundleElem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEQSEP();
    antlr4::tree::TerminalNode* SEQSEP(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  OscUnclosedBundleContext* oscUnclosedBundle();

  class  OscBundleElemContext : public antlr4::ParserRuleContext {
  public:
    OscBundleElemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OscBundleContext *oscBundle();
    OscMessageContext *oscMessage();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OscBundleElemContext* oscBundleElem();

  class  OscMessageContext : public antlr4::ParserRuleContext {
  public:
    OscMessageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OSCADDRESS();
    antlr4::tree::TerminalNode *BIND();
    OscMessageItemsContext *oscMessageItems();
    antlr4::tree::TerminalNode *OSCPATTERN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OscMessageContext* oscMessage();

  class  OscMessageItemsContext : public antlr4::ParserRuleContext {
  public:
    oscbnParser::OscMessageItemContext *first = nullptr;
    oscbnParser::OscMessageItemContext *rest = nullptr;
    OscMessageItemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OscMessageItemContext *> oscMessageItem();
    OscMessageItemContext* oscMessageItem(size_t i);
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    std::vector<antlr4::tree::TerminalNode *> SEQSEP();
    antlr4::tree::TerminalNode* SEQSEP(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OscMessageItemsContext* oscMessageItems();

  class  OscMessageItemContext : public antlr4::ParserRuleContext {
  public:
    OscMessageItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT32();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *BLOB();
    OscBundleContext *oscBundle();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OscMessageItemContext* oscMessageItem();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

