# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\JetBrain\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = E:\JetBrain\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Workspace\C\DataStructure_algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Workspace\C\DataStructure_algorithm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DataStructure_algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataStructure_algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataStructure_algorithm.dir/flags.make

CMakeFiles/DataStructure_algorithm.dir/sort/list_insert_sort.cpp.obj: CMakeFiles/DataStructure_algorithm.dir/flags.make
CMakeFiles/DataStructure_algorithm.dir/sort/list_insert_sort.cpp.obj: ../sort/list_insert_sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Workspace\C\DataStructure_algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataStructure_algorithm.dir/sort/list_insert_sort.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DataStructure_algorithm.dir\sort\list_insert_sort.cpp.obj -c E:\Workspace\C\DataStructure_algorithm\sort\list_insert_sort.cpp

CMakeFiles/DataStructure_algorithm.dir/sort/list_insert_sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructure_algorithm.dir/sort/list_insert_sort.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Workspace\C\DataStructure_algorithm\sort\list_insert_sort.cpp > CMakeFiles\DataStructure_algorithm.dir\sort\list_insert_sort.cpp.i

CMakeFiles/DataStructure_algorithm.dir/sort/list_insert_sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructure_algorithm.dir/sort/list_insert_sort.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Workspace\C\DataStructure_algorithm\sort\list_insert_sort.cpp -o CMakeFiles\DataStructure_algorithm.dir\sort\list_insert_sort.cpp.s

# Object files for target DataStructure_algorithm
DataStructure_algorithm_OBJECTS = \
"CMakeFiles/DataStructure_algorithm.dir/sort/list_insert_sort.cpp.obj"

# External object files for target DataStructure_algorithm
DataStructure_algorithm_EXTERNAL_OBJECTS =

DataStructure_algorithm.exe: CMakeFiles/DataStructure_algorithm.dir/sort/list_insert_sort.cpp.obj
DataStructure_algorithm.exe: CMakeFiles/DataStructure_algorithm.dir/build.make
DataStructure_algorithm.exe: CMakeFiles/DataStructure_algorithm.dir/linklibs.rsp
DataStructure_algorithm.exe: CMakeFiles/DataStructure_algorithm.dir/objects1.rsp
DataStructure_algorithm.exe: CMakeFiles/DataStructure_algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Workspace\C\DataStructure_algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DataStructure_algorithm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DataStructure_algorithm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataStructure_algorithm.dir/build: DataStructure_algorithm.exe

.PHONY : CMakeFiles/DataStructure_algorithm.dir/build

CMakeFiles/DataStructure_algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DataStructure_algorithm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DataStructure_algorithm.dir/clean

CMakeFiles/DataStructure_algorithm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Workspace\C\DataStructure_algorithm E:\Workspace\C\DataStructure_algorithm E:\Workspace\C\DataStructure_algorithm\cmake-build-debug E:\Workspace\C\DataStructure_algorithm\cmake-build-debug E:\Workspace\C\DataStructure_algorithm\cmake-build-debug\CMakeFiles\DataStructure_algorithm.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataStructure_algorithm.dir/depend

