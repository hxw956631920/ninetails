# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/baldwey/个人程序/ninetails

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/baldwey/个人程序/ninetails

# Include any dependencies generated for this target.
include shader/CMakeFiles/Shader.dir/depend.make

# Include the progress variables for this target.
include shader/CMakeFiles/Shader.dir/progress.make

# Include the compile flags for this target's objects.
include shader/CMakeFiles/Shader.dir/flags.make

shader/CMakeFiles/Shader.dir/LoadShaders.cpp.o: shader/CMakeFiles/Shader.dir/flags.make
shader/CMakeFiles/Shader.dir/LoadShaders.cpp.o: shader/LoadShaders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/baldwey/个人程序/ninetails/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object shader/CMakeFiles/Shader.dir/LoadShaders.cpp.o"
	cd /Users/baldwey/个人程序/ninetails/shader && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Shader.dir/LoadShaders.cpp.o -c /Users/baldwey/个人程序/ninetails/shader/LoadShaders.cpp

shader/CMakeFiles/Shader.dir/LoadShaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shader.dir/LoadShaders.cpp.i"
	cd /Users/baldwey/个人程序/ninetails/shader && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/baldwey/个人程序/ninetails/shader/LoadShaders.cpp > CMakeFiles/Shader.dir/LoadShaders.cpp.i

shader/CMakeFiles/Shader.dir/LoadShaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shader.dir/LoadShaders.cpp.s"
	cd /Users/baldwey/个人程序/ninetails/shader && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/baldwey/个人程序/ninetails/shader/LoadShaders.cpp -o CMakeFiles/Shader.dir/LoadShaders.cpp.s

# Object files for target Shader
Shader_OBJECTS = \
"CMakeFiles/Shader.dir/LoadShaders.cpp.o"

# External object files for target Shader
Shader_EXTERNAL_OBJECTS =

shader/libShader.a: shader/CMakeFiles/Shader.dir/LoadShaders.cpp.o
shader/libShader.a: shader/CMakeFiles/Shader.dir/build.make
shader/libShader.a: shader/CMakeFiles/Shader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/baldwey/个人程序/ninetails/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libShader.a"
	cd /Users/baldwey/个人程序/ninetails/shader && $(CMAKE_COMMAND) -P CMakeFiles/Shader.dir/cmake_clean_target.cmake
	cd /Users/baldwey/个人程序/ninetails/shader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Shader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
shader/CMakeFiles/Shader.dir/build: shader/libShader.a

.PHONY : shader/CMakeFiles/Shader.dir/build

shader/CMakeFiles/Shader.dir/clean:
	cd /Users/baldwey/个人程序/ninetails/shader && $(CMAKE_COMMAND) -P CMakeFiles/Shader.dir/cmake_clean.cmake
.PHONY : shader/CMakeFiles/Shader.dir/clean

shader/CMakeFiles/Shader.dir/depend:
	cd /Users/baldwey/个人程序/ninetails && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/baldwey/个人程序/ninetails /Users/baldwey/个人程序/ninetails/shader /Users/baldwey/个人程序/ninetails /Users/baldwey/个人程序/ninetails/shader /Users/baldwey/个人程序/ninetails/shader/CMakeFiles/Shader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : shader/CMakeFiles/Shader.dir/depend

