#include "Castle.hpp"
#include "../PhysicalEntities/Characters/Enemies/Witch.hpp"
#include "../PhysicalEntities/Characters/Enemies/Wolf.hpp"
#include "../PhysicalEntities/Characters/Enemies/Dragon.hpp"
#include "../PhysicalEntities/Projectiles/Apple.hpp"
#include "../PhysicalEntities/Projectiles/Fire.hpp"
#include "../Managers/ScreenManager.hpp"
#include "../Tiles/TilesManager.hpp"
//#include "../Utilities/RandomGenerator.hpp"
#include <fstream>
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        // Construtora da classe MedievalRuins.
        Castle::Castle(PhysicalEntities::Characters::Players::Shrek *_player1, PhysicalEntities::Characters::Players::Donkey *_player2, const std::string _backgroundPath) : Level(new Tiles::TilesManager{
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
                                                                                                                                                                                       "../map/Castle.json"},
                                                                                                                                                                                   _player1, _player2, "../assets/level1/Background2.png")

        {
            id = 2000;
        }
        // Destrutora da classe Castle.
        Castle::~Castle()
        {
        }

        void Castle::initialize()
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
            std::vector<Utilities::myVector2F> spawnsWolfs = tilesManager->getEnemySpawnsWolfs();
            std::vector<Utilities::myVector2F> spawnsWitchs = tilesManager->getEnemySpawnsWitchs();
            int nEnemies = Utilities::RandomGenerator::getInstance()->getRandomIntInRange(5, 10);
            for (int i = 0; i < nEnemies; i++)
            {
                int idx = Utilities::RandomGenerator::getInstance()->getRandomIntInRange(0, spawnsWitchs.size());
                Utilities::myVector2F pos = spawnsWitchs[idx] + Utilities::myVector2F(32.0f, -76.0f);
                players.insert(new PhysicalEntities::Characters::Enemies::Witch(pos, Utilities::myVector2F(0, 10)));

                idx = Utilities::RandomGenerator::getInstance()->getRandomIntInRange(0, spawnsWolfs.size());
                pos = spawnsWolfs[idx] + Utilities::myVector2F(32.0f, 32.0f);
                players.insert(new PhysicalEntities::Characters::Enemies::Wolf(pos, Utilities::myVector2F(20, 0)));
            }

            players.insert(new PhysicalEntities::Characters::Enemies::Dragon(Utilities::myVector2F(2463, 1212), Utilities::myVector2F(0, 0)));
            // Carrega as imagens nas entidades físicas e inicializa os gerenciadores de eventos.
            players.initializePhysicalEntities(*pEventsManager, collisionManager);

            if (player1)
                player1->setPosition(Utilities::myVector2F(64.0f, 230.0f));
            if (player2)
                player2->setPosition(Utilities::myVector2F(64.0f, 230.0f));
        }
        nlohmann::json Castle::toJSON()
        {
            nlohmann::json json;

            json["players"] = players.toJSON();

            return json;
        }

        void Castle::load(const std::string &path)
        {
            std::ifstream file(path);
            if (file.fail())
            {
                throw "arquivo nao encontrado!";
            }
            nlohmann::json j;
            file >> j;

            for (nlohmann::json player : j["players"])
            {

                switch (static_cast<int>(player["id"]))
                {
                case 100:
                    if (player1)
                    {
                        player1->initializeJSON(player);
                        players.insert(player1);
                    }
                    break;
                case 101:
                    if (player2)
                    {
                        player2->initializeJSON(player);
                        players.insert(player2);
                    }
                    break;
                case 102:
                {

                    players.insert(new PhysicalEntities::Characters::Enemies::Witch(player));
                    break;
                }
                case 103:
                {

                    players.insert(new PhysicalEntities::Characters::Enemies::Wolf(player));
                    break;
                }
                case 104:
                {

                    players.insert(new PhysicalEntities::Characters::Enemies::Dragon(player));
                    break;
                }
                case 200:
                {

                    players.insert(new PhysicalEntities::Projectiles::Apple(player));
                    break;
                }
                case 201:
                {

                    players.insert(new PhysicalEntities::Projectiles::Fire(player));
                    break;
                }
                default:
                    break;
                }
            }
            players.initializePhysicalEntities(*pEventsManager, collisionManager);
            file.close();
        }
    }
}