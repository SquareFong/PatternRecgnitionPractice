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
CMAKE_COMMAND = /opt/Clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/Clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/squarefong/Documents/coding/CLionProjects/ID3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/squarefong/Documents/coding/CLionProjects/ID3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ID3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ID3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ID3.dir/flags.make

CMakeFiles/ID3.dir/main.cpp.o: CMakeFiles/ID3.dir/flags.make
CMakeFiles/ID3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/squarefong/Documents/coding/CLionProjects/ID3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ID3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ID3.dir/main.cpp.o -c /home/squarefong/Documents/coding/CLionProjects/ID3/main.cpp

CMakeFiles/ID3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ID3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/squarefong/Documents/coding/CLionProjects/ID3/main.cpp > CMakeFiles/ID3.dir/main.cpp.i

CMakeFiles/ID3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ID3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/squarefong/Documents/coding/CLionProjects/ID3/main.cpp -o CMakeFiles/ID3.dir/main.cpp.s

CMakeFiles/ID3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ID3.dir/main.cpp.o.requires

CMakeFiles/ID3.dir/main.cpp.o.provides: CMakeFiles/ID3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ID3.dir/build.make CMakeFiles/ID3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ID3.dir/main.cpp.o.provides

CMakeFiles/ID3.dir/main.cpp.o.provides.build: CMakeFiles/ID3.dir/main.cpp.o


CMakeFiles/ID3.dir/ID3.cpp.o: CMakeFiles/ID3.dir/flags.make
CMakeFiles/ID3.dir/ID3.cpp.o: ../ID3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/squarefong/Documents/coding/CLionProjects/ID3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ID3.dir/ID3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ID3.dir/ID3.cpp.o -c /home/squarefong/Documents/coding/CLionProjects/ID3/ID3.cpp

CMakeFiles/ID3.dir/ID3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ID3.dir/ID3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/squarefong/Documents/coding/CLionProjects/ID3/ID3.cpp > CMakeFiles/ID3.dir/ID3.cpp.i

CMakeFiles/ID3.dir/ID3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ID3.dir/ID3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/squarefong/Documents/coding/CLionProjects/ID3/ID3.cpp -o CMakeFiles/ID3.dir/ID3.cpp.s

CMakeFiles/ID3.dir/ID3.cpp.o.requires:

.PHONY : CMakeFiles/ID3.dir/ID3.cpp.o.requires

CMakeFiles/ID3.dir/ID3.cpp.o.provides: CMakeFiles/ID3.dir/ID3.cpp.o.requires
	$(MAKE) -f CMakeFiles/ID3.dir/build.make CMakeFiles/ID3.dir/ID3.cpp.o.provides.build
.PHONY : CMakeFiles/ID3.dir/ID3.cpp.o.provides

CMakeFiles/ID3.dir/ID3.cpp.o.provides.build: CMakeFiles/ID3.dir/ID3.cpp.o


# Object files for target ID3
ID3_OBJECTS = \
"CMakeFiles/ID3.dir/main.cpp.o" \
"CMakeFiles/ID3.dir/ID3.cpp.o"

# External object files for target ID3
ID3_EXTERNAL_OBJECTS =

ID3: CMakeFiles/ID3.dir/main.cpp.o
ID3: CMakeFiles/ID3.dir/ID3.cpp.o
ID3: CMakeFiles/ID3.dir/build.make
ID3: CMakeFiles/ID3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/squarefong/Documents/coding/CLionProjects/ID3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ID3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ID3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ID3.dir/build: ID3

.PHONY : CMakeFiles/ID3.dir/build

CMakeFiles/ID3.dir/requires: CMakeFiles/ID3.dir/main.cpp.o.requires
CMakeFiles/ID3.dir/requires: CMakeFiles/ID3.dir/ID3.cpp.o.requires

.PHONY : CMakeFiles/ID3.dir/requires

CMakeFiles/ID3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ID3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ID3.dir/clean

CMakeFiles/ID3.dir/depend:
	cd /home/squarefong/Documents/coding/CLionProjects/ID3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/squarefong/Documents/coding/CLionProjects/ID3 /home/squarefong/Documents/coding/CLionProjects/ID3 /home/squarefong/Documents/coding/CLionProjects/ID3/cmake-build-debug /home/squarefong/Documents/coding/CLionProjects/ID3/cmake-build-debug /home/squarefong/Documents/coding/CLionProjects/ID3/cmake-build-debug/CMakeFiles/ID3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ID3.dir/depend
