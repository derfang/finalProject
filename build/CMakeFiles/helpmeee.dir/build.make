# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = C:\Strawberry\c\bin\cmake.exe

# The command to remove a file.
RM = C:\Strawberry\c\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\PADIDAR\Desktop\finalProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\PADIDAR\Desktop\finalProject\build

# Include any dependencies generated for this target.
include CMakeFiles/helpmeee.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/helpmeee.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/helpmeee.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/helpmeee.dir/flags.make

CMakeFiles/helpmeee.dir/help.cpp.obj: CMakeFiles/helpmeee.dir/flags.make
CMakeFiles/helpmeee.dir/help.cpp.obj: C:/Users/PADIDAR/Desktop/finalProject/help.cpp
CMakeFiles/helpmeee.dir/help.cpp.obj: CMakeFiles/helpmeee.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\PADIDAR\Desktop\finalProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/helpmeee.dir/help.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helpmeee.dir/help.cpp.obj -MF CMakeFiles\helpmeee.dir\help.cpp.obj.d -o CMakeFiles\helpmeee.dir\help.cpp.obj -c C:\Users\PADIDAR\Desktop\finalProject\help.cpp

CMakeFiles/helpmeee.dir/help.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helpmeee.dir/help.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\PADIDAR\Desktop\finalProject\help.cpp > CMakeFiles\helpmeee.dir\help.cpp.i

CMakeFiles/helpmeee.dir/help.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helpmeee.dir/help.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\PADIDAR\Desktop\finalProject\help.cpp -o CMakeFiles\helpmeee.dir\help.cpp.s

# Object files for target helpmeee
helpmeee_OBJECTS = \
"CMakeFiles/helpmeee.dir/help.cpp.obj"

# External object files for target helpmeee
helpmeee_EXTERNAL_OBJECTS =

libhelpmeee.a: CMakeFiles/helpmeee.dir/help.cpp.obj
libhelpmeee.a: CMakeFiles/helpmeee.dir/build.make
libhelpmeee.a: CMakeFiles/helpmeee.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\PADIDAR\Desktop\finalProject\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhelpmeee.a"
	$(CMAKE_COMMAND) -P CMakeFiles\helpmeee.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\helpmeee.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/helpmeee.dir/build: libhelpmeee.a
.PHONY : CMakeFiles/helpmeee.dir/build

CMakeFiles/helpmeee.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\helpmeee.dir\cmake_clean.cmake
.PHONY : CMakeFiles/helpmeee.dir/clean

CMakeFiles/helpmeee.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\PADIDAR\Desktop\finalProject C:\Users\PADIDAR\Desktop\finalProject C:\Users\PADIDAR\Desktop\finalProject\build C:\Users\PADIDAR\Desktop\finalProject\build C:\Users\PADIDAR\Desktop\finalProject\build\CMakeFiles\helpmeee.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/helpmeee.dir/depend

