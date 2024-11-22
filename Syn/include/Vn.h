
#ifndef UNTITLED1_VN_H
#define UNTITLED1_VN_H

#include "V.h"
#include <set>
#include <vector>
class Vn : public V {
    private:
        std::set<std::vector<V>> rights;
    public:
        void addRights(std::vector<V> right);
};

#endif