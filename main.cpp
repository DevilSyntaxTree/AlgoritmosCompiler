#include <iostream>
#include <fstream>
#include <FlexLexer.h>

#include "tokens.h"

extern int yylex();
extern yyFlexLexer* yylexer;
std::string* pStr = nullptr;

//extern std::ifstream yyin; // Declaración de la entrada del lexer

std::ifstream archivo; // Declaración del archivo

int main(int argc, char* argv[]) {
    archivo.open("ex_language.txt"); // Abre el archivo

    if (archivo.is_open()) {
        //yyin = &archivo; // Redirige la entrada del lexer al archivo
        yyFlexLexer lexer; // Crea una instancia de yyFlexLexer
        lexer.switch_streams(&archivo, nullptr); // Cambia la entrada al archivo


        while (tokens::token_t tok = static_cast<tokens::token_t>(lexer.yylex())) {
            if (tok == tokens::TOK_EOF) {
                break;
            }
            switch(tok) {
                case tokens::IF: std::cout << "IF" << " "; break;
                case tokens::WHILE: std::cout << "WHILE" << " "; break;
                case tokens::PRINT: std::cout << "PRINT" << " "; break;
                case tokens::READ: std::cout << "READ" << " "; break;
                case tokens::IDENTIFIER: std::cout << "IDENTIFIER(" << *pStr << ") "; delete pStr; pStr=nullptr; break;
                case tokens::INT: std::cout << "INT(" << *pStr << ") "; delete pStr; pStr=nullptr; break;
                case tokens::ASSIGN: std::cout << "OPERATOR(" << *pStr << ") "; delete pStr; pStr=nullptr; break;
                case tokens::PLUS: std::cout << "OPERATOR(" << *pStr << ") "; delete pStr; pStr=nullptr; break;
                case tokens::MINUS: std::cout << "OPERATOR(" << *pStr << ") "; delete pStr; pStr=nullptr; break;
                case tokens::MULT: std::cout << "OPERATOR(" << *pStr << ") "; delete pStr; pStr=nullptr; break;
                case tokens::DIV: std::cout << "OPERATOR(" << *pStr << ") "; delete pStr; pStr=nullptr; break;
                case tokens::SEMICOLON: std::cout << "SYMBOL(" << *pStr << ") "; delete pStr; pStr=nullptr; break;
            };
        }
        
        archivo.close(); // Cierra el archivo después de su uso
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }

    return 0;
}
