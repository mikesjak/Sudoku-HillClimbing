# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.26.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.26.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/jakubmikes/Repositories/BI-ZUM/Semestral Work"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jakubmikes/Repositories/BI-ZUM/Semestral Work"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.26.0/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.26.0/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/jakubmikes/Repositories/BI-ZUM/Semestral Work/CMakeFiles" "/Users/jakubmikes/Repositories/BI-ZUM/Semestral Work//CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/jakubmikes/Repositories/BI-ZUM/Semestral Work/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Semestral_Work

# Build rule for target.
Semestral_Work: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Semestral_Work
.PHONY : Semestral_Work

# fast build rule for target.
Semestral_Work/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/build
.PHONY : Semestral_Work/fast

CGrid.o: CGrid.cpp.o
.PHONY : CGrid.o

# target to build an object file
CGrid.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/CGrid.cpp.o
.PHONY : CGrid.cpp.o

CGrid.i: CGrid.cpp.i
.PHONY : CGrid.i

# target to preprocess a source file
CGrid.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/CGrid.cpp.i
.PHONY : CGrid.cpp.i

CGrid.s: CGrid.cpp.s
.PHONY : CGrid.s

# target to generate assembly for a file
CGrid.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/CGrid.cpp.s
.PHONY : CGrid.cpp.s

CHillClimber.o: CHillClimber.cpp.o
.PHONY : CHillClimber.o

# target to build an object file
CHillClimber.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/CHillClimber.cpp.o
.PHONY : CHillClimber.cpp.o

CHillClimber.i: CHillClimber.cpp.i
.PHONY : CHillClimber.i

# target to preprocess a source file
CHillClimber.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/CHillClimber.cpp.i
.PHONY : CHillClimber.cpp.i

CHillClimber.s: CHillClimber.cpp.s
.PHONY : CHillClimber.s

# target to generate assembly for a file
CHillClimber.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/CHillClimber.cpp.s
.PHONY : CHillClimber.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/main.cpp.s
.PHONY : main.cpp.s

solver.o: solver.cpp.o
.PHONY : solver.o

# target to build an object file
solver.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/solver.cpp.o
.PHONY : solver.cpp.o

solver.i: solver.cpp.i
.PHONY : solver.i

# target to preprocess a source file
solver.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/solver.cpp.i
.PHONY : solver.cpp.i

solver.s: solver.cpp.s
.PHONY : solver.s

# target to generate assembly for a file
solver.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Semestral_Work.dir/build.make CMakeFiles/Semestral_Work.dir/solver.cpp.s
.PHONY : solver.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Semestral_Work"
	@echo "... CGrid.o"
	@echo "... CGrid.i"
	@echo "... CGrid.s"
	@echo "... CHillClimber.o"
	@echo "... CHillClimber.i"
	@echo "... CHillClimber.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... solver.o"
	@echo "... solver.i"
	@echo "... solver.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
