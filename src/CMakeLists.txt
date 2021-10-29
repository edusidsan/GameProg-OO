cmake_minimum_required(VERSION 3.15)
project(gameOO VERSION 0.1.0)
# project(gameOO CXX)

set(SFML_DIR "../lib/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics network audio)

###############################################################################
add_library(main)
# Create a sources variable with a link to all cpp files to compile
set(
    SOURCES
    Principal.cpp
    Personagem.cpp
    Lists/listPersonagens.cpp
)
set(
    HEADERS
    Principal.hpp
    Personagem.hpp
    Lists/listPersonagens.hpp
)
target_sources(
    main 
    PUBLIC
        ${HEADERS}
    PRIVATE
        ${SOURCES}
)
target_link_libraries(
    main 
    PRIVATE
        sfml-graphics
)
###############################################################################

###############################################################################
add_executable(gameOO)

target_sources(
    main
    PRIVATE
        main.cpp
)
target_link_libraries(
    gameOO 
    PRIVATE
        main
)
###############################################################################


