#include "PauseMenu.hpp"
#include "../Managers/ScreenManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        PauseMenu::PauseMenu():Menu()
        {
            pGraphicManager->centerCamera(pGraphicManager->getScreenSize() * 0.5);
            bm.addButton(new Button({200.0f, 20.0f}, {100, 50}, "Continue", [this] {setGameCode(Managers::GameCode::EXIT_PAUSE_MENU);} ));
            bm.addButton(new Button({200.0f, 100.0f}, {100, 50}, "Save Game", [this] {setGameCode(Managers::GameCode::SAVE_GAME);} ));
            bm.addButton(new Button({200.0f, 180.0f}, {100, 50}, "Main Menu", [this] {setGameCode(Managers::GameCode::MAIN_MENU);} ));
        }
    }
}