#include "Level.hpp"
#include "../Managers/ScreenManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        // Construtora da classe Level.
        Level::Level(Tiles::TilesManager *_tilesManager, PhysicalEntities::Characters::Players::Shrek *_player1, PhysicalEntities::Characters::Players::Donkey *_player2, Background _backgroundImage) : Entity(),
                                                                                                                                                                                                         State(),
                                                                                                                                                                                                         tilesManager{_tilesManager},
                                                                                                                                                                                                         player1{_player1},
                                                                                                                                                                                                         player2{_player2},
                                                                                                                                                                                                         backgroundImage{_backgroundImage},
                                                                                                                                                                                                         // lambda-expression.
                                                                                                                                                                                                         idClosedWindow{
                                                                                                                                                                                                             eventsManager.addOtherListener([this](const sf::Event &event)
                                                                                                                                                                                                                                            { closedWindowButton(event); })},
                                                                                                                                                                                                         idGoToMenu{
                                                                                                                                                                                                             eventsManager.addKeyboardListener([this](const sf::Event &event)
                                                                                                                                                                                                                                            { goToMenuButton(event); })},
                                                                                                                                                                                                         gameCode{Managers::continueGame}

        {
            backgroundImage.initialize();

            // Inicializa gerenciador de tiles.
            tilesManager->initialize(*pGraphicManager, eventsManager);
            // Atribui ao gerenciador de eventos a window que está sendo utilizada pelo gerenciador gráfico.
            eventsManager.setWindow(pGraphicManager->getWindow());
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

            backgroundImage.draw();
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
            eventsManager.handleEvent();
        }

        // Método encarregado de encerrar processo do jogo caso o evento de fechar a janela do jogo tenha ocorrido.
        void Level::closedWindowButton(const sf::Event &event)
        {
            if (event.type == sf::Event::Closed)
            {
                setGameCode(Managers::END_GAME);
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