
#include "Menu.hpp"
#include "../Managers/ScreenManager.hpp"
#include <iostream>

// #include "../Managers/ButtonsManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        // Construtora da classe Level.

        Menu::Menu() : Entity(),
                       State(),

                       bm{*pGraphicManager, em},
                       gameCode{Managers::continueGame},
                       idKeyboardEvent{0},
                       idMouseEvent{0},
                       idOtherEvent{0}

        {
            // pGraphicManager->centerCamera(pGraphicManager->getScreenSize() * 0.5);
            // em.setWindow(pGraphicManager->getWindow());
        }
        // Destrutora da classe Level.
        Menu::~Menu()
        {
            removeListeners();
        }

        void Menu::init()
        {
            std::cout << "Implementar Menu::init()" << std::endl;

            em.setWindow(pGraphicManager->getWindow());

            em.addOtherListener([this](const sf::Event &event)
                                { closedWindowButton(event); });
        }

        int Menu::run()
        {
            gameCode = Managers::continueGame;
            em.handleEvent();
            bm.draw();
            return gameCode;
        }
        void Menu::setGameCode(int _gameCode)
        {
            gameCode = _gameCode;
        }

        // Método encarregado de encerrar processo do jogo caso o evento de fechar a janela do jogo tenha ocorrido.
        void Menu::closedWindowButton(const sf::Event &event)
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Entity closed" << std::endl;
                setGameCode(Managers::END_GAME);
            }
        }

        void Menu::removeListeners()
        {
            if (idKeyboardEvent != 0)
            {
                em.removeKeyboardListener(idKeyboardEvent);
                idKeyboardEvent = 0;
            }
            if (idMouseEvent != 0)
            {
                em.removeMouseListener(idMouseEvent);
                idMouseEvent = 0;
            }
            if (idOtherEvent != 0)
            {
                em.removeOtherListener(idOtherEvent);
                idOtherEvent = 0;
            }
        }
    }
}
