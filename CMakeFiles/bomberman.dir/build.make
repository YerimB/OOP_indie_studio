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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexis/Tek2/INDIE/OOP_indie_studio_2019

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexis/Tek2/INDIE/OOP_indie_studio_2019

# Include any dependencies generated for this target.
include CMakeFiles/bomberman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bomberman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bomberman.dir/flags.make

CMakeFiles/bomberman.dir/Sources/InputManager.cpp.o: CMakeFiles/bomberman.dir/flags.make
CMakeFiles/bomberman.dir/Sources/InputManager.cpp.o: Sources/InputManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexis/Tek2/INDIE/OOP_indie_studio_2019/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bomberman.dir/Sources/InputManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bomberman.dir/Sources/InputManager.cpp.o -c /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/InputManager.cpp

CMakeFiles/bomberman.dir/Sources/InputManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bomberman.dir/Sources/InputManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/InputManager.cpp > CMakeFiles/bomberman.dir/Sources/InputManager.cpp.i

CMakeFiles/bomberman.dir/Sources/InputManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bomberman.dir/Sources/InputManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/InputManager.cpp -o CMakeFiles/bomberman.dir/Sources/InputManager.cpp.s

CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.o: CMakeFiles/bomberman.dir/flags.make
CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.o: Sources/Thread/Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexis/Tek2/INDIE/OOP_indie_studio_2019/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.o -c /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/Thread/Thread.cpp

CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/Thread/Thread.cpp > CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.i

CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/Thread/Thread.cpp -o CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.s

CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.o: CMakeFiles/bomberman.dir/flags.make
CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.o: Sources/Thread/ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexis/Tek2/INDIE/OOP_indie_studio_2019/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.o -c /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/Thread/ThreadPool.cpp

CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/Thread/ThreadPool.cpp > CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.i

CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/Thread/ThreadPool.cpp -o CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.s

CMakeFiles/bomberman.dir/Sources/main.cpp.o: CMakeFiles/bomberman.dir/flags.make
CMakeFiles/bomberman.dir/Sources/main.cpp.o: Sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexis/Tek2/INDIE/OOP_indie_studio_2019/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/bomberman.dir/Sources/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bomberman.dir/Sources/main.cpp.o -c /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/main.cpp

CMakeFiles/bomberman.dir/Sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bomberman.dir/Sources/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/main.cpp > CMakeFiles/bomberman.dir/Sources/main.cpp.i

CMakeFiles/bomberman.dir/Sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bomberman.dir/Sources/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/Sources/main.cpp -o CMakeFiles/bomberman.dir/Sources/main.cpp.s

# Object files for target bomberman
bomberman_OBJECTS = \
"CMakeFiles/bomberman.dir/Sources/InputManager.cpp.o" \
"CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.o" \
"CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.o" \
"CMakeFiles/bomberman.dir/Sources/main.cpp.o"

# External object files for target bomberman
bomberman_EXTERNAL_OBJECTS =

bomberman: CMakeFiles/bomberman.dir/Sources/InputManager.cpp.o
bomberman: CMakeFiles/bomberman.dir/Sources/Thread/Thread.cpp.o
bomberman: CMakeFiles/bomberman.dir/Sources/Thread/ThreadPool.cpp.o
bomberman: CMakeFiles/bomberman.dir/Sources/main.cpp.o
bomberman: CMakeFiles/bomberman.dir/build.make
bomberman: CMakeFiles/bomberman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexis/Tek2/INDIE/OOP_indie_studio_2019/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bomberman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bomberman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bomberman.dir/build: bomberman

.PHONY : CMakeFiles/bomberman.dir/build

CMakeFiles/bomberman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bomberman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bomberman.dir/clean

CMakeFiles/bomberman.dir/depend:
	cd /home/alexis/Tek2/INDIE/OOP_indie_studio_2019 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexis/Tek2/INDIE/OOP_indie_studio_2019 /home/alexis/Tek2/INDIE/OOP_indie_studio_2019 /home/alexis/Tek2/INDIE/OOP_indie_studio_2019 /home/alexis/Tek2/INDIE/OOP_indie_studio_2019 /home/alexis/Tek2/INDIE/OOP_indie_studio_2019/CMakeFiles/bomberman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bomberman.dir/depend

