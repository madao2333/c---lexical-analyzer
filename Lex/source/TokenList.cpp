//
// Created by vivekdagar on 3/30/24.
//
#include <string>
#include <utility>
#include "../include/TokenList.h"

namespace ctokens {

    // Textual Data
    std::unordered_map<std::string, std::pair<ctokens::TokType, int>> keywords = {{"int", {ctokens::TokType::KW, 1}}, {"float", {ctokens::TokType::KW, 2}}, {"char", {ctokens::TokType::KW, 3}}, { "void", {ctokens::TokType::KW, 4}},
                                                {"return", {ctokens::TokType::KW, 5}}, {"const", {ctokens::TokType::KW, 6}}, {"main", {ctokens::TokType::KW, 7}},
                                                {"struct", {ctokens::TokType::KW, 8}}, {"union", {ctokens::TokType::KW, 9}}, {"switch", {ctokens::TokType::KW, 10}}};

    std::unordered_map<std::string, std::pair<ctokens::TokType, int>> operators = {{"!", {ctokens::TokType::OP, 11}}, {"+", {ctokens::TokType::OP, 12}}, {"-", {ctokens::TokType::OP, 13}}, {"*", {ctokens::TokType::OP, 14}}, {"/", {ctokens::TokType::OP, 15}},
                                                {"%", {ctokens::TokType::OP, 16}}, {"=", {ctokens::TokType::OP, 17}}, {">", {ctokens::TokType::OP, 18}}, {"<", {ctokens::TokType::OP, 19}}, 
                                                {"==", {ctokens::TokType::OP, 20}}, {"<=", {ctokens::TokType::OP, 21}}, {">=", {ctokens::TokType::OP, 22}}, {"!=", {ctokens::TokType::OP, 23}},
                                                 {"&&", {ctokens::TokType::OP, 24}}, {"||", {ctokens::TokType::OP, 25}}};
    
    std::unordered_map<std::string, std::pair<ctokens::TokType, int>> ses = {{"(", {ctokens::TokType::SE, 26}}, {")", {ctokens::TokType::SE, 27}}, {"{", {ctokens::TokType::SE, 28}}, {"}", {ctokens::TokType::SE, 29}}, 
                                                {";", {ctokens::TokType::SE, 30}}, {",", {ctokens::TokType::SE, 31}}};
} // ctokens