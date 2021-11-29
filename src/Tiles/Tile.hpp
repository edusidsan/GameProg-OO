#ifndef _TILES_HPP_
#define _TILES_HPP_

#include "../Utilities/Vector2D.hpp"
#include "../Managers/GraphicManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Tiles // Namespace do Pacote Tiles.
    {
        class Tile
        {
        private:
            // Utiliza o padrão de projeto Singleton.
            Managers::GraphicManager *pGraphicManager;
            const int id;
            const char *filePath;
            const Utilities::gameVector2F dimension;

        public:
            // Construtora da classe Tile.
            Tile(const int _id = 0, const char *_filePath = nullptr, Utilities::gameVector2F _dimension = {32.0f, 32.0f});
            // Destrutora da classe Tile.
            virtual ~Tile();
            virtual void initialize();
            void draw(const Utilities::gameVector2F position) const;
            const int getId() const;
            virtual void collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2U position);
        };
    }
}
#endif