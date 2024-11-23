#ifndef UNTITLED1_VT_H
#define UNTITLED1_VT_H

#include "V.h"
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
#include "../../Lex/include/TokenList.h"

class Vt : public V {
    private:
      static std::unordered_set<std::string> vars;
    public:
      Vt() = default;
      Vt(std::string lexeme);
      static bool isVt(const std::string & str);
      static Vt epsilon(); // 添加一个静态成员函数返回epsilon的Vt实例
};

#endif