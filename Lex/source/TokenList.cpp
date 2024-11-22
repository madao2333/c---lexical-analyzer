//
// Created by vivekdagar on 3/30/24.
//
#include <string>
#include <utility>
#include "../include/TokenList.h"

namespace ctokens {

    // Textual Data
    std::unordered_map<std::string, std::pair<TokType, int>> keywords = {{"int", {TokType::KW, 1}}, {"float", {TokType::KW, 2}}, {"char", {TokType::KW, 3}}, { "void", {TokType::KW, 4}},
                                                {"return", {TokType::KW, 5}}, {"const", {TokType::KW, 6}}, {"main", {TokType::KW, 7}},
                                                {"struct", {TokType::KW, 8}}, {"union", {TokType::KW, 9}}, {"switch", {TokType::KW, 10}}, {"case", {TokType::KW, 11}}, 
                                                {"break", {TokType::KW, 12}}, {"default", {TokType::KW, 13}}};

    std::unordered_map<std::string, std::pair<TokType, int>> operators = {{"!", {TokType::OP, 14}}, {"+", {TokType::OP, 15}}, {"-", {TokType::OP, 16}}, {"*", {TokType::OP, 17}}, {"/", {TokType::OP, 18}},
                                                {"%", {TokType::OP, 19}}, {"=", {TokType::OP, 20}}, {">", {TokType::OP, 21}}, {"<", {TokType::OP, 22}}, 
                                                {"==", {TokType::OP, 23}}, {"<=", {TokType::OP, 24}}, {">=", {TokType::OP, 25}}, {"!=", {TokType::OP, 26}},
                                                 {"&&", {TokType::OP, 27}}, {"||", {TokType::OP, 28}}, {":", {TokType::OP, 29}}};
    
    std::unordered_map<std::string, std::pair<TokType, int>> ses = {{"(", {TokType::SE, 30}}, {")", {TokType::SE, 31}}, {"{", {TokType::SE, 32}}, {"}", {TokType::SE, 33}}, 
                                                {";", {TokType::SE, 34}}, {",", {TokType::SE, 35}}};
} // ctokens