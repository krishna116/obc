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
#include "ObcLexer.h"

using namespace antlr4;

ObcLexer::ObcLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ObcLexer::~ObcLexer() {
  delete _interpreter;
}

std::string ObcLexer::getGrammarFileName() const {
  return "Obc.g4";
}

const std::vector<std::string>& ObcLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& ObcLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& ObcLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& ObcLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& ObcLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> ObcLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& ObcLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> ObcLexer::_decisionToDFA;
atn::PredictionContextCache ObcLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ObcLexer::_atn;
std::vector<uint16_t> ObcLexer::_serializedATN;

std::vector<std::string> ObcLexer::_ruleNames = {
  "T__0", "T__1", "T__2", "CName", "MacroName", "NotCName", "Special", "Args", 
  "Number", "LeftBrace", "RightBrace", "Spaces", "Comment1", "Comment2"
};

std::vector<std::string> ObcLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> ObcLexer::_modeNames = {
  "DEFAULT_MODE"
};

std::vector<std::string> ObcLexer::_literalNames = {
  "", "'struct'", "';'", "'='", "", "", "", "", "", "", "'{'", "'}'"
};

std::vector<std::string> ObcLexer::_symbolicNames = {
  "", "", "", "", "CName", "MacroName", "NotCName", "Special", "Args", "Number", 
  "LeftBrace", "RightBrace", "Spaces", "Comment1", "Comment2"
};

dfa::Vocabulary ObcLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ObcLexer::_tokenNames;

ObcLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
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
       0x2, 0x10, 0x77, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 
       0x4, 0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 
       0x7, 0x9, 0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 
       0x9, 0xa, 0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 
       0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x2d, 0xa, 
       0x5, 0xc, 0x5, 0xe, 0x5, 0x30, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x7, 0x5, 0x7, 0x37, 0xa, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x3d, 0xa, 0x7, 0x3, 0x8, 0x6, 
       0x8, 0x40, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x41, 0x3, 0x9, 0x3, 0x9, 
       0x7, 0x9, 0x46, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x49, 0xb, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0xa, 0x6, 0xa, 0x4e, 0xa, 0xa, 0xd, 0xa, 0xe, 
       0xa, 0x4f, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
       0x7, 0xe, 0x5e, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x61, 0xb, 0xe, 0x3, 
       0xe, 0x5, 0xe, 0x64, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x6e, 0xa, 
       0xf, 0xc, 0xf, 0xe, 0xf, 0x71, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0x47, 0x5f, 0x6f, 0x2, 0x10, 0x3, 0x3, 
       0x5, 0x4, 0x7, 0x5, 0x9, 0x6, 0xb, 0x7, 0xd, 0x8, 0xf, 0x9, 0x11, 
       0xa, 0x13, 0xb, 0x15, 0xc, 0x17, 0xd, 0x19, 0xe, 0x1b, 0xf, 0x1d, 
       0x10, 0x3, 0x2, 0xa, 0x5, 0x2, 0x43, 0x5c, 0x61, 0x61, 0x63, 0x7c, 
       0x6, 0x2, 0x32, 0x3b, 0x43, 0x5c, 0x61, 0x61, 0x63, 0x7c, 0x3, 0x2, 
       0x27, 0x27, 0x7, 0x2, 0x28, 0x28, 0x2c, 0x2c, 0x3c, 0x3c, 0x5d, 0x5d, 
       0x5f, 0x5f, 0x3, 0x2, 0x2a, 0x2a, 0x3, 0x2, 0x3d, 0x3d, 0x3, 0x2, 
       0x32, 0x3b, 0x5, 0x2, 0xb, 0xc, 0xf, 0xf, 0x22, 0x22, 0x2, 0x7f, 
       0x2, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 
       0x7, 0x3, 0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2, 0xb, 
       0x3, 0x2, 0x2, 0x2, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x2, 0xf, 0x3, 
       0x2, 0x2, 0x2, 0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x2, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0x2, 0x15, 0x3, 0x2, 0x2, 0x2, 0x2, 0x17, 0x3, 0x2, 0x2, 
       0x2, 0x2, 0x19, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 
       0x2, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x3, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x5, 
       0x26, 0x3, 0x2, 0x2, 0x2, 0x7, 0x28, 0x3, 0x2, 0x2, 0x2, 0x9, 0x2a, 
       0x3, 0x2, 0x2, 0x2, 0xb, 0x31, 0x3, 0x2, 0x2, 0x2, 0xd, 0x3c, 0x3, 
       0x2, 0x2, 0x2, 0xf, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x11, 0x43, 0x3, 0x2, 
       0x2, 0x2, 0x13, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x15, 0x51, 0x3, 0x2, 0x2, 
       0x2, 0x17, 0x53, 0x3, 0x2, 0x2, 0x2, 0x19, 0x55, 0x3, 0x2, 0x2, 0x2, 
       0x1b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1f, 
       0x20, 0x7, 0x75, 0x2, 0x2, 0x20, 0x21, 0x7, 0x76, 0x2, 0x2, 0x21, 
       0x22, 0x7, 0x74, 0x2, 0x2, 0x22, 0x23, 0x7, 0x77, 0x2, 0x2, 0x23, 
       0x24, 0x7, 0x65, 0x2, 0x2, 0x24, 0x25, 0x7, 0x76, 0x2, 0x2, 0x25, 
       0x4, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x7, 0x3d, 0x2, 0x2, 0x27, 0x6, 
       0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0x3f, 0x2, 0x2, 0x29, 0x8, 0x3, 
       0x2, 0x2, 0x2, 0x2a, 0x2e, 0x9, 0x2, 0x2, 0x2, 0x2b, 0x2d, 0x9, 0x3, 
       0x2, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x30, 0x3, 0x2, 0x2, 
       0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 
       0x2f, 0xa, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x31, 
       0x32, 0x9, 0x4, 0x2, 0x2, 0x32, 0x33, 0x5, 0x9, 0x5, 0x2, 0x33, 0x34, 
       0x9, 0x4, 0x2, 0x2, 0x34, 0xc, 0x3, 0x2, 0x2, 0x2, 0x35, 0x37, 0x5, 
       0xf, 0x8, 0x2, 0x36, 0x35, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 
       0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x5, 0x9, 0x5, 
       0x2, 0x39, 0x3a, 0x5, 0xf, 0x8, 0x2, 0x3a, 0x3d, 0x3, 0x2, 0x2, 0x2, 
       0x3b, 0x3d, 0x5, 0xf, 0x8, 0x2, 0x3c, 0x36, 0x3, 0x2, 0x2, 0x2, 0x3c, 
       0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0xe, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 
       0x9, 0x5, 0x2, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 
       0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 
       0x2, 0x2, 0x42, 0x10, 0x3, 0x2, 0x2, 0x2, 0x43, 0x47, 0x9, 0x6, 0x2, 
       0x2, 0x44, 0x46, 0xa, 0x7, 0x2, 0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 
       0x46, 0x49, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x47, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 
       0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x9, 0x7, 0x2, 0x2, 0x4b, 0x12, 0x3, 
       0x2, 0x2, 0x2, 0x4c, 0x4e, 0x9, 0x8, 0x2, 0x2, 0x4d, 0x4c, 0x3, 0x2, 
       0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 
       0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x14, 0x3, 0x2, 0x2, 0x2, 
       0x51, 0x52, 0x7, 0x7d, 0x2, 0x2, 0x52, 0x16, 0x3, 0x2, 0x2, 0x2, 
       0x53, 0x54, 0x7, 0x7f, 0x2, 0x2, 0x54, 0x18, 0x3, 0x2, 0x2, 0x2, 
       0x55, 0x56, 0x9, 0x9, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 
       0x58, 0x8, 0xd, 0x2, 0x2, 0x58, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 
       0x7, 0x31, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x31, 0x2, 0x2, 0x5b, 0x5f, 
       0x3, 0x2, 0x2, 0x2, 0x5c, 0x5e, 0xb, 0x2, 0x2, 0x2, 0x5d, 0x5c, 0x3, 
       0x2, 0x2, 0x2, 0x5e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 
       0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 0x63, 0x3, 0x2, 0x2, 
       0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x62, 0x64, 0x7, 0xf, 0x2, 0x2, 
       0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 
       0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 0xc, 0x2, 0x2, 0x66, 0x67, 
       0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x8, 0xe, 0x2, 0x2, 0x68, 0x1c, 0x3, 
       0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x31, 0x2, 0x2, 0x6a, 0x6b, 0x7, 
       0x2c, 0x2, 0x2, 0x6b, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6e, 0xb, 
       0x2, 0x2, 0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x71, 0x3, 0x2, 
       0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 
       0x2, 0x70, 0x72, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 
       0x72, 0x73, 0x7, 0x2c, 0x2, 0x2, 0x73, 0x74, 0x7, 0x31, 0x2, 0x2, 
       0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x8, 0xf, 0x2, 0x2, 0x76, 
       0x1e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x2, 0x2e, 0x36, 0x3c, 0x41, 0x47, 
       0x4f, 0x5f, 0x63, 0x6f, 0x3, 0x8, 0x2, 0x2, 
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

ObcLexer::Initializer ObcLexer::_init;
