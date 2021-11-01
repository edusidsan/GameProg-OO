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
    Lists/PhysicalEntityList.cpp
    Managers/EventsManager.cpp
    Managers/GraphicManager.cpp
    PhysicalEntities/PhysicalEntity.cpp
    PhysicalEntities/Characters/Character.cpp
    PhysicalEntities/Characters/Enemies/Enemy.cpp
    PhysicalEntities/Characters/Players/Shrek.cpp
    OtherGrandRandomOgre.cpp
    Entity.cpp
)
set(
    HEADERS
    # Lists/List.hpp
    Lists/PhysicalEntityList.hpp
    Managers/EventsManager.hpp
    Managers/GraphicManager.hpp
    PhysicalEntities/PhysicalEntity.hpp
    PhysicalEntities/Characters/Character.hpp
    PhysicalEntities/Characters/Enemies/Enemy.hpp
    PhysicalEntities/Characters/Players/Shrek.hpp
    Utilities/Vector2D.hpp
    OtherGrandRandomOgre.hpp
    Entity.hpp
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


