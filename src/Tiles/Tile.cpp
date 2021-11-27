#include "Tile.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Tiles // Namespace do Pacote Tiles.
    {
        // Construtora da classe Tile.
        Tile::Tile(const int _id, const char *_filePath, Utilities::gameVector2F _dimension) : pGraphicManager(Managers::GraphicManager::getInstance()),
                                                                                               id{_id},
                                                                                               filePath{_filePath},
                                                                                               dimension{_dimension}
        {
        }
        // Destrutora da classe Tile.
        Tile::~Tile()
        {
            pGraphicManager= nullptr;
            filePath = nullptr;
        }
        void Tile::initialize()
        {
            pGraphicManager->loadAsset(filePath);
        }
        void Tile::draw(const Utilities::gameVector2F position) const
        {
            pGraphicManager->draw(filePath, position);
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