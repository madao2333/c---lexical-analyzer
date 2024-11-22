
#ifndef UNTITLED1_ANALYZER_H
#define UNTITLED1_ANALYZER_H

#include "V.h"
#include "Vn.h"
#include "Vt.h"
#include <set>
#include <string>
#include <vector>

class analyzer {
    private:
        std::set<Vn> vnSet;
        std::set<Vt> vtSet;
    public:
        void readSyntax();
    private:
        std::vector<V> turnStringVecToVvec(std::vector<std::string> stringVec);
};

#endif