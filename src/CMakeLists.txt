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
    Managers/CollisionManager.cpp
    Managers/EventsManager.cpp
    Managers/GraphicManager.cpp
    Lists/PhysicalEntityList.cpp
    PhysicalEntities/Characters/Enemies/Enemy.cpp
    PhysicalEntities/Characters/Players/Shrek.cpp
    PhysicalEntities/Characters/Character.cpp
    PhysicalEntities/Obstacles/Obstacle.cpp
    PhysicalEntities/PhysicalEntity.cpp
    OtherGrandRandomOgre.cpp
    Entity.cpp
)
set(
    HEADERS
    # Lists/List.hpp
    Managers/CollisionManager.hpp
    Managers/EventsManager.hpp
    Managers/GraphicManager.hpp
    Lists/PhysicalEntityList.hpp
    PhysicalEntities/Characters/Enemies/Enemy.hpp
    PhysicalEntities/Characters/Players/Shrek.hpp
    PhysicalEntities/Characters/Character.hpp
    PhysicalEntities/Obstacles/Obstacle.hpp
    PhysicalEntities/PhysicalEntity.hpp
    # Utilities/Vector2D.hpp
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


