#include "Tile.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Tiles // Namespace do Pacote Tiles.
    {
        // Construtora da classe Tile.
        Tile::Tile(const int _id, const char *_filePath, Utilities::gameVector2F _dimension) : id{_id},
                                                                                             filePath{_filePath},
                                                                                             dimension{_dimension}
        {
        }
        // Destrutora da classe Tile.
        Tile::~Tile()
        {
        }
        void Tile::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em)
        {
            gm.loadAsset(filePath);
        }
        void Tile::draw(Managers::GraphicManager &gm, const Utilities::gameVector2F position) const
        {
            gm.draw(filePath, position);
        }
        const int Tile::getId() const
        {
            return id;
        }
        void Tile::collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2U position)
        {
        }
    }
}