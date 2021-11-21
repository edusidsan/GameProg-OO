#include "TilesManager.hpp"
#include "../Managers/CollisionManager.hpp"
#include "../Managers/EventsManager.hpp"
#include "../Managers/GraphicManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Tiles // Namespace do Pacote Tiles.
    {

        TilesManager::TilesManager(std::vector<Tile *> _tiles, float TileSide, Utilities::myVector2F _tilesDimension, const char *_filePath) : tiles{_tiles},
                                                                                                                               tileSide{TileSide},
                                                                                                                               tilesDimension{_tilesDimension},
                                                                                                                               filePath{_filePath},
                                                                                                                               tileMap{_filePath}
                                                                                                                               //tileMap{*(new TileMap(filepath, this))}
        {
        }
        TilesManager::~TilesManager()
        {
            std::vector<Tile *>::iterator it = tiles.begin();
            Tile *t = nullptr;
            while (it != tiles.end())
            {
                t = (*it);
                delete t;
                it++;
            }
            t = nullptr;
        }
        void TilesManager::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em)
        {
            std::vector<Tile *>::iterator it = tiles.begin();
            while (it != tiles.end())
            {
                (*it)->initialize(gm, em);
                it++;
            }
        }
        void TilesManager::draw(Managers::GraphicManager &gm) const
        {
            // for (unsigned int i = 0; i < tilesDimension.coordY; ++i)
            for (unsigned int i = 0; i < tileMap.getTileMapDimension().coordY; ++i)
            {
                // for (unsigned int j = 0; j < tilesDimension.coordX; ++j)
                for (unsigned int j = 0; j < tileMap.getTileMapDimension().coordX; ++j)
                {
                    // std::cout << tilesDimension.coordX << std::endl;
                    // std::cout << "tileMap[" << i << "][" << j << "] - 1: " << tileMap[i][j] - 1 << std::endl;
                    short index = tileMap[i][j] - 1;
                    if (index >= 0 && index < (long)tiles.size())
                        if (index >= 0)
                        {
                            tiles[index]->draw(gm, mapToScreenPosition(Utilities::myVector2U{j, i}));
                        }
                }
            }
        }

        std::vector<TilesManager::tilesManagerAttributes> TilesManager::checkCollisions(const int id, Utilities::myVector2F position, Utilities::myVector2F dimension)
        {
            int up = (int)floor((position.coordY - dimension.coordY / 2) / tilesDimension.coordY);
            int down = (int)ceil((position.coordY + dimension.coordY / 2) / tilesDimension.coordY);
            int left = (int)floor((position.coordX - dimension.coordX / 2) / tilesDimension.coordX);
            int right = (int)ceil((position.coordX + dimension.coordX / 2) / tilesDimension.coordX);

            std::vector<TilesManager::tilesManagerAttributes> collision;

            //objeto parcialmente fora do mapa: é ignorado.
            if (up < 0 || left < 0 || down >= (int)tileMap.getTileMapDimension().coordY || left >= (int)tileMap.getTileMapDimension().coordX)
            {
                return collision;
            }

            for (int i = up; i < down; ++i)
            {
                for (int j = left; j < right; ++j)
                {
                    short indice = tileMap[i][j] - 1; // o -1 é um offset, pois 0 no formato do tilemap indica a falta de um tile e não o tile no índice 0
                    if (0 <= indice && indice < (long)tiles.size())
                    {
                        Tile *t = tiles[indice];

                        t->collided(id, position, {(unsigned int)j, (unsigned int)i});

                        collision.push_back({t->getId(), mapToScreenPosition({(unsigned int)j, (unsigned int)i}), tilesDimension});
                    }
                }
            }
            return collision;
        }

        const Utilities::myVector2F TilesManager::mapToScreenPosition(const Utilities::myVector2U pos) const
        {
            // std::cout << tilesDimension.operator*(0.5f) + Utilities::myVector2F(tilesDimension.coordX * pos.coordX, tilesDimension.coordY * pos.coordY) << std::endl;
            return tilesDimension.operator*(0.5f) + Utilities::myVector2F(tilesDimension.coordX * pos.coordX, tilesDimension.coordY * pos.coordY);
        }
        const TileMap* TilesManager::getTileMap() const {
            return &tileMap;
        }
        const std::vector<Utilities::myVector2F>& TilesManager::getEnemySpawns() const {
            return enemySpawns;
    }
        void TilesManager::randomTilesPlace(){
            tileMap.loadTileMap(filePath);

            for (unsigned i = 0; i < tileMap.getTileMapDimension().coordY; ++i) {
                for (unsigned j = 0; j < tileMap.getTileMapDimension().coordX; ++j) {
                    if (tileMap[i][j] == 51 || (i > 0 && tileMap[i][j] == 14 && tileMap[i-1][j] == 6)) {
                        // enemy spawn point
                        enemySpawns.push_back(Utilities::myVector2F(j, i - 1) * tileSide);
          }  
                }
            }
        }
    }
}