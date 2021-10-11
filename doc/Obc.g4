
//
// The MIT License
// Copyright 2021 Krishna sssky307@163.com
//
// Grammar for the obc.exe tool.
// antlr4 -Dlanguage=Cpp Obc.g4 -listener -visitor -o src
//
grammar Obc;

start		: 'struct' struct_name struct_enter (option)* (method)+ struct_exit ';'* ;

struct_name	: CName ;

struct_enter: LeftBrace ;
struct_exit	: RightBrace ;

option		: key '=' (value)+ ';' ;
key			: MacroName ;
value		: MacroName | CName | Number;

method		: method_left method_name method_right ;
method_left	: (anyToken)+ ;
anyToken    : CName | NotCName ;
method_name	: MacroName ;
method_right : Args ;


//
// lexer
//
CName		: [a-zA-Z_]([a-zA-Z0-9_])* ;
MacroName	: [%] CName [%] ;
NotCName	: (Special)? CName Special | Special;
Special		: ('*' | '&' | ':' | '[' | ']')+ ;
Args		: [(] ~[;]*? [;] ;
Number		: [0-9]+ ;
LeftBrace	: '{' ;
RightBrace	: '}' ;
			

Spaces		: [ \t\r\n] -> skip ;
Comment1	: '//' .*? '\r'? '\n' -> skip ;
Comment2	: '/*' .*? '*/' -> skip ;