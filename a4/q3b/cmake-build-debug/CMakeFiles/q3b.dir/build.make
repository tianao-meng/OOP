# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /Users/mengtianao/Documents/cs246/cs246/a4/q3b

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/q3b.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/q3b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/q3b.dir/flags.make

CMakeFiles/q3b.dir/main.cpp.o: CMakeFiles/q3b.dir/flags.make
CMakeFiles/q3b.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/q3b.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q3b.dir/main.cpp.o -c /Users/mengtianao/Documents/cs246/cs246/a4/q3b/main.cpp

CMakeFiles/q3b.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q3b.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mengtianao/Documents/cs246/cs246/a4/q3b/main.cpp > CMakeFiles/q3b.dir/main.cpp.i

CMakeFiles/q3b.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q3b.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mengtianao/Documents/cs246/cs246/a4/q3b/main.cpp -o CMakeFiles/q3b.dir/main.cpp.s

CMakeFiles/q3b.dir/cell.cpp.o: CMakeFiles/q3b.dir/flags.make
CMakeFiles/q3b.dir/cell.cpp.o: ../cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/q3b.dir/cell.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q3b.dir/cell.cpp.o -c /Users/mengtianao/Documents/cs246/cs246/a4/q3b/cell.cpp

CMakeFiles/q3b.dir/cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q3b.dir/cell.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mengtianao/Documents/cs246/cs246/a4/q3b/cell.cpp > CMakeFiles/q3b.dir/cell.cpp.i

CMakeFiles/q3b.dir/cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q3b.dir/cell.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mengtianao/Documents/cs246/cs246/a4/q3b/cell.cpp -o CMakeFiles/q3b.dir/cell.cpp.s

CMakeFiles/q3b.dir/grid.cpp.o: CMakeFiles/q3b.dir/flags.make
CMakeFiles/q3b.dir/grid.cpp.o: ../grid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/q3b.dir/grid.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q3b.dir/grid.cpp.o -c /Users/mengtianao/Documents/cs246/cs246/a4/q3b/grid.cpp

CMakeFiles/q3b.dir/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q3b.dir/grid.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mengtianao/Documents/cs246/cs246/a4/q3b/grid.cpp > CMakeFiles/q3b.dir/grid.cpp.i

CMakeFiles/q3b.dir/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q3b.dir/grid.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mengtianao/Documents/cs246/cs246/a4/q3b/grid.cpp -o CMakeFiles/q3b.dir/grid.cpp.s

CMakeFiles/q3b.dir/subject.cpp.o: CMakeFiles/q3b.dir/flags.make
CMakeFiles/q3b.dir/subject.cpp.o: ../subject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/q3b.dir/subject.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q3b.dir/subject.cpp.o -c /Users/mengtianao/Documents/cs246/cs246/a4/q3b/subject.cpp

CMakeFiles/q3b.dir/subject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q3b.dir/subject.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mengtianao/Documents/cs246/cs246/a4/q3b/subject.cpp > CMakeFiles/q3b.dir/subject.cpp.i

CMakeFiles/q3b.dir/subject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q3b.dir/subject.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mengtianao/Documents/cs246/cs246/a4/q3b/subject.cpp -o CMakeFiles/q3b.dir/subject.cpp.s

CMakeFiles/q3b.dir/textdisplay.cpp.o: CMakeFiles/q3b.dir/flags.make
CMakeFiles/q3b.dir/textdisplay.cpp.o: ../textdisplay.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/q3b.dir/textdisplay.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q3b.dir/textdisplay.cpp.o -c /Users/mengtianao/Documents/cs246/cs246/a4/q3b/textdisplay.cpp

CMakeFiles/q3b.dir/textdisplay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q3b.dir/textdisplay.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mengtianao/Documents/cs246/cs246/a4/q3b/textdisplay.cpp > CMakeFiles/q3b.dir/textdisplay.cpp.i

CMakeFiles/q3b.dir/textdisplay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q3b.dir/textdisplay.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mengtianao/Documents/cs246/cs246/a4/q3b/textdisplay.cpp -o CMakeFiles/q3b.dir/textdisplay.cpp.s

CMakeFiles/q3b.dir/window.cpp.o: CMakeFiles/q3b.dir/flags.make
CMakeFiles/q3b.dir/window.cpp.o: ../window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/q3b.dir/window.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q3b.dir/window.cpp.o -c /Users/mengtianao/Documents/cs246/cs246/a4/q3b/window.cpp

CMakeFiles/q3b.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q3b.dir/window.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mengtianao/Documents/cs246/cs246/a4/q3b/window.cpp > CMakeFiles/q3b.dir/window.cpp.i

CMakeFiles/q3b.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q3b.dir/window.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mengtianao/Documents/cs246/cs246/a4/q3b/window.cpp -o CMakeFiles/q3b.dir/window.cpp.s

CMakeFiles/q3b.dir/GraphicsDisplay.cpp.o: CMakeFiles/q3b.dir/flags.make
CMakeFiles/q3b.dir/GraphicsDisplay.cpp.o: ../GraphicsDisplay.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/q3b.dir/GraphicsDisplay.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q3b.dir/GraphicsDisplay.cpp.o -c /Users/mengtianao/Documents/cs246/cs246/a4/q3b/GraphicsDisplay.cpp

CMakeFiles/q3b.dir/GraphicsDisplay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q3b.dir/GraphicsDisplay.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mengtianao/Documents/cs246/cs246/a4/q3b/GraphicsDisplay.cpp > CMakeFiles/q3b.dir/GraphicsDisplay.cpp.i

CMakeFiles/q3b.dir/GraphicsDisplay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q3b.dir/GraphicsDisplay.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mengtianao/Documents/cs246/cs246/a4/q3b/GraphicsDisplay.cpp -o CMakeFiles/q3b.dir/GraphicsDisplay.cpp.s

# Object files for target q3b
q3b_OBJECTS = \
"CMakeFiles/q3b.dir/main.cpp.o" \
"CMakeFiles/q3b.dir/cell.cpp.o" \
"CMakeFiles/q3b.dir/grid.cpp.o" \
"CMakeFiles/q3b.dir/subject.cpp.o" \
"CMakeFiles/q3b.dir/textdisplay.cpp.o" \
"CMakeFiles/q3b.dir/window.cpp.o" \
"CMakeFiles/q3b.dir/GraphicsDisplay.cpp.o"

# External object files for target q3b
q3b_EXTERNAL_OBJECTS =

q3b: CMakeFiles/q3b.dir/main.cpp.o
q3b: CMakeFiles/q3b.dir/cell.cpp.o
q3b: CMakeFiles/q3b.dir/grid.cpp.o
q3b: CMakeFiles/q3b.dir/subject.cpp.o
q3b: CMakeFiles/q3b.dir/textdisplay.cpp.o
q3b: CMakeFiles/q3b.dir/window.cpp.o
q3b: CMakeFiles/q3b.dir/GraphicsDisplay.cpp.o
q3b: CMakeFiles/q3b.dir/build.make
q3b: CMakeFiles/q3b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable q3b"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/q3b.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/q3b.dir/build: q3b

.PHONY : CMakeFiles/q3b.dir/build

CMakeFiles/q3b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/q3b.dir/cmake_clean.cmake
.PHONY : CMakeFiles/q3b.dir/clean

CMakeFiles/q3b.dir/depend:
	cd /Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mengtianao/Documents/cs246/cs246/a4/q3b /Users/mengtianao/Documents/cs246/cs246/a4/q3b /Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug /Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug /Users/mengtianao/Documents/cs246/cs246/a4/q3b/cmake-build-debug/CMakeFiles/q3b.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/q3b.dir/depend
