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

#include "ObcBaseVisitor.h"
#include "ObcHelper.h"

#include <set>
#include <string>
#include <vector>
#include <optional>
#include <fstream>

struct ObsFileStream
{
    // filename.
    std::string hFileName;
    std::string cFileName;

    // class.h content.
    std::string includeGuardBegin;
    std::string typeDefinePart;
    std::string structApiPart;
    std::string publicApiPart;
    std::string includeGuardEnd;

    // class.c content.
    std::string implementInclude;
    std::string implementPart;

    int dump()
    {
        obc::cout << "output to stdout:" << obc::endl;

        printf("\n");
        printf("// [%s] ---------------------------------------------\n", hFileName.c_str());
        printf("%s", includeGuardBegin.c_str());
        printf("%s", typeDefinePart.c_str());
        printf("%s", structApiPart.c_str());
        printf("%s", publicApiPart.c_str());
        printf("%s", includeGuardEnd.c_str());

        printf("\n");
        printf("\n// [%s] ---------------------------------------------\n", cFileName.c_str());
        printf("%s", implementInclude.c_str());
        printf("%s", implementPart.c_str());

        return 0;
    }

    int writeTo(const std::string &outputDir)
    {
        if (hFileName.empty() || cFileName.empty())
        {
            throw std::runtime_error("obsFileStream is empty.");
        }

        std::string hFileFullName = outputDir + "/" + hFileName;
        std::ofstream hFile(hFileFullName);
        if (!hFile.good())
            throw std::runtime_error("cannot write file: " + hFileFullName);
        hFile << includeGuardBegin;
        hFile << typeDefinePart;
        hFile << structApiPart;
        hFile << publicApiPart;
        hFile << includeGuardEnd;
        hFile.flush();
        hFile.close();
        obc::cout << "output: " << hFileFullName << obc::endl;

        std::string cFileFullName = outputDir + "/" + cFileName;
        std::ofstream cFile(cFileFullName);
        if (!cFile.good())
            throw std::runtime_error("cannot write file: " + hFileFullName);
        cFile << implementInclude;
        cFile << implementPart;
        cFile.flush();
        cFile.close();
        obc::cout << "output: " << cFileFullName << obc::endl;

        return 0;
    }
};

typedef void (*PrintMessageFn)(const std::string &msg);

class ObcTreeVisitor : public ObcBaseVisitor
{
public:
    ObcTreeVisitor();
    virtual ~ObcTreeVisitor();

    virtual antlrcpp::Any visitStruct_name(ObcParser::Struct_nameContext *ctx) override;

    virtual antlrcpp::Any visitStruct_enter(ObcParser::Struct_enterContext *ctx) override;

    virtual antlrcpp::Any visitMethod(ObcParser::MethodContext *ctx) override;

    virtual antlrcpp::Any visitOption(ObcParser::OptionContext *ctx) override;

    virtual antlrcpp::Any visitStruct_exit(ObcParser::Struct_exitContext *ctx) override;

    void getResult(ObsFileStream &fileStream)
    {
        fileStream = std::move(obsfileStream_);
    }

private:
    static ObsFileStream obsfileStream_;

    struct VisitCache;
    VisitCache *cache_;

    const std::string indent_ = "    ";
    std::string removeMacroChar(std::string token);
    std::string getUpperString(std::string str);
};
