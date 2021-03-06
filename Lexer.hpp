/**
 * Antoine Chauvin © Slang
 */

#ifndef SLANG_LEXER_HPP
#define SLANG_LEXER_HPP


#include <istream>
#include "Lex.hpp"

class Lexer {
public:
    Lexer(std::istream& is);

    std::unique_ptr<const Lex> next();
    void expect(LexType lexType);
    std::string expectAtom();

private:
    std::unique_ptr<const Lex> nextStr();

    void ignoreLine();
    void ignoreWhitespaces();
    std::string untilWhitespace();
    bool isWhitespacePart(char c);
    bool isEndLex(char c);

    std::istream& _is;
    bool _inStr;
};


#endif//SLANG_LEXER_HPP
