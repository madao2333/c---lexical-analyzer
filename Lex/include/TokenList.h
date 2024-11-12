//
// Created by vivekdagar on 3/30/24.
//

#ifndef UNTITLED1_TOKENLIST_H
#define UNTITLED1_TOKENLIST_H
#include <string>
#include <unordered_map>
#include <utility>


namespace ctokens {
     // Enumeration for token types
    enum class TokType {
        KW,
        OP,
        SE,
        IDN,
        INT,
        FLOAT,
        CHAR,
        STR,
        INVALID_TOK,
        END_OF_FILE
    };

    // External sets of keywords and preprocessor directives
    extern std::unordered_map<std::string, std::pair<ctokens::TokType, int>> keywords;
    extern std::unordered_map<std::string, std::pair<ctokens::TokType, int>> operators;
    extern std::unordered_map<std::string, std::pair<ctokens::TokType, int>> ses;

   

} // namespace ctokens

#endif //UNTITLED1_TOKENLIST_H
