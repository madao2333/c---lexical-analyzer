#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <assert.h>
#include <filesystem>
#include <vector>
#include <string>
#include <iostream>
#include "../include/V.h"
#include "../include/Vn.h"
#include "../include/Vt.h"
#include "../include/analyzer.h"

// 用于存储 FIRST 集合的全局变量
std::unordered_map<std::string, std::unordered_set<std::string>> FIRST;
analyzer a;
std::vector<V> res;
void analyzer::toFirst(const std::string &str){
    bool changed=true;
    while(changed){
        
        if(Vt::isVt(str)){
        FIRST[str].insert(str);
    }
    else{
        for(auto& vn:vnVec)
    }

    }
    


}


// 计算FIRST集合的函数
void calculateFirst(std::unordered_map<std::string, std::vector<GrammarRule>>& grammar,
                    std::unordered_map<std::string, std::unordered_set<std::string>>& first) {
    bool changed;
    do {
        changed = false;
        for (auto& rulePair : grammar) {
            std::string X = rulePair.first;
            for (auto& rule : rulePair.second) {
                for (auto& symbol : rule.rights) {
                    if (isTerminal(symbol)) {
                        if (first[X].find(symbol) == first[X].end()) {
                            first[X].insert(symbol);
                            changed = true;
                        }
                    } else { // 非终结符
                        std::unordered_set<std::string>& firstY = first[symbol];
                        for (auto& firstSymbol : firstY) {
                            if (firstSymbol != "ε") {
                                if (first[X].find(firstSymbol) == first[X].end()) {
                                    first[X].insert(firstSymbol);
                                    changed = true;
                                }
                            }
                        }
                        // 如果FIRST(Y)包含ε，并且Y能推导出ε
                        if (firstY.find("ε") != firstY.end()) {
                            bool canDeriveEpsilon = true;
                            for (size_t i = 0; i < rule.rights.size(); ++i) {
                                if (i < rule.rights.size() - 1) {
                                    std::unordered_set<std::string>& firstNext = first[rule.rights[i]];
                                    if (firstNext.find("ε") == firstNext.end()) {
                                        canDeriveEpsilon = false;
                                        break;
                                    }
                                } else if (i == rule.rights.size() - 1) {
                                    canDeriveEpsilon = true;
                                }
                            }
                            if (canDeriveEpsilon && first[X].find("ε") == first[X].end()) {
                                first[X].insert("ε");
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    } while (changed);
}