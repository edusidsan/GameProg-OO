#include "PauseMenu.hpp"
#include "../Managers/ScreenManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {

        PauseMenu::PauseMenu():Menu()
        {
            bm.addButton(new Button({200.0f, 50.0f}, {100, 50}, "Continue", [this] {setGameCode(Managers::continueGame);} ));
            bm.addButton(new Button({200.0f, 100.0f}, {100, 50}, "Save Game", [this] {setGameCode(Managers::SAVE_GAME);} ));
            bm.addButton(new Button({200.0f, 150.0f}, {100, 50}, "Main Menu", [this] {setGameCode(Managers::MAIN_MENU);} ));
        }

    }
}