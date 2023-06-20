
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

"begin"                 { TOKEN(TOK_BEGIN) }
"end"                   { TOKEN(TOK_END) }
"if"                    { TOKEN(TOK_IF) }
"elseif"                { TOKEN(TOK_ELSEIF) }
"else"                  { TOKEN(TOK_ELSE) }
"then"                  { TOKEN(TOK_THEN) }
"procedure"             { TOKEN(TOK_PROCEDURE) }
"function"              { TOKEN(TOK_FUNCTION) }
"return"                { TOKEN(TOK_RETURN) }
"var"                   { TOKEN(TOK_VAR) }
"break"                 { TOKEN(TOK_BREAK) }
"while"                 { TOKEN(TOK_WHILE) }
"do"                    { TOKEN(TOK_DO) }
"repeat"                { TOKEN(TOK_REPEAT) }
"until"                 { TOKEN(TOK_UNTIL) }

"true"                  { TOKEN(TOK_TRUE) }
"false"                 { TOKEN(TOK_FALSE) }

"print"                { TOKEN(TOK_PRINT) }

[a-zA-Z_][a-zA-Z0_9]*   { pStr = new std::string(yytext, yyleng); TOKEN(TOK_IDENTIFIER) }
[0-9]+                  { pStr = new std::string(yytext, yyleng); TOKEN(TOK_INT) }

":="                    { TOKEN(TOK_ASSIGN) }
"+"                     { TOKEN(TOK_PLUS) }
"-"                     { TOKEN(TOK_MINUS) }
"*"                     { TOKEN(TOK_MULT) }
"/"                     { TOKEN(TOK_DIV) }
"="                     { TOKEN(TOK_EQUAL) }
"<"                     { TOKEN(TOK_LESS) }
">"                     { TOKEN(TOK_GREATER) }
"<="                    { TOKEN(TOK_LESS_EQUAL) }
">="                    { TOKEN(TOK_GREATER_EQUAL) }

"("                     { TOKEN(TOK_LPAREN) }
")"                     { TOKEN(TOK_RPAREN) }
"{"                     { TOKEN(TOK_LBRACE) }
"}"                     { TOKEN(TOK_RBRACE) }
"["                     { TOKEN(TOK_LBRACKET) }
"]"                     { TOKEN(TOK_RBRACKET) }
"?"                     { TOKEN(TOK_QUESTION) }
":"                     { TOKEN(TOK_COLON) }
";"                     { TOKEN(TOK_SEMICOLON) }
"."                     { TOKEN(TOK_DOT) }
","                     { TOKEN(TOK_COMMA) }

.                       { std::cout << "LEXICAL ERROR: unexpected character "; }
<<EOF>>                 { std::cout << "EOF "; TOKEN(TOK_EOF) }


%%
