cmake_minimum_required(VERSION 3.12)
project(shoot_me C)

set(CMAKE_C_STANDARD 99)


# Set include directory (no longer use include/ after this)
include_directories(include)
# Get all .c file located in src directory and name it src_file also get .h located in include
file(GLOB_RECURSE src_files src/*.c *.h)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Get SDL lib
find_package(SDL REQUIRED)
# Check with a sdl variable
if(!SDL_FOUND)
    message(FATAL_ERROR "Lib SDL not found")
endif()
# Get SDL_image lib
find_package(SDL_image)
if(!SDL_IMAGE_FOUND)
    message(FATAL_ERROR "Lib SDL_image not found")
endif ()

find_package(SDL_ttf)
if(!SDL_TTF_FOUND)
    message(FATAL_ERROR "lib ttf not found")
endif()

find_package(FMOD)
if(!FMOD_FOUND)
    message(FATAL_ERROR "lib fmod not found")
endif()
# Included directories from a path variable
include_directories(${SDL_INCLUDE_DIR} ${SDL_IMAGE_INCLUDE_DIRS} ${SDL_TTF_INCLUDE_DIRS} ${FMOD_INCLUDE_DIR})

add_executable(shoot_me main.c include/define.h src/utilities.c include/utilities.h)

# On link notre librairie avec notre projet le nom de la lib et encore fournit via une variable mise à disposition
target_link_libraries(shoot_me ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARIES} ${SDL_TTF_LIBRARIES} ${FMOD_LIBRARY})