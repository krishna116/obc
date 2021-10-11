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
#include "ObcVisitor.h"


/**
 * This class provides an empty implementation of ObcVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ObcBaseVisitor : public ObcVisitor {
public:

  virtual antlrcpp::Any visitStart(ObcParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStruct_name(ObcParser::Struct_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStruct_enter(ObcParser::Struct_enterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStruct_exit(ObcParser::Struct_exitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOption(ObcParser::OptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKey(ObcParser::KeyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue(ObcParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod(ObcParser::MethodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_left(ObcParser::Method_leftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnyToken(ObcParser::AnyTokenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_name(ObcParser::Method_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_right(ObcParser::Method_rightContext *ctx) override {
    return visitChildren(ctx);
  }


};

