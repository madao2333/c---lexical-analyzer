#include <iostream>
#include <algorithm>
#include "Lex/include/Lexer.h"
#include "Lex/include/Preprocessor.h"

using namespace std;

int main()
{
    string input = R"(
        // Test
        int a = 10; 
        int main(){ 
            a=10; 
            return 0; 
        }
    )";

    Lexer h(input);
    h.tokenize();
    for(auto a : h.getTokens())
    {
        cout << a;
    }

}
