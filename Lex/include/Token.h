//
// Created by vivekdagar on 3/30/24.
//

#ifndef UNTITLED1_TOKEN_H
#define UNTITLED1_TOKEN_H

#include <utility>
#ifndef TOKEN_H
#define TOKEN_H

#include "TokenList.h"
#include <string>
#include <iostream>

class Token {
private:
    // Data members
    std::string lexeme;
    std::pair<ctokens::TokType, int> p;

public:
    // Constructor
    Token(std::string lexeme, std::pair<ctokens::TokType, int> p);
    //Constructor for invalid token, IDN, int, float, char, str
    Token(std::string lexeme, ctokens::TokType tokType);

    // Accessors
    [[nodiscard]] const std::pair<ctokens::TokType, int> &getP() const;
    [[nodiscard]] const std::string &getLexeme() const;
    std::string print() const;

    // Overloaded output operator
    friend std::ostream &operator<<(std::ostream &os, const Token &token);
};

#endif // TOKEN_H


#endif //UNTITLED1_TOKEN_H
