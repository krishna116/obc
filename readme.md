# obc
Object based code generating for C language.

特点：  
1，提供简单的构造函数/析构函数。  
2，没有实现虚函数表。  
3，松散的词法/语法检查。

Feature：  
1，provide simple constructor/destructor.  
2，it has no vtbl(virtual table) implementation.  
3，loose lexer/grammar check. (you need keep C language semantics).

# Usage
1，given a text file(stack.txt) like this:
~~~
struct stack
{
    // Options for code generating, all options are optional.
    %self% = self;         //this pointer name.
    %ctor% = create;       //default constructor name.
    %dtor% = destroy;      //default destructor name.
    %ator% = malloc;
    %etor% = free;
    %asst% = assert;

    //
    // There are various combinations for this option, for example:
    // %apis%   = %Class% _ %Method% _ %class% _ %method% _
    // %apis%   = any_prefix_ %method% _any_suffix
    //
    // These values are place holder:
    // %class% means class-name begin with lower-case.
    // %Class% means class-name begin with upper-case.
    // %method% means method-name begin with lower-case.
    // %Method% means method-name begin with upper-case.
    //
    %apis% = %class% _ %method%; //public api style.

    // Public APIs.
    bool    %push%  (data_t data);
    data_t  %pop%   ();
    size_t  %size%  ();
    void    %clear% ();
};
~~~
2, run command:
~~~
obc.exe stack.txt --output stdout
~~~
3，This is the output:
~~~
// [stack.h] ---------------------------------------------
#ifndef _STACK_H_
#define _STACK_H_

typedef struct stack_ stack;
typedef bool (*STACK_PUSH)(stack* self, data_t data);
typedef data_t (*STACK_POP)(stack* self);
typedef size_t (*STACK_SIZE)(stack* self);
typedef void (*STACK_CLEAR)(stack* self);
typedef void (*STACK_DESTROY)(stack** self);

struct stack_
{
    STACK_PUSH       push;
    STACK_POP        pop;
    STACK_SIZE       size;
    STACK_CLEAR      clear;
    STACK_DESTROY    destroy;
};

stack* stack_create();
bool stack_push(stack* self, data_t data);
data_t stack_pop(stack* self);
size_t stack_size(stack* self);
void stack_clear(stack* self);
void stack_destroy(stack** self);

#endif //_STACK_H_
~~~

~~~
// [stack.c] ---------------------------------------------
#include "stack.h"

stack* stack_create()
{
    stack* s= (stack*)malloc(sizeof(stack));
    assert(s != NULL);

    s->push = stack_push;
    s->pop = stack_pop;
    s->size = stack_size;
    s->clear = stack_clear;
    s->destroy = stack_destroy;

    return s;
}

bool stack_push(stack* self, data_t data)
{
    // To be done...
}

data_t stack_pop(stack* self)
{
    // To be done...
}

size_t stack_size(stack* self)
{
    // To be done...
}

void stack_clear(stack* self)
{
    // To be done...
}

void stack_destroy(stack** self)
{
    if(self && *self)
    {
        free(*self);
        (*self) = NULL;
    }
}
~~~
# How to build it
This project has used antlr technology and it has antlr-runtime dependency. it can be built with msys/mingw64 shell.  
1, Install antlr4-runtime:  
```
pacman -S mingw-w64-x86_64-antlr4-runtime-cpp
```
2, Build:
```
#You may need set antlr-runtime variable:
#cmake -S . -B build -G "MinGW Makefiles" -D ANTLR4_INCLUDE_DIR=<where> -D ANTLR4_LIBRARY_DIR=<where> -D ANTLR4_LIBRARY_NAME=<name>
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
```

# References  
https://www.antlr.org/  
http://ldeniau.web.cern.ch/ldeniau/html/oopc/oopc.html  
https://www.cs.rit.edu/~ats/books/ooc.pdf  
https://lwn.net/Articles/444910/
