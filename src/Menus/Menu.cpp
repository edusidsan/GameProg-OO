
#include "Menu.hpp"
#include "../Managers/ScreenManager.hpp"

// #include "../Managers/ButtonsManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        // Construtora da classe Level.

        Menu::Menu() : Entity(),
                       State(),
                       bm{*pGraphicManager, em},
                       gameCode{Managers::continueGame}

        {
            em.setWindow(pGraphicManager->getWindow());
        }
        // Destrutora da classe Level.
        Menu::~Menu()
        {
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
    }
}
