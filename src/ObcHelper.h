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

#include <iostream>

/**
 * @brief Provide any help function.
 * 
 */
namespace obc
{
    /**
     * @brief Provide a global printer.
     * using like this: obc::cout<<"something..."<<obc::endl;
     *                  obc::cout.isUsingVerbose=true;
     *                  obc::cout<<"something..."<<obc::endl;
     */
    struct cout_
    {
        static bool isUsingVerbose;
        std::string prefix="[info ]: ";

        cout_ &operator<<(cout_& other)
        {
            if (isUsingVerbose)
            {
                std::cout<<std::endl;
            }
            return *this;
        }

        template <typename T>
        cout_ &operator<<(T msg)
        {
            if (isUsingVerbose)
            {
                std::cout << prefix << msg;
            }
            return *this;
        }
    };

    static cout_ cout;
    static cout_ endl;
}
