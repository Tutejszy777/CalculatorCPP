# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\DOWNLOADS EXTERNAL\mingw64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\DOWNLOADS EXTERNAL\mingw64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Murav\Documents\GitHub\Calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Murav\Documents\GitHub\Calculator\out\build\mypreset

# Include any dependencies generated for this target.
include CMakeFiles/tree_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tree_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tree_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tree_test.dir/flags.make

CMakeFiles/tree_test.dir/tree_test.cc.obj: CMakeFiles/tree_test.dir/flags.make
CMakeFiles/tree_test.dir/tree_test.cc.obj: C:/Users/Murav/Documents/GitHub/Calculator/tree_test.cc
CMakeFiles/tree_test.dir/tree_test.cc.obj: CMakeFiles/tree_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Murav\Documents\GitHub\Calculator\out\build\mypreset\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tree_test.dir/tree_test.cc.obj"
	C:\DOWNLO~1\mingw64\bin\CLANG_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tree_test.dir/tree_test.cc.obj -MF CMakeFiles\tree_test.dir\tree_test.cc.obj.d -o CMakeFiles\tree_test.dir\tree_test.cc.obj -c C:\Users\Murav\Documents\GitHub\Calculator\tree_test.cc

CMakeFiles/tree_test.dir/tree_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tree_test.dir/tree_test.cc.i"
	C:\DOWNLO~1\mingw64\bin\CLANG_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Murav\Documents\GitHub\Calculator\tree_test.cc > CMakeFiles\tree_test.dir\tree_test.cc.i

CMakeFiles/tree_test.dir/tree_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tree_test.dir/tree_test.cc.s"
	C:\DOWNLO~1\mingw64\bin\CLANG_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Murav\Documents\GitHub\Calculator\tree_test.cc -o CMakeFiles\tree_test.dir\tree_test.cc.s

CMakeFiles/tree_test.dir/tree.cpp.obj: CMakeFiles/tree_test.dir/flags.make
CMakeFiles/tree_test.dir/tree.cpp.obj: C:/Users/Murav/Documents/GitHub/Calculator/tree.cpp
CMakeFiles/tree_test.dir/tree.cpp.obj: CMakeFiles/tree_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Murav\Documents\GitHub\Calculator\out\build\mypreset\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tree_test.dir/tree.cpp.obj"
	C:\DOWNLO~1\mingw64\bin\CLANG_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tree_test.dir/tree.cpp.obj -MF CMakeFiles\tree_test.dir\tree.cpp.obj.d -o CMakeFiles\tree_test.dir\tree.cpp.obj -c C:\Users\Murav\Documents\GitHub\Calculator\tree.cpp

CMakeFiles/tree_test.dir/tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tree_test.dir/tree.cpp.i"
	C:\DOWNLO~1\mingw64\bin\CLANG_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Murav\Documents\GitHub\Calculator\tree.cpp > CMakeFiles\tree_test.dir\tree.cpp.i

CMakeFiles/tree_test.dir/tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tree_test.dir/tree.cpp.s"
	C:\DOWNLO~1\mingw64\bin\CLANG_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Murav\Documents\GitHub\Calculator\tree.cpp -o CMakeFiles\tree_test.dir\tree.cpp.s

# Object files for target tree_test
tree_test_OBJECTS = \
"CMakeFiles/tree_test.dir/tree_test.cc.obj" \
"CMakeFiles/tree_test.dir/tree.cpp.obj"

# External object files for target tree_test
tree_test_EXTERNAL_OBJECTS =

libtree_test.a: CMakeFiles/tree_test.dir/tree_test.cc.obj
libtree_test.a: CMakeFiles/tree_test.dir/tree.cpp.obj
libtree_test.a: CMakeFiles/tree_test.dir/build.make
libtree_test.a: CMakeFiles/tree_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Murav\Documents\GitHub\Calculator\out\build\mypreset\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libtree_test.a"
	$(CMAKE_COMMAND) -P CMakeFiles\tree_test.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tree_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tree_test.dir/build: libtree_test.a
.PHONY : CMakeFiles/tree_test.dir/build

CMakeFiles/tree_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tree_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tree_test.dir/clean

CMakeFiles/tree_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Murav\Documents\GitHub\Calculator C:\Users\Murav\Documents\GitHub\Calculator C:\Users\Murav\Documents\GitHub\Calculator\out\build\mypreset C:\Users\Murav\Documents\GitHub\Calculator\out\build\mypreset C:\Users\Murav\Documents\GitHub\Calculator\out\build\mypreset\CMakeFiles\tree_test.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tree_test.dir/depend

