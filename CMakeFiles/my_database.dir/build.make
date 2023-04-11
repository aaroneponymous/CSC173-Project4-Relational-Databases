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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD"

# Include any dependencies generated for this target.
include CMakeFiles/my_database.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_database.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_database.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_database.dir/flags.make

CMakeFiles/my_database.dir/main.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/main.c.o: main.c
CMakeFiles/my_database.dir/main.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_database.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/main.c.o -MF CMakeFiles/my_database.dir/main.c.o.d -o CMakeFiles/my_database.dir/main.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/main.c"

CMakeFiles/my_database.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/main.c" > CMakeFiles/my_database.dir/main.c.i

CMakeFiles/my_database.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/main.c" -o CMakeFiles/my_database.dir/main.c.s

CMakeFiles/my_database.dir/Database.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/Database.c.o: Database.c
CMakeFiles/my_database.dir/Database.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/my_database.dir/Database.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/Database.c.o -MF CMakeFiles/my_database.dir/Database.c.o.d -o CMakeFiles/my_database.dir/Database.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/Database.c"

CMakeFiles/my_database.dir/Database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/Database.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/Database.c" > CMakeFiles/my_database.dir/Database.c.i

CMakeFiles/my_database.dir/Database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/Database.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/Database.c" -o CMakeFiles/my_database.dir/Database.c.s

CMakeFiles/my_database.dir/GHVDDelete.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/GHVDDelete.c.o: GHVDDelete.c
CMakeFiles/my_database.dir/GHVDDelete.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/my_database.dir/GHVDDelete.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/GHVDDelete.c.o -MF CMakeFiles/my_database.dir/GHVDDelete.c.o.d -o CMakeFiles/my_database.dir/GHVDDelete.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GHVDDelete.c"

CMakeFiles/my_database.dir/GHVDDelete.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/GHVDDelete.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GHVDDelete.c" > CMakeFiles/my_database.dir/GHVDDelete.c.i

CMakeFiles/my_database.dir/GHVDDelete.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/GHVDDelete.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GHVDDelete.c" -o CMakeFiles/my_database.dir/GHVDDelete.c.s

CMakeFiles/my_database.dir/GHVDLookUp.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/GHVDLookUp.c.o: GHVDLookUp.c
CMakeFiles/my_database.dir/GHVDLookUp.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/my_database.dir/GHVDLookUp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/GHVDLookUp.c.o -MF CMakeFiles/my_database.dir/GHVDLookUp.c.o.d -o CMakeFiles/my_database.dir/GHVDLookUp.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GHVDLookUp.c"

CMakeFiles/my_database.dir/GHVDLookUp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/GHVDLookUp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GHVDLookUp.c" > CMakeFiles/my_database.dir/GHVDLookUp.c.i

CMakeFiles/my_database.dir/GHVDLookUp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/GHVDLookUp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GHVDLookUp.c" -o CMakeFiles/my_database.dir/GHVDLookUp.c.s

CMakeFiles/my_database.dir/GHVDRelation.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/GHVDRelation.c.o: GHVDRelation.c
CMakeFiles/my_database.dir/GHVDRelation.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/my_database.dir/GHVDRelation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/GHVDRelation.c.o -MF CMakeFiles/my_database.dir/GHVDRelation.c.o.d -o CMakeFiles/my_database.dir/GHVDRelation.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GHVDRelation.c"

CMakeFiles/my_database.dir/GHVDRelation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/GHVDRelation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GHVDRelation.c" > CMakeFiles/my_database.dir/GHVDRelation.c.i

CMakeFiles/my_database.dir/GHVDRelation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/GHVDRelation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GHVDRelation.c" -o CMakeFiles/my_database.dir/GHVDRelation.c.s

CMakeFiles/my_database.dir/GPGRelation.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/GPGRelation.c.o: GPGRelation.c
CMakeFiles/my_database.dir/GPGRelation.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/my_database.dir/GPGRelation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/GPGRelation.c.o -MF CMakeFiles/my_database.dir/GPGRelation.c.o.d -o CMakeFiles/my_database.dir/GPGRelation.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GPGRelation.c"

CMakeFiles/my_database.dir/GPGRelation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/GPGRelation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GPGRelation.c" > CMakeFiles/my_database.dir/GPGRelation.c.i

CMakeFiles/my_database.dir/GPGRelation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/GPGRelation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/GPGRelation.c" -o CMakeFiles/my_database.dir/GPGRelation.c.s

CMakeFiles/my_database.dir/HashTable.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/HashTable.c.o: HashTable.c
CMakeFiles/my_database.dir/HashTable.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/my_database.dir/HashTable.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/HashTable.c.o -MF CMakeFiles/my_database.dir/HashTable.c.o.d -o CMakeFiles/my_database.dir/HashTable.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/HashTable.c"

CMakeFiles/my_database.dir/HashTable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/HashTable.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/HashTable.c" > CMakeFiles/my_database.dir/HashTable.c.i

CMakeFiles/my_database.dir/HashTable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/HashTable.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/HashTable.c" -o CMakeFiles/my_database.dir/HashTable.c.s

CMakeFiles/my_database.dir/PNBRelation.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/PNBRelation.c.o: PNBRelation.c
CMakeFiles/my_database.dir/PNBRelation.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/my_database.dir/PNBRelation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/PNBRelation.c.o -MF CMakeFiles/my_database.dir/PNBRelation.c.o.d -o CMakeFiles/my_database.dir/PNBRelation.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/PNBRelation.c"

CMakeFiles/my_database.dir/PNBRelation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/PNBRelation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/PNBRelation.c" > CMakeFiles/my_database.dir/PNBRelation.c.i

CMakeFiles/my_database.dir/PNBRelation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/PNBRelation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/PNBRelation.c" -o CMakeFiles/my_database.dir/PNBRelation.c.s

CMakeFiles/my_database.dir/Query.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/Query.c.o: Query.c
CMakeFiles/my_database.dir/Query.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/my_database.dir/Query.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/Query.c.o -MF CMakeFiles/my_database.dir/Query.c.o.d -o CMakeFiles/my_database.dir/Query.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/Query.c"

CMakeFiles/my_database.dir/Query.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/Query.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/Query.c" > CMakeFiles/my_database.dir/Query.c.i

CMakeFiles/my_database.dir/Query.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/Query.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/Query.c" -o CMakeFiles/my_database.dir/Query.c.s

CMakeFiles/my_database.dir/RelationalAlgebra.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/RelationalAlgebra.c.o: RelationalAlgebra.c
CMakeFiles/my_database.dir/RelationalAlgebra.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/my_database.dir/RelationalAlgebra.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/RelationalAlgebra.c.o -MF CMakeFiles/my_database.dir/RelationalAlgebra.c.o.d -o CMakeFiles/my_database.dir/RelationalAlgebra.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/RelationalAlgebra.c"

CMakeFiles/my_database.dir/RelationalAlgebra.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/RelationalAlgebra.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/RelationalAlgebra.c" > CMakeFiles/my_database.dir/RelationalAlgebra.c.i

CMakeFiles/my_database.dir/RelationalAlgebra.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/RelationalAlgebra.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/RelationalAlgebra.c" -o CMakeFiles/my_database.dir/RelationalAlgebra.c.s

CMakeFiles/my_database.dir/TCRelation.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/TCRelation.c.o: TCRelation.c
CMakeFiles/my_database.dir/TCRelation.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/my_database.dir/TCRelation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/TCRelation.c.o -MF CMakeFiles/my_database.dir/TCRelation.c.o.d -o CMakeFiles/my_database.dir/TCRelation.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/TCRelation.c"

CMakeFiles/my_database.dir/TCRelation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/TCRelation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/TCRelation.c" > CMakeFiles/my_database.dir/TCRelation.c.i

CMakeFiles/my_database.dir/TCRelation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/TCRelation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/TCRelation.c" -o CMakeFiles/my_database.dir/TCRelation.c.s

CMakeFiles/my_database.dir/TPNRelation.c.o: CMakeFiles/my_database.dir/flags.make
CMakeFiles/my_database.dir/TPNRelation.c.o: TPNRelation.c
CMakeFiles/my_database.dir/TPNRelation.c.o: CMakeFiles/my_database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/my_database.dir/TPNRelation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/my_database.dir/TPNRelation.c.o -MF CMakeFiles/my_database.dir/TPNRelation.c.o.d -o CMakeFiles/my_database.dir/TPNRelation.c.o -c "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/TPNRelation.c"

CMakeFiles/my_database.dir/TPNRelation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_database.dir/TPNRelation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/TPNRelation.c" > CMakeFiles/my_database.dir/TPNRelation.c.i

CMakeFiles/my_database.dir/TPNRelation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_database.dir/TPNRelation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/TPNRelation.c" -o CMakeFiles/my_database.dir/TPNRelation.c.s

# Object files for target my_database
my_database_OBJECTS = \
"CMakeFiles/my_database.dir/main.c.o" \
"CMakeFiles/my_database.dir/Database.c.o" \
"CMakeFiles/my_database.dir/GHVDDelete.c.o" \
"CMakeFiles/my_database.dir/GHVDLookUp.c.o" \
"CMakeFiles/my_database.dir/GHVDRelation.c.o" \
"CMakeFiles/my_database.dir/GPGRelation.c.o" \
"CMakeFiles/my_database.dir/HashTable.c.o" \
"CMakeFiles/my_database.dir/PNBRelation.c.o" \
"CMakeFiles/my_database.dir/Query.c.o" \
"CMakeFiles/my_database.dir/RelationalAlgebra.c.o" \
"CMakeFiles/my_database.dir/TCRelation.c.o" \
"CMakeFiles/my_database.dir/TPNRelation.c.o"

# External object files for target my_database
my_database_EXTERNAL_OBJECTS =

executable_file_name: CMakeFiles/my_database.dir/main.c.o
executable_file_name: CMakeFiles/my_database.dir/Database.c.o
executable_file_name: CMakeFiles/my_database.dir/GHVDDelete.c.o
executable_file_name: CMakeFiles/my_database.dir/GHVDLookUp.c.o
executable_file_name: CMakeFiles/my_database.dir/GHVDRelation.c.o
executable_file_name: CMakeFiles/my_database.dir/GPGRelation.c.o
executable_file_name: CMakeFiles/my_database.dir/HashTable.c.o
executable_file_name: CMakeFiles/my_database.dir/PNBRelation.c.o
executable_file_name: CMakeFiles/my_database.dir/Query.c.o
executable_file_name: CMakeFiles/my_database.dir/RelationalAlgebra.c.o
executable_file_name: CMakeFiles/my_database.dir/TCRelation.c.o
executable_file_name: CMakeFiles/my_database.dir/TPNRelation.c.o
executable_file_name: CMakeFiles/my_database.dir/build.make
executable_file_name: CMakeFiles/my_database.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Linking C executable executable_file_name"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_database.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_database.dir/build: executable_file_name
.PHONY : CMakeFiles/my_database.dir/build

CMakeFiles/my_database.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_database.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_database.dir/clean

CMakeFiles/my_database.dir/depend:
	cd "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD" "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD" "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD" "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD" "/mnt/c/Aaron's Folder/University of Rochester/CSC173_Computational_Formal_Systems/Projects/Project_4/Project_4_RD/CMakeFiles/my_database.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/my_database.dir/depend

