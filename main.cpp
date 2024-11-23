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
    string filePath = "C:\\Gtt\\c---lexical-analyzer\\now.txt";
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filePath << endl;
        return 1;
    }
    stringstream buffer;
    buffer << file.rdbuf();
    string input = buffer.str();
    Lexer h(input);
    h.tokenize();
    cout << h;

    analyzer a;
    a.readSyntax();
    a.print();
}
