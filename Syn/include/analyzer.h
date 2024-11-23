
#ifndef UNTITLED1_ANALYZER_H
#define UNTITLED1_ANALYZER_H

#include "V.h"
#include "Vn.h"
#include "Vt.h"
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
class analyzer {
    private:
        std::vector<Vn> vnVec;
        std::vector<Vt> vtVec;
    public:
        void print();
        void readSyntax();
        void toFirst();
        void toFollow();
    private:
        std::vector<V> turnStringVecToVvec(std::vector<std::string> stringVec);
};

#endif