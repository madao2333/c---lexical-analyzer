//
// Created by vivekdagar on 4/2/24.
//

#include <cctype>
#include <utility>
#include <algorithm>
#include <sstream>
#include "../include/Lexer.h"
#include "../include/Preprocessor.h"

Lexer::Lexer(std::string input) : input(std::move(input)), pos(0) {}

void Lexer::skipSpc() {
    auto nonSpaceIter = std::find_if(input.begin() + pos, input.end(), [](char c) {
        return !std::isspace(static_cast<unsigned char>(c));
    });

    pos = nonSpaceIter - input.begin();
}

void Lexer::extractWord() {
    // Check for regular word
    regularWord();
}

void Lexer::regularWord() {
    std::string word;

    // Check for regular word
    while (pos < input.length() and ((isalpha(input[pos]) or input[pos] == '_' or std::isdigit(input[pos])) and not isspace(input[pos]))) {
        word += input[pos];
        pos++;
    }

    using ctokens::keywords, ctokens::TokType;
    if (scan(keywords, word) not_eq keywords.end()) {
        this->tokens.emplace_back(Token(word, scan(keywords, word)->second));
    } else {
        this->tokens.emplace_back(Token(word, TokType::IDN));
    }
}

std::unordered_map<std::string, std::pair<ctokens::TokType, int>>::iterator Lexer::scan(std::unordered_map<std::string, std::pair<ctokens::TokType, int>> list, const std::string &word) {
    return list.find(word);
}

[[maybe_unused]] bool Lexer::isArithOp(const char &ch) {
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return true;
        default:
            return false;
    }
}

void Lexer::tokenize() {
    Preprocessor obj(this->input);
    obj.preprocess();
    this->input = obj.getCode();

    if (this->tokens.empty())
        this->advance();

    while (this->tokens.back().getP().first not_eq ctokens::TokType::END_OF_FILE)
        this->advance();
}

void Lexer::advance() {
    this->skipSpc();

    if (pos >= input.length()) {
        tokens.emplace_back(Token("#", {ctokens::TokType::END_OF_FILE, 0}));
        return;
    }

    char currentChar = input[pos];
    char nextChar = (pos < input.length() - 1) ? input[pos + 1] : ' ';

    if (isdigit(currentChar) or currentChar=='.') {
        this->extractNum();
        return;
    }

    if (currentChar == '\'') {
        this->makeChar();
        return;
    }

    switch (currentChar) {
        case '=': {
            std::string op(1, currentChar);
            int num;
            if (this->pos + 1 < this->input.length() and this->input[this->pos + 1] == '=') {
                op += '=';
                this->pos++;
            }
            this->pos++;
            this->tokens.emplace_back(Token(op, scan(ctokens::operators, op)->second));
        }
            break;
        case '<':
        case '>': {
            std::string bitwise(1, currentChar);
            this->pos++;

            switch (this->input[this->pos]) {
                case '=': {
                    if (currentChar == '>' or currentChar == '<') {
                        bitwise += this->input[this->pos++];
                        this->tokens.emplace_back(Token(bitwise, scan(ctokens::operators, bitwise)->second));
                        return;
                    }
                }
                    break;
            }

            switch (currentChar) {
                case '>':
                case '<': {
                    this->tokens.emplace_back(Token(bitwise, scan(ctokens::operators, bitwise)->second));
                    return;
                }
                    break;
            }
        }
            break;
        default: {
            if (isSE(currentChar)) {
                this->tokens.emplace_back(Token(std::string("") + currentChar, scan(ctokens::ses, std::string("") + currentChar)->second));
                this->pos++;
            } else if (isalpha(currentChar)) {
                this->extractWord();
            } else if (isArithOp(currentChar)) {
                this->tokens.emplace_back(Token(std::string("") + currentChar, scan(ctokens::operators, std::string("") + currentChar)->second));
                this->pos++;
            } else if (currentChar == '&' || currentChar == '|' || currentChar == '!') {
                std::string logOp(1, currentChar);
                this->pos++;

                if (currentChar == '!') {
                    if (this->input[this->pos] == '=') {
                        logOp += this->input[this->pos++];
                    }
                    this->tokens.emplace_back(Token(logOp, scan(ctokens::operators, logOp)->second));
                } else {
                    // Handle bitwise, logical, or assignment operators
                    logOp += this->input[this->pos++];
                    ctokens::TokType type;
                    if (logOp != "||" and logOp != "&&") {
                        logOp.pop_back(); // Remove redundant character if present
                    }
                    if(scan(ctokens::operators, logOp)==NULL){
                        tokens.emplace_back(Token(logOp, ctokens::TokType::INVALID_TOK));
                    }
                    else 
                    this->tokens.emplace_back(Token(logOp, scan(ctokens::operators, logOp)->second));
                }
            } else {
                std::string logOp(1, currentChar);
                if(scan(ctokens::operators, logOp)==NULL){
                        tokens.emplace_back(Token(logOp, ctokens::TokType::INVALID_TOK));
                }
                else 
                this->tokens.emplace_back(Token(logOp, scan(ctokens::operators, logOp)->second));
                this->pos++;
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Lexer &lexer) {
    for (const auto &token: lexer.tokens)
        os << token;
    return os;
}

int Lexer::isFloat(const std::string &str) {
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f; // Try to read the float
    if (iss.eof() and not iss.fail())
        return std::count(str.begin(), str.end(), '.') == 1;
    return -1;
}

const std::vector<Token> &Lexer::getTokens() const {
    return tokens;
}

bool Lexer::isSE(const char &currentChar) {
    switch (currentChar) {
        case '(':
        case ')':
        case ';':
        case ',':
        case '{':
        case '}':
            return true;
        default:
            return false;
    }
}

void Lexer::extractNum() {
    std::string constant;

    // while (pos < input.length()  and
    //        (this->input[pos] not_eq ';' and this->input[pos] not_eq ',')) {
    //     if (isdigit(input[pos]) or input[pos] == '.') {
    //         constant += input[pos];
    //     } else {
    //         while (pos < input.length() && !isspace(input[pos]) && input[pos] != ';') {
    //             constant += input[pos];
    //             pos++;
    //         }
    //         tokens.emplace_back(Token(constant, ctokens::TokType::INVALID_TOK));
    //         return;
    //     }
    //     pos++;
    // }

    // 提取连续的数字或小数点
    while (pos < input.length() && (isdigit(this->input[pos]) || this->input[pos] == '.')) {
        constant += input[pos];
        pos++;
    }

    // 检查数字后的字符是否合法
    if (pos < input.length() && (isalpha(input[pos]) || input[pos] == '_')) {
        // 如果数字后接字母或下划线，标记为非法 token
        while (pos < input.length() && !isspace(input[pos]) && input[pos] != ';') {
            constant += input[pos];
            pos++;
        }
        tokens.emplace_back(Token(constant, ctokens::TokType::INVALID_TOK));
        return;
    }
    
    ctokens::TokType numType;

    switch (isFloat(constant)) {
        case -1:
            numType = ctokens::TokType::INVALID_TOK;
            break;
        case 0:
            numType = ctokens::TokType::INT;
            break;
        default:
            numType = ctokens::TokType::FLOAT;
            break;
    }

    if (numType == ctokens::TokType::INVALID_TOK) {
        tokens.emplace_back(Token(constant, numType));
        return;
    }

    tokens.emplace_back(Token(constant, numType));
}

void Lexer::makeChar() {
    std::string obj;
    obj += this->input[this->pos];

    // Map whitespace characters to their respective representations
    std::unordered_map<char, char> whitespaceMap = {
            {' ',  's'},
            {'\t', 't'},
            {'\n', 'n'},
            {'\r', 'r'},
            {'\f', 'f'},
            {'\v', 'v'}
    };

    if (this->pos + 1 < this->input.length()) {
        char character = this->input[this->pos + 1];

        // Check if it's a whitespace character
        if (whitespaceMap.find(character) != whitespaceMap.end()) {
            while (this->input[pos] != '\'' or isspace(input[pos])) {
                obj += this->input[pos];
                pos++;
            }
            if (this->input[pos] == '\'') {
                obj += this->input[pos];
                pos++;
            }
            this->tokens.emplace_back(Token(obj, ctokens::TokType::INVALID_TOK));
        } else if (this->pos + 2 < this->input.length() && this->input[this->pos + 2] == '\'') {
            this->tokens.emplace_back(Token(std::string(1, character), ctokens::TokType::CHAR));
            this->pos += 3;
        } else {
            this->pos++;
            while (pos < this->input.length() && (this->input[this->pos] != '\'')) {
                obj += this->input[this->pos];
                pos++;
            }
            if (pos < this->input.length() and this->input[this->pos] == '\'')
                obj += '\'';
            this->tokens.emplace_back(Token(obj, ctokens::TokType::INVALID_TOK));
            this->pos++;
        }
    } else {
        this->tokens.emplace_back(Token("\'", ctokens::TokType::INVALID_TOK));
        this->pos++;
    }
}


