
// Generated from oscbn.g4 by ANTLR 4.9.3


#include "oscbnVisitor.h"

#include "oscbnParser.h"


using namespace antlrcpp;
using namespace oscbn;
using namespace antlr4;

oscbnParser::oscbnParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

oscbnParser::~oscbnParser() {
  delete _interpreter;
}

std::string oscbnParser::getGrammarFileName() const {
  return "oscbn.g4";
}

const std::vector<std::string>& oscbnParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& oscbnParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- OscContext ------------------------------------------------------------------

oscbnParser::OscContext::OscContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

oscbnParser::OscBundleContext* oscbnParser::OscContext::oscBundle() {
  return getRuleContext<oscbnParser::OscBundleContext>(0);
}

oscbnParser::OscMessageContext* oscbnParser::OscContext::oscMessage() {
  return getRuleContext<oscbnParser::OscMessageContext>(0);
}

oscbnParser::OscUnclosedBundleContext* oscbnParser::OscContext::oscUnclosedBundle() {
  return getRuleContext<oscbnParser::OscUnclosedBundleContext>(0);
}


size_t oscbnParser::OscContext::getRuleIndex() const {
  return oscbnParser::RuleOsc;
}


antlrcpp::Any oscbnParser::OscContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<oscbnVisitor*>(visitor))
    return parserVisitor->visitOsc(this);
  else
    return visitor->visitChildren(this);
}

oscbnParser::OscContext* oscbnParser::osc() {
  OscContext *_localctx = _tracker.createInstance<OscContext>(_ctx, getState());
  enterRule(_localctx, 0, oscbnParser::RuleOsc);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(17);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(14);
      oscBundle();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(15);
      oscMessage();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(16);
      oscUnclosedBundle();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OscBundleContext ------------------------------------------------------------------

oscbnParser::OscBundleContext::OscBundleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t oscbnParser::OscBundleContext::getRuleIndex() const {
  return oscbnParser::RuleOscBundle;
}

void oscbnParser::OscBundleContext::copyFrom(OscBundleContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- EmptyBundleContext ------------------------------------------------------------------

tree::TerminalNode* oscbnParser::EmptyBundleContext::LBRACE() {
  return getToken(oscbnParser::LBRACE, 0);
}

tree::TerminalNode* oscbnParser::EmptyBundleContext::RBRACE() {
  return getToken(oscbnParser::RBRACE, 0);
}

oscbnParser::EmptyBundleContext::EmptyBundleContext(OscBundleContext *ctx) { copyFrom(ctx); }


antlrcpp::Any oscbnParser::EmptyBundleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<oscbnVisitor*>(visitor))
    return parserVisitor->visitEmptyBundle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NonEmptyBundleContext ------------------------------------------------------------------

tree::TerminalNode* oscbnParser::NonEmptyBundleContext::LBRACE() {
  return getToken(oscbnParser::LBRACE, 0);
}

tree::TerminalNode* oscbnParser::NonEmptyBundleContext::RBRACE() {
  return getToken(oscbnParser::RBRACE, 0);
}

std::vector<oscbnParser::OscBundleElemContext *> oscbnParser::NonEmptyBundleContext::oscBundleElem() {
  return getRuleContexts<oscbnParser::OscBundleElemContext>();
}

oscbnParser::OscBundleElemContext* oscbnParser::NonEmptyBundleContext::oscBundleElem(size_t i) {
  return getRuleContext<oscbnParser::OscBundleElemContext>(i);
}

std::vector<tree::TerminalNode *> oscbnParser::NonEmptyBundleContext::SEQSEP() {
  return getTokens(oscbnParser::SEQSEP);
}

tree::TerminalNode* oscbnParser::NonEmptyBundleContext::SEQSEP(size_t i) {
  return getToken(oscbnParser::SEQSEP, i);
}

oscbnParser::NonEmptyBundleContext::NonEmptyBundleContext(OscBundleContext *ctx) { copyFrom(ctx); }


antlrcpp::Any oscbnParser::NonEmptyBundleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<oscbnVisitor*>(visitor))
    return parserVisitor->visitNonEmptyBundle(this);
  else
    return visitor->visitChildren(this);
}
oscbnParser::OscBundleContext* oscbnParser::oscBundle() {
  OscBundleContext *_localctx = _tracker.createInstance<OscBundleContext>(_ctx, getState());
  enterRule(_localctx, 2, oscbnParser::RuleOscBundle);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(32);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<oscbnParser::EmptyBundleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(19);
      match(oscbnParser::LBRACE);
      setState(20);
      match(oscbnParser::RBRACE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<oscbnParser::NonEmptyBundleContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(21);
      match(oscbnParser::LBRACE);
      setState(22);
      antlrcpp::downCast<NonEmptyBundleContext *>(_localctx)->first = oscBundleElem();
      setState(27);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == oscbnParser::SEQSEP) {
        setState(23);
        match(oscbnParser::SEQSEP);
        setState(24);
        antlrcpp::downCast<NonEmptyBundleContext *>(_localctx)->rest = oscBundleElem();
        setState(29);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(30);
      match(oscbnParser::RBRACE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OscUnclosedBundleContext ------------------------------------------------------------------

oscbnParser::OscUnclosedBundleContext::OscUnclosedBundleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t oscbnParser::OscUnclosedBundleContext::getRuleIndex() const {
  return oscbnParser::RuleOscUnclosedBundle;
}

void oscbnParser::OscUnclosedBundleContext::copyFrom(OscUnclosedBundleContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnclosedEmptyBundleContext ------------------------------------------------------------------

tree::TerminalNode* oscbnParser::UnclosedEmptyBundleContext::LBRACE() {
  return getToken(oscbnParser::LBRACE, 0);
}

oscbnParser::UnclosedEmptyBundleContext::UnclosedEmptyBundleContext(OscUnclosedBundleContext *ctx) { copyFrom(ctx); }


antlrcpp::Any oscbnParser::UnclosedEmptyBundleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<oscbnVisitor*>(visitor))
    return parserVisitor->visitUnclosedEmptyBundle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnclosedNonEmptyBundleContext ------------------------------------------------------------------

tree::TerminalNode* oscbnParser::UnclosedNonEmptyBundleContext::LBRACE() {
  return getToken(oscbnParser::LBRACE, 0);
}

std::vector<oscbnParser::OscBundleElemContext *> oscbnParser::UnclosedNonEmptyBundleContext::oscBundleElem() {
  return getRuleContexts<oscbnParser::OscBundleElemContext>();
}

oscbnParser::OscBundleElemContext* oscbnParser::UnclosedNonEmptyBundleContext::oscBundleElem(size_t i) {
  return getRuleContext<oscbnParser::OscBundleElemContext>(i);
}

std::vector<tree::TerminalNode *> oscbnParser::UnclosedNonEmptyBundleContext::SEQSEP() {
  return getTokens(oscbnParser::SEQSEP);
}

tree::TerminalNode* oscbnParser::UnclosedNonEmptyBundleContext::SEQSEP(size_t i) {
  return getToken(oscbnParser::SEQSEP, i);
}

oscbnParser::UnclosedNonEmptyBundleContext::UnclosedNonEmptyBundleContext(OscUnclosedBundleContext *ctx) { copyFrom(ctx); }


antlrcpp::Any oscbnParser::UnclosedNonEmptyBundleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<oscbnVisitor*>(visitor))
    return parserVisitor->visitUnclosedNonEmptyBundle(this);
  else
    return visitor->visitChildren(this);
}
oscbnParser::OscUnclosedBundleContext* oscbnParser::oscUnclosedBundle() {
  OscUnclosedBundleContext *_localctx = _tracker.createInstance<OscUnclosedBundleContext>(_ctx, getState());
  enterRule(_localctx, 4, oscbnParser::RuleOscUnclosedBundle);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<oscbnParser::UnclosedEmptyBundleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(34);
      match(oscbnParser::LBRACE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<oscbnParser::UnclosedNonEmptyBundleContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(35);
      match(oscbnParser::LBRACE);
      setState(36);
      antlrcpp::downCast<UnclosedNonEmptyBundleContext *>(_localctx)->first = oscBundleElem();
      setState(41);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == oscbnParser::SEQSEP) {
        setState(37);
        match(oscbnParser::SEQSEP);
        setState(38);
        antlrcpp::downCast<UnclosedNonEmptyBundleContext *>(_localctx)->rest = oscBundleElem();
        setState(43);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OscBundleElemContext ------------------------------------------------------------------

oscbnParser::OscBundleElemContext::OscBundleElemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

oscbnParser::OscBundleContext* oscbnParser::OscBundleElemContext::oscBundle() {
  return getRuleContext<oscbnParser::OscBundleContext>(0);
}

oscbnParser::OscMessageContext* oscbnParser::OscBundleElemContext::oscMessage() {
  return getRuleContext<oscbnParser::OscMessageContext>(0);
}


size_t oscbnParser::OscBundleElemContext::getRuleIndex() const {
  return oscbnParser::RuleOscBundleElem;
}


antlrcpp::Any oscbnParser::OscBundleElemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<oscbnVisitor*>(visitor))
    return parserVisitor->visitOscBundleElem(this);
  else
    return visitor->visitChildren(this);
}

oscbnParser::OscBundleElemContext* oscbnParser::oscBundleElem() {
  OscBundleElemContext *_localctx = _tracker.createInstance<OscBundleElemContext>(_ctx, getState());
  enterRule(_localctx, 6, oscbnParser::RuleOscBundleElem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(48);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(46);
      oscBundle();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(47);
      oscMessage();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OscMessageContext ------------------------------------------------------------------

oscbnParser::OscMessageContext::OscMessageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* oscbnParser::OscMessageContext::OSCADDRESS() {
  return getToken(oscbnParser::OSCADDRESS, 0);
}

tree::TerminalNode* oscbnParser::OscMessageContext::BIND() {
  return getToken(oscbnParser::BIND, 0);
}

oscbnParser::OscMessageItemsContext* oscbnParser::OscMessageContext::oscMessageItems() {
  return getRuleContext<oscbnParser::OscMessageItemsContext>(0);
}

tree::TerminalNode* oscbnParser::OscMessageContext::OSCPATTERN() {
  return getToken(oscbnParser::OSCPATTERN, 0);
}


size_t oscbnParser::OscMessageContext::getRuleIndex() const {
  return oscbnParser::RuleOscMessage;
}


antlrcpp::Any oscbnParser::OscMessageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<oscbnVisitor*>(visitor))
    return parserVisitor->visitOscMessage(this);
  else
    return visitor->visitChildren(this);
}

oscbnParser::OscMessageContext* oscbnParser::oscMessage() {
  OscMessageContext *_localctx = _tracker.createInstance<OscMessageContext>(_ctx, getState());
  enterRule(_localctx, 8, oscbnParser::RuleOscMessage);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(69);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(50);
      match(oscbnParser::OSCADDRESS);
      setState(52);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == oscbnParser::BIND) {
        setState(51);
        match(oscbnParser::BIND);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(55);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == oscbnParser::OSCADDRESS) {
        setState(54);
        match(oscbnParser::OSCADDRESS);
      }
      setState(57);
      match(oscbnParser::BIND);
      setState(58);
      oscMessageItems();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(59);
      match(oscbnParser::OSCPATTERN);
      setState(61);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == oscbnParser::BIND) {
        setState(60);
        match(oscbnParser::BIND);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(64);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == oscbnParser::OSCPATTERN) {
        setState(63);
        match(oscbnParser::OSCPATTERN);
      }
      setState(66);
      match(oscbnParser::BIND);
      setState(67);
      oscMessageItems();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(68);
      oscMessageItems();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OscMessageItemsContext ------------------------------------------------------------------

oscbnParser::OscMessageItemsContext::OscMessageItemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<oscbnParser::OscMessageItemContext *> oscbnParser::OscMessageItemsContext::oscMessageItem() {
  return getRuleContexts<oscbnParser::OscMessageItemContext>();
}

oscbnParser::OscMessageItemContext* oscbnParser::OscMessageItemsContext::oscMessageItem(size_t i) {
  return getRuleContext<oscbnParser::OscMessageItemContext>(i);
}

tree::TerminalNode* oscbnParser::OscMessageItemsContext::LBRACKET() {
  return getToken(oscbnParser::LBRACKET, 0);
}

tree::TerminalNode* oscbnParser::OscMessageItemsContext::RBRACKET() {
  return getToken(oscbnParser::RBRACKET, 0);
}

std::vector<tree::TerminalNode *> oscbnParser::OscMessageItemsContext::SEQSEP() {
  return getTokens(oscbnParser::SEQSEP);
}

tree::TerminalNode* oscbnParser::OscMessageItemsContext::SEQSEP(size_t i) {
  return getToken(oscbnParser::SEQSEP, i);
}


size_t oscbnParser::OscMessageItemsContext::getRuleIndex() const {
  return oscbnParser::RuleOscMessageItems;
}


antlrcpp::Any oscbnParser::OscMessageItemsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<oscbnVisitor*>(visitor))
    return parserVisitor->visitOscMessageItems(this);
  else
    return visitor->visitChildren(this);
}

oscbnParser::OscMessageItemsContext* oscbnParser::oscMessageItems() {
  OscMessageItemsContext *_localctx = _tracker.createInstance<OscMessageItemsContext>(_ctx, getState());
  enterRule(_localctx, 10, oscbnParser::RuleOscMessageItems);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case oscbnParser::INT32:
      case oscbnParser::FLOAT:
      case oscbnParser::STRING:
      case oscbnParser::BLOB:
      case oscbnParser::TIMETAG:
      case oscbnParser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(71);
        oscMessageItem();
        break;
      }

      case oscbnParser::LBRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(72);
        match(oscbnParser::LBRACKET);
        setState(74);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << oscbnParser::INT32)
          | (1ULL << oscbnParser::FLOAT)
          | (1ULL << oscbnParser::STRING)
          | (1ULL << oscbnParser::BLOB)
          | (1ULL << oscbnParser::TIMETAG)
          | (1ULL << oscbnParser::LBRACE))) != 0)) {
          setState(73);
          antlrcpp::downCast<OscMessageItemsContext *>(_localctx)->first = oscMessageItem();
        }
        setState(80);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == oscbnParser::SEQSEP) {
          setState(76);
          match(oscbnParser::SEQSEP);
          setState(77);
          antlrcpp::downCast<OscMessageItemsContext *>(_localctx)->rest = oscMessageItem();
          setState(82);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(83);
        match(oscbnParser::RBRACKET);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OscMessageItemContext ------------------------------------------------------------------

oscbnParser::OscMessageItemContext::OscMessageItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* oscbnParser::OscMessageItemContext::INT32() {
  return getToken(oscbnParser::INT32, 0);
}

tree::TerminalNode* oscbnParser::OscMessageItemContext::FLOAT() {
  return getToken(oscbnParser::FLOAT, 0);
}

tree::TerminalNode* oscbnParser::OscMessageItemContext::STRING() {
  return getToken(oscbnParser::STRING, 0);
}

tree::TerminalNode* oscbnParser::OscMessageItemContext::BLOB() {
  return getToken(oscbnParser::BLOB, 0);
}

tree::TerminalNode* oscbnParser::OscMessageItemContext::TIMETAG() {
  return getToken(oscbnParser::TIMETAG, 0);
}

oscbnParser::OscBundleContext* oscbnParser::OscMessageItemContext::oscBundle() {
  return getRuleContext<oscbnParser::OscBundleContext>(0);
}


size_t oscbnParser::OscMessageItemContext::getRuleIndex() const {
  return oscbnParser::RuleOscMessageItem;
}


antlrcpp::Any oscbnParser::OscMessageItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<oscbnVisitor*>(visitor))
    return parserVisitor->visitOscMessageItem(this);
  else
    return visitor->visitChildren(this);
}

oscbnParser::OscMessageItemContext* oscbnParser::oscMessageItem() {
  OscMessageItemContext *_localctx = _tracker.createInstance<OscMessageItemContext>(_ctx, getState());
  enterRule(_localctx, 12, oscbnParser::RuleOscMessageItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case oscbnParser::INT32: {
        enterOuterAlt(_localctx, 1);
        setState(86);
        match(oscbnParser::INT32);
        break;
      }

      case oscbnParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(87);
        match(oscbnParser::FLOAT);
        break;
      }

      case oscbnParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(88);
        match(oscbnParser::STRING);
        break;
      }

      case oscbnParser::BLOB: {
        enterOuterAlt(_localctx, 4);
        setState(89);
        match(oscbnParser::BLOB);
        break;
      }

      case oscbnParser::TIMETAG: {
        enterOuterAlt(_localctx, 5);
        setState(90);
        match(oscbnParser::TIMETAG);
        break;
      }

      case oscbnParser::LBRACE: {
        enterOuterAlt(_localctx, 6);
        setState(91);
        oscBundle();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> oscbnParser::_decisionToDFA;
atn::PredictionContextCache oscbnParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN oscbnParser::_atn;
std::vector<uint16_t> oscbnParser::_serializedATN;

std::vector<std::string> oscbnParser::_ruleNames = {
  "osc", "oscBundle", "oscUnclosedBundle", "oscBundleElem", "oscMessage", 
  "oscMessageItems", "oscMessageItem"
};

std::vector<std::string> oscbnParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "':'", "'['", "']'", "'{'", "'}'", 
  "','"
};

std::vector<std::string> oscbnParser::_symbolicNames = {
  "", "OSCPATTERN", "OSCADDRESS", "INT32", "FLOAT", "Digit", "DigitSequence", 
  "STRING", "BLOB", "TIMETAG", "BIND", "LBRACKET", "RBRACKET", "LBRACE", 
  "RBRACE", "SEQSEP", "COMMENT", "WHITESPACE"
};

dfa::Vocabulary oscbnParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> oscbnParser::_tokenNames;

oscbnParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x13, 0x61, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 
       0x14, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x7, 0x3, 0x1c, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x1f, 0xb, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x23, 0xa, 0x3, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x2a, 0xa, 0x4, 0xc, 
       0x4, 0xe, 0x4, 0x2d, 0xb, 0x4, 0x5, 0x4, 0x2f, 0xa, 0x4, 0x3, 0x5, 
       0x3, 0x5, 0x5, 0x5, 0x33, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 
       0x37, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x3a, 0xa, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x40, 0xa, 0x6, 0x3, 0x6, 0x5, 
       0x6, 0x43, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x48, 
       0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x4d, 0xa, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x51, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 
       0x54, 0xb, 0x7, 0x3, 0x7, 0x5, 0x7, 0x57, 0xa, 0x7, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x5f, 0xa, 
       0x8, 0x3, 0x8, 0x2, 0x2, 0x9, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
       0x2, 0x2, 0x2, 0x70, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 0x4, 0x22, 0x3, 
       0x2, 0x2, 0x2, 0x6, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x32, 0x3, 0x2, 
       0x2, 0x2, 0xa, 0x47, 0x3, 0x2, 0x2, 0x2, 0xc, 0x56, 0x3, 0x2, 0x2, 
       0x2, 0xe, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x14, 0x5, 0x4, 0x3, 0x2, 
       0x11, 0x14, 0x5, 0xa, 0x6, 0x2, 0x12, 0x14, 0x5, 0x6, 0x4, 0x2, 0x13, 
       0x10, 0x3, 0x2, 0x2, 0x2, 0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x12, 
       0x3, 0x2, 0x2, 0x2, 0x14, 0x3, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x7, 
       0xf, 0x2, 0x2, 0x16, 0x23, 0x7, 0x10, 0x2, 0x2, 0x17, 0x18, 0x7, 
       0xf, 0x2, 0x2, 0x18, 0x1d, 0x5, 0x8, 0x5, 0x2, 0x19, 0x1a, 0x7, 0x11, 
       0x2, 0x2, 0x1a, 0x1c, 0x5, 0x8, 0x5, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 
       0x2, 0x1c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 
       0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x20, 0x3, 0x2, 0x2, 0x2, 0x1f, 
       0x1d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x7, 0x10, 0x2, 0x2, 0x21, 
       0x23, 0x3, 0x2, 0x2, 0x2, 0x22, 0x15, 0x3, 0x2, 0x2, 0x2, 0x22, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x23, 0x5, 0x3, 0x2, 0x2, 0x2, 0x24, 0x2f, 0x7, 
       0xf, 0x2, 0x2, 0x25, 0x26, 0x7, 0xf, 0x2, 0x2, 0x26, 0x2b, 0x5, 0x8, 
       0x5, 0x2, 0x27, 0x28, 0x7, 0x11, 0x2, 0x2, 0x28, 0x2a, 0x5, 0x8, 
       0x5, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2d, 0x3, 0x2, 0x2, 
       0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 
       0x2c, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2e, 
       0x24, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x7, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x5, 0x4, 0x3, 0x2, 0x31, 0x33, 0x5, 
       0xa, 0x6, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x31, 0x3, 0x2, 
       0x2, 0x2, 0x33, 0x9, 0x3, 0x2, 0x2, 0x2, 0x34, 0x36, 0x7, 0x4, 0x2, 
       0x2, 0x35, 0x37, 0x7, 0xc, 0x2, 0x2, 0x36, 0x35, 0x3, 0x2, 0x2, 0x2, 
       0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x48, 0x3, 0x2, 0x2, 0x2, 0x38, 
       0x3a, 0x7, 0x4, 0x2, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 
       0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 
       0xc, 0x2, 0x2, 0x3c, 0x48, 0x5, 0xc, 0x7, 0x2, 0x3d, 0x3f, 0x7, 0x3, 
       0x2, 0x2, 0x3e, 0x40, 0x7, 0xc, 0x2, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 
       0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0x48, 0x3, 0x2, 0x2, 0x2, 
       0x41, 0x43, 0x7, 0x3, 0x2, 0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x42, 
       0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 
       0x7, 0xc, 0x2, 0x2, 0x45, 0x48, 0x5, 0xc, 0x7, 0x2, 0x46, 0x48, 0x5, 
       0xc, 0x7, 0x2, 0x47, 0x34, 0x3, 0x2, 0x2, 0x2, 0x47, 0x39, 0x3, 0x2, 
       0x2, 0x2, 0x47, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x47, 0x42, 0x3, 0x2, 0x2, 
       0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0xb, 0x3, 0x2, 0x2, 0x2, 
       0x49, 0x57, 0x5, 0xe, 0x8, 0x2, 0x4a, 0x4c, 0x7, 0xd, 0x2, 0x2, 0x4b, 
       0x4d, 0x5, 0xe, 0x8, 0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 
       0x3, 0x2, 0x2, 0x2, 0x4d, 0x52, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x7, 
       0x11, 0x2, 0x2, 0x4f, 0x51, 0x5, 0xe, 0x8, 0x2, 0x50, 0x4e, 0x3, 
       0x2, 0x2, 0x2, 0x51, 0x54, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 
       0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x55, 0x3, 0x2, 0x2, 
       0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x55, 0x57, 0x7, 0xe, 0x2, 0x2, 
       0x56, 0x49, 0x3, 0x2, 0x2, 0x2, 0x56, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x57, 
       0xd, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5f, 0x7, 0x5, 0x2, 0x2, 0x59, 0x5f, 
       0x7, 0x6, 0x2, 0x2, 0x5a, 0x5f, 0x7, 0x9, 0x2, 0x2, 0x5b, 0x5f, 0x7, 
       0xa, 0x2, 0x2, 0x5c, 0x5f, 0x7, 0xb, 0x2, 0x2, 0x5d, 0x5f, 0x5, 0x4, 
       0x3, 0x2, 0x5e, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x59, 0x3, 0x2, 0x2, 
       0x2, 0x5e, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5b, 0x3, 0x2, 0x2, 0x2, 
       0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 
       0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 0x13, 0x1d, 0x22, 0x2b, 0x2e, 0x32, 
       0x36, 0x39, 0x3f, 0x42, 0x47, 0x4c, 0x52, 0x56, 0x5e, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

oscbnParser::Initializer oscbnParser::_init;
