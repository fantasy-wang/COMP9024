# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\9024 date stru"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\9024 date stru\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/9024_date_stru.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/9024_date_stru.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/9024_date_stru.dir/flags.make

CMakeFiles/9024_date_stru.dir/puzzle.c.obj: CMakeFiles/9024_date_stru.dir/flags.make
CMakeFiles/9024_date_stru.dir/puzzle.c.obj: ../puzzle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\9024 date stru\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/9024_date_stru.dir/puzzle.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\9024_date_stru.dir\puzzle.c.obj   -c "D:\9024 date stru\puzzle.c"

CMakeFiles/9024_date_stru.dir/puzzle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/9024_date_stru.dir/puzzle.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\9024 date stru\puzzle.c" > CMakeFiles\9024_date_stru.dir\puzzle.c.i

CMakeFiles/9024_date_stru.dir/puzzle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/9024_date_stru.dir/puzzle.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\9024 date stru\puzzle.c" -o CMakeFiles\9024_date_stru.dir\puzzle.c.s

CMakeFiles/9024_date_stru.dir/boardADT.c.obj: CMakeFiles/9024_date_stru.dir/flags.make
CMakeFiles/9024_date_stru.dir/boardADT.c.obj: ../boardADT.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\9024 date stru\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/9024_date_stru.dir/boardADT.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\9024_date_stru.dir\boardADT.c.obj   -c "D:\9024 date stru\boardADT.c"

CMakeFiles/9024_date_stru.dir/boardADT.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/9024_date_stru.dir/boardADT.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\9024 date stru\boardADT.c" > CMakeFiles\9024_date_stru.dir\boardADT.c.i

CMakeFiles/9024_date_stru.dir/boardADT.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/9024_date_stru.dir/boardADT.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\9024 date stru\boardADT.c" -o CMakeFiles\9024_date_stru.dir\boardADT.c.s

# Object files for target 9024_date_stru
9024_date_stru_OBJECTS = \
"CMakeFiles/9024_date_stru.dir/puzzle.c.obj" \
"CMakeFiles/9024_date_stru.dir/boardADT.c.obj"

# External object files for target 9024_date_stru
9024_date_stru_EXTERNAL_OBJECTS =

9024_date_stru.exe: CMakeFiles/9024_date_stru.dir/puzzle.c.obj
9024_date_stru.exe: CMakeFiles/9024_date_stru.dir/boardADT.c.obj
9024_date_stru.exe: CMakeFiles/9024_date_stru.dir/build.make
9024_date_stru.exe: CMakeFiles/9024_date_stru.dir/linklibs.rsp
9024_date_stru.exe: CMakeFiles/9024_date_stru.dir/objects1.rsp
9024_date_stru.exe: CMakeFiles/9024_date_stru.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\9024 date stru\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 9024_date_stru.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\9024_date_stru.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/9024_date_stru.dir/build: 9024_date_stru.exe

.PHONY : CMakeFiles/9024_date_stru.dir/build

CMakeFiles/9024_date_stru.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\9024_date_stru.dir\cmake_clean.cmake
.PHONY : CMakeFiles/9024_date_stru.dir/clean

CMakeFiles/9024_date_stru.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\9024 date stru" "D:\9024 date stru" "D:\9024 date stru\cmake-build-debug" "D:\9024 date stru\cmake-build-debug" "D:\9024 date stru\cmake-build-debug\CMakeFiles\9024_date_stru.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/9024_date_stru.dir/depend
