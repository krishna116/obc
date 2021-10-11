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
#include "ObcParser.h"

/**
 * This interface defines an abstract listener for a parse tree produced by ObcParser.
 */
class  ObcListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(ObcParser::StartContext *ctx) = 0;
  virtual void exitStart(ObcParser::StartContext *ctx) = 0;

  virtual void enterStruct_name(ObcParser::Struct_nameContext *ctx) = 0;
  virtual void exitStruct_name(ObcParser::Struct_nameContext *ctx) = 0;

  virtual void enterStruct_enter(ObcParser::Struct_enterContext *ctx) = 0;
  virtual void exitStruct_enter(ObcParser::Struct_enterContext *ctx) = 0;

  virtual void enterStruct_exit(ObcParser::Struct_exitContext *ctx) = 0;
  virtual void exitStruct_exit(ObcParser::Struct_exitContext *ctx) = 0;

  virtual void enterOption(ObcParser::OptionContext *ctx) = 0;
  virtual void exitOption(ObcParser::OptionContext *ctx) = 0;

  virtual void enterKey(ObcParser::KeyContext *ctx) = 0;
  virtual void exitKey(ObcParser::KeyContext *ctx) = 0;

  virtual void enterValue(ObcParser::ValueContext *ctx) = 0;
  virtual void exitValue(ObcParser::ValueContext *ctx) = 0;

  virtual void enterMethod(ObcParser::MethodContext *ctx) = 0;
  virtual void exitMethod(ObcParser::MethodContext *ctx) = 0;

  virtual void enterMethod_left(ObcParser::Method_leftContext *ctx) = 0;
  virtual void exitMethod_left(ObcParser::Method_leftContext *ctx) = 0;

  virtual void enterAnyToken(ObcParser::AnyTokenContext *ctx) = 0;
  virtual void exitAnyToken(ObcParser::AnyTokenContext *ctx) = 0;

  virtual void enterMethod_name(ObcParser::Method_nameContext *ctx) = 0;
  virtual void exitMethod_name(ObcParser::Method_nameContext *ctx) = 0;

  virtual void enterMethod_right(ObcParser::Method_rightContext *ctx) = 0;
  virtual void exitMethod_right(ObcParser::Method_rightContext *ctx) = 0;


};

