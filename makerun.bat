rmdir /s /q build
mkdir build
cmake -G "MinGW Makefiles" -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
.\build\untitled1.exe