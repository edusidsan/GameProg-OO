#include "Entity.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    // Construtora da classe Entity. Atributos default configurados
    Entity::Entity() : id{0}
    {
    }
    // Entity::Entity(Managers::GraphicManager &gm) : id{0}
    // //    pGraphicManager(&gm)
    // {
    //     pGraphicManager = &gm;
    // }
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