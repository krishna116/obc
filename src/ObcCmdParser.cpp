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
#include "ObcCmdParser.h"

#include "ObcLexer.h"
#include "ObcParser.h"
#include "ObcErrorListener.h"
#include "ObcTreeVisitor.h"
#include "ObcHelper.h"

#include "config.h"

#include <fstream>
#include <exception>
#include <iostream>
#include <sstream>

ObcCmdParser::ObcCmdParser(int argc, const char **argv)
{
    args = std::vector<std::string>{argv, argv + argc};
}

int ObcCmdParser::doWork()
{
    std::string inputFileName;
    std::string outputDir;

    if (args.size() <= 1)
    {
        return showHelp();
    }

    auto it = args.begin() + 1;
    while (it != args.end())
    {
        if (*it == "-o" || *it == "--output")
        {
            // --output dir
            if ((it + 1) != args.end() && (*(it + 1))[0] != '-' && outputDir.empty())
            {
                outputDir = *(it + 1);
                it += 2;
                continue;
            }
            else
            {
                printf("[error]: invalid input.\n");
                return -1;
            }
        }
        else if (*it == "-h" || *it == "--help")
        {
            // --help
            return showHelp();
        }
        else if (*it == "-v" || *it == "--version")
        {
            // --version
            return showVersion();
        }
        else if (*it == "--verbose")
        {
            // --verbose
            obc::cout.isUsingVerbose = 1;
        }
        else
        {
            // <file>
            if (inputFileName.empty() && (*it)[0] != '-')
            {
                inputFileName = *it;
            }
            else
            {
                printf("[error]: invalid input [%s].\n", (*it).c_str());
                return -1;
            }
        }
        ++it;
    }

    if (inputFileName.empty() || outputDir.empty())
    {
        printf("[error]: invalid input.\n");
        return -1;
    }

    if (outputDir == "stdout")
    {
        outputDir.clear();
        return parseFile(inputFileName, outputDir, true);
    }
    else
    {
        return parseFile(inputFileName, outputDir, false);
    }
}

int ObcCmdParser::showHelp()
{
    std::string str =
        R"~(obc.exe <file> [<options>]

Object based code generating for C language.

Options:
    -o, --output dir        specify output directory or using "stdout" instead.
    -h, --help              show this help.
    -v, --version           show version.
        --verbose           show verbose infomation.)~";

    std::cout << str << std::endl;

    return 0;
}

int ObcCmdParser::showVersion()
{
    std::cout << OBC_VERSION_STR << std::endl;

    return 0;
}

int ObcCmdParser::parseFile(const std::string &inputFileName, const std::string outputDir, bool isUsingStdout)
{
    try
    {
        if (inputFileName.empty())
            throw std::runtime_error("input file name is empty.");

        std::ifstream inFile(inputFileName);
        if (!inFile.good())
            throw std::runtime_error("Cannot open file: " + inputFileName);

        std::stringstream stream;
        stream << inFile.rdbuf();
        inFile.close();

        obc::cout << "input file stream finished." << obc::endl;

        ANTLRInputStream input(stream);
        ObcLexer lexer(&input);
        lexer.addErrorListener(new ObcErrorListener());
        CommonTokenStream tokens(&lexer);

        ObcParser parser(&tokens);
        parser.addErrorListener(new ObcErrorListener());

        std::unique_ptr<ObcTreeVisitor> visitor(new ObcTreeVisitor());
        visitor->visit(parser.start());

        obc::cout << "visit struct finished." << obc::endl;

        ObsFileStream fileStream;
        visitor->getResult(fileStream);

        obc::cout << "get file stream." << obc::endl;

        if (!outputDir.empty())
        {
            fileStream.writeTo(outputDir);
        }

        if (isUsingStdout)
            fileStream.dump();
    }
    catch (const std::exception &e)
    {
        std::cerr << "[error]: " << e.what() << '\n';
        return -1;
    }

    return 0;
}
