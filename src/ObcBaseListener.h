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
#pragma once

#include "antlr4-runtime.h"
#include "ObcListener.h"


/**
 * This class provides an empty implementation of ObcListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ObcBaseListener : public ObcListener {
public:

  virtual void enterStart(ObcParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(ObcParser::StartContext * /*ctx*/) override { }

  virtual void enterStruct_name(ObcParser::Struct_nameContext * /*ctx*/) override { }
  virtual void exitStruct_name(ObcParser::Struct_nameContext * /*ctx*/) override { }

  virtual void enterStruct_enter(ObcParser::Struct_enterContext * /*ctx*/) override { }
  virtual void exitStruct_enter(ObcParser::Struct_enterContext * /*ctx*/) override { }

  virtual void enterStruct_exit(ObcParser::Struct_exitContext * /*ctx*/) override { }
  virtual void exitStruct_exit(ObcParser::Struct_exitContext * /*ctx*/) override { }

  virtual void enterOption(ObcParser::OptionContext * /*ctx*/) override { }
  virtual void exitOption(ObcParser::OptionContext * /*ctx*/) override { }

  virtual void enterKey(ObcParser::KeyContext * /*ctx*/) override { }
  virtual void exitKey(ObcParser::KeyContext * /*ctx*/) override { }

  virtual void enterValue(ObcParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(ObcParser::ValueContext * /*ctx*/) override { }

  virtual void enterMethod(ObcParser::MethodContext * /*ctx*/) override { }
  virtual void exitMethod(ObcParser::MethodContext * /*ctx*/) override { }

  virtual void enterMethod_left(ObcParser::Method_leftContext * /*ctx*/) override { }
  virtual void exitMethod_left(ObcParser::Method_leftContext * /*ctx*/) override { }

  virtual void enterAnyToken(ObcParser::AnyTokenContext * /*ctx*/) override { }
  virtual void exitAnyToken(ObcParser::AnyTokenContext * /*ctx*/) override { }

  virtual void enterMethod_name(ObcParser::Method_nameContext * /*ctx*/) override { }
  virtual void exitMethod_name(ObcParser::Method_nameContext * /*ctx*/) override { }

  virtual void enterMethod_right(ObcParser::Method_rightContext * /*ctx*/) override { }
  virtual void exitMethod_right(ObcParser::Method_rightContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

