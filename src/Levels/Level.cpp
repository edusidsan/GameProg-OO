#include "Level.hpp"
#include "../Managers/ScreenManager.hpp"
#include "../Utilities/RandomGenerator.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        // Construtora da classe Level.
        Level::Level(Tiles::TilesManager *_tilesManager, PhysicalEntities::Characters::Players::Shrek *_player1, PhysicalEntities::Characters::Players::Donkey *_player2, const std::string _backgroundPath) : Entity(),
                                                                                                                                                                                                               State(),
                                                                                                                                                                                                               Mementos::LevelMemento(),
                                                                                                                                                                                                               collisionManager(),
                                                                                                                                                                                                               pEventsManager(Managers::EventsManager::getInstance()),
                                                                                                                                                                                                               players(),
                                                                                                                                                                                                               player1(_player1),
                                                                                                                                                                                                               player2(_player2),
                                                                                                                                                                                                               backgroundPath(_backgroundPath),
                                                                                                                                                                                                               tilesManager(_tilesManager),
                                                                                                                                                                                                               // lambda-expression.
                                                                                                                                                                                                               idClosedWindow(
                                                                                                                                                                                                                   pEventsManager->addOtherListener([this](const sf::Event &event)
                                                                                                                                                                                                                                                    { closedWindowButton(event); })),
                                                                                                                                                                                                               idGoToMenu(
                                                                                                                                                                                                                   pEventsManager->addKeyboardListener([this](const sf::Event &event)
                                                                                                                                                                                                                                                       { goToMenuButton(event); })),
                                                                                                                                                                                                               clock(),
                                                                                                                                                                                                               gameCode{Managers::continueGame}

        {
            // backgroundImage.initialize();
            pGraphicManager->loadAsset(backgroundPath);
            // Inicializa gerenciador de tiles.
            tilesManager->initialize(*pGraphicManager, *pEventsManager);
            // Atribui ao gerenciador de eventos a window que está sendo utilizada pelo gerenciador gráfico.
            pEventsManager->setWindow(pGraphicManager->getWindow());
            // Atribui ao gerenciador de collisões o endereço do gerenciador de tiles.
            collisionManager.setTilesManager(tilesManager);
        }
        // Destrutora da classe Level.
        Level::~Level()
        {
            // Remove o jogador da lista para ele não ser desalocado da memória.
            players.removeFirst(player1);
            players.removeFirst(player2);
            // Deleta dinamicamente os objetos das entidades físicas.
            players.destroyPhysicalEntities();
            delete tilesManager;
        }
        int Level::run()
        {
            gameCode = Managers::continueGame;

            pGraphicManager->draw(backgroundPath, Utilities::gameVector2F{800.0f, 280.0f});

            double t = clock.getTime();
            // Método que gerencia os eventos nas fases.
            handleEvents();
            // Atualiza a lista das entidades físicas, passando como parametro o tempo da aplicação em segundos.
            players.updatePhysicalEntities(t);
            // Método que gerencia as colisões nas fases.
            handleCollisions();
            // Gerenciador de tiles envia solicitação de desenho na tela para o gerenciador gráfico
            tilesManager->draw(*pGraphicManager);
            // Desenha as entidades físicas na window.
            players.drawPhysicalEntities(*pGraphicManager);

            return gameCode;
        }
        void Level::addPhysicalEntity(PhysicalEntities::PhysicalEntity *_physicalEntity)
        {
            _physicalEntity->initialize(*pEventsManager, collisionManager);
            players.insert(_physicalEntity);
            collisionManager.addToLCollidablesPhysicalEntities((_physicalEntity));
        }

        // Método que gerencia as colisões nas fases.
        void Level::handleCollisions()
        {
            // Gerenciador de colissões verifica se houve colisão entre entidades físicas.
            collisionManager.checkCollisions();
        }
        // Método que gerencia os eventos nas fases.
        void Level::handleEvents()
        {
            // Verifica se ocorreu algum evento.
            pEventsManager->handleEvent();
        }

        void Level::setPlayers(PhysicalEntities::Characters::Players::Shrek *_player1)
        {
            player1 = _player1;
            player2 = nullptr;
        }
        void Level::setPlayers(PhysicalEntities::Characters::Players::Shrek *_player1, PhysicalEntities::Characters::Players::Donkey *_player2)
        {
            player1 = _player1;
            player2 = _player2;
        }

        const Utilities::gameVector2F Level::getMainPlayerPosition() const
        {
            if (player1 == nullptr)
            {
                std::cout << "Ponteiro para player1 ainda não atribuído." << std::endl;
            }
            return player1->getPosition();
        }

        // Método encarregado de encerrar processo do jogo caso o evento de fechar a janela do jogo tenha ocorrido.
        void Level::closedWindowButton(const sf::Event &event)
        {
            if (event.type == sf::Event::Closed)
            {
                setGameCode(Managers::END_GAME);
            }
        }

        int Level::getRankingScore()
        {
            if ((player1) && (player2))
            {
                return (player1->getLife() + player2->getLife()) / 2;
            }
            else if (player1)
            {
                return player1->getLife();
            }
        }

        void Level::resetLevel()
        {
            if (this->getId() == 1000)
            {
                setGameCode(Managers::START_MEDIEVAL_RUINS_LEVEL);
            }
            else if (this->getId() == 2000)
            {
                setGameCode(Managers::START_CASTLE_LEVEL);
            }
        }

        void Level::goNextLevel()
        {
            if (this->getId() == 1000)
            {
                setGameCode(Managers::START_CASTLE_LEVEL);
            }
            else if (this->getId() == 2000)
            {
                setGameCode(Managers::RANKING_INSERT);
            }
        }

        void Level::goToMenuButton(const sf::Event &event)
        {
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Escape)
            {
                {
                    setGameCode(Managers::PAUSE_MENU);
                    clock.pause();
                }
            }
        }

        void Level::setGameCode(int _gameCode)
        {
            gameCode = _gameCode;
        }

    }
}