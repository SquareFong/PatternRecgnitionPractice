# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/squarefong/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4445.17/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/squarefong/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4445.17/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NaiveBayes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NaiveBayes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NaiveBayes.dir/flags.make

CMakeFiles/NaiveBayes.dir/main.cpp.o: CMakeFiles/NaiveBayes.dir/flags.make
CMakeFiles/NaiveBayes.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NaiveBayes.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NaiveBayes.dir/main.cpp.o -c /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/main.cpp

CMakeFiles/NaiveBayes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaiveBayes.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/main.cpp > CMakeFiles/NaiveBayes.dir/main.cpp.i

CMakeFiles/NaiveBayes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaiveBayes.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/main.cpp -o CMakeFiles/NaiveBayes.dir/main.cpp.s

CMakeFiles/NaiveBayes.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/NaiveBayes.dir/main.cpp.o.requires

CMakeFiles/NaiveBayes.dir/main.cpp.o.provides: CMakeFiles/NaiveBayes.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/NaiveBayes.dir/build.make CMakeFiles/NaiveBayes.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/NaiveBayes.dir/main.cpp.o.provides

CMakeFiles/NaiveBayes.dir/main.cpp.o.provides.build: CMakeFiles/NaiveBayes.dir/main.cpp.o


CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o: CMakeFiles/NaiveBayes.dir/flags.make
CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o: ../NaiveBayes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o -c /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/NaiveBayes.cpp

CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/NaiveBayes.cpp > CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.i

CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/NaiveBayes.cpp -o CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.s

CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o.requires:

.PHONY : CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o.requires

CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o.provides: CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o.requires
	$(MAKE) -f CMakeFiles/NaiveBayes.dir/build.make CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o.provides.build
.PHONY : CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o.provides

CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o.provides.build: CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o


# Object files for target NaiveBayes
NaiveBayes_OBJECTS = \
"CMakeFiles/NaiveBayes.dir/main.cpp.o" \
"CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o"

# External object files for target NaiveBayes
NaiveBayes_EXTERNAL_OBJECTS =

NaiveBayes: CMakeFiles/NaiveBayes.dir/main.cpp.o
NaiveBayes: CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o
NaiveBayes: CMakeFiles/NaiveBayes.dir/build.make
NaiveBayes: CMakeFiles/NaiveBayes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable NaiveBayes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NaiveBayes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NaiveBayes.dir/build: NaiveBayes

.PHONY : CMakeFiles/NaiveBayes.dir/build

CMakeFiles/NaiveBayes.dir/requires: CMakeFiles/NaiveBayes.dir/main.cpp.o.requires
CMakeFiles/NaiveBayes.dir/requires: CMakeFiles/NaiveBayes.dir/NaiveBayes.cpp.o.requires

.PHONY : CMakeFiles/NaiveBayes.dir/requires

CMakeFiles/NaiveBayes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NaiveBayes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NaiveBayes.dir/clean

CMakeFiles/NaiveBayes.dir/depend:
	cd /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/cmake-build-debug /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/cmake-build-debug /home/squarefong/Documents/PatternRecgnitionPractice/NaiveBayes/cmake-build-debug/CMakeFiles/NaiveBayes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NaiveBayes.dir/depend

