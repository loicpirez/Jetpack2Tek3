cmake_minimum_required(VERSION 3.7)

project(client)

file(STRINGS sources.mk SOURCE_FILES)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -W -pedantic -g")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(SDL_INCLUDE_DIR /usr/include/SDL)
set(SDL_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL.so)

find_package(SDL REQUIRED)

include_directories(include)
include_directories(${SDL_INCLUDE_DIR})


link_libraries(
        ${SDL_LIBRARY}
        ${SDLIMAGE_LIBRARY}
        SDL2
        pthread
)

add_executable(client ${SOURCE_FILES})
target_link_libraries(client ${SDL2_LIBRARY})
