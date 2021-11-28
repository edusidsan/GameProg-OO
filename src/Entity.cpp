#include "Entity.hpp"
#include "Managers/ScreenManager.hpp"
#include "Levels/Level.hpp"

namespace OgrO // Namespace com o nome do jogo.
{

    Levels::Level *Entity::currentLevel = nullptr;

    // Construtora da classe Entity. Atributos default configurados
    Entity::Entity() : pGraphicManager(Managers::GraphicManager::getInstance()),
                       pEventsManager(Managers::EventsManager::getInstance()),
                       pCollisionManager(Managers::CollisionManager::getInstance()),
                       id(0)

    {
    }
    // Destrutora da classe Entity.
    Entity::~Entity()
    {
        currentLevel = nullptr;
    }
    // Método desenhar de Entity.
    void Entity::initLevel(Levels::Level *level)
    {
        currentLevel = level;
        initialize();
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
}