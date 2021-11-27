#ifndef _TILESMANAGER_HPP_
#define _TILESMANAGER_HPP_

#include "Tile.hpp"
#include "TileMap.hpp"
#include "../Utilities/Vector2D.hpp"
#include <vector>

namespace OgrO // Namespace com o nome do jogo.
{
     namespace Utilities // Namespace do Pacote Utilities.
    {
        class gameVector2D;
    } 
    /*---------------------------- Atribuição de classes para não ocorrer conflito de inclusão recursiva.*/
    namespace Managers // Namespace do Pacote Managers.
    {
        class EventsManager;
        class GraphicManager;
        class CollisionManager;
    }
    /*--------------------------------------------------------------------------------------------------*/
    namespace Tiles // Namespace do Pacote Tiles.
    {
        class TilesManager
        {
        public:
            struct tilesManagerAttributes
            {
                const int id;
                const Utilities::gameVector2F position;
                const Utilities::gameVector2F dimension;
            };

        private:
            std::vector<Tile *> tiles;
            Utilities::gameVector2F tilesDimension;
            const char *filePath;
            TileMap tileMap;
            float tileSide;
            std::vector<Utilities::gameVector2F> enemySpawnsWolfs;
            std::vector<Utilities::gameVector2F> enemySpawnsWitchs;
        public:
            TilesManager(std::vector<Tile *> _tiles = {}, float tileSide = 0, Utilities::gameVector2F _tilesDimension = {0.0f, 0.0f}, const char *_filePath = nullptr);
            ~TilesManager();
            void initialize();
            void draw() const;
            std::vector<tilesManagerAttributes> checkCollisions(const int id, Utilities::gameVector2F position, Utilities::gameVector2F dimension);
            void randomTilesPlace();
            const std::vector<Utilities::gameVector2F>& getEnemySpawnsWolfs() const;
            const std::vector<Utilities::gameVector2F>& getEnemySpawnsWitchs() const;
            const TileMap* getTileMap() const;
        private:
            const Utilities::gameVector2F mapToScreenPosition (const Utilities::gameVector2U pos) const;
            
        };
    }
}

#endif