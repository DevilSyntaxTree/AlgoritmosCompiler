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
    archivo.open("ex_gold.txt"); // Abre el archivo

    std::ifstream f("ex_gold.txt"); // Abre el archivo en modo lectura

    if (f.is_open()) {
        std::string linea;
        while (std::getline(f, linea)) {
            //std::cout << linea << std::endl; // Imprime cada línea en la salida estándar
        }
        f.close(); // Cierra el archivo después de leerlo
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }

    if (archivo.is_open()) {
        yyFlexLexer lexer; // Crea una instancia de yyFlexLexer
        lexer.switch_streams(&archivo, nullptr); // Cambia la entrada al archivo

        while (tokens::token_t tok = static_cast<tokens::token_t>(lexer.yylex())) {
            if (tok == tokens::TOK_EOF) {
                std::cout << "SE VA A ACABARRRRRRRRRR" << std::endl;
                break;
            }
            switch (tok) {
                case tokens::TOK_BEGIN: std::cout << "BEGIN" << " "; break;
                case tokens::TOK_END: std::cout << "END" << " "; break;
                case tokens::TOK_IF: std::cout << "IF" << " "; break;
                case tokens::TOK_ELSEIF: std::cout << "ELSEIF" << " "; break;
                case tokens::TOK_ELSE: std::cout << "ELSE" << " "; break;
                case tokens::TOK_THEN: std::cout << "THEN" << " "; break;
                case tokens::TOK_PROCEDURE: std::cout << "PROCEDURE" << " "; break;
                case tokens::TOK_FUNCTION: std::cout << "FUNCTION" << " "; break;
                case tokens::TOK_RETURN: std::cout << "RETURN" << " "; break;
                case tokens::TOK_VAR: std::cout << "VAR" << " "; break;
                case tokens::TOK_BREAK: std::cout << "BREAK" << " "; break;
                case tokens::TOK_WHILE: std::cout << "WHILE" << " "; break;
                case tokens::TOK_DO: std::cout << "DO" << " "; break;
                case tokens::TOK_REPEAT: std::cout << "REPEAT" << " "; break;
                case tokens::TOK_UNTIL: std::cout << "UNTIL" << " "; break;
                case tokens::TOK_TRUE: std::cout << "TRUE" << " "; break;
                case tokens::TOK_FALSE: std::cout << "FALSE" << " "; break;
                case tokens::TOK_PRINT: std::cout << "PRINT" << " "; break;
                case tokens::TOK_IDENTIFIER: std::cout << "IDENTIFIER(" << *pStr << ") "; delete pStr; pStr = nullptr; break;
                case tokens::TOK_INT: std::cout << "INT(" << *pStr << ") "; delete pStr; pStr = nullptr; break;
                case tokens::TOK_ASSIGN: std::cout << "ASSIGN" << " "; break;
                case tokens::TOK_PLUS: std::cout << "PLUS" << " "; break;
                case tokens::TOK_MINUS: std::cout << "MINUS" << " "; break;
                case tokens::TOK_MULT: std::cout << "MULT" << " "; break;
                case tokens::TOK_DIV: std::cout << "DIV" << " "; break;
                case tokens::TOK_EQUAL: std::cout << "EQUAL" << " "; break;
                case tokens::TOK_LESS: std::cout << "LESS" << " "; break;
                case tokens::TOK_GREATER: std::cout << "GREATER" << " "; break;
                case tokens::TOK_LESS_EQUAL: std::cout << "LESS_EQUAL" << " "; break;
                case tokens::TOK_GREATER_EQUAL: std::cout << "GREATER_EQUAL" << " "; break;
                case tokens::TOK_LPAREN: std::cout << "LPAREN" << " "; break;
                case tokens::TOK_RPAREN: std::cout << "RPAREN" << " "; break;
                case tokens::TOK_LBRACE: std::cout << "LBRACE" << " "; break;
                case tokens::TOK_RBRACE: std::cout << "RBRACE" << " "; break;
                case tokens::TOK_LBRACKET: std::cout << "LBRACKET" << " "; break;
                case tokens::TOK_RBRACKET: std::cout << "RBRACKET" << " "; break;
                case tokens::TOK_QUESTION: std::cout << "QUESTION" << " "; break;
                case tokens::TOK_COLON: std::cout << "COLON" << " "; break;
                case tokens::TOK_SEMICOLON: std::cout << "SEMICOLON" << " "; break;
                case tokens::TOK_DOT: std::cout << "DOT" << " "; break;
                case tokens::TOK_COMMA: std::cout << "COMMA" << " "; break;
            }
        }
        
        archivo.close(); // Cierra el archivo después de su uso
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }

    return 0;
}
