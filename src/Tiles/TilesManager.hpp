#ifndef _TILESMANAGER_HPP_
#define _TILESMANAGER_HPP_

#include "Tile.hpp"
#include "TileMap.hpp"
#include "../Utilities/Vector2D.hpp"
#include <vector>

namespace OgrO // Namespace com o nome do jogo.
{
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
                const Utilities::myVector2F position;
                const Utilities::myVector2F dimension;
            };

        private:
            std::vector<Tile *> tiles;
            Utilities::myVector2F tilesDimension;
            const char *filePath;
            TileMap tileMap;

        public:
            TilesManager(std::vector<Tile *> _tiles = {}, Utilities::myVector2F _tilesDimension = {0.0f, 0.0f}, const char *_filePath = nullptr);
            ~TilesManager();
            void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em);
            void draw(Managers::GraphicManager &gm) const;
            std::vector<tilesManagerAttributes> checkCollisions(const int id, Utilities::myVector2F position, Utilities::myVector2F dimension);

        private:
            const Utilities::myVector2F mapToScreenPosition (const Utilities::myVector2U pos) const;
        };
    }
}

#endif