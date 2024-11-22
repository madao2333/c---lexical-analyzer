#include <iostream>
#include <algorithm>
#include "Lex/include/Lexer.h"
#include "Lex/include/Preprocessor.h"

using namespace std;

int main()
{
    string input = R"(
        int main() { 
            int x = 2; 
            int y = 3; 
            switch (x) { 
                case 1: { 
                y = 10;  // 简单语句 
                break; 
                } 
                case 2: { 
                y = 20;     
                // 简单赋值语句 
                func(y);      
                break; 
                } 
                default: {       
                return 0;    
                } 
            } 
        } 
    )";

    Lexer h(input);
    h.tokenize();
    cout << h;

}
