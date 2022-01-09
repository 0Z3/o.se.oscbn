
// Generated from oscbn.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  oscbnLexer : public antlr4::Lexer {
public:
  enum {
    OSCPATTERN = 1, OSCADDRESS = 2, INT32 = 3, FLOAT = 4, DigitSequence = 5, 
    STRING = 6, BLOB = 7, BIND = 8, LBRACKET = 9, RBRACKET = 10, LBRACE = 11, 
    RBRACE = 12, SEQSEP = 13, COMMENT = 14, WHITESPACE = 15
  };

  explicit oscbnLexer(antlr4::CharStream *input);
  ~oscbnLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

