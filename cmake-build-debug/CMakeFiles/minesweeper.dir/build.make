# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/loganbon/CLionProjects/minesweeper-solver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/loganbon/CLionProjects/minesweeper-solver/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/minesweeper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minesweeper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minesweeper.dir/flags.make

CMakeFiles/minesweeper.dir/main.cpp.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/loganbon/CLionProjects/minesweeper-solver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minesweeper.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minesweeper.dir/main.cpp.o -c /Users/loganbon/CLionProjects/minesweeper-solver/main.cpp

CMakeFiles/minesweeper.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minesweeper.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/loganbon/CLionProjects/minesweeper-solver/main.cpp > CMakeFiles/minesweeper.dir/main.cpp.i

CMakeFiles/minesweeper.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minesweeper.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/loganbon/CLionProjects/minesweeper-solver/main.cpp -o CMakeFiles/minesweeper.dir/main.cpp.s

CMakeFiles/minesweeper.dir/Board.cpp.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/Board.cpp.o: ../Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/loganbon/CLionProjects/minesweeper-solver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/minesweeper.dir/Board.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minesweeper.dir/Board.cpp.o -c /Users/loganbon/CLionProjects/minesweeper-solver/Board.cpp

CMakeFiles/minesweeper.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minesweeper.dir/Board.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/loganbon/CLionProjects/minesweeper-solver/Board.cpp > CMakeFiles/minesweeper.dir/Board.cpp.i

CMakeFiles/minesweeper.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minesweeper.dir/Board.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/loganbon/CLionProjects/minesweeper-solver/Board.cpp -o CMakeFiles/minesweeper.dir/Board.cpp.s

CMakeFiles/minesweeper.dir/Player.cpp.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/Player.cpp.o: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/loganbon/CLionProjects/minesweeper-solver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/minesweeper.dir/Player.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minesweeper.dir/Player.cpp.o -c /Users/loganbon/CLionProjects/minesweeper-solver/Player.cpp

CMakeFiles/minesweeper.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minesweeper.dir/Player.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/loganbon/CLionProjects/minesweeper-solver/Player.cpp > CMakeFiles/minesweeper.dir/Player.cpp.i

CMakeFiles/minesweeper.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minesweeper.dir/Player.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/loganbon/CLionProjects/minesweeper-solver/Player.cpp -o CMakeFiles/minesweeper.dir/Player.cpp.s

CMakeFiles/minesweeper.dir/Button.cpp.o: CMakeFiles/minesweeper.dir/flags.make
CMakeFiles/minesweeper.dir/Button.cpp.o: ../Button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/loganbon/CLionProjects/minesweeper-solver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/minesweeper.dir/Button.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/minesweeper.dir/Button.cpp.o -c /Users/loganbon/CLionProjects/minesweeper-solver/Button.cpp

CMakeFiles/minesweeper.dir/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minesweeper.dir/Button.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/loganbon/CLionProjects/minesweeper-solver/Button.cpp > CMakeFiles/minesweeper.dir/Button.cpp.i

CMakeFiles/minesweeper.dir/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minesweeper.dir/Button.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/loganbon/CLionProjects/minesweeper-solver/Button.cpp -o CMakeFiles/minesweeper.dir/Button.cpp.s

# Object files for target minesweeper
minesweeper_OBJECTS = \
"CMakeFiles/minesweeper.dir/main.cpp.o" \
"CMakeFiles/minesweeper.dir/Board.cpp.o" \
"CMakeFiles/minesweeper.dir/Player.cpp.o" \
"CMakeFiles/minesweeper.dir/Button.cpp.o"

# External object files for target minesweeper
minesweeper_EXTERNAL_OBJECTS =

minesweeper: CMakeFiles/minesweeper.dir/main.cpp.o
minesweeper: CMakeFiles/minesweeper.dir/Board.cpp.o
minesweeper: CMakeFiles/minesweeper.dir/Player.cpp.o
minesweeper: CMakeFiles/minesweeper.dir/Button.cpp.o
minesweeper: CMakeFiles/minesweeper.dir/build.make
minesweeper: /usr/local/lib/libsfml-graphics.2.5.1.dylib
minesweeper: /usr/local/lib/libsfml-audio.2.5.1.dylib
minesweeper: /usr/local/lib/libsfml-network.2.5.1.dylib
minesweeper: /usr/local/lib/libsfml-window.2.5.1.dylib
minesweeper: /usr/local/lib/libsfml-system.2.5.1.dylib
minesweeper: CMakeFiles/minesweeper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/loganbon/CLionProjects/minesweeper-solver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable minesweeper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minesweeper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minesweeper.dir/build: minesweeper

.PHONY : CMakeFiles/minesweeper.dir/build

CMakeFiles/minesweeper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minesweeper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minesweeper.dir/clean

CMakeFiles/minesweeper.dir/depend:
	cd /Users/loganbon/CLionProjects/minesweeper-solver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/loganbon/CLionProjects/minesweeper-solver /Users/loganbon/CLionProjects/minesweeper-solver /Users/loganbon/CLionProjects/minesweeper-solver/cmake-build-debug /Users/loganbon/CLionProjects/minesweeper-solver/cmake-build-debug /Users/loganbon/CLionProjects/minesweeper-solver/cmake-build-debug/CMakeFiles/minesweeper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minesweeper.dir/depend

