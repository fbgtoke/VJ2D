# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_SOURCE_DIR = /home/kilian/Downloads/VJ/VJ2D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kilian/Downloads/VJ/VJ2D

# Include any dependencies generated for this target.
include CMakeFiles/Bubble.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bubble.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bubble.dir/flags.make

CMakeFiles/Bubble.dir/BubbleBoard.cpp.o: CMakeFiles/Bubble.dir/flags.make
CMakeFiles/Bubble.dir/BubbleBoard.cpp.o: BubbleBoard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bubble.dir/BubbleBoard.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bubble.dir/BubbleBoard.cpp.o -c /home/kilian/Downloads/VJ/VJ2D/BubbleBoard.cpp

CMakeFiles/Bubble.dir/BubbleBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bubble.dir/BubbleBoard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kilian/Downloads/VJ/VJ2D/BubbleBoard.cpp > CMakeFiles/Bubble.dir/BubbleBoard.cpp.i

CMakeFiles/Bubble.dir/BubbleBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bubble.dir/BubbleBoard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kilian/Downloads/VJ/VJ2D/BubbleBoard.cpp -o CMakeFiles/Bubble.dir/BubbleBoard.cpp.s

CMakeFiles/Bubble.dir/BubbleBoard.cpp.o.requires:

.PHONY : CMakeFiles/Bubble.dir/BubbleBoard.cpp.o.requires

CMakeFiles/Bubble.dir/BubbleBoard.cpp.o.provides: CMakeFiles/Bubble.dir/BubbleBoard.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/BubbleBoard.cpp.o.provides.build
.PHONY : CMakeFiles/Bubble.dir/BubbleBoard.cpp.o.provides

CMakeFiles/Bubble.dir/BubbleBoard.cpp.o.provides.build: CMakeFiles/Bubble.dir/BubbleBoard.cpp.o


CMakeFiles/Bubble.dir/Player.cpp.o: CMakeFiles/Bubble.dir/flags.make
CMakeFiles/Bubble.dir/Player.cpp.o: Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Bubble.dir/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bubble.dir/Player.cpp.o -c /home/kilian/Downloads/VJ/VJ2D/Player.cpp

CMakeFiles/Bubble.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bubble.dir/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kilian/Downloads/VJ/VJ2D/Player.cpp > CMakeFiles/Bubble.dir/Player.cpp.i

CMakeFiles/Bubble.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bubble.dir/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kilian/Downloads/VJ/VJ2D/Player.cpp -o CMakeFiles/Bubble.dir/Player.cpp.s

CMakeFiles/Bubble.dir/Player.cpp.o.requires:

.PHONY : CMakeFiles/Bubble.dir/Player.cpp.o.requires

CMakeFiles/Bubble.dir/Player.cpp.o.provides: CMakeFiles/Bubble.dir/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Player.cpp.o.provides.build
.PHONY : CMakeFiles/Bubble.dir/Player.cpp.o.provides

CMakeFiles/Bubble.dir/Player.cpp.o.provides.build: CMakeFiles/Bubble.dir/Player.cpp.o


CMakeFiles/Bubble.dir/Sprite.cpp.o: CMakeFiles/Bubble.dir/flags.make
CMakeFiles/Bubble.dir/Sprite.cpp.o: Sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Bubble.dir/Sprite.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bubble.dir/Sprite.cpp.o -c /home/kilian/Downloads/VJ/VJ2D/Sprite.cpp

CMakeFiles/Bubble.dir/Sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bubble.dir/Sprite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kilian/Downloads/VJ/VJ2D/Sprite.cpp > CMakeFiles/Bubble.dir/Sprite.cpp.i

CMakeFiles/Bubble.dir/Sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bubble.dir/Sprite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kilian/Downloads/VJ/VJ2D/Sprite.cpp -o CMakeFiles/Bubble.dir/Sprite.cpp.s

CMakeFiles/Bubble.dir/Sprite.cpp.o.requires:

.PHONY : CMakeFiles/Bubble.dir/Sprite.cpp.o.requires

CMakeFiles/Bubble.dir/Sprite.cpp.o.provides: CMakeFiles/Bubble.dir/Sprite.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Sprite.cpp.o.provides.build
.PHONY : CMakeFiles/Bubble.dir/Sprite.cpp.o.provides

CMakeFiles/Bubble.dir/Sprite.cpp.o.provides.build: CMakeFiles/Bubble.dir/Sprite.cpp.o


CMakeFiles/Bubble.dir/TileMap.cpp.o: CMakeFiles/Bubble.dir/flags.make
CMakeFiles/Bubble.dir/TileMap.cpp.o: TileMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Bubble.dir/TileMap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bubble.dir/TileMap.cpp.o -c /home/kilian/Downloads/VJ/VJ2D/TileMap.cpp

CMakeFiles/Bubble.dir/TileMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bubble.dir/TileMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kilian/Downloads/VJ/VJ2D/TileMap.cpp > CMakeFiles/Bubble.dir/TileMap.cpp.i

CMakeFiles/Bubble.dir/TileMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bubble.dir/TileMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kilian/Downloads/VJ/VJ2D/TileMap.cpp -o CMakeFiles/Bubble.dir/TileMap.cpp.s

CMakeFiles/Bubble.dir/TileMap.cpp.o.requires:

.PHONY : CMakeFiles/Bubble.dir/TileMap.cpp.o.requires

CMakeFiles/Bubble.dir/TileMap.cpp.o.provides: CMakeFiles/Bubble.dir/TileMap.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/TileMap.cpp.o.provides.build
.PHONY : CMakeFiles/Bubble.dir/TileMap.cpp.o.provides

CMakeFiles/Bubble.dir/TileMap.cpp.o.provides.build: CMakeFiles/Bubble.dir/TileMap.cpp.o


CMakeFiles/Bubble.dir/Texture.cpp.o: CMakeFiles/Bubble.dir/flags.make
CMakeFiles/Bubble.dir/Texture.cpp.o: Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Bubble.dir/Texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bubble.dir/Texture.cpp.o -c /home/kilian/Downloads/VJ/VJ2D/Texture.cpp

CMakeFiles/Bubble.dir/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bubble.dir/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kilian/Downloads/VJ/VJ2D/Texture.cpp > CMakeFiles/Bubble.dir/Texture.cpp.i

CMakeFiles/Bubble.dir/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bubble.dir/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kilian/Downloads/VJ/VJ2D/Texture.cpp -o CMakeFiles/Bubble.dir/Texture.cpp.s

CMakeFiles/Bubble.dir/Texture.cpp.o.requires:

.PHONY : CMakeFiles/Bubble.dir/Texture.cpp.o.requires

CMakeFiles/Bubble.dir/Texture.cpp.o.provides: CMakeFiles/Bubble.dir/Texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Texture.cpp.o.provides.build
.PHONY : CMakeFiles/Bubble.dir/Texture.cpp.o.provides

CMakeFiles/Bubble.dir/Texture.cpp.o.provides.build: CMakeFiles/Bubble.dir/Texture.cpp.o


CMakeFiles/Bubble.dir/Scene.cpp.o: CMakeFiles/Bubble.dir/flags.make
CMakeFiles/Bubble.dir/Scene.cpp.o: Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Bubble.dir/Scene.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bubble.dir/Scene.cpp.o -c /home/kilian/Downloads/VJ/VJ2D/Scene.cpp

CMakeFiles/Bubble.dir/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bubble.dir/Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kilian/Downloads/VJ/VJ2D/Scene.cpp > CMakeFiles/Bubble.dir/Scene.cpp.i

CMakeFiles/Bubble.dir/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bubble.dir/Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kilian/Downloads/VJ/VJ2D/Scene.cpp -o CMakeFiles/Bubble.dir/Scene.cpp.s

CMakeFiles/Bubble.dir/Scene.cpp.o.requires:

.PHONY : CMakeFiles/Bubble.dir/Scene.cpp.o.requires

CMakeFiles/Bubble.dir/Scene.cpp.o.provides: CMakeFiles/Bubble.dir/Scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Scene.cpp.o.provides.build
.PHONY : CMakeFiles/Bubble.dir/Scene.cpp.o.provides

CMakeFiles/Bubble.dir/Scene.cpp.o.provides.build: CMakeFiles/Bubble.dir/Scene.cpp.o


CMakeFiles/Bubble.dir/Shader.cpp.o: CMakeFiles/Bubble.dir/flags.make
CMakeFiles/Bubble.dir/Shader.cpp.o: Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Bubble.dir/Shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bubble.dir/Shader.cpp.o -c /home/kilian/Downloads/VJ/VJ2D/Shader.cpp

CMakeFiles/Bubble.dir/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bubble.dir/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kilian/Downloads/VJ/VJ2D/Shader.cpp > CMakeFiles/Bubble.dir/Shader.cpp.i

CMakeFiles/Bubble.dir/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bubble.dir/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kilian/Downloads/VJ/VJ2D/Shader.cpp -o CMakeFiles/Bubble.dir/Shader.cpp.s

CMakeFiles/Bubble.dir/Shader.cpp.o.requires:

.PHONY : CMakeFiles/Bubble.dir/Shader.cpp.o.requires

CMakeFiles/Bubble.dir/Shader.cpp.o.provides: CMakeFiles/Bubble.dir/Shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Shader.cpp.o.provides.build
.PHONY : CMakeFiles/Bubble.dir/Shader.cpp.o.provides

CMakeFiles/Bubble.dir/Shader.cpp.o.provides.build: CMakeFiles/Bubble.dir/Shader.cpp.o


CMakeFiles/Bubble.dir/ShaderProgram.cpp.o: CMakeFiles/Bubble.dir/flags.make
CMakeFiles/Bubble.dir/ShaderProgram.cpp.o: ShaderProgram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Bubble.dir/ShaderProgram.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bubble.dir/ShaderProgram.cpp.o -c /home/kilian/Downloads/VJ/VJ2D/ShaderProgram.cpp

CMakeFiles/Bubble.dir/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bubble.dir/ShaderProgram.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kilian/Downloads/VJ/VJ2D/ShaderProgram.cpp > CMakeFiles/Bubble.dir/ShaderProgram.cpp.i

CMakeFiles/Bubble.dir/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bubble.dir/ShaderProgram.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kilian/Downloads/VJ/VJ2D/ShaderProgram.cpp -o CMakeFiles/Bubble.dir/ShaderProgram.cpp.s

CMakeFiles/Bubble.dir/ShaderProgram.cpp.o.requires:

.PHONY : CMakeFiles/Bubble.dir/ShaderProgram.cpp.o.requires

CMakeFiles/Bubble.dir/ShaderProgram.cpp.o.provides: CMakeFiles/Bubble.dir/ShaderProgram.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/ShaderProgram.cpp.o.provides.build
.PHONY : CMakeFiles/Bubble.dir/ShaderProgram.cpp.o.provides

CMakeFiles/Bubble.dir/ShaderProgram.cpp.o.provides.build: CMakeFiles/Bubble.dir/ShaderProgram.cpp.o


CMakeFiles/Bubble.dir/Game.cpp.o: CMakeFiles/Bubble.dir/flags.make
CMakeFiles/Bubble.dir/Game.cpp.o: Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Bubble.dir/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bubble.dir/Game.cpp.o -c /home/kilian/Downloads/VJ/VJ2D/Game.cpp

CMakeFiles/Bubble.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bubble.dir/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kilian/Downloads/VJ/VJ2D/Game.cpp > CMakeFiles/Bubble.dir/Game.cpp.i

CMakeFiles/Bubble.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bubble.dir/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kilian/Downloads/VJ/VJ2D/Game.cpp -o CMakeFiles/Bubble.dir/Game.cpp.s

CMakeFiles/Bubble.dir/Game.cpp.o.requires:

.PHONY : CMakeFiles/Bubble.dir/Game.cpp.o.requires

CMakeFiles/Bubble.dir/Game.cpp.o.provides: CMakeFiles/Bubble.dir/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Game.cpp.o.provides.build
.PHONY : CMakeFiles/Bubble.dir/Game.cpp.o.provides

CMakeFiles/Bubble.dir/Game.cpp.o.provides.build: CMakeFiles/Bubble.dir/Game.cpp.o


CMakeFiles/Bubble.dir/main.cpp.o: CMakeFiles/Bubble.dir/flags.make
CMakeFiles/Bubble.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Bubble.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bubble.dir/main.cpp.o -c /home/kilian/Downloads/VJ/VJ2D/main.cpp

CMakeFiles/Bubble.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bubble.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kilian/Downloads/VJ/VJ2D/main.cpp > CMakeFiles/Bubble.dir/main.cpp.i

CMakeFiles/Bubble.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bubble.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kilian/Downloads/VJ/VJ2D/main.cpp -o CMakeFiles/Bubble.dir/main.cpp.s

CMakeFiles/Bubble.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Bubble.dir/main.cpp.o.requires

CMakeFiles/Bubble.dir/main.cpp.o.provides: CMakeFiles/Bubble.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Bubble.dir/main.cpp.o.provides

CMakeFiles/Bubble.dir/main.cpp.o.provides.build: CMakeFiles/Bubble.dir/main.cpp.o


# Object files for target Bubble
Bubble_OBJECTS = \
"CMakeFiles/Bubble.dir/BubbleBoard.cpp.o" \
"CMakeFiles/Bubble.dir/Player.cpp.o" \
"CMakeFiles/Bubble.dir/Sprite.cpp.o" \
"CMakeFiles/Bubble.dir/TileMap.cpp.o" \
"CMakeFiles/Bubble.dir/Texture.cpp.o" \
"CMakeFiles/Bubble.dir/Scene.cpp.o" \
"CMakeFiles/Bubble.dir/Shader.cpp.o" \
"CMakeFiles/Bubble.dir/ShaderProgram.cpp.o" \
"CMakeFiles/Bubble.dir/Game.cpp.o" \
"CMakeFiles/Bubble.dir/main.cpp.o"

# External object files for target Bubble
Bubble_EXTERNAL_OBJECTS =

Bubble: CMakeFiles/Bubble.dir/BubbleBoard.cpp.o
Bubble: CMakeFiles/Bubble.dir/Player.cpp.o
Bubble: CMakeFiles/Bubble.dir/Sprite.cpp.o
Bubble: CMakeFiles/Bubble.dir/TileMap.cpp.o
Bubble: CMakeFiles/Bubble.dir/Texture.cpp.o
Bubble: CMakeFiles/Bubble.dir/Scene.cpp.o
Bubble: CMakeFiles/Bubble.dir/Shader.cpp.o
Bubble: CMakeFiles/Bubble.dir/ShaderProgram.cpp.o
Bubble: CMakeFiles/Bubble.dir/Game.cpp.o
Bubble: CMakeFiles/Bubble.dir/main.cpp.o
Bubble: CMakeFiles/Bubble.dir/build.make
Bubble: /usr/lib/x86_64-linux-gnu/libGLU.so
Bubble: /usr/lib/x86_64-linux-gnu/libGL.so
Bubble: /usr/lib/x86_64-linux-gnu/libglut.so
Bubble: /usr/lib/x86_64-linux-gnu/libXmu.so
Bubble: /usr/lib/x86_64-linux-gnu/libXi.so
Bubble: /usr/lib/x86_64-linux-gnu/libGLEW.so
Bubble: /usr/lib/libSOIL.so
Bubble: CMakeFiles/Bubble.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kilian/Downloads/VJ/VJ2D/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Bubble"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bubble.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bubble.dir/build: Bubble

.PHONY : CMakeFiles/Bubble.dir/build

CMakeFiles/Bubble.dir/requires: CMakeFiles/Bubble.dir/BubbleBoard.cpp.o.requires
CMakeFiles/Bubble.dir/requires: CMakeFiles/Bubble.dir/Player.cpp.o.requires
CMakeFiles/Bubble.dir/requires: CMakeFiles/Bubble.dir/Sprite.cpp.o.requires
CMakeFiles/Bubble.dir/requires: CMakeFiles/Bubble.dir/TileMap.cpp.o.requires
CMakeFiles/Bubble.dir/requires: CMakeFiles/Bubble.dir/Texture.cpp.o.requires
CMakeFiles/Bubble.dir/requires: CMakeFiles/Bubble.dir/Scene.cpp.o.requires
CMakeFiles/Bubble.dir/requires: CMakeFiles/Bubble.dir/Shader.cpp.o.requires
CMakeFiles/Bubble.dir/requires: CMakeFiles/Bubble.dir/ShaderProgram.cpp.o.requires
CMakeFiles/Bubble.dir/requires: CMakeFiles/Bubble.dir/Game.cpp.o.requires
CMakeFiles/Bubble.dir/requires: CMakeFiles/Bubble.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Bubble.dir/requires

CMakeFiles/Bubble.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bubble.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bubble.dir/clean

CMakeFiles/Bubble.dir/depend:
	cd /home/kilian/Downloads/VJ/VJ2D && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kilian/Downloads/VJ/VJ2D /home/kilian/Downloads/VJ/VJ2D /home/kilian/Downloads/VJ/VJ2D /home/kilian/Downloads/VJ/VJ2D /home/kilian/Downloads/VJ/VJ2D/CMakeFiles/Bubble.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bubble.dir/depend

