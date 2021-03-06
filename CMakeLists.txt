cmake_minimum_required(VERSION 2.8)

cmake_policy(SET CMP0015 NEW)

execute_process(COMMAND ln -s ../shaders)
execute_process(COMMAND ln -s ../images)
execute_process(COMMAND ln -s ../levels)

set(appName Bubble)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
find_package(SOIL REQUIRED)
find_package(SFML COMPONENTS audio REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})
include_directories(${SOIL_INCLUDE_DIRS})
include_directories(${SFML_INCLUDE_DIRS})

link_directories(${OPENGL_LIBRARY_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})
link_directories(${SOIL_LIBRARY_DIRS})
link_directories(${SFML_LIBRARY_DIRS})

add_executable(${appName} BubbleBoard.h BubbleBoard.cpp BubbleLevel.h BubbleLevel.cpp BubbleType.h Cannon.h Cannon.cpp Explosion.cpp Explosion.h FallingBubble.h FallingBubble.cpp Konami.cpp Konami.h MovingBubble.h MovingBubble.cpp Particle.h Particle.cpp AnimKeyframes.h Sprite.h Sprite.cpp SpriteBobble.h SpriteBobble.cpp SpriteBubble.h SpriteBubble.cpp Texture.h Texture.cpp Scene.h Scene.cpp SceneCredits.h SceneCredits.cpp SceneFinal.cpp SceneFinal.h SceneGameOver.cpp SceneGameOver.h SceneHelp.h SceneHelp.cpp SceneMenu.h SceneMenu.cpp ScenePlay.h ScenePlay.cpp SceneWin.h SceneWin.cpp Shader.h Shader.cpp ShaderProgram.h ShaderProgram.cpp Text.h Text.cpp Game.h Game.cpp main.cpp)

target_link_libraries(${appName} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES} ${SOIL_LIBRARIES} ${FREETYPE_LIBRARIES} ${SFML_LIBRARIES}) # ${GLM_LIBRARIES}



