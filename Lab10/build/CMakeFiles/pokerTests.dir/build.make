# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /nix/store/5h0akwq4cwlc3yp92i84nfgcxpv5xv79-cmake-3.26.4/bin/cmake

# The command to remove a file.
RM = /nix/store/5h0akwq4cwlc3yp92i84nfgcxpv5xv79-cmake-3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10/build"

# Include any dependencies generated for this target.
include CMakeFiles/pokerTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pokerTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pokerTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pokerTests.dir/flags.make

CMakeFiles/pokerTests.dir/test.cpp.o: CMakeFiles/pokerTests.dir/flags.make
CMakeFiles/pokerTests.dir/test.cpp.o: /home/dylan/Seafile/My\ Library/Temp_Git_Files/CS300/Lab10/test.cpp
CMakeFiles/pokerTests.dir/test.cpp.o: CMakeFiles/pokerTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pokerTests.dir/test.cpp.o"
	/run/current-system/sw/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pokerTests.dir/test.cpp.o -MF CMakeFiles/pokerTests.dir/test.cpp.o.d -o CMakeFiles/pokerTests.dir/test.cpp.o -c "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10/test.cpp"

CMakeFiles/pokerTests.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pokerTests.dir/test.cpp.i"
	/run/current-system/sw/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10/test.cpp" > CMakeFiles/pokerTests.dir/test.cpp.i

CMakeFiles/pokerTests.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pokerTests.dir/test.cpp.s"
	/run/current-system/sw/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10/test.cpp" -o CMakeFiles/pokerTests.dir/test.cpp.s

# Object files for target pokerTests
pokerTests_OBJECTS = \
"CMakeFiles/pokerTests.dir/test.cpp.o"

# External object files for target pokerTests
pokerTests_EXTERNAL_OBJECTS =

pokerTests: CMakeFiles/pokerTests.dir/test.cpp.o
pokerTests: CMakeFiles/pokerTests.dir/build.make
pokerTests: lib/libgtest_main.a
pokerTests: libpokerHand.so
pokerTests: lib/libgtest.a
pokerTests: CMakeFiles/pokerTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pokerTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pokerTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pokerTests.dir/build: pokerTests
.PHONY : CMakeFiles/pokerTests.dir/build

CMakeFiles/pokerTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pokerTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pokerTests.dir/clean

CMakeFiles/pokerTests.dir/depend:
	cd "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10" "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10" "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10/build" "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10/build" "/home/dylan/Seafile/My Library/Temp_Git_Files/CS300/Lab10/build/CMakeFiles/pokerTests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/pokerTests.dir/depend

