cmake_minimum_required(VERSION 3.27)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        Lex/source/TokenList.cpp
        Lex/include/TokenList.h
        Lex/source/Token.cpp
        Lex/include/Token.h
        Lex/source/Lexer.cpp
        Lex/include/Lexer.h
        Lex/source/Preprocessor.cpp
        Lex/include/Preprocessor.h
        Syn/include/analyzer.h
        Syn/include/V.h
        Syn/include/Vn.h
        Syn/include/Vt.h
        Syn/source/analyzer.cpp
        Syn/source/V.cpp
        Syn/source/Vn.cpp
        Syn/source/Vt.cpp
)
