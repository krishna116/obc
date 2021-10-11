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
 * This class defines an abstract visitor for a parse tree
 * produced by ObcParser.
 */
class  ObcVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ObcParser.
   */
    virtual antlrcpp::Any visitStart(ObcParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitStruct_name(ObcParser::Struct_nameContext *context) = 0;

    virtual antlrcpp::Any visitStruct_enter(ObcParser::Struct_enterContext *context) = 0;

    virtual antlrcpp::Any visitStruct_exit(ObcParser::Struct_exitContext *context) = 0;

    virtual antlrcpp::Any visitOption(ObcParser::OptionContext *context) = 0;

    virtual antlrcpp::Any visitKey(ObcParser::KeyContext *context) = 0;

    virtual antlrcpp::Any visitValue(ObcParser::ValueContext *context) = 0;

    virtual antlrcpp::Any visitMethod(ObcParser::MethodContext *context) = 0;

    virtual antlrcpp::Any visitMethod_left(ObcParser::Method_leftContext *context) = 0;

    virtual antlrcpp::Any visitAnyToken(ObcParser::AnyTokenContext *context) = 0;

    virtual antlrcpp::Any visitMethod_name(ObcParser::Method_nameContext *context) = 0;

    virtual antlrcpp::Any visitMethod_right(ObcParser::Method_rightContext *context) = 0;
};
