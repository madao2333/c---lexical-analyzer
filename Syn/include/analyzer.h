
#ifndef UNTITLED1_ANALYZER_H
#define UNTITLED1_ANALYZER_H

#include "V.h"
#include "Vn.h"
#include "Vt.h"
#include "../../Lex/include/Token.h"
#include "../../Lex/include/Lexer.h"
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
class analyzer {
    private:
        std::vector<Vn> vnVec;
        std::vector<Vt> vtVec;
        map<string, set<string> >FIRST;  //不包括$
        map<string, set<string>> FOLLOW; //保存每个非终结符的 FOLLOW 集合
        map<string, int> cntnull;        //每个符号的FIRST是否包括$
        map<string,map<string, vector<V> > > Produ;         //预测分析表
        map<string,map<string, bool > > ProduFollow;        //预测分析表
    public:
        void print();
        void readSyntax();
        void toFirst();
        void toFollow();
        void printProdu(); //打印预测分析表
        void work(vector<Token> VecToken); //分析过程
    private:
        std::vector<V> turnStringVecToVvec(std::vector<std::string> stringVec);
};

#endif