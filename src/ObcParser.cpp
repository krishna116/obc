/*
The MIT License

Copyright 2021 Krishna sssky307@163.com

Permission is hereby granted, free of charge, to any person obtaining a 
copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, including without limitation 
the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the 
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in 
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
IN THE SOFTWARE.
*/
#include "ObcListener.h"
#include "ObcVisitor.h"

#include "ObcParser.h"


using namespace antlrcpp;
using namespace antlr4;

ObcParser::ObcParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ObcParser::~ObcParser() {
  delete _interpreter;
}

std::string ObcParser::getGrammarFileName() const {
  return "Obc.g4";
}

const std::vector<std::string>& ObcParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ObcParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

ObcParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ObcParser::Struct_nameContext* ObcParser::StartContext::struct_name() {
  return getRuleContext<ObcParser::Struct_nameContext>(0);
}

ObcParser::Struct_enterContext* ObcParser::StartContext::struct_enter() {
  return getRuleContext<ObcParser::Struct_enterContext>(0);
}

ObcParser::Struct_exitContext* ObcParser::StartContext::struct_exit() {
  return getRuleContext<ObcParser::Struct_exitContext>(0);
}

std::vector<ObcParser::OptionContext *> ObcParser::StartContext::option() {
  return getRuleContexts<ObcParser::OptionContext>();
}

ObcParser::OptionContext* ObcParser::StartContext::option(size_t i) {
  return getRuleContext<ObcParser::OptionContext>(i);
}

std::vector<ObcParser::MethodContext *> ObcParser::StartContext::method() {
  return getRuleContexts<ObcParser::MethodContext>();
}

ObcParser::MethodContext* ObcParser::StartContext::method(size_t i) {
  return getRuleContext<ObcParser::MethodContext>(i);
}


size_t ObcParser::StartContext::getRuleIndex() const {
  return ObcParser::RuleStart;
}

void ObcParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void ObcParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


antlrcpp::Any ObcParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::StartContext* ObcParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, ObcParser::RuleStart);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    match(ObcParser::T__0);
    setState(25);
    struct_name();
    setState(26);
    struct_enter();
    setState(30);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ObcParser::MacroName) {
      setState(27);
      option();
      setState(32);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(34); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(33);
      method();
      setState(36); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ObcParser::CName

    || _la == ObcParser::NotCName);
    setState(38);
    struct_exit();
    setState(42);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ObcParser::T__1) {
      setState(39);
      match(ObcParser::T__1);
      setState(44);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_nameContext ------------------------------------------------------------------

ObcParser::Struct_nameContext::Struct_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ObcParser::Struct_nameContext::CName() {
  return getToken(ObcParser::CName, 0);
}


size_t ObcParser::Struct_nameContext::getRuleIndex() const {
  return ObcParser::RuleStruct_name;
}

void ObcParser::Struct_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStruct_name(this);
}

void ObcParser::Struct_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStruct_name(this);
}


antlrcpp::Any ObcParser::Struct_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitStruct_name(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::Struct_nameContext* ObcParser::struct_name() {
  Struct_nameContext *_localctx = _tracker.createInstance<Struct_nameContext>(_ctx, getState());
  enterRule(_localctx, 2, ObcParser::RuleStruct_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    match(ObcParser::CName);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_enterContext ------------------------------------------------------------------

ObcParser::Struct_enterContext::Struct_enterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ObcParser::Struct_enterContext::LeftBrace() {
  return getToken(ObcParser::LeftBrace, 0);
}


size_t ObcParser::Struct_enterContext::getRuleIndex() const {
  return ObcParser::RuleStruct_enter;
}

void ObcParser::Struct_enterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStruct_enter(this);
}

void ObcParser::Struct_enterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStruct_enter(this);
}


antlrcpp::Any ObcParser::Struct_enterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitStruct_enter(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::Struct_enterContext* ObcParser::struct_enter() {
  Struct_enterContext *_localctx = _tracker.createInstance<Struct_enterContext>(_ctx, getState());
  enterRule(_localctx, 4, ObcParser::RuleStruct_enter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    match(ObcParser::LeftBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Struct_exitContext ------------------------------------------------------------------

ObcParser::Struct_exitContext::Struct_exitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ObcParser::Struct_exitContext::RightBrace() {
  return getToken(ObcParser::RightBrace, 0);
}


size_t ObcParser::Struct_exitContext::getRuleIndex() const {
  return ObcParser::RuleStruct_exit;
}

void ObcParser::Struct_exitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStruct_exit(this);
}

void ObcParser::Struct_exitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStruct_exit(this);
}


antlrcpp::Any ObcParser::Struct_exitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitStruct_exit(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::Struct_exitContext* ObcParser::struct_exit() {
  Struct_exitContext *_localctx = _tracker.createInstance<Struct_exitContext>(_ctx, getState());
  enterRule(_localctx, 6, ObcParser::RuleStruct_exit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(ObcParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OptionContext ------------------------------------------------------------------

ObcParser::OptionContext::OptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ObcParser::KeyContext* ObcParser::OptionContext::key() {
  return getRuleContext<ObcParser::KeyContext>(0);
}

std::vector<ObcParser::ValueContext *> ObcParser::OptionContext::value() {
  return getRuleContexts<ObcParser::ValueContext>();
}

ObcParser::ValueContext* ObcParser::OptionContext::value(size_t i) {
  return getRuleContext<ObcParser::ValueContext>(i);
}


size_t ObcParser::OptionContext::getRuleIndex() const {
  return ObcParser::RuleOption;
}

void ObcParser::OptionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOption(this);
}

void ObcParser::OptionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOption(this);
}


antlrcpp::Any ObcParser::OptionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitOption(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::OptionContext* ObcParser::option() {
  OptionContext *_localctx = _tracker.createInstance<OptionContext>(_ctx, getState());
  enterRule(_localctx, 8, ObcParser::RuleOption);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    key();
    setState(52);
    match(ObcParser::T__2);
    setState(54); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(53);
      value();
      setState(56); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ObcParser::CName)
      | (1ULL << ObcParser::MacroName)
      | (1ULL << ObcParser::Number))) != 0));
    setState(58);
    match(ObcParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyContext ------------------------------------------------------------------

ObcParser::KeyContext::KeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ObcParser::KeyContext::MacroName() {
  return getToken(ObcParser::MacroName, 0);
}


size_t ObcParser::KeyContext::getRuleIndex() const {
  return ObcParser::RuleKey;
}

void ObcParser::KeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKey(this);
}

void ObcParser::KeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKey(this);
}


antlrcpp::Any ObcParser::KeyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitKey(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::KeyContext* ObcParser::key() {
  KeyContext *_localctx = _tracker.createInstance<KeyContext>(_ctx, getState());
  enterRule(_localctx, 10, ObcParser::RuleKey);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(ObcParser::MacroName);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

ObcParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ObcParser::ValueContext::MacroName() {
  return getToken(ObcParser::MacroName, 0);
}

tree::TerminalNode* ObcParser::ValueContext::CName() {
  return getToken(ObcParser::CName, 0);
}

tree::TerminalNode* ObcParser::ValueContext::Number() {
  return getToken(ObcParser::Number, 0);
}


size_t ObcParser::ValueContext::getRuleIndex() const {
  return ObcParser::RuleValue;
}

void ObcParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void ObcParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}


antlrcpp::Any ObcParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::ValueContext* ObcParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 12, ObcParser::RuleValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ObcParser::CName)
      | (1ULL << ObcParser::MacroName)
      | (1ULL << ObcParser::Number))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodContext ------------------------------------------------------------------

ObcParser::MethodContext::MethodContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ObcParser::Method_leftContext* ObcParser::MethodContext::method_left() {
  return getRuleContext<ObcParser::Method_leftContext>(0);
}

ObcParser::Method_nameContext* ObcParser::MethodContext::method_name() {
  return getRuleContext<ObcParser::Method_nameContext>(0);
}

ObcParser::Method_rightContext* ObcParser::MethodContext::method_right() {
  return getRuleContext<ObcParser::Method_rightContext>(0);
}


size_t ObcParser::MethodContext::getRuleIndex() const {
  return ObcParser::RuleMethod;
}

void ObcParser::MethodContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethod(this);
}

void ObcParser::MethodContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethod(this);
}


antlrcpp::Any ObcParser::MethodContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitMethod(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::MethodContext* ObcParser::method() {
  MethodContext *_localctx = _tracker.createInstance<MethodContext>(_ctx, getState());
  enterRule(_localctx, 14, ObcParser::RuleMethod);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    method_left();
    setState(65);
    method_name();
    setState(66);
    method_right();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_leftContext ------------------------------------------------------------------

ObcParser::Method_leftContext::Method_leftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ObcParser::AnyTokenContext *> ObcParser::Method_leftContext::anyToken() {
  return getRuleContexts<ObcParser::AnyTokenContext>();
}

ObcParser::AnyTokenContext* ObcParser::Method_leftContext::anyToken(size_t i) {
  return getRuleContext<ObcParser::AnyTokenContext>(i);
}


size_t ObcParser::Method_leftContext::getRuleIndex() const {
  return ObcParser::RuleMethod_left;
}

void ObcParser::Method_leftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethod_left(this);
}

void ObcParser::Method_leftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethod_left(this);
}


antlrcpp::Any ObcParser::Method_leftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitMethod_left(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::Method_leftContext* ObcParser::method_left() {
  Method_leftContext *_localctx = _tracker.createInstance<Method_leftContext>(_ctx, getState());
  enterRule(_localctx, 16, ObcParser::RuleMethod_left);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(68);
      anyToken();
      setState(71); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ObcParser::CName

    || _la == ObcParser::NotCName);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnyTokenContext ------------------------------------------------------------------

ObcParser::AnyTokenContext::AnyTokenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ObcParser::AnyTokenContext::CName() {
  return getToken(ObcParser::CName, 0);
}

tree::TerminalNode* ObcParser::AnyTokenContext::NotCName() {
  return getToken(ObcParser::NotCName, 0);
}


size_t ObcParser::AnyTokenContext::getRuleIndex() const {
  return ObcParser::RuleAnyToken;
}

void ObcParser::AnyTokenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnyToken(this);
}

void ObcParser::AnyTokenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnyToken(this);
}


antlrcpp::Any ObcParser::AnyTokenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitAnyToken(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::AnyTokenContext* ObcParser::anyToken() {
  AnyTokenContext *_localctx = _tracker.createInstance<AnyTokenContext>(_ctx, getState());
  enterRule(_localctx, 18, ObcParser::RuleAnyToken);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    _la = _input->LA(1);
    if (!(_la == ObcParser::CName

    || _la == ObcParser::NotCName)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_nameContext ------------------------------------------------------------------

ObcParser::Method_nameContext::Method_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ObcParser::Method_nameContext::MacroName() {
  return getToken(ObcParser::MacroName, 0);
}


size_t ObcParser::Method_nameContext::getRuleIndex() const {
  return ObcParser::RuleMethod_name;
}

void ObcParser::Method_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethod_name(this);
}

void ObcParser::Method_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethod_name(this);
}


antlrcpp::Any ObcParser::Method_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitMethod_name(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::Method_nameContext* ObcParser::method_name() {
  Method_nameContext *_localctx = _tracker.createInstance<Method_nameContext>(_ctx, getState());
  enterRule(_localctx, 20, ObcParser::RuleMethod_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    match(ObcParser::MacroName);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_rightContext ------------------------------------------------------------------

ObcParser::Method_rightContext::Method_rightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ObcParser::Method_rightContext::Args() {
  return getToken(ObcParser::Args, 0);
}


size_t ObcParser::Method_rightContext::getRuleIndex() const {
  return ObcParser::RuleMethod_right;
}

void ObcParser::Method_rightContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethod_right(this);
}

void ObcParser::Method_rightContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ObcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethod_right(this);
}


antlrcpp::Any ObcParser::Method_rightContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ObcVisitor*>(visitor))
    return parserVisitor->visitMethod_right(this);
  else
    return visitor->visitChildren(this);
}

ObcParser::Method_rightContext* ObcParser::method_right() {
  Method_rightContext *_localctx = _tracker.createInstance<Method_rightContext>(_ctx, getState());
  enterRule(_localctx, 22, ObcParser::RuleMethod_right);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(ObcParser::Args);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ObcParser::_decisionToDFA;
atn::PredictionContextCache ObcParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ObcParser::_atn;
std::vector<uint16_t> ObcParser::_serializedATN;

std::vector<std::string> ObcParser::_ruleNames = {
  "start", "struct_name", "struct_enter", "struct_exit", "option", "key", 
  "value", "method", "method_left", "anyToken", "method_name", "method_right"
};

std::vector<std::string> ObcParser::_literalNames = {
  "", "'struct'", "';'", "'='", "", "", "", "", "", "", "'{'", "'}'"
};

std::vector<std::string> ObcParser::_symbolicNames = {
  "", "", "", "", "CName", "MacroName", "NotCName", "Special", "Args", "Number", 
  "LeftBrace", "RightBrace", "Spaces", "Comment1", "Comment2"
};

dfa::Vocabulary ObcParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ObcParser::_tokenNames;

ObcParser::Initializer::Initializer() {
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
       0x3, 0x10, 0x52, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x1f, 0xa, 0x2, 0xc, 
       0x2, 0xe, 0x2, 0x22, 0xb, 0x2, 0x3, 0x2, 0x6, 0x2, 0x25, 0xa, 0x2, 
       0xd, 0x2, 0xe, 0x2, 0x26, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x2b, 0xa, 
       0x2, 0xc, 0x2, 0xe, 0x2, 0x2e, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x6, 0x6, 0x39, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x3a, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x6, 0xa, 0x48, 0xa, 0xa, 0xd, 0xa, 
       0xe, 0xa, 0x49, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x2, 0x2, 0xe, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
       0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x2, 0x4, 0x4, 0x2, 0x6, 0x7, 
       0xb, 0xb, 0x4, 0x2, 0x6, 0x6, 0x8, 0x8, 0x2, 0x4a, 0x2, 0x1a, 0x3, 
       0x2, 0x2, 0x2, 0x4, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x6, 0x31, 0x3, 0x2, 
       0x2, 0x2, 0x8, 0x33, 0x3, 0x2, 0x2, 0x2, 0xa, 0x35, 0x3, 0x2, 0x2, 
       0x2, 0xc, 0x3e, 0x3, 0x2, 0x2, 0x2, 0xe, 0x40, 0x3, 0x2, 0x2, 0x2, 
       0x10, 0x42, 0x3, 0x2, 0x2, 0x2, 0x12, 0x47, 0x3, 0x2, 0x2, 0x2, 0x14, 
       0x4b, 0x3, 0x2, 0x2, 0x2, 0x16, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x18, 0x4f, 
       0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0x3, 0x2, 0x2, 0x1b, 0x1c, 0x5, 
       0x4, 0x3, 0x2, 0x1c, 0x20, 0x5, 0x6, 0x4, 0x2, 0x1d, 0x1f, 0x5, 0xa, 
       0x6, 0x2, 0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x22, 0x3, 0x2, 0x2, 
       0x2, 0x20, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 
       0x21, 0x24, 0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 0x2, 0x2, 0x2, 0x23, 
       0x25, 0x5, 0x10, 0x9, 0x2, 0x24, 0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 
       0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 
       0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2c, 0x5, 
       0x8, 0x5, 0x2, 0x29, 0x2b, 0x7, 0x4, 0x2, 0x2, 0x2a, 0x29, 0x3, 0x2, 
       0x2, 0x2, 0x2b, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 
       0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x3, 0x3, 0x2, 0x2, 0x2, 
       0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x6, 0x2, 0x2, 0x30, 
       0x5, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0xc, 0x2, 0x2, 0x32, 0x7, 
       0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0xd, 0x2, 0x2, 0x34, 0x9, 0x3, 
       0x2, 0x2, 0x2, 0x35, 0x36, 0x5, 0xc, 0x7, 0x2, 0x36, 0x38, 0x7, 0x5, 
       0x2, 0x2, 0x37, 0x39, 0x5, 0xe, 0x8, 0x2, 0x38, 0x37, 0x3, 0x2, 0x2, 
       0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 
       0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3c, 
       0x3d, 0x7, 0x4, 0x2, 0x2, 0x3d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 
       0x7, 0x7, 0x2, 0x2, 0x3f, 0xd, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x9, 
       0x2, 0x2, 0x2, 0x41, 0xf, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x5, 0x12, 
       0xa, 0x2, 0x43, 0x44, 0x5, 0x16, 0xc, 0x2, 0x44, 0x45, 0x5, 0x18, 
       0xd, 0x2, 0x45, 0x11, 0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 0x5, 0x14, 
       0xb, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 
       0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 
       0x4a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x9, 0x3, 0x2, 0x2, 0x4c, 
       0x15, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x7, 0x2, 0x2, 0x4e, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0xa, 0x2, 0x2, 0x50, 0x19, 0x3, 
       0x2, 0x2, 0x2, 0x7, 0x20, 0x26, 0x2c, 0x3a, 0x49, 
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

ObcParser::Initializer ObcParser::_init;
