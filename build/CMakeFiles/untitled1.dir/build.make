# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\c---lexical-analyzer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\c---lexical-analyzer\build

# Include any dependencies generated for this target.
include CMakeFiles/untitled1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/untitled1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled1.dir/flags.make

CMakeFiles/untitled1.dir/codegen:
.PHONY : CMakeFiles/untitled1.dir/codegen

CMakeFiles/untitled1.dir/main.cpp.obj: CMakeFiles/untitled1.dir/flags.make
CMakeFiles/untitled1.dir/main.cpp.obj: E:/c---lexical-analyzer/main.cpp
CMakeFiles/untitled1.dir/main.cpp.obj: CMakeFiles/untitled1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\c---lexical-analyzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled1.dir/main.cpp.obj"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled1.dir/main.cpp.obj -MF CMakeFiles\untitled1.dir\main.cpp.obj.d -o CMakeFiles\untitled1.dir\main.cpp.obj -c E:\c---lexical-analyzer\main.cpp

CMakeFiles/untitled1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled1.dir/main.cpp.i"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c---lexical-analyzer\main.cpp > CMakeFiles\untitled1.dir\main.cpp.i

CMakeFiles/untitled1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled1.dir/main.cpp.s"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c---lexical-analyzer\main.cpp -o CMakeFiles\untitled1.dir\main.cpp.s

CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.obj: CMakeFiles/untitled1.dir/flags.make
CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.obj: E:/c---lexical-analyzer/Lex/source/TokenList.cpp
CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.obj: CMakeFiles/untitled1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\c---lexical-analyzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.obj"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.obj -MF CMakeFiles\untitled1.dir\Lex\source\TokenList.cpp.obj.d -o CMakeFiles\untitled1.dir\Lex\source\TokenList.cpp.obj -c E:\c---lexical-analyzer\Lex\source\TokenList.cpp

CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.i"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c---lexical-analyzer\Lex\source\TokenList.cpp > CMakeFiles\untitled1.dir\Lex\source\TokenList.cpp.i

CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.s"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c---lexical-analyzer\Lex\source\TokenList.cpp -o CMakeFiles\untitled1.dir\Lex\source\TokenList.cpp.s

CMakeFiles/untitled1.dir/Lex/source/Token.cpp.obj: CMakeFiles/untitled1.dir/flags.make
CMakeFiles/untitled1.dir/Lex/source/Token.cpp.obj: E:/c---lexical-analyzer/Lex/source/Token.cpp
CMakeFiles/untitled1.dir/Lex/source/Token.cpp.obj: CMakeFiles/untitled1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\c---lexical-analyzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/untitled1.dir/Lex/source/Token.cpp.obj"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled1.dir/Lex/source/Token.cpp.obj -MF CMakeFiles\untitled1.dir\Lex\source\Token.cpp.obj.d -o CMakeFiles\untitled1.dir\Lex\source\Token.cpp.obj -c E:\c---lexical-analyzer\Lex\source\Token.cpp

CMakeFiles/untitled1.dir/Lex/source/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled1.dir/Lex/source/Token.cpp.i"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c---lexical-analyzer\Lex\source\Token.cpp > CMakeFiles\untitled1.dir\Lex\source\Token.cpp.i

CMakeFiles/untitled1.dir/Lex/source/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled1.dir/Lex/source/Token.cpp.s"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c---lexical-analyzer\Lex\source\Token.cpp -o CMakeFiles\untitled1.dir\Lex\source\Token.cpp.s

CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.obj: CMakeFiles/untitled1.dir/flags.make
CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.obj: E:/c---lexical-analyzer/Lex/source/Lexer.cpp
CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.obj: CMakeFiles/untitled1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\c---lexical-analyzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.obj"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.obj -MF CMakeFiles\untitled1.dir\Lex\source\Lexer.cpp.obj.d -o CMakeFiles\untitled1.dir\Lex\source\Lexer.cpp.obj -c E:\c---lexical-analyzer\Lex\source\Lexer.cpp

CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.i"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c---lexical-analyzer\Lex\source\Lexer.cpp > CMakeFiles\untitled1.dir\Lex\source\Lexer.cpp.i

CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.s"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c---lexical-analyzer\Lex\source\Lexer.cpp -o CMakeFiles\untitled1.dir\Lex\source\Lexer.cpp.s

CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.obj: CMakeFiles/untitled1.dir/flags.make
CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.obj: E:/c---lexical-analyzer/Lex/source/Preprocessor.cpp
CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.obj: CMakeFiles/untitled1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\c---lexical-analyzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.obj"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.obj -MF CMakeFiles\untitled1.dir\Lex\source\Preprocessor.cpp.obj.d -o CMakeFiles\untitled1.dir\Lex\source\Preprocessor.cpp.obj -c E:\c---lexical-analyzer\Lex\source\Preprocessor.cpp

CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.i"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\c---lexical-analyzer\Lex\source\Preprocessor.cpp > CMakeFiles\untitled1.dir\Lex\source\Preprocessor.cpp.i

CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.s"
	E:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\c---lexical-analyzer\Lex\source\Preprocessor.cpp -o CMakeFiles\untitled1.dir\Lex\source\Preprocessor.cpp.s

# Object files for target untitled1
untitled1_OBJECTS = \
"CMakeFiles/untitled1.dir/main.cpp.obj" \
"CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.obj" \
"CMakeFiles/untitled1.dir/Lex/source/Token.cpp.obj" \
"CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.obj" \
"CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.obj"

# External object files for target untitled1
untitled1_EXTERNAL_OBJECTS =

untitled1.exe: CMakeFiles/untitled1.dir/main.cpp.obj
untitled1.exe: CMakeFiles/untitled1.dir/Lex/source/TokenList.cpp.obj
untitled1.exe: CMakeFiles/untitled1.dir/Lex/source/Token.cpp.obj
untitled1.exe: CMakeFiles/untitled1.dir/Lex/source/Lexer.cpp.obj
untitled1.exe: CMakeFiles/untitled1.dir/Lex/source/Preprocessor.cpp.obj
untitled1.exe: CMakeFiles/untitled1.dir/build.make
untitled1.exe: CMakeFiles/untitled1.dir/linkLibs.rsp
untitled1.exe: CMakeFiles/untitled1.dir/objects1.rsp
untitled1.exe: CMakeFiles/untitled1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\c---lexical-analyzer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable untitled1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled1.dir/build: untitled1.exe
.PHONY : CMakeFiles/untitled1.dir/build

CMakeFiles/untitled1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled1.dir/clean

CMakeFiles/untitled1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\c---lexical-analyzer E:\c---lexical-analyzer E:\c---lexical-analyzer\build E:\c---lexical-analyzer\build E:\c---lexical-analyzer\build\CMakeFiles\untitled1.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/untitled1.dir/depend

