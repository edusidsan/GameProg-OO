#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

#include "../Entity.hpp"
#include "../Managers/CollisionManager.hpp"
#include "../Managers/EventsManager.hpp"
#include "../Lists/PhysicalEntityList.hpp"

#define PATH_BACKGROUND_MEDIEVALRUINS "../assets/level1/Background_01.png"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        class Level : public Entity
        {
        protected:
            // Atributo do gerenciador de colisões criado para o jogo.
            Managers::CollisionManager collisionManager;
            // Atributo do gerenciador de eventos criado para o jogo.
            Managers::EventsManager eventsManager;
            // Atributo referente a lista de entidades físicas.
            Lists::PhysicalEntityList players;

        public:
            // Construtora da classe Level.
            Level();
            // Destrutora da classe Level.
            virtual ~Level();
            // Método run virtual puro -> TORNA CLASSE ABSTRATA.
            virtual int run() = 0;
            // Método que gerencia as colisões nas fases.
            void handleCollisions();
            // Método que gerencia os eventos nas fases.
            void handleEvents();
        };
    }
}
#endif