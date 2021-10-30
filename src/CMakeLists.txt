cmake_minimum_required(VERSION 3.15)
project(OgrO VERSION 0.1.0)
# project(OgrO CXX)

set(SFML_DIR "../lib/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics network audio)

###############################################################################
add_library(main)
# Create a sources variable with a link to all cpp files to compile
set(
    SOURCES
    OtherGrandRandomOgre.cpp
    Entities/Character.cpp
    Lists/ListCharacters.cpp
    Managers/GraphicManager.cpp
)
set(
    HEADERS
    OtherGrandRandomOgre.hpp
    Entities/Character.hpp
    Lists/ListCharacters.hpp
    Managers/GraphicManager.hpp
    Utilities/Vector2D.hpp
    Utilities/Vector2DMethods.hpp
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
add_executable(OgrO)

target_sources(
    main
    PRIVATE
        main.cpp
)
target_link_libraries(
    OgrO 
    PRIVATE
        main
)
###############################################################################


