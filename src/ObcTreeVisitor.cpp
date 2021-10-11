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

#include "ObcTreeVisitor.h"

#include <iostream>

ObsFileStream ObcTreeVisitor::obsfileStream_ = ObsFileStream();

struct ObcTreeVisitor::VisitCache
{
    std::string structName;
    std::string self = "self";
    std::string ctor;
    std::string dtor;
    std::string ator = "malloc";
    std::string etor = "free";
    std::string asst = "assert";
    std::vector<std::string> apis;

    std::set<std::string> uniqueOptionNameSet;
    static const size_t maxTokenSizeAllowed = 255;
    static const char macroChar = '%';
    struct Method
    {
        enum class MethodType
        {
            Unknown,
            Constructor,
            Destructor
        };
        std::string leftPart;
        std::string name;
        std::string rightPart;
        MethodType methodType = MethodType::Unknown;
    };
    std::vector<Method> methodArray;
    std::size_t visitedMethodNameMaxSize = 0;
};

ObcTreeVisitor::ObcTreeVisitor()
    : cache_(new VisitCache())
{
    assert(cache_ != nullptr);
}

ObcTreeVisitor::~ObcTreeVisitor()
{
    if (cache_)
    {
        delete cache_;
        cache_ = nullptr;
    }
}

antlrcpp::Any ObcTreeVisitor::visitStruct_name(ObcParser::Struct_nameContext *ctx)
{
    obc::cout << "visit struct: " + ctx->CName()->getText() << obc::endl;
    
    cache_->structName = ctx->CName()->getText();

    return visitChildren(ctx);
}

antlrcpp::Any ObcTreeVisitor::visitStruct_enter(ObcParser::Struct_enterContext *ctx)
{
    //assert(cache_ != nullptr);
    return visitChildren(ctx);
}

antlrcpp::Any ObcTreeVisitor::visitMethod(ObcParser::MethodContext *ctx)
{
    VisitCache::Method method;

    obc::cout << "visit method: " + ctx->method_name()->getText() << obc::endl;

    // make left part words split with space for code generating.
    bool fillSpace=0;
    for(auto const& v: ctx->method_left()->anyToken())
    {
        if(fillSpace) method.leftPart+=" ";
        method.leftPart += v->getText();
        fillSpace=1;
    };

    method.name = removeMacroChar(ctx->method_name()->getText());
    method.rightPart = ctx->method_right()->getText();
    cache_->methodArray.push_back(method);
    cache_->visitedMethodNameMaxSize = std::max(cache_->visitedMethodNameMaxSize,method.name.size());

    return visitChildren(ctx);
}

antlrcpp::Any ObcTreeVisitor::visitOption(ObcParser::OptionContext *ctx)
{
    assert(cache_ != nullptr);
    using MethodType = VisitCache::Method::MethodType;

    obc::cout << "visit option: " + ctx->key()->getText() << obc::endl;

    auto optionName = ctx->key()->getText();
    auto result = cache_->uniqueOptionNameSet.insert(optionName);
    if (result.second == false)
        throw std::runtime_error("duplicated options are not allowed.");

    auto checkOneValue = [&](const std::string &optionName) {
        auto values = ctx->value();

        if (values.size() != 1)
            throw std::runtime_error("option " + optionName + "'s value is invald.");

        auto value = values[0]->getText();

        if (value.empty())
            throw std::runtime_error("option " + optionName + "'s value cannot be empty.");

        if (value[0] == '%')
            throw std::runtime_error("option " + optionName + "'s value should be a CName.");

        if (value.size() > cache_->maxTokenSizeAllowed)
            throw std::runtime_error("option value-length out of range, max-length-allowed-is: " + std::to_string(cache_->maxTokenSizeAllowed) + ".");

        return value;
    };

    if (optionName == "%self%")
    {
        cache_->self = checkOneValue(optionName);
    }
    else if (optionName == "%ctor%")
    {
        cache_->ctor = checkOneValue(optionName);
    }
    else if (optionName == "%dtor%")
    {
        cache_->dtor = checkOneValue(optionName);
    }
    else if (optionName == "%ator%")
    {
        cache_->ator = checkOneValue(optionName);
    }
    else if (optionName == "%etor%")
    {
        cache_->etor = checkOneValue(optionName);
    }
    else if (optionName == "%asst%")
    {
        cache_->asst = checkOneValue(optionName);
    }
    else if (optionName == "%apis%")
    {
        std::string methodMacroName1 = "%Method%";
        std::string methodMacroName2 = "%method%";
        bool hasAnyMethodMacroName = false;

        for (auto const &v : ctx->value())
        {
            if (v->getText() == methodMacroName1 || v->getText() == methodMacroName2)
            {
                hasAnyMethodMacroName = true;
            }
            cache_->apis.push_back(v->getText());
        }
        if (!hasAnyMethodMacroName)
        {
            throw std::runtime_error("public api style must have a method-macro-name:" + methodMacroName1 + " or " + methodMacroName2);
        }
    }
    else
    {
        throw std::runtime_error("unknown option: " + optionName);
    }

    return visitChildren(ctx);
}

antlrcpp::Any ObcTreeVisitor::visitStruct_exit(ObcParser::Struct_exitContext *ctx)
{
    assert(cache_ != nullptr);
    auto &fileStream = ObcTreeVisitor::obsfileStream_;

    obc::cout << "generate code start..." << obc::endl;

    auto getIncludeGuardName = [&]() {
        std::string str{"_"};
        
        str += getUpperString(cache_->structName);
        str += "_H_";

        return str;
    };

    fileStream.hFileName = cache_->structName + ".h";
    fileStream.cFileName = cache_->structName + ".c";
    fileStream.includeGuardBegin = "#ifndef " + getIncludeGuardName() + "\n";
    fileStream.includeGuardBegin += "#define " + getIncludeGuardName() + "\n";
    fileStream.includeGuardEnd = "#endif //" + getIncludeGuardName() + "\n";
    fileStream.implementInclude = "#include \"" + fileStream.hFileName + "\"\n";

    using MethodType = VisitCache::Method::MethodType;

    auto getSelfPointer = [&](bool isUsingOneStar = true) {
        std::string str = cache_->structName;

        (isUsingOneStar) ? (str += "* ") : (str += "** ");
        str += cache_->self;

        return str;
    };

    auto splitMethodNameToWords = [&](const std::string &methodName) {
        std::vector<std::string> words;
        std::string word;
        
        for (auto const &ch : methodName)
        {
            if (std::isupper(ch))
            {
                if (!word.empty())
                    words.push_back(std::move(word));
                word.push_back(ch);
            }
            else
            {
                word.push_back(ch);
            }
        }
        if (!word.empty())
        {
            words.push_back(std::move(word));
        }

        return words;
    };

    auto getAlignSpaces = [&](const std::string &methodName) {
        auto thisMethodNameSize = methodName.size();
        assert(cache_->visitedMethodNameMaxSize >= thisMethodNameSize);

        auto alignSize = cache_->visitedMethodNameMaxSize - thisMethodNameSize + 4;

        return std::string(alignSize, ' ');
    };

    auto getTypedefMethodName = [&](const std::string &methodName) {
        std::string str;

        str += getUpperString(cache_->structName);
        for (auto const &word : splitMethodNameToWords(methodName))
        {
            str += "_" + getUpperString(word);
        }

        return str;
    };

    auto getPublicApiName = [&](std::string methodName) {
        std::string str;
        std::string className = cache_->structName;
        
        //we will directly access string[0], so assert.
        assert(!className.empty());
        assert(!methodName.empty());

        for (auto const &token : cache_->apis)
        {
            if (token == "%class%")
            {
                className[0] = ::tolower(className[0]);
                str += className;
            }
            else if (token == "%Class%")
            {
                className[0] = ::toupper(className[0]);
                str += className;
            }
            else if (token == "%method%")
            {
                methodName[0] = ::tolower(methodName[0]);
                str += methodName;
            }
            else if (token == "%Method%")
            {
                methodName[0] = ::toupper(methodName[0]);
                str += methodName;
            }
            else
            {
                str += removeMacroChar(token);
            }
        }

        return str;
    };

    auto insertSelfPointer = [&](std::string methodRight, const MethodType &methodType) {
        std::string str;
        bool hasArg = false;

        assert(methodRight.size() >= 2);

        for (auto const &ch : methodRight)
        {
            if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_')
            {
                hasArg = true;
                break;
            }
        }

        //methodRight is "(...);"
        str += methodRight.substr(0, 1); //it is "("

        if (methodType == MethodType::Destructor)
        {
            str += getSelfPointer(false);
        }
        else
        {
            str += getSelfPointer(true);
        }

        //methodRight is "(...);", if it contains any argument(not empty),
        //we need insert a ',' before next argument;
        if (hasArg)
        {
            str += ", ";
        }

        str += methodRight.substr(1);

        return str;
    };

    auto buildTypedefPart = [&](const std::string &methodLeft, const std::string &methodName, const std::string &methodRight, const MethodType &methodType) {
        std::string str;

        if (methodType != MethodType::Constructor)
        {
            str += "typedef " + methodLeft + " (*" + getTypedefMethodName(methodName) + ")";
            str += insertSelfPointer(methodRight, methodType) + "\n";
        }

        return str;
    };

    auto buildStructApiPart = [&](const std::string &methodLeft, const std::string &methodName, const std::string &methodRight, const MethodType &methodType) {
        std::string str;

        if (methodType != MethodType::Constructor)
        {
            str += indent_ + getTypedefMethodName(methodName) + getAlignSpaces(methodName) + methodName + ";\n";
        }
        return str;
    };

    auto buildPublicApifPart = [&](const std::string &methodLeft, const std::string &methodName, const std::string &methodRight, const MethodType &methodType) {
        std::string str;
        str += methodLeft + " ";
        str += getPublicApiName(methodName);

        if (methodType != MethodType::Constructor)
        {
            str += insertSelfPointer(methodRight, methodType);
        }
        else
        {
            str += methodRight;
        }

        {
            //generate implementPart;
            fileStream.implementPart += "\n";
            fileStream.implementPart += str;

            if (fileStream.implementPart.back() == ';')
            {
                //remove redundant ";"
                fileStream.implementPart.pop_back();
            }
            fileStream.implementPart += "\n{\n";

            if (methodType == MethodType::Constructor && !cache_->ator.empty())
            {
                //constructor code here.
                std::string var(1, cache_->structName[0]);

                fileStream.implementPart += indent_;
                fileStream.implementPart += cache_->structName + "* " + var;
                fileStream.implementPart += "= (" + cache_->structName + "*)" + cache_->ator + "(sizeof(" + cache_->structName + "));\n";

                if (!cache_->asst.empty())
                {
                    fileStream.implementPart += indent_ + cache_->asst + "(" + var + " != NULL);\n";
                }

                fileStream.implementPart += "\n";
                for (auto const &method : cache_->methodArray)
                {
                    if (method.methodType == MethodType::Constructor)
                        continue;
                    fileStream.implementPart += indent_;
                    fileStream.implementPart += var + "->" + removeMacroChar(method.name) + " = ";
                    fileStream.implementPart += getPublicApiName(method.name) + ";\n";
                }
                fileStream.implementPart += "\n";
                fileStream.implementPart += indent_ + "return " + var + ";\n";
            }
            else if (methodType == MethodType::Destructor && !cache_->etor.empty())
            {
                //destructor code here.
                fileStream.implementPart += indent_ + "if(" + cache_->self + " && *" + cache_->self + ")\n";
                fileStream.implementPart += indent_ + "{\n";
                fileStream.implementPart += indent_ + indent_ + cache_->etor + "(*" + cache_->self + ");\n";
                fileStream.implementPart += indent_ + indent_ + "(*" + cache_->self + ") = NULL;\n";
                fileStream.implementPart += indent_ + "}\n";
            }
            else
            {
                fileStream.implementPart += "    // To be done...\n";
            }

            fileStream.implementPart += "}\n";
        } // generate implement part end.

        str += "\n";
        return str;
    };

    auto getFrontDeclarationStructName = [&]() {
        return std::string{"struct " + cache_->structName + "_"};
    };

    auto buildMethodCode = [&](const std::string &methodLeft, const std::string &methodName, const std::string &methodRight, const MethodType &methodType) {
        fileStream.typeDefinePart += buildTypedefPart(methodLeft, methodName, methodRight, methodType);
        fileStream.structApiPart += buildStructApiPart(methodLeft, methodName, methodRight, methodType);
        fileStream.publicApiPart += buildPublicApifPart(methodLeft, methodName, methodRight, methodType);
    };

    auto prepareConstructorAndDestructor = [&]() {
        if (!cache_->ctor.empty())
        {
            // insert default constructor for code generating.
            VisitCache::Method method;
            method.leftPart = cache_->structName + "*";
            method.name = cache_->ctor;
            method.rightPart = "();";
            method.methodType = MethodType::Constructor;
            cache_->methodArray.insert(cache_->methodArray.begin(), method);
            cache_->visitedMethodNameMaxSize = std::max(cache_->visitedMethodNameMaxSize, method.name.size());
        }

        if (!cache_->dtor.empty())
        {
            // insert default destructor for code generating.
            VisitCache::Method method;
            method.leftPart = "void";
            method.name = cache_->dtor;
            method.rightPart = "();";
            method.methodType = MethodType::Destructor;
            cache_->methodArray.push_back(method);
            cache_->visitedMethodNameMaxSize = std::max(cache_->visitedMethodNameMaxSize, method.name.size());
        }
    };

    auto buildCode = [&]() {
        fileStream.typeDefinePart += "typedef " + getFrontDeclarationStructName() + " " + cache_->structName + ";\n";
        fileStream.structApiPart += getFrontDeclarationStructName() + "\n{\n";

        prepareConstructorAndDestructor();
        for (auto const &method : cache_->methodArray)
        {
            obc::cout << " generate -> " + method.name << obc::endl;
            buildMethodCode(method.leftPart, method.name, method.rightPart, method.methodType);
        }
        fileStream.structApiPart += "};\n";

        // insert empty line between every part for write-file.
        fileStream.includeGuardBegin += "\n";
        fileStream.typeDefinePart += "\n";
        fileStream.publicApiPart += "\n";
        fileStream.structApiPart += "\n";
    };

    buildCode();

    obc::cout << "generate code finished." << obc::endl;
    return visitChildren(ctx);
}

std::string ObcTreeVisitor::removeMacroChar(std::string token)
{
    std::string str;

    if (!token.empty() && token[0] == VisitCache::macroChar)
    {
        str = token.substr(1);
    }
    else
    {
        str = token;
    }

    if (!str.empty() && str.back() == VisitCache::macroChar)
    {
        str.pop_back();
    }

    assert(!str.empty());
    return str;
}

std::string ObcTreeVisitor::getUpperString(std::string str)
{
    for (auto &ch : str)
    {
        ch = ::toupper(ch);
    }
    return str;
};
