#include <algorithm>
#include <functional>
#include <ranges>
#include <cctype>
#include <cstddef>
#include <fstream>
#include <ios>
#include <string>
#include <vector>

#include "../include/analyzer.h"
//除去空白字符
std::string trim(std::string& str) {
    auto is_space = [](char c) -> bool {
        return std::isspace(c);
    };
    return std::string(std::ranges::find_if(str.begin(), str.end(), std::not_fn(is_space)),
    std::ranges::find_if(str.rbegin(), str.rend(), std::not_fn(is_space)).base());
}
//按照指定分隔符分割
std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = s.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(s.substr(start, s.length()));
    return tokens;
}

std::vector<V> analyzer::turnStringVecToVvec(std::vector<std::string> stringVec) {
    std::vector<V> res;
    for (std::string str : stringVec) {
        int find = -1;
        for (auto& vn : vnVec) {
            if (vn.getLexeme() == str) {
                res.push_back(vn);
                find = 0;
            }
        }
        if (find == -1) {
            if (Vt::isVt(str) == true) {
               res.push_back(Vt(str));
            } else {
                res.push_back(Vn(str));
            }
        }
    }
    return res;
};

void analyzer::readSyntax() {
    std::ifstream infile;
    infile.open("../syntax.txt", std::ios::in);
    if (!infile.is_open()) {
        infile.open("syntax.txt", std::ios::in);
    }
    if (!infile.is_open()) {
        std::cout << "读取失败" << "\n";
        return;
    }
    std::string buf;
    while (std::getline(infile, buf)) {
        size_t pos = buf.find("-");
        std::string left = buf.substr(0, pos);
        std::string right = buf.substr(pos + 2);
        left = trim(left);
        right = trim(right);
        int find = -1;
        for (auto& vn : vnVec) {
            if (vn.getLexeme() == left) {
                vn.addRights(turnStringVecToVvec(split(right, ' ')));
                find = 0; 
            }
        }
        if (find == -1) {
            Vn newVn =  Vn(left);
            newVn.addRights(turnStringVecToVvec(split(right, ' ')));
            vnVec.push_back(newVn);
        }
    }
}

void analyzer::print() {
    for (auto& vn : vnVec) {
        vn.print();
    }
}

void analyzer::toFirst() {
    std::unordered_map<V, std::unordered_set<V>> FIRST;
    bool changed = true;

    while (changed) {
        changed = false;
        for (auto& vt : vtVec) {
            if (FIRST[vt].empty()) {
                FIRST[vt].insert(vt);
                changed = true;
            }
        }

        for (auto& vn : vnVec) {
            for (auto& rule : vn.getRules()) {
                for (size_t i = 0; i < rule.size(); ++i) {
                    auto& symbol = rule[i];
                    if (Vt::isVt(symbol.getLexeme())) {
                        Vt vt = Vt(symbol.getLexeme());
                        if (vt != Vt::epsilon() && FIRST[vn].find(vt) == FIRST[vn].end()) {
                            FIRST[vn].insert(vt);
                            changed = true;
                        }
                    } else {
                        auto& firstY = FIRST[symbol];
                        for (auto& y : firstY) {
                            if (y != Vt::epsilon()) {
                                if (FIRST[vn].find(y) == FIRST[vn].end()) {
                                    FIRST[vn].insert(y);
                                    changed = true;
                                }
                            }
                        }

                        if (firstY.find(Vt::epsilon()) != firstY.end()) {
                            bool canDeriveEpsilon = true;
                            for (size_t j = 0; j < rule.size(); ++j) {
                                if (j < rule.size() - 1) {
                                    auto& firstNext = FIRST[rule[j]];
                                    if (firstNext.find(Vt::epsilon()) == firstNext.end()) {
                                        canDeriveEpsilon = false;
                                        break;
                                    }
                                } else if (j == rule.size() - 1) {
                                    canDeriveEpsilon = true;
                                }
                            }

                            if (canDeriveEpsilon && FIRST[vn].find(Vt::epsilon()) == FIRST[vn].end()) {
                                FIRST[vn].insert(Vt::epsilon());
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    }

    // 打印FIRST集合
    for (auto& vn : vnVec) {
        std::cout << "FIRST(" << vn.getLexeme() << ") = {";
        for (auto& v : FIRST[vn]) {
            std::cout << v.getLexeme() << " ";
        }
        std::cout << "}\n";
    }
}