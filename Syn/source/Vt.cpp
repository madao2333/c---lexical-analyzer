#include "../include/Vt.h"
#include "../../Lex/include/TokenList.h"

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
    return isVt_helper(str, ctokens::keywords) or isVt_helper(str, ctokens::operators) or isVt_helper(str, ctokens::ses); 
};