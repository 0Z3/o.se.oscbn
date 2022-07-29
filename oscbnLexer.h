
// Generated from oscbn.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"


namespace oscbn {


class  oscbnLexer : public antlr4::Lexer {
public:
  enum {
    OSCPATTERN = 1, OSCADDRESS = 2, INT32 = 3, FLOAT = 4, Digit = 5, DigitSequence = 6, 
    STRING = 7, BLOB = 8, TIMETAG = 9, BIND = 10, LBRACKET = 11, RBRACKET = 12, 
    LBRACE = 13, RBRACE = 14, SEQSEP = 15, COMMENT = 16, WHITESPACE = 17
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

}  // namespace oscbn
