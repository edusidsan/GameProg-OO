#include "PauseMenu.hpp"
#include "../Managers/ScreenManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        PauseMenu::PauseMenu() : Menu()
        {
            initialize();
        }

        PauseMenu::~PauseMenu()
        {
        }

        void PauseMenu::initialize()
        {
            Menu::initialize();
            Utilities::myVector2F screenSize = pGraphicManager->getScreenSize();
            pGraphicManager->centerCamera(pGraphicManager->getScreenSize() * 0.5);
            bm.addButton(new Button(
                1, Utilities::myVector2F(screenSize.coordX / 2, screenSize.coordY / 4 * 1), {170, 30}, "Continue", [this]
                { setGameCode(Managers::GameCode::EXIT_PAUSE_MENU); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                2, Utilities::myVector2F(screenSize.coordX / 2, screenSize.coordY / 4 * 2), {170, 30}, "Save Game", [this]
                { setGameCode(Managers::GameCode::SAVE_GAME); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                3, Utilities::myVector2F(screenSize.coordX / 2, screenSize.coordY / 4 * 3), {170, 30}, "Main Menu", [this]
                { setGameCode(Managers::GameCode::MAIN_MENU); },
                15U, Utilities::Color{127, 0, 0}));
        }

        int PauseMenu::run()
        {

            Utilities::myVector2F screenSize = pGraphicManager->getScreenSize();
            pGraphicManager->centerCamera(screenSize * 0.5);
            gameCode = Managers::PAUSE_MENU;

            while (gameCode == Managers::PAUSE_MENU)
            {
                pEventsManager->handleEvent();
                bm.draw();
                pGraphicManager->display();
            }

            removeListeners();
            return gameCode;
        }
    }
}