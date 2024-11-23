#include <unordered_map>
#include <map>
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
    map<string, set<string> >FIRST;
void analyzer::toFirst() {
    map<string, int> vis;
    map<string, int> getans;

    map<string, int> cntnull;
    function<void(string)> dfs = [&](string now)
    {
        if (getans.count(now))
            return;
        if (vis[now] && (!getans.count(now)))
        {
            cout << "There exists left recursion :" + now << endl;
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
                                FIRST[now].insert(sonFirst);
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
    map<string, set<string>> FOLLOW; // 保存每个非终结符的 FOLLOW 集合
    string star = "program";
    // 初始化：将起始符号的 FOLLOW 集合中加入 `$`
    FOLLOW[star].insert("#");
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (auto &r : vnVec)
        {
            string A = r.getLexeme(); // 当前非终结符
            for (auto &t : r.getRules())
            {
                for (size_t i = 0; i < t.size(); i++)
                {
                    string B = t[i].getLexeme(); // 当前符号
                    if (!Vt::isVt(t[i].getLexeme()))
                    {
                        if (i + 1 < t.size())
                        {
                            string beta = t[i + 1].getLexeme(); // β 的第一个符号
                            for (const string &ter : FIRST[beta])
                            {
                                if (ter != "$")
                                {
                                    if (FOLLOW[B].insert(ter).second)
                                    {
                                        changed = true; // FOLLOW 集更新
                                    }
                                }
                            }
                        }
                    }

                    bool btoe = true;
                    for (size_t j = i + 1; j < t.size(); j++)
                    {
                        string beta = t[j].getLexeme();
                        if (FIRST[beta].count("$") == 0)
                        {
                            btoe = false;
                            break;
                        }
                    }
                    if (btoe || i + 1 == t.size())
                    {
                        for (const string &terminal : FOLLOW[A])
                        {
                            if (FOLLOW[B].insert(terminal).second)
                            {
                                changed = true; // FOLLOW 集更新
                            }
                        }
                    }
                }
            }
        }
        // 输出 FOLLOW 
        cout << "FOLLOW ：" << endl;
        for (auto &[nonTerminal, followSet] : FOLLOW)
        {
            cout << nonTerminal << ": ";
            for (auto &terminal : followSet)
            {
                cout << terminal << " ";
            }
            cout << endl;
        }
    }
}