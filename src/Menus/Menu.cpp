#include "Menu.hpp"
#include "../Managers/ScreenManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        // Construtora da classe Menu.
        Menu::Menu() : Entity(),
                       State(),
                       gameCode(Managers::continueGame),
                       idKeyboardEvent(0),
                       idMouseEvent(0),
                       idOtherEvent(0),
                       pEventsManager(Managers::EventsManager::getInstance()),
                       bm(*pGraphicManager, *pEventsManager)
        {
        }
        // Destrutora da classe Level.
        Menu::~Menu()
        {
            removeListeners();
            gameCode = 0;
            idKeyboardEvent = 0;
            idMouseEvent = 0;
            idOtherEvent = 0;
            pEventsManager = nullptr;
        }

        void Menu::initialize()
        {
            pGraphicManager->clear();
            pEventsManager->setWindow(pGraphicManager->getWindow());
            pEventsManager->addOtherListener([this](const sf::Event &e)
                                             { closedWindowButton(e); });
        }

        int Menu::run()
        {
            gameCode = Managers::continueGame;
            return gameCode;
        }

        void Menu::removeListeners()
        {
            if (idKeyboardEvent != 0)
            {
                pEventsManager->removeKeyboardListener(idKeyboardEvent);
                idKeyboardEvent = 0;
            }
            if (idMouseEvent != 0)
            {
                pEventsManager->removeMouseListener(idMouseEvent);
                idMouseEvent = 0;
            }
            if (idOtherEvent != 0)
            {
                pEventsManager->removeOtherListener(idOtherEvent);
                idOtherEvent = 0;
            }
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
                setGameCode(Managers::END_GAME);
            }
        }

    }
}
