#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

#include "Background.hpp"
#include "../Entity.hpp"
#include "../Managers/CollisionManager.hpp"
#include "../Managers/EventsManager.hpp"
#include "../Mementos/LevelMemento.hpp"
#include "../Lists/PhysicalEntityList.hpp"
#include "../Tiles/TilesManager.hpp"
#include "../PhysicalEntities/Characters/Players/Shrek.hpp"
#include "../PhysicalEntities/Characters/Players/Donkey.hpp"
#include "../PhysicalEntities/PhysicalEntity.hpp"
#include "../State.hpp"
#include "../Utilities/Clock.hpp"

// #define PATH_BACKGROUND_MEDIEVALRUINS "../assets/level1/Background_01.png"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        class Level : public Entity , public State, public Mementos::LevelMemento
        {
        protected:
            // Atributo do gerenciador de colisões criado para o jogo.
            Managers::CollisionManager collisionManager;
            // Atributo do gerenciador de eventos criado para o jogo.
            // Managers::EventsManager eventsManager;
            Managers::EventsManager *pEventsManager;
            // Atributo referente a lista de entidades físicas.
            Lists::PhysicalEntityList players;

            // Atributo que aponta para a classe do player Shrek.
            PhysicalEntities::Characters::Players::Shrek *player1;
            // Atributo que aponta para a classe do player Donkey.
            PhysicalEntities::Characters::Players::Donkey *player2;

            Background backgroundImage;

            // Atributo do gerenciador de tiles criado para o jogo.
            Tiles::TilesManager *tilesManager;
            // Atributo que indica a chave única do evento de fechar a window do jogo.
            unsigned int idClosedWindow;
            // Atributo que indica a chave única do evento de ESC.
            unsigned int idGoToMenu;
            // Atributo de um relógio que será útil para verificação do tempo.
            Utilities::MyClock clock;

        public:
            // Construtora da classe Level.
            Level();
            Level(Tiles::TilesManager *_tilesManager, PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr, PhysicalEntities::Characters::Players::Donkey *_player2 = nullptr, Background _backgroundImage = "");
            // Destrutora da classe Level.
            virtual ~Level();
            // Método run virtual puro -> TORNA CLASSE ABSTRATA.
            int run();
            virtual void initialize() = 0;
            // Método que gerencia as colisões nas fases.
            void handleCollisions();
            // Método que gerencia os eventos nas fases.
            void handleEvents();

        private:
            // Método encarregado de encerrar processo do jogo caso o evento de fechar a janela do jogo tenha ocorrido.
            void closedWindowButton(const sf::Event &event);
            void goToMenuButton(const sf::Event &event);

        protected:
            void setGameCode(int _gameCode);
            int gameCode;
        };
    }
}
#endif