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
    Levels/Castle.cpp
    Levels/MedievalRuins.cpp
    Managers/ButtonsManager.cpp
    Managers/ScreenManager.cpp
    Managers/StateManager.cpp
    Managers/CollisionManager.cpp
    Managers/EventsManager.cpp
    Managers/GraphicManager.cpp
    Mementos/Memento.cpp
    Mementos/LevelMemento.cpp
    Menus/Button.cpp
    Menus/MainMenu.cpp
    Menus/Menu.cpp
    Menus/PauseMenu.cpp
    Menus/Ranking.cpp
    Menus/RankingInsert.cpp
    Menus/TextInputBox.cpp
    MultiplesThreads/Threads.cpp
    MultiplesThreads/ExtraLevel.cpp
    MultiplesThreads/ThreadWitch.cpp
    Lists/PhysicalEntityList.cpp
    PhysicalEntities/Characters/Enemies/Enemy.cpp
    PhysicalEntities/Characters/Enemies/Witch.cpp
    PhysicalEntities/Characters/Enemies/Wolf.cpp
    PhysicalEntities/Characters/Enemies/Dragon.cpp
    PhysicalEntities/Characters/Players/Player.cpp
    PhysicalEntities/Characters/Players/Shrek.cpp
    PhysicalEntities/Characters/Players/Donkey.cpp
    PhysicalEntities/Characters/Character.cpp
    PhysicalEntities/Obstacles/Obstacle.cpp
    PhysicalEntities/Projectiles/Apple.cpp
    PhysicalEntities/Projectiles/Fire.cpp
    PhysicalEntities/Projectiles/Projectile.cpp
    PhysicalEntities/PhysicalEntity.cpp
    Tiles/Tile.cpp
    Tiles/TileMap.cpp
    Tiles/TilesManager.cpp
    Utilities/Color.cpp
    Utilities/Clock.cpp
    Utilities/RandomGenerator.cpp
    State.cpp
    OtherGrandRandomOgre.cpp
    Entity.cpp
)
set(
    HEADERS
    # Lists/List.hpp
    Levels/Level.hpp
    Levels/Castle.hpp
    Levels/MedievalRuins.hpp
    Managers/ButtonsManager.hpp
    Managers/ScreenManager.hpp
    Managers/StateManager.hpp
    Managers/CollisionManager.hpp
    Managers/EventsManager.hpp
    Managers/GraphicManager.hpp
    Mementos/Memento.hpp
    Mementos/LevelMemento.hpp
    Menus/Button.hpp
    Menus/MainMenu.hpp
    Menus/Menu.hpp
    Menus/PauseMenu.hpp
    Menus/Ranking.hpp
    Menus/RankingInsert.hpp
    Menus/TextInputBox.hpp
    MultiplesThreads/Threads.hpp
    MultiplesThreads/ExtraLevel.hpp
    MultiplesThreads/ThreadWitch.hpp
    Lists/PhysicalEntityList.hpp
    PhysicalEntities/Characters/Enemies/Dragon.hpp
    PhysicalEntities/Characters/Enemies/Enemy.hpp
    PhysicalEntities/Characters/Enemies/Witch.hpp
    PhysicalEntities/Characters/Enemies/Wolf.hpp
    PhysicalEntities/Characters/Players/Player.hpp
    PhysicalEntities/Characters/Players/Shrek.hpp
    PhysicalEntities/Characters/Players/Donkey.hpp
    PhysicalEntities/Characters/Character.hpp
    PhysicalEntities/Obstacles/Obstacle.hpp
    PhysicalEntities/Projectiles/Apple.hpp
    PhysicalEntities/Projectiles/Fire.hpp
    PhysicalEntities/Projectiles/Projectile.hpp
    PhysicalEntities/PhysicalEntity.hpp
    Tiles/Tile.hpp
    Tiles/TileMap.hpp
    Tiles/TilesManager.hpp
    Utilities/Clock.hpp
    Utilities/Color.hpp
    Utilities/RandomGenerator.hpp
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


