#include "../include/Vn.h"
#include <iostream>
#include <string>

void Vn::addRights(std::vector<V> right) {
    rights.insert(right);
};

Vn::Vn(std::string lexeme) : V(lexeme) {}

void Vn::print() {
    std::cout << this->getLexeme()<<":\n";
    for (auto& right : rights) {
        std::cout << "\t";
        for (auto& v : right) {
            std::cout << v.getLexeme() << " ";
        }
        std::cout << "\n";
    }
}