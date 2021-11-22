#include "Entity.hpp"
#include "Managers/ScreenManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    // Construtora da classe Entity. Atributos default configurados
    Entity::Entity() : id{0},
                       pGraphicManager(Managers::GraphicManager::getInstance())
    {
    }
    // Destrutora da classe Entity.
    Entity::~Entity()
    {
    }
    // Método desenhar de Entity.
    void Entity::draw()
    {
    }

    // Método desenhar de Entity.
    void Entity::init()
    {
    }

    void Entity::setLevel(Levels::Level *_currentLevel)
    {
        currentLevel = _currentLevel;
    }

    // void Entity::run()
    // {
    // }

}