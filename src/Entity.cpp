#include "Entity.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    // Managers::GraphicManager *Entity::pGraphicManager = nullptr;
    // Construtora da classe Entity. Atributos default configurados
    Entity::Entity() : id{0},
                       pGraphicManager(Managers::GraphicManager::getInstance())
    {
        // pGraphicManager = gm;
    }
    // Destrutora da classe Entity.
    Entity::~Entity()
    {
    }
    // Método desenhar de Entity.
    void Entity::draw()
    {
    }
    // void Entity::setGraphicManager(Managers::GraphicManager &gm)
    // {
    //     pGraphicManager = &gm;
    // }

    // void Entity::run()
    // {
    // }
}