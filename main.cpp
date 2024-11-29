#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <assert.h>
#include <filesystem>
#include "Lex/include/Lexer.h"
#include "Syn/include/analyzer.h"
#include "Lex/include/Preprocessor.h"
using namespace std;

int main()
{
    string filePath = "test35.sy";
    //	freopen("input.txt","r",stdin);
    ifstream file(filePath);
    if (!file.is_open()) {
        ifstream file2("../test35.sy");
        swap(file, file2);
    }
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filePath << endl;
        return 1;
    }
    stringstream buffer;
    buffer << file.rdbuf();
    string input = buffer.str();
    Lexer h(input);
    h.tokenize();
    cout << h;              //打印token序列
    ofstream outFile;
    outFile.open("../35lex.tsv");
    if (outFile.is_open()) {
        outFile << h;
        outFile.close();
    } else {
        cerr << "Error: Unable to open output file 35lex.tsv" << endl;
        return 1;
    }
    analyzer a;
    a.readSyntax();
    // a.print();    
    a.toFirst();
    a.toFollow();
    // a.printProdu();
    a.work(cout, h.getTokens());
    ofstream of("../35gra.tsv");
    if (of.is_open()) {
        a.work(of, h.getTokens());
        of.close();
    }
}
