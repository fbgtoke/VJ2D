# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/fabio/Documents/VJ2D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fabio/Documents/VJ2D

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/fabio/Documents/VJ2D/CMakeFiles /home/fabio/Documents/VJ2D/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/fabio/Documents/VJ2D/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Bubble

# Build rule for target.
Bubble: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Bubble
.PHONY : Bubble

# fast build rule for target.
Bubble/fast:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/build
.PHONY : Bubble/fast

BubbleBoard.o: BubbleBoard.cpp.o

.PHONY : BubbleBoard.o

# target to build an object file
BubbleBoard.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/BubbleBoard.cpp.o
.PHONY : BubbleBoard.cpp.o

BubbleBoard.i: BubbleBoard.cpp.i

.PHONY : BubbleBoard.i

# target to preprocess a source file
BubbleBoard.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/BubbleBoard.cpp.i
.PHONY : BubbleBoard.cpp.i

BubbleBoard.s: BubbleBoard.cpp.s

.PHONY : BubbleBoard.s

# target to generate assembly for a file
BubbleBoard.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/BubbleBoard.cpp.s
.PHONY : BubbleBoard.cpp.s

BubbleLevel.o: BubbleLevel.cpp.o

.PHONY : BubbleLevel.o

# target to build an object file
BubbleLevel.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/BubbleLevel.cpp.o
.PHONY : BubbleLevel.cpp.o

BubbleLevel.i: BubbleLevel.cpp.i

.PHONY : BubbleLevel.i

# target to preprocess a source file
BubbleLevel.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/BubbleLevel.cpp.i
.PHONY : BubbleLevel.cpp.i

BubbleLevel.s: BubbleLevel.cpp.s

.PHONY : BubbleLevel.s

# target to generate assembly for a file
BubbleLevel.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/BubbleLevel.cpp.s
.PHONY : BubbleLevel.cpp.s

Cannon.o: Cannon.cpp.o

.PHONY : Cannon.o

# target to build an object file
Cannon.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Cannon.cpp.o
.PHONY : Cannon.cpp.o

Cannon.i: Cannon.cpp.i

.PHONY : Cannon.i

# target to preprocess a source file
Cannon.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Cannon.cpp.i
.PHONY : Cannon.cpp.i

Cannon.s: Cannon.cpp.s

.PHONY : Cannon.s

# target to generate assembly for a file
Cannon.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Cannon.cpp.s
.PHONY : Cannon.cpp.s

FallingBubble.o: FallingBubble.cpp.o

.PHONY : FallingBubble.o

# target to build an object file
FallingBubble.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/FallingBubble.cpp.o
.PHONY : FallingBubble.cpp.o

FallingBubble.i: FallingBubble.cpp.i

.PHONY : FallingBubble.i

# target to preprocess a source file
FallingBubble.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/FallingBubble.cpp.i
.PHONY : FallingBubble.cpp.i

FallingBubble.s: FallingBubble.cpp.s

.PHONY : FallingBubble.s

# target to generate assembly for a file
FallingBubble.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/FallingBubble.cpp.s
.PHONY : FallingBubble.cpp.s

Game.o: Game.cpp.o

.PHONY : Game.o

# target to build an object file
Game.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Game.cpp.o
.PHONY : Game.cpp.o

Game.i: Game.cpp.i

.PHONY : Game.i

# target to preprocess a source file
Game.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Game.cpp.i
.PHONY : Game.cpp.i

Game.s: Game.cpp.s

.PHONY : Game.s

# target to generate assembly for a file
Game.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Game.cpp.s
.PHONY : Game.cpp.s

MovingBubble.o: MovingBubble.cpp.o

.PHONY : MovingBubble.o

# target to build an object file
MovingBubble.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/MovingBubble.cpp.o
.PHONY : MovingBubble.cpp.o

MovingBubble.i: MovingBubble.cpp.i

.PHONY : MovingBubble.i

# target to preprocess a source file
MovingBubble.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/MovingBubble.cpp.i
.PHONY : MovingBubble.cpp.i

MovingBubble.s: MovingBubble.cpp.s

.PHONY : MovingBubble.s

# target to generate assembly for a file
MovingBubble.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/MovingBubble.cpp.s
.PHONY : MovingBubble.cpp.s

Particle.o: Particle.cpp.o

.PHONY : Particle.o

# target to build an object file
Particle.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Particle.cpp.o
.PHONY : Particle.cpp.o

Particle.i: Particle.cpp.i

.PHONY : Particle.i

# target to preprocess a source file
Particle.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Particle.cpp.i
.PHONY : Particle.cpp.i

Particle.s: Particle.cpp.s

.PHONY : Particle.s

# target to generate assembly for a file
Particle.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Particle.cpp.s
.PHONY : Particle.cpp.s

Scene.o: Scene.cpp.o

.PHONY : Scene.o

# target to build an object file
Scene.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Scene.cpp.o
.PHONY : Scene.cpp.o

Scene.i: Scene.cpp.i

.PHONY : Scene.i

# target to preprocess a source file
Scene.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Scene.cpp.i
.PHONY : Scene.cpp.i

Scene.s: Scene.cpp.s

.PHONY : Scene.s

# target to generate assembly for a file
Scene.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Scene.cpp.s
.PHONY : Scene.cpp.s

SceneCredits.o: SceneCredits.cpp.o

.PHONY : SceneCredits.o

# target to build an object file
SceneCredits.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneCredits.cpp.o
.PHONY : SceneCredits.cpp.o

SceneCredits.i: SceneCredits.cpp.i

.PHONY : SceneCredits.i

# target to preprocess a source file
SceneCredits.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneCredits.cpp.i
.PHONY : SceneCredits.cpp.i

SceneCredits.s: SceneCredits.cpp.s

.PHONY : SceneCredits.s

# target to generate assembly for a file
SceneCredits.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneCredits.cpp.s
.PHONY : SceneCredits.cpp.s

SceneFinal.o: SceneFinal.cpp.o

.PHONY : SceneFinal.o

# target to build an object file
SceneFinal.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneFinal.cpp.o
.PHONY : SceneFinal.cpp.o

SceneFinal.i: SceneFinal.cpp.i

.PHONY : SceneFinal.i

# target to preprocess a source file
SceneFinal.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneFinal.cpp.i
.PHONY : SceneFinal.cpp.i

SceneFinal.s: SceneFinal.cpp.s

.PHONY : SceneFinal.s

# target to generate assembly for a file
SceneFinal.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneFinal.cpp.s
.PHONY : SceneFinal.cpp.s

SceneGameOver.o: SceneGameOver.cpp.o

.PHONY : SceneGameOver.o

# target to build an object file
SceneGameOver.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneGameOver.cpp.o
.PHONY : SceneGameOver.cpp.o

SceneGameOver.i: SceneGameOver.cpp.i

.PHONY : SceneGameOver.i

# target to preprocess a source file
SceneGameOver.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneGameOver.cpp.i
.PHONY : SceneGameOver.cpp.i

SceneGameOver.s: SceneGameOver.cpp.s

.PHONY : SceneGameOver.s

# target to generate assembly for a file
SceneGameOver.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneGameOver.cpp.s
.PHONY : SceneGameOver.cpp.s

SceneHelp.o: SceneHelp.cpp.o

.PHONY : SceneHelp.o

# target to build an object file
SceneHelp.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneHelp.cpp.o
.PHONY : SceneHelp.cpp.o

SceneHelp.i: SceneHelp.cpp.i

.PHONY : SceneHelp.i

# target to preprocess a source file
SceneHelp.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneHelp.cpp.i
.PHONY : SceneHelp.cpp.i

SceneHelp.s: SceneHelp.cpp.s

.PHONY : SceneHelp.s

# target to generate assembly for a file
SceneHelp.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneHelp.cpp.s
.PHONY : SceneHelp.cpp.s

SceneMenu.o: SceneMenu.cpp.o

.PHONY : SceneMenu.o

# target to build an object file
SceneMenu.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneMenu.cpp.o
.PHONY : SceneMenu.cpp.o

SceneMenu.i: SceneMenu.cpp.i

.PHONY : SceneMenu.i

# target to preprocess a source file
SceneMenu.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneMenu.cpp.i
.PHONY : SceneMenu.cpp.i

SceneMenu.s: SceneMenu.cpp.s

.PHONY : SceneMenu.s

# target to generate assembly for a file
SceneMenu.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneMenu.cpp.s
.PHONY : SceneMenu.cpp.s

ScenePlay.o: ScenePlay.cpp.o

.PHONY : ScenePlay.o

# target to build an object file
ScenePlay.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/ScenePlay.cpp.o
.PHONY : ScenePlay.cpp.o

ScenePlay.i: ScenePlay.cpp.i

.PHONY : ScenePlay.i

# target to preprocess a source file
ScenePlay.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/ScenePlay.cpp.i
.PHONY : ScenePlay.cpp.i

ScenePlay.s: ScenePlay.cpp.s

.PHONY : ScenePlay.s

# target to generate assembly for a file
ScenePlay.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/ScenePlay.cpp.s
.PHONY : ScenePlay.cpp.s

SceneWin.o: SceneWin.cpp.o

.PHONY : SceneWin.o

# target to build an object file
SceneWin.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneWin.cpp.o
.PHONY : SceneWin.cpp.o

SceneWin.i: SceneWin.cpp.i

.PHONY : SceneWin.i

# target to preprocess a source file
SceneWin.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneWin.cpp.i
.PHONY : SceneWin.cpp.i

SceneWin.s: SceneWin.cpp.s

.PHONY : SceneWin.s

# target to generate assembly for a file
SceneWin.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SceneWin.cpp.s
.PHONY : SceneWin.cpp.s

Shader.o: Shader.cpp.o

.PHONY : Shader.o

# target to build an object file
Shader.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Shader.cpp.o
.PHONY : Shader.cpp.o

Shader.i: Shader.cpp.i

.PHONY : Shader.i

# target to preprocess a source file
Shader.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Shader.cpp.i
.PHONY : Shader.cpp.i

Shader.s: Shader.cpp.s

.PHONY : Shader.s

# target to generate assembly for a file
Shader.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Shader.cpp.s
.PHONY : Shader.cpp.s

ShaderProgram.o: ShaderProgram.cpp.o

.PHONY : ShaderProgram.o

# target to build an object file
ShaderProgram.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/ShaderProgram.cpp.o
.PHONY : ShaderProgram.cpp.o

ShaderProgram.i: ShaderProgram.cpp.i

.PHONY : ShaderProgram.i

# target to preprocess a source file
ShaderProgram.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/ShaderProgram.cpp.i
.PHONY : ShaderProgram.cpp.i

ShaderProgram.s: ShaderProgram.cpp.s

.PHONY : ShaderProgram.s

# target to generate assembly for a file
ShaderProgram.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/ShaderProgram.cpp.s
.PHONY : ShaderProgram.cpp.s

Sprite.o: Sprite.cpp.o

.PHONY : Sprite.o

# target to build an object file
Sprite.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Sprite.cpp.o
.PHONY : Sprite.cpp.o

Sprite.i: Sprite.cpp.i

.PHONY : Sprite.i

# target to preprocess a source file
Sprite.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Sprite.cpp.i
.PHONY : Sprite.cpp.i

Sprite.s: Sprite.cpp.s

.PHONY : Sprite.s

# target to generate assembly for a file
Sprite.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Sprite.cpp.s
.PHONY : Sprite.cpp.s

SpriteBobble.o: SpriteBobble.cpp.o

.PHONY : SpriteBobble.o

# target to build an object file
SpriteBobble.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SpriteBobble.cpp.o
.PHONY : SpriteBobble.cpp.o

SpriteBobble.i: SpriteBobble.cpp.i

.PHONY : SpriteBobble.i

# target to preprocess a source file
SpriteBobble.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SpriteBobble.cpp.i
.PHONY : SpriteBobble.cpp.i

SpriteBobble.s: SpriteBobble.cpp.s

.PHONY : SpriteBobble.s

# target to generate assembly for a file
SpriteBobble.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SpriteBobble.cpp.s
.PHONY : SpriteBobble.cpp.s

SpriteBubble.o: SpriteBubble.cpp.o

.PHONY : SpriteBubble.o

# target to build an object file
SpriteBubble.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SpriteBubble.cpp.o
.PHONY : SpriteBubble.cpp.o

SpriteBubble.i: SpriteBubble.cpp.i

.PHONY : SpriteBubble.i

# target to preprocess a source file
SpriteBubble.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SpriteBubble.cpp.i
.PHONY : SpriteBubble.cpp.i

SpriteBubble.s: SpriteBubble.cpp.s

.PHONY : SpriteBubble.s

# target to generate assembly for a file
SpriteBubble.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/SpriteBubble.cpp.s
.PHONY : SpriteBubble.cpp.s

Text.o: Text.cpp.o

.PHONY : Text.o

# target to build an object file
Text.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Text.cpp.o
.PHONY : Text.cpp.o

Text.i: Text.cpp.i

.PHONY : Text.i

# target to preprocess a source file
Text.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Text.cpp.i
.PHONY : Text.cpp.i

Text.s: Text.cpp.s

.PHONY : Text.s

# target to generate assembly for a file
Text.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Text.cpp.s
.PHONY : Text.cpp.s

Texture.o: Texture.cpp.o

.PHONY : Texture.o

# target to build an object file
Texture.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Texture.cpp.o
.PHONY : Texture.cpp.o

Texture.i: Texture.cpp.i

.PHONY : Texture.i

# target to preprocess a source file
Texture.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Texture.cpp.i
.PHONY : Texture.cpp.i

Texture.s: Texture.cpp.s

.PHONY : Texture.s

# target to generate assembly for a file
Texture.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/Texture.cpp.s
.PHONY : Texture.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/Bubble.dir/build.make CMakeFiles/Bubble.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... Bubble"
	@echo "... BubbleBoard.o"
	@echo "... BubbleBoard.i"
	@echo "... BubbleBoard.s"
	@echo "... BubbleLevel.o"
	@echo "... BubbleLevel.i"
	@echo "... BubbleLevel.s"
	@echo "... Cannon.o"
	@echo "... Cannon.i"
	@echo "... Cannon.s"
	@echo "... FallingBubble.o"
	@echo "... FallingBubble.i"
	@echo "... FallingBubble.s"
	@echo "... Game.o"
	@echo "... Game.i"
	@echo "... Game.s"
	@echo "... MovingBubble.o"
	@echo "... MovingBubble.i"
	@echo "... MovingBubble.s"
	@echo "... Particle.o"
	@echo "... Particle.i"
	@echo "... Particle.s"
	@echo "... Scene.o"
	@echo "... Scene.i"
	@echo "... Scene.s"
	@echo "... SceneCredits.o"
	@echo "... SceneCredits.i"
	@echo "... SceneCredits.s"
	@echo "... SceneFinal.o"
	@echo "... SceneFinal.i"
	@echo "... SceneFinal.s"
	@echo "... SceneGameOver.o"
	@echo "... SceneGameOver.i"
	@echo "... SceneGameOver.s"
	@echo "... SceneHelp.o"
	@echo "... SceneHelp.i"
	@echo "... SceneHelp.s"
	@echo "... SceneMenu.o"
	@echo "... SceneMenu.i"
	@echo "... SceneMenu.s"
	@echo "... ScenePlay.o"
	@echo "... ScenePlay.i"
	@echo "... ScenePlay.s"
	@echo "... SceneWin.o"
	@echo "... SceneWin.i"
	@echo "... SceneWin.s"
	@echo "... Shader.o"
	@echo "... Shader.i"
	@echo "... Shader.s"
	@echo "... ShaderProgram.o"
	@echo "... ShaderProgram.i"
	@echo "... ShaderProgram.s"
	@echo "... Sprite.o"
	@echo "... Sprite.i"
	@echo "... Sprite.s"
	@echo "... SpriteBobble.o"
	@echo "... SpriteBobble.i"
	@echo "... SpriteBobble.s"
	@echo "... SpriteBubble.o"
	@echo "... SpriteBubble.i"
	@echo "... SpriteBubble.s"
	@echo "... Text.o"
	@echo "... Text.i"
	@echo "... Text.s"
	@echo "... Texture.o"
	@echo "... Texture.i"
	@echo "... Texture.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

