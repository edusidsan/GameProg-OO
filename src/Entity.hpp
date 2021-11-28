#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "Managers/GraphicManager.hpp"
#include "Managers/EventsManager.hpp"
#include "Managers/CollisionManager.hpp"
#include "Mementos/Memento.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels
    {
        class Level;
    }
    class Entity : public Mementos::Memento
    {
    protected:
        // Atributo que aponta para o gerenciador gráfico criado para o jogo.
        Managers::GraphicManager *pGraphicManager;
        Managers::EventsManager *pEventsManager;
        Managers::CollisionManager *pCollisionManager;
        static Levels::Level *currentLevel;
        int id;

    public:
        // Construtora da classe Entity. Atributos default configurados
        Entity();
        // Destrutora da classe Entity.
        virtual ~Entity();
        void initLevel(Levels::Level *level);
        virtual void initialize() = 0;
        virtual int run() = 0;
        void setLevel(Levels::Level *_currentLevel);
        Levels::Level *getLevel() const;
        const int getId() const;
    };

}
#endif