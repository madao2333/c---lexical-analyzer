
// Created by vivekdagar on 3/30/24.
//

#include <utility>

#include "../include/Token.h"

Token::Token(std::string lexeme, std::pair<ctokens::TokType, int> p) : lexeme(std::move(lexeme)), p(p) {}
Token::Token(std::string lexeme, ctokens::TokType tokType) : lexeme(std::move(lexeme)), p({tokType, -1}) {}

const std::pair<ctokens::TokType, int> &Token::getP() const {
    return p;
}

const std::string &Token::getLexeme() const {
    return lexeme;
}

std::string Token::print() const {
        switch (p.first) {
            case ctokens::TokType::KW:
                return "<KW," + std::to_string(p.second) + ">";
            case ctokens::TokType::OP:
                return "<OP," + std::to_string(p.second) + ">";
            case ctokens::TokType::SE:
                return "<SE," + std::to_string(p.second) + ">";
            case ctokens::TokType::IDN:
                return "<IDN," + lexeme + ">";
            case ctokens::TokType::INT:
                return "<INT," + lexeme + ">";
            case ctokens::TokType::FLOAT:
                return "<FLOAT," + lexeme + ">";
            case ctokens::TokType::CHAR:
                return "<CHAR," + lexeme + ">";
            case ctokens::TokType::STR:
                return "<STR," + lexeme + ">";
            case ctokens::TokType::INVALID_TOK:
                return "<INVALID_TOK," + lexeme + ">";
            case ctokens::TokType::END_OF_FILE:
                return "";
            default:
                return "UNKNOWN"; // Handle unknown token types
        }
}

std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << token.getLexeme() << "\t" << token.print() << "\n";
    return os;
}
