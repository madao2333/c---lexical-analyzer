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
    return vars.find(str) != vars.end(); // 简化函数，直接检查vars集合
}

Vt::Vt(std::string lexeme) : V(lexeme) {}

// 添加epsilon到vars集合中
std::unordered_set<std::string> Vt::vars = {"$", "Ident", "number", "CHAR", "INT", "FLOAT", "ε"}; // ε是epsilon的希腊字母表示

// 实现epsilon静态成员函数
Vt Vt::epsilon() {
    return Vt("ε");
}