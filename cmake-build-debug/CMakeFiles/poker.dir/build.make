# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "/Users/ethan/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/223.8836.42/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/ethan/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/223.8836.42/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ethan/Documents/Coding/PokerInC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ethan/Documents/Coding/PokerInC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/poker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/poker.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/poker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/poker.dir/flags.make

CMakeFiles/poker.dir/main.c.o: CMakeFiles/poker.dir/flags.make
CMakeFiles/poker.dir/main.c.o: /Users/ethan/Documents/Coding/PokerInC/main.c
CMakeFiles/poker.dir/main.c.o: CMakeFiles/poker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ethan/Documents/Coding/PokerInC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/poker.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/poker.dir/main.c.o -MF CMakeFiles/poker.dir/main.c.o.d -o CMakeFiles/poker.dir/main.c.o -c /Users/ethan/Documents/Coding/PokerInC/main.c

CMakeFiles/poker.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/poker.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ethan/Documents/Coding/PokerInC/main.c > CMakeFiles/poker.dir/main.c.i

CMakeFiles/poker.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/poker.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ethan/Documents/Coding/PokerInC/main.c -o CMakeFiles/poker.dir/main.c.s

# Object files for target poker
poker_OBJECTS = \
"CMakeFiles/poker.dir/main.c.o"

# External object files for target poker
poker_EXTERNAL_OBJECTS =

poker: CMakeFiles/poker.dir/main.c.o
poker: CMakeFiles/poker.dir/build.make
poker: CMakeFiles/poker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ethan/Documents/Coding/PokerInC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable poker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/poker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/poker.dir/build: poker
.PHONY : CMakeFiles/poker.dir/build

CMakeFiles/poker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/poker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/poker.dir/clean

CMakeFiles/poker.dir/depend:
	cd /Users/ethan/Documents/Coding/PokerInC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ethan/Documents/Coding/PokerInC /Users/ethan/Documents/Coding/PokerInC /Users/ethan/Documents/Coding/PokerInC/cmake-build-debug /Users/ethan/Documents/Coding/PokerInC/cmake-build-debug /Users/ethan/Documents/Coding/PokerInC/cmake-build-debug/CMakeFiles/poker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/poker.dir/depend
