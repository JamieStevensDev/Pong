# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /Users/jamie/portfolio/Pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jamie/portfolio/Pong/cmake-build-debug

# Utility rule file for HelloASGE+GameData.

# Include the progress variables for this target.
include CMakeFiles/HelloASGE+GameData.dir/progress.make

CMakeFiles/HelloASGE+GameData:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/jamie/portfolio/Pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "creating data archive"
	cd /Users/jamie/portfolio/Pong/Data && /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E tar cfv /Users/jamie/portfolio/Pong/cmake-build-debug/bin/game.dat --format=7zip -- *

HelloASGE+GameData: CMakeFiles/HelloASGE+GameData
HelloASGE+GameData: CMakeFiles/HelloASGE+GameData.dir/build.make

.PHONY : HelloASGE+GameData

# Rule to build all files generated by this target.
CMakeFiles/HelloASGE+GameData.dir/build: HelloASGE+GameData

.PHONY : CMakeFiles/HelloASGE+GameData.dir/build

CMakeFiles/HelloASGE+GameData.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HelloASGE+GameData.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HelloASGE+GameData.dir/clean

CMakeFiles/HelloASGE+GameData.dir/depend:
	cd /Users/jamie/portfolio/Pong/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jamie/portfolio/Pong /Users/jamie/portfolio/Pong /Users/jamie/portfolio/Pong/cmake-build-debug /Users/jamie/portfolio/Pong/cmake-build-debug /Users/jamie/portfolio/Pong/cmake-build-debug/CMakeFiles/HelloASGE+GameData.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HelloASGE+GameData.dir/depend

