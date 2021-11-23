#include "Level.hpp"
#include "../Managers/ScreenManager.hpp"
#include "../Utilities/RandomGenerator.hpp"
#include <iostream>
#include <fstream>

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        // Construtora da classe Level.
        Level::Level(Tiles::TilesManager *_tilesManager, PhysicalEntities::Characters::Players::Shrek *_player1, PhysicalEntities::Characters::Players::Donkey *_player2, const std::string _backgroundPath) : Entity(),
                                                                                                                                                                                                               State(),
                                                                                                                                                                                                               collisionManager{},
                                                                                                                                                                                                               pEventsManager{Managers::EventsManager::getInstance()},
                                                                                                                                                                                                               players{},
                                                                                                                                                                                                               player1{_player1},
                                                                                                                                                                                                               player2{_player2},
                                                                                                                                                                                                               backgroundPath{_backgroundPath},
                                                                                                                                                                                                               tilesManager{_tilesManager},
                                                                                                                                                                                                               // lambda-expression.
                                                                                                                                                                                                               idClosedWindow{
                                                                                                                                                                                                                   pEventsManager->addOtherListener([this](const sf::Event &event)
                                                                                                                                                                                                                                                    { closedWindowButton(event); })},
                                                                                                                                                                                                               idGoToMenu{
                                                                                                                                                                                                                   pEventsManager->addKeyboardListener([this](const sf::Event &event)
                                                                                                                                                                                                                                                       { goToMenuButton(event); })},
                                                                                                                                                                                                               clock{},
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

            pGraphicManager->draw(backgroundPath, Utilities::myVector2F{800.0f, 280.0f});

            // backgroundImage.draw();
            // Atribui a t o tempo em que a aplicação está rodando.
            // sf::Time t = clock.getElapsedTime();
            double t = clock.getTime();
            // Reseta a contagem do clock.
            // clock.restart();
            // Método que gerencia os eventos nas fases.
            handleEvents();
            // Atualiza a lista das entidades físicas, passando como parametro o tempo da aplicação em segundos.
            // players.updatePhysicalEntities(t.asSeconds());
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
            std::cout << "Player configurado" << std::endl;
        }
        void Level::setPlayers(PhysicalEntities::Characters::Players::Shrek *_player1, PhysicalEntities::Characters::Players::Donkey *_player2)
        {
            player1 = _player1;
            player2 = _player2;
            std::cout << "Players configurados" << std::endl;
        }

        // Método encarregado de encerrar processo do jogo caso o evento de fechar a janela do jogo tenha ocorrido.
        void Level::closedWindowButton(const sf::Event &event)
        {
            if (event.type == sf::Event::Closed)
            {
                setGameCode(Managers::END_GAME);
            }
        }

        const Utilities::myVector2F Level::getMainPlayerPosition() const
        {
            if (player1 == nullptr)
            {
                std::cout << "segfaulting agora" << std::endl;
            }
            return player1->getPosition();
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