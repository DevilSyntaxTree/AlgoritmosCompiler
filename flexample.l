
%{ 
    #include <iostream>
    #include "tokens.h"

    #define TOKEN(X) return tokens::X;
    extern std::string* pStr;
%}

%option c++
%option noyywrap

%%

[ \t\n\r]+              { /* ignore whitespace */ }

"if"                    { TOKEN(IF) }
"while"                 { TOKEN(WHILE) }
"print"                 { TOKEN(PRINT) }
"read"                  { TOKEN(READ) }

[a-zA-Z_][a-zA-Z0_9]*   { pStr = new std::string(yytext, yyleng); TOKEN(IDENTIFIER) }
[0-9]+                  { pStr = new std::string(yytext, yyleng); TOKEN(INT) }

"="                     { pStr = new std::string(yytext, yyleng); TOKEN(ASSIGN) }
"+"                     { pStr = new std::string(yytext, yyleng); TOKEN(PLUS) }
"-"                     { pStr = new std::string(yytext, yyleng); TOKEN(MINUS) }
"*"                     { pStr = new std::string(yytext, yyleng); TOKEN(MULT) }
"/"                     { pStr = new std::string(yytext, yyleng); TOKEN(DIV) }
";"                     { pStr = new std::string(yytext, yyleng); TOKEN(SEMICOLON) }

.                       { std::cout << "LEXICAL ERROR: unexpected character "; }
<<EOF>>                 { std::cout << "EOF "; TOKEN(TOK_EOF) }


%%
