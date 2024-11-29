#include <ostream>
#include <unordered_map>
#include <map>
#include <iomanip>
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
#include <stack>
#include "../include/V.h"
#include "../include/Vn.h"
#include "../include/Vt.h"
#include "../include/analyzer.h"

// 除去空白字符
std::string trim(std::string &str)
{
    auto is_space = [](char c) -> bool
    {
        return std::isspace(c);
    };
    return std::string(std::ranges::find_if(str.begin(), str.end(), std::not_fn(is_space)),
                       std::ranges::find_if(str.rbegin(), str.rend(), std::not_fn(is_space)).base());
}
// 按照指定分隔符分割
std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = s.find(delimiter, start)) != std::string::npos)
    {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(s.substr(start, s.length()));
    return tokens;
}

std::vector<V> analyzer::turnStringVecToVvec(std::vector<std::string> stringVec)
{
    std::vector<V> res;
    for (std::string str : stringVec)
    {
        int find = -1;
        for (auto &vn : vnVec)
        {
            if (vn.getLexeme() == str)
            {
                res.push_back(vn);
                find = 0;
            }
        }
        if (find == -1)
        {
            if (Vt::isVt(str) == true)
            {
                res.push_back(Vt(str));
            }
            else
            {
                res.push_back(Vn(str));
            }
        }
    }
    return res;
};
using namespace std;
set<string> setVt;
void analyzer::readSyntax()
{
    std::ifstream infile;
    infile.open("../syntes.txt", std::ios::in);
    if (!infile.is_open())
    {
        infile.open("syntes.txt", std::ios::in);
    }
    if (!infile.is_open())
    {
        std::cout << "读取失败" << "\n";
        return;
    }
    std::string buf;
    while (std::getline(infile, buf))
    {
        size_t pos = buf.find("-");
        std::string left = buf.substr(0, pos);
        std::string right = buf.substr(pos + 2);
        left = trim(left);
        right = trim(right);
        int find = -1;
        for (auto p : turnStringVecToVvec(split(right, ' ')))
            setVt.insert(p.getLexeme());
        for (auto &vn : vnVec)
        {
            if (vn.getLexeme() == left)
            {
                vn.addRights(turnStringVecToVvec(split(right, ' ')));
                find = 0;
            }
        }
        if (find == -1)
        {
            Vn newVn = Vn(left);
            newVn.addRights(turnStringVecToVvec(split(right, ' ')));
            vnVec.push_back(newVn);
        }
    }
    for (auto vn : vnVec)
    {
        setVt.erase(vn.getLexeme());
    }
    for (auto p : setVt)
    {
        vtVec.push_back(Vt(p));
    }
}
using namespace std;
void analyzer::print()
{
    for (auto &vn : vnVec)
    {
        vn.print();
    }
}


void analyzer::toFirst() {
    map<string, int> vis;
    map<string, int> getans;
    function<void(string)> dfs = [&](string now)
    {
        if (getans.count(now))
            return;
        if (vis[now] && (!getans.count(now)))
        {
            cout << "Error. There exists left recursion :" + now << endl;
            assert(0);
        }
        vis[now]++;
        if (setVt.count(now))
        {
            if (now != "$")
                FIRST[now].insert(now);
            getans[now]++;
            if (now == "$")
                cntnull[now] = 1;
            return;
        }
        for (auto u : vnVec)
        {
            if (u.getLexeme() == now)
            {
                for (auto vec : u.getRules())
                {
                    int flag = 1;
                    for (auto nxt : vec)
                    {
                        dfs(nxt.getLexeme());
                        if (flag)
                        {
                            for (auto sonFirst : FIRST[nxt.getLexeme()])
                            {
                                FIRST[now].insert(sonFirst);
                                // if(!Produ[now][sonFirst].empty()&&Produ[now][sonFirst]!=vec){
                                //     cout << now <<" "<<sonFirst<<" "<<nxt.getLexeme()<< endl;
                                //     for(auto p:vec)cout<<p.getLexeme()<<" ";cout<<endl;
                                //     for(auto p:Produ[now][sonFirst])cout<<p.getLexeme()<<" ";cout<<endl;
                                //     cout << "Error. Grammar has ambiguity" << endl;
                                //     assert(0);
                                // }
                                Produ[now][sonFirst]=vec;
                            }
                        }
                        if (!cntnull[nxt.getLexeme()])
                            flag = 0;
                        if (flag == 0)
                            break;
                    }
                    if (flag == 1)
                        cntnull[now] = 1;
                }
            }
        }
        getans[now]++;
    };
    for (auto v : vnVec)
        dfs(v.getLexeme());
    for (auto v : vtVec)
        dfs(v.getLexeme());
    FIRST.erase("$");
    cout << FIRST.size() << endl;
    for (auto [now, v] : FIRST)
    {
        cout << now << ":";
        if (cntnull[now])
            cout << " $";
        for (auto str : v)
        {
            cout << " " << str;
        }
        cout << endl;
    }
}

void analyzer::toFollow()
{
    string star = "program";
    // 初始化：将起始符号的 FOLLOW 集合中加入 `$`
    auto addFollowAtoB = [&](string A, string B) {
        for(auto p:FOLLOW[A])
            FOLLOW[B].insert(p);
    };
    auto addFirstAtoB = [&](string A, string B) {
        for(auto p:FIRST[A])
            FOLLOW[B].insert(p);
    };
    FOLLOW[star].insert("#");
    int lastsz = 1;
    while(1){
        for(auto _:vnVec){
            for(auto vec:_.getRules()){
                int len = vec.size();
                for (int i = len - 1; i >= 0;i--){
                    addFollowAtoB(_.getLexeme(),vec[i].getLexeme());
                    if(!cntnull[vec[i].getLexeme()])break;
                }
                for (int i = len - 2; i >= 0;i--){
                    for (int j = i + 1; j < len;j++){
                        addFirstAtoB(vec[j].getLexeme(), vec[i].getLexeme());
                        if(!cntnull[vec[j].getLexeme()])break;
                    }
                }
            }
        }
        int nowsz=0;
        for(auto[p,t]:FOLLOW)nowsz+=t.size();
        if(nowsz==lastsz)
            break;
        lastsz = nowsz;
    }
    setVt.insert("#");  //结束标志
    setVt.erase("$");  //空标志
    // 输出 FOLLOW 
    cout << "FOLLOW " << endl;
    for (auto [nonTerminal, followSet] : FOLLOW)
    {
        if(setVt.count(nonTerminal))continue;
        cout << nonTerminal << ": ";
        for (auto terminal : followSet)
        {
            cout << terminal << " ";
        }
        cout << endl;
    }

    for(auto v:vnVec){
        if(cntnull[v.getLexeme()])
        for(auto p:FOLLOW[v.getLexeme()]){
            // if(FIRST[v.getLexeme()].count(p)){
            //     cout << v.getLexeme() << endl;
            //     cout << "FIRST of " << v.getLexeme() << ":";
            //     for(auto p:FIRST[v.getLexeme()])cout<<p<<" ";cout << endl;
            //     cout << "FOLLOW of " << v.getLexeme() << ":";
            //     for(auto p:FOLLOW[v.getLexeme()])cout<<p<<" ";cout << endl;
            //     cout << "Error. Grammar has ambiguity" << endl;
            //     assert(0);
            // }
            ProduFollow[v.getLexeme()][p] = true;
        }
    }
}


void analyzer::printProdu(){    //打印预测分析表
    const int cellWidth = 20;
    cout << left << setw(cellWidth) << "";
    for(auto p:setVt){
        cout << left << setw(cellWidth)<< p;
    }
    cout << endl;
    for(auto v:vnVec){
        cout << left << setw(cellWidth)<< v.getLexeme();
        for(auto p:setVt){
            if(Produ[v.getLexeme()][p].empty()){
                if(ProduFollow[v.getLexeme()][p]){
                    cout << left << setw(cellWidth)<< v.getLexeme()+" -> $";
                }
                else cout<< left << setw(cellWidth)<<"error";
            }
            else {
                string now = v.getLexeme() + " -> ";
                for(auto t:Produ[v.getLexeme()][p])
                    now+= t.getLexeme() + " ";
                cout<< left << setw(cellWidth)<<now;
            }
        }
        cout << endl;
    }
}


string getlex(Token u){
        switch (u.getP().first) {
        case ctokens::TokType::KW:
        case ctokens::TokType::OP:
        case ctokens::TokType::SE:
            return u.getLexeme();
        case ctokens::TokType::IDN:
            return "Ident";
        case ctokens::TokType::INT:
            return "INT";
        case ctokens::TokType::FLOAT:
            return "FLOAT";
        case ctokens::TokType::CHAR:
            return "CHAR";
        case ctokens::TokType::END_OF_FILE:
            return "#";
        default:
            return "UNKNOWN"; // Handle unknown token types
    }
}


void  analyzer::work(std::ostream& os, vector<Token> VecToken){
    stack<string> st;
    st.push("#");   //结束符号
    st.push("program");   //初始符号
    int cntStep = 0;
    for(auto u:VecToken){
        auto printreduction=[&](std::ostream& os) {
        os<<++cntStep<<" "<<st.top()<<"#"<<u.getLexeme()<<" "<<"reduction"<<endl;
        };
        auto printmove=[&](std::ostream& os) {
        os<<++cntStep<<" "<<st.top()<<"#"<<u.getLexeme()<<" "<<"move"<<endl;
        };
        auto printerror=[&](std::ostream& os) {
        os<<++cntStep<<" "<<st.top()<<"#"<<u.getLexeme()<<" "<<"error"<<endl;
        };
        string nowtype = getlex(u);
        while(!setVt.count(st.top())){
            if(!Produ[st.top()][nowtype].empty()){
                vector<string> nxt;
                for(auto p:Produ[st.top()][nowtype])nxt.push_back(p.getLexeme());
                printreduction(os);
                st.pop();
                while(!nxt.empty()){
                    st.push(nxt.back());
                    nxt.pop_back();
                }
            }
            else if(ProduFollow[st.top()][nowtype]){
                printreduction(os);
                st.pop();
            }
            else {
                printerror(os);
                os << "Matching failed" << endl;
                assert(0);
            }
        }
        if(st.top()==nowtype)
        {
            printmove(os);
            st.pop();
        }
        else {
            printerror(os);
            os << "error" << endl;
            assert(0);
        }
    }

    os << "accept";
}