
#ifndef UNTITLED1_VN_H
#define UNTITLED1_VN_H

#include "V.h"
#include "vector_hash.h"
#include <string>
#include <unordered_set>
#include <vector>
class Vn : public V {
    private:
        std::unordered_set<std::vector<V>, VectorHash> rights;
    public:
        Vn(std::string lexeme);
        void print();
        void addRights(std::vector<V> right);
};

#endif