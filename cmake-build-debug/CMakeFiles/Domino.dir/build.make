# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/dominik/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dominik/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dominik/CLionProjects/Domino

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dominik/CLionProjects/Domino/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Domino.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Domino.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Domino.dir/flags.make

CMakeFiles/Domino.dir/main.cpp.o: CMakeFiles/Domino.dir/flags.make
CMakeFiles/Domino.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dominik/CLionProjects/Domino/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Domino.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Domino.dir/main.cpp.o -c /home/dominik/CLionProjects/Domino/main.cpp

CMakeFiles/Domino.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Domino.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dominik/CLionProjects/Domino/main.cpp > CMakeFiles/Domino.dir/main.cpp.i

CMakeFiles/Domino.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Domino.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dominik/CLionProjects/Domino/main.cpp -o CMakeFiles/Domino.dir/main.cpp.s

CMakeFiles/Domino.dir/Source.cpp.o: CMakeFiles/Domino.dir/flags.make
CMakeFiles/Domino.dir/Source.cpp.o: ../Source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dominik/CLionProjects/Domino/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Domino.dir/Source.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Domino.dir/Source.cpp.o -c /home/dominik/CLionProjects/Domino/Source.cpp

CMakeFiles/Domino.dir/Source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Domino.dir/Source.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dominik/CLionProjects/Domino/Source.cpp > CMakeFiles/Domino.dir/Source.cpp.i

CMakeFiles/Domino.dir/Source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Domino.dir/Source.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dominik/CLionProjects/Domino/Source.cpp -o CMakeFiles/Domino.dir/Source.cpp.s

CMakeFiles/Domino.dir/Scan.cpp.o: CMakeFiles/Domino.dir/flags.make
CMakeFiles/Domino.dir/Scan.cpp.o: ../Scan.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dominik/CLionProjects/Domino/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Domino.dir/Scan.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Domino.dir/Scan.cpp.o -c /home/dominik/CLionProjects/Domino/Scan.cpp

CMakeFiles/Domino.dir/Scan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Domino.dir/Scan.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dominik/CLionProjects/Domino/Scan.cpp > CMakeFiles/Domino.dir/Scan.cpp.i

CMakeFiles/Domino.dir/Scan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Domino.dir/Scan.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dominik/CLionProjects/Domino/Scan.cpp -o CMakeFiles/Domino.dir/Scan.cpp.s

# Object files for target Domino
Domino_OBJECTS = \
"CMakeFiles/Domino.dir/main.cpp.o" \
"CMakeFiles/Domino.dir/Source.cpp.o" \
"CMakeFiles/Domino.dir/Scan.cpp.o"

# External object files for target Domino
Domino_EXTERNAL_OBJECTS =

Domino: CMakeFiles/Domino.dir/main.cpp.o
Domino: CMakeFiles/Domino.dir/Source.cpp.o
Domino: CMakeFiles/Domino.dir/Scan.cpp.o
Domino: CMakeFiles/Domino.dir/build.make
Domino: CMakeFiles/Domino.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dominik/CLionProjects/Domino/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Domino"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Domino.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Domino.dir/build: Domino

.PHONY : CMakeFiles/Domino.dir/build

CMakeFiles/Domino.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Domino.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Domino.dir/clean

CMakeFiles/Domino.dir/depend:
	cd /home/dominik/CLionProjects/Domino/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dominik/CLionProjects/Domino /home/dominik/CLionProjects/Domino /home/dominik/CLionProjects/Domino/cmake-build-debug /home/dominik/CLionProjects/Domino/cmake-build-debug /home/dominik/CLionProjects/Domino/cmake-build-debug/CMakeFiles/Domino.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Domino.dir/depend

