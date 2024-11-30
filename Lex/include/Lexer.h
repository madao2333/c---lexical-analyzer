//
// Created by vivekdagar on 4/2/24.
//

#ifndef UNTITLED1_LEXER_H
#define UNTITLED1_LEXER_H

#include <utility>
#include <vector>
#include <ostream>
#include "Token.h"
#include "TokenList.h"

class Lexer {
public:
    // Constructors
    explicit Lexer(std::string input);

    // Performing lexical analysis
    void tokenize();

    // Accessors
    const std::vector<Token> &getTokens() const;

    // Overloaded output operator
    friend std::ostream &operator<<(std::ostream &os, const Lexer &lexer);

private:
    // Data members
    std::string input;
    size_t pos;
    std::vector<Token> tokens;

private:
    // Private utility functions
    static std::unordered_map<std::string, std::pair<ctokens::TokType, int>>::iterator scan(std::unordered_map<std::string, std::pair<ctokens::TokType, int>>& list, const std::string &word);
    static int isFloat(const std::string &str);
    static bool isArithOp(const char &ch);
    static bool isSE(const char &currentChar);

    // Lexical analysis methods
    void regularWord();
    void makeStr();
    void makeChar();
    void advance();
    void skipSpc();
    void extractWord();
    void extractNum();
};


#endif //UNTITLED1_LEXER_H
