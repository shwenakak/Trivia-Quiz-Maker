# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/src/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/csmajs/ameno011/final-project-ameno011-abrou004-skak001/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/src/main.cpp.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/main.cpp.o -c /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001/src/main.cpp

CMakeFiles/game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/main.cpp.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001/src/main.cpp > CMakeFiles/game.dir/src/main.cpp.i

CMakeFiles/game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/main.cpp.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001/src/main.cpp -o CMakeFiles/game.dir/src/main.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/src/main.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/src/main.cpp.o
game: CMakeFiles/game.dir/build.make
game: lib/libgtest.a
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/csmajs/ameno011/final-project-ameno011-abrou004-skak001/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001 /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001 /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001 /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001 /home/csmajs/ameno011/final-project-ameno011-abrou004-skak001/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

