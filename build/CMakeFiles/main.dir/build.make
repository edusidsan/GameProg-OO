# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/build"

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/Principal.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Principal.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/Principal.cpp.obj: D:/UTFPR/Engenharia\ da\ Computacao/2\ PERIODO/TECNICAS\ DE\ PROGRAMACAO/GameProg-OO/src/Principal.cpp
CMakeFiles/main.dir/Principal.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/Principal.cpp.obj"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/Principal.cpp.obj -MF CMakeFiles/main.dir/Principal.cpp.obj.d -o CMakeFiles/main.dir/Principal.cpp.obj -c "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src/Principal.cpp"

CMakeFiles/main.dir/Principal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Principal.cpp.i"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src/Principal.cpp" > CMakeFiles/main.dir/Principal.cpp.i

CMakeFiles/main.dir/Principal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Principal.cpp.s"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src/Principal.cpp" -o CMakeFiles/main.dir/Principal.cpp.s

CMakeFiles/main.dir/Personagem.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Personagem.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/Personagem.cpp.obj: D:/UTFPR/Engenharia\ da\ Computacao/2\ PERIODO/TECNICAS\ DE\ PROGRAMACAO/GameProg-OO/src/Personagem.cpp
CMakeFiles/main.dir/Personagem.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/Personagem.cpp.obj"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/Personagem.cpp.obj -MF CMakeFiles/main.dir/Personagem.cpp.obj.d -o CMakeFiles/main.dir/Personagem.cpp.obj -c "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src/Personagem.cpp"

CMakeFiles/main.dir/Personagem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Personagem.cpp.i"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src/Personagem.cpp" > CMakeFiles/main.dir/Personagem.cpp.i

CMakeFiles/main.dir/Personagem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Personagem.cpp.s"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src/Personagem.cpp" -o CMakeFiles/main.dir/Personagem.cpp.s

CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/main.cpp.obj: D:/UTFPR/Engenharia\ da\ Computacao/2\ PERIODO/TECNICAS\ DE\ PROGRAMACAO/GameProg-OO/src/main.cpp
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/main.cpp.obj"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.obj -MF CMakeFiles/main.dir/main.cpp.obj.d -o CMakeFiles/main.dir/main.cpp.obj -c "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src/main.cpp"

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src/main.cpp" > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	C:/msys64/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src/main.cpp" -o CMakeFiles/main.dir/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/Principal.cpp.obj" \
"CMakeFiles/main.dir/Personagem.cpp.obj" \
"CMakeFiles/main.dir/main.cpp.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

libmain.a: CMakeFiles/main.dir/Principal.cpp.obj
libmain.a: CMakeFiles/main.dir/Personagem.cpp.obj
libmain.a: CMakeFiles/main.dir/main.cpp.obj
libmain.a: CMakeFiles/main.dir/build.make
libmain.a: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libmain.a"
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: libmain.a
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src" "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/src" "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/build" "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/build" "D:/UTFPR/Engenharia da Computacao/2 PERIODO/TECNICAS DE PROGRAMACAO/GameProg-OO/build/CMakeFiles/main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

