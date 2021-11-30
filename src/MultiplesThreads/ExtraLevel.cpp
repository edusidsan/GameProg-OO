#include "ExtraLevel.hpp"
#include "../PhysicalEntities/Characters/Enemies/Witch.hpp"
#include "../PhysicalEntities/Characters/Enemies/Wolf.hpp"
#include "../Managers/ScreenManager.hpp"
#include "../Tiles/TilesManager.hpp"
#include "../Utilities/RandomGenerator.hpp"
#include <iterator>
namespace OgrO // Namespace com o nome do jogo.
{
    namespace MultiplesThreads
    {
        ExtraLevel::ExtraLevel(PhysicalEntities::Characters::Players::Shrek *_player1, PhysicalEntities::Characters::Players::Donkey *_player2, const std::string _backgroundPath) : Level(new Tiles::TilesManager{
                                                                                                                                                                                               {
                                                                                                                                                                                                   //  new Tiles::Tile(0, "../assets/level1/Bonus.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(1, "../assets/level1/Brick_01.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(2, "../assets/level1/Brick_02.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(3, "../assets/level1/Bridge_01.png", {16.0f, 16.0f}),
                                                                                                                                                                                                   new Tiles::Tile(4, "../assets/level1/Bridge_02.png", {16.0f, 16.0f}),
                                                                                                                                                                                                   new Tiles::Tile(5, "../assets/level1/Decor_Brick.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(6, "../assets/level1/Decor_Plant.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(7, "../assets/level1/Decor_Ruins_01.png", {120.0f, 120.0f}),
                                                                                                                                                                                                   new Tiles::Tile(8, "../assets/level1/Decor_Ruins_02.png", {120.0f, 120.0f}),
                                                                                                                                                                                                   new Tiles::Tile(9, "../assets/level1/Decor_Statue.png", {64.0f, 64.0f}),
                                                                                                                                                                                                   new Tiles::Tile(10, "../assets/level1/Fence.png", {32.0f, 32.0f}),

                                                                                                                                                                                                   new Tiles::Tile(11, "../assets/level1/Grass_01.png", {32.0f, 16.0f}),
                                                                                                                                                                                                   new Tiles::Tile(12, "../assets/level1/Grass_02.png", {32.0f, 16.0f}),
                                                                                                                                                                                                   new Tiles::Tile(13, "../assets/level1/Ground_01.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(14, "../assets/level1/Ground_02.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(15, "../assets/level1/Ground_03.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(16, "../assets/level1/Ground_04.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(17, "../assets/level1/Ground_05.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(18, "../assets/level1/Ground_06.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(19, "../assets/level1/Ground_07.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(20, "../assets/level1/Ground_08.png", {32.0f, 32.0f}),

                                                                                                                                                                                                   new Tiles::Tile(21, "../assets/level1/Ground_09.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(22, "../assets/level1/Ground_10.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(23, "../assets/level1/Ground_11.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(24, "../assets/level1/Ground_12.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(25, "../assets/level1/Ground_13.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(26, "../assets/level1/Ground-Additional_01.png", {80.0f, 80.0f}),
                                                                                                                                                                                                   new Tiles::Tile(27, "../assets/level1/Ground-Additional_02.png", {80.0f, 80.0f}),
                                                                                                                                                                                                   new Tiles::Tile(28, "../assets/level1/Ground-Additional_03.png", {80.0f, 80.0f}),
                                                                                                                                                                                                   new Tiles::Tile(29, "../assets/level1/Ground-Additional_04.png", {80.0f, 80.0f}),
                                                                                                                                                                                                   new Tiles::Tile(30, "../assets/level1/Ground-Additional_05.png", {32.0f, 80.0f}),

                                                                                                                                                                                                   new Tiles::Tile(31, "../assets/level1/Ground-Additional_06.png", {32.0f, 80.0f}),
                                                                                                                                                                                                   new Tiles::Tile(32, "../assets/level1/Ground-Additional_07.png", {80.0f, 80.0f}),
                                                                                                                                                                                                   new Tiles::Tile(33, "../assets/level1/hotPixel.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(34, "../assets/level1/Ladder.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(35, "../assets/level1/Lion_Bas_Relief.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(36, "../assets/level1/Little_Wreckage.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(37, "../assets/level1/Rock_01.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(38, "../assets/level1/Rock_02.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(39, "../assets/level1/Rock_03.png", {32.0f, 16.0f}),
                                                                                                                                                                                                   new Tiles::Tile(40, "../assets/level1/Rock_04.png", {32.0f, 16.0f}),

                                                                                                                                                                                                   new Tiles::Tile(41, "../assets/level1/Rock_05.png", {16.0f, 16.0f}),
                                                                                                                                                                                                   new Tiles::Tile(42, "../assets/level1/Rock_06.png", {16.0f, 16.0f}),
                                                                                                                                                                                                   new Tiles::Tile(43, "../assets/level1/Rock_07.png", {16.0f, 16.0f}),
                                                                                                                                                                                                   new Tiles::Tile(44, "../assets/level1/Rock_08.png", {16.0f, 16.0f}),
                                                                                                                                                                                                   new Tiles::Tile(45, "../assets/level1/Sign_01.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(46, "../assets/level1/Sign_02.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(47, "../assets/level1/Sign_03.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(48, "../assets/level1/Sign_04.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(49, "../assets/level1/Sign_05.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(50, "../assets/level1/Sign_06.png", {32.0f, 32.0f}),

                                                                                                                                                                                                   new Tiles::Tile(51, "../assets/level1/Spikes.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(52, "../assets/level1/Wooden_Barrel.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(53, "../assets/level1/Wooden_Box.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(54, "../assets/level1/Spring.png", {32.0f, 32.0f}),
                                                                                                                                                                                                   new Tiles::Tile(55, "../assets/level1/NoSpawnGround.png", {32.0f, 32.0f}),
                                                                                                                                                                                               },
                                                                                                                                                                                               32.0f,
                                                                                                                                                                                               {32.0f, 32.0f},
                                                                                                                                                                                               "../map/ExtraLevel.json"},
                                                                                                                                                                                           _player1, _player2, "../assets/level1/Background2.png"),
                                                                                                                                                                                           VectorWitchs()
        {
            pGraphicManager->zoomOut();
        }
        ExtraLevel::~ExtraLevel()
        {
            
            pGraphicManager->zoomIn();
            for (auto &w : VectorWitchs){                
                delete w;
                }            
            VectorWitchs.clear();
        }

        void ExtraLevel::initialize()
        {
            {
                if (player1)
                {
                    players.insert(player1);
                }
                if (player2)
                {
                    players.insert(player2);
                }
                tilesManager->randomTilesPlace();
                std::vector<Utilities::gameVector2F> spawnsWitchs = tilesManager->getEnemySpawnsWitchs();
                Utilities::gameVector2F pos = spawnsWitchs[19] + Utilities::gameVector2F(32.0f, -76.0f);
                VectorWitchs.push_back(new MultiplesThreads::ThreadWitch(pos, Utilities::gameVector2F(0, 10)));
                pos = spawnsWitchs[11] + Utilities::gameVector2F(32.0f, -76.0f);
                VectorWitchs.push_back(new MultiplesThreads::ThreadWitch(pos, Utilities::gameVector2F(0, 10)));
                pos = spawnsWitchs[2] + Utilities::gameVector2F(32.0f, -76.0f);
                VectorWitchs.push_back(new MultiplesThreads::ThreadWitch(pos, Utilities::gameVector2F(0, 10)));
                //Inicialização das Witchs
                for (auto &w : VectorWitchs){
                    w->initialize();
                    w->start();                    
                    w->setPaused(true);
                    }
                
              
                players.initializePhysicalEntities();

                if (player1)
                    player1->setPosition(Utilities::gameVector2F(150.0f, 220.0f));
                if (player2)
                    player2->setPosition(Utilities::gameVector2F(150.0f, 220.0f));
            }
        }
        void ExtraLevel::load(const std::string &path) {}
        int ExtraLevel::run()
        {
            gameCode = Managers::CONTINUE_GAME;
            double t = clock.getTime();
            //desabilitando o pause da witch
            for (auto &w : VectorWitchs){
                w->setPaused(false);
            }

          
            handleEvents();
            pGraphicManager->draw(backgroundPath, Utilities::gameVector2F{800.0f, 280.0f});
            //Update das entidades fisicas
            players.updatePhysicalEntities(t);
            for (auto &w : VectorWitchs){
                w->start();
                // w->update(t);
            }
            handleCollisions();
            //draw das entidades da fase
            tilesManager->draw();
            players.drawPhysicalEntities();
            for (auto &w : VectorWitchs){
                w->draw();
            }
            //habilitando o pause da witch
            for (auto &w : VectorWitchs){
                w->setPaused(true);
                }

            return gameCode;
        }

    }
}
