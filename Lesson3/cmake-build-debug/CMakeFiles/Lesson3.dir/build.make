# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/maxim/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/maxim/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lesson3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lesson3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lesson3.dir/flags.make

CMakeFiles/Lesson3.dir/main.cpp.o: CMakeFiles/Lesson3.dir/flags.make
CMakeFiles/Lesson3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lesson3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lesson3.dir/main.cpp.o -c /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/main.cpp

CMakeFiles/Lesson3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lesson3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/main.cpp > CMakeFiles/Lesson3.dir/main.cpp.i

CMakeFiles/Lesson3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lesson3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/main.cpp -o CMakeFiles/Lesson3.dir/main.cpp.s

CMakeFiles/Lesson3.dir/values.cpp.o: CMakeFiles/Lesson3.dir/flags.make
CMakeFiles/Lesson3.dir/values.cpp.o: ../values.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lesson3.dir/values.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lesson3.dir/values.cpp.o -c /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/values.cpp

CMakeFiles/Lesson3.dir/values.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lesson3.dir/values.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/values.cpp > CMakeFiles/Lesson3.dir/values.cpp.i

CMakeFiles/Lesson3.dir/values.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lesson3.dir/values.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/values.cpp -o CMakeFiles/Lesson3.dir/values.cpp.s

# Object files for target Lesson3
Lesson3_OBJECTS = \
"CMakeFiles/Lesson3.dir/main.cpp.o" \
"CMakeFiles/Lesson3.dir/values.cpp.o"

# External object files for target Lesson3
Lesson3_EXTERNAL_OBJECTS =

Lesson3: CMakeFiles/Lesson3.dir/main.cpp.o
Lesson3: CMakeFiles/Lesson3.dir/values.cpp.o
Lesson3: CMakeFiles/Lesson3.dir/build.make
Lesson3: CMakeFiles/Lesson3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lesson3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lesson3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lesson3.dir/build: Lesson3

.PHONY : CMakeFiles/Lesson3.dir/build

CMakeFiles/Lesson3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lesson3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lesson3.dir/clean

CMakeFiles/Lesson3.dir/depend:
	cd /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3 /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3 /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/cmake-build-debug /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/cmake-build-debug /home/maxim/ProjectC++/Project_GeekBrains/CourseC++/HomeTask/Lesson3/cmake-build-debug/CMakeFiles/Lesson3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lesson3.dir/depend

