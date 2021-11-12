#ifndef _TILES_HPP_
#define _TILES_HPP_

#include "../Utilities/Vector2D.hpp"
#include "../Managers/EventsManager.hpp"
#include "../Managers/GraphicManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Tiles // Namespace do Pacote Tiles.
    {
        class Tile
        {
        private:
            const int id;
            const char *filePath;
            const Utilities::myVector2F dimension;

        public:
            // Construtora da classe Tile.
            Tile(const int _id = 0, const char *_filePath = nullptr, Utilities::myVector2F _dimension = {32.0f, 32.0f});
            // Destrutora da classe Tile.
            virtual ~Tile();
            virtual void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em);
            void draw(Managers::GraphicManager &gm, const Utilities::myVector2F position) const;
            const int getId() const;
            virtual void collided(int idOther, Utilities::myVector2F positionOther, Utilities::myVector2U position);
        };
    }
}
#endif