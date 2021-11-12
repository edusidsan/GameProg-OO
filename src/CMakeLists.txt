cmake_minimum_required(VERSION 3.15)
# project(OgrO VERSION 0.1.0)
project(OgrO CXX)

set(SFML_DIR "../lib/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics network audio)

# set(nlohmann_json_DIR "../lib/JSON/cmake")
# find_package(nlohmann_json)

###############################################################################
add_library(main)
# Create a sources variable with a link to all cpp files to compile
set(
    SOURCES
    Levels/Level.cpp
    Levels/MedievalRuins.cpp
    Managers/ScreenManager.cpp
    Managers/StateManager.cpp
    Managers/CollisionManager.cpp
    Managers/EventsManager.cpp
    Managers/GraphicManager.cpp
    Menus/Menu.cpp
    Lists/PhysicalEntityList.cpp
    PhysicalEntities/Characters/Enemies/Enemy.cpp
    PhysicalEntities/Characters/Players/Shrek.cpp
    PhysicalEntities/Characters/Character.cpp
    PhysicalEntities/Obstacles/Obstacle.cpp
    PhysicalEntities/PhysicalEntity.cpp
    Tiles/Tile.cpp
    Tiles/TileMap.cpp
    Tiles/TilesManager.cpp
    State.cpp
    OtherGrandRandomOgre.cpp
    Entity.cpp
)
set(
    HEADERS
    # Lists/List.hpp
    Levels/Level.hpp
    Levels/MedievalRuins.hpp
    Managers/ScreenManager.hpp
    Managers/StateManager.hpp
    Managers/CollisionManager.hpp
    Managers/EventsManager.hpp
    Managers/GraphicManager.hpp
    Menus/Menu.hpp
    Lists/PhysicalEntityList.hpp
    PhysicalEntities/Characters/Enemies/Enemy.hpp
    PhysicalEntities/Characters/Players/Shrek.hpp
    PhysicalEntities/Characters/Character.hpp
    PhysicalEntities/Obstacles/Obstacle.hpp
    PhysicalEntities/PhysicalEntity.hpp
    Tiles/Tile.hpp
    Tiles/TileMap.hpp
    Tiles/TilesManager.hpp
    json.hpp
    # Utilities/Vector2D.hpp
    State.hpp
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
        # nlohmann_json
)
###############################################################################


