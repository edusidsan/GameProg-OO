#include "Entity.hpp"
#include "Managers/ScreenManager.hpp"
#include "Levels/Level.hpp"

namespace OgrO // Namespace com o nome do jogo.
{

    Levels::Level *Entity::currentLevel = nullptr;

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
    void Entity::initLevel(Levels::Level *level)
    {
        currentLevel = level;
        initialize();
    }
    void Entity::initialize()
    {
    }

    void Entity::setLevel(Levels::Level *_currentLevel)
    {
        currentLevel = _currentLevel;
    }
    Levels::Level *Entity::getLevel() const
    {
        return currentLevel;
    }
    const int Entity::getId() const
    {
        return id;
    }

    // void Entity::run()
    // {
    // }

}