#include "../include/Vt.h"
#include "../../Lex/include/TokenList.h"
#include <string>
#include <unordered_set>

bool isVt_helper(const std::string &str,
 std::unordered_map<std::string, std::pair<ctokens::TokType, int>> mp) {
    for (const auto& p : mp) {
        if (p.first == str) {
            return true;
        }
    }
    return false;
}

bool Vt::isVt(const std::string &str) {
    auto isVars = [](std::string str, std::unordered_set<std::string> vars) -> bool {
        for (const auto& p : vars) 
            if (p == str) return true;
        return false;
    };
    return isVars(str, vars) or isVt_helper(str, ctokens::keywords) or isVt_helper(str, ctokens::operators) or isVt_helper(str, ctokens::ses); 
};

Vt::Vt(std::string lexeme) : V(lexeme) {}

std::unordered_set<std::string> Vt::vars = {"$", "Ident", "number", "CHAR", "INT", "FLOAT"};