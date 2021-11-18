
#include "MainMenu.hpp"
#include "../Managers/ScreenManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {

        // Construtora da classe MainMenu.
        MainMenu::MainMenu() : Menu(),
                               printed{false},
                               textInputBox{em, 15, {200.0f, 50.0f}, {100, 40}}
        {
            bm.addButton(new Button({200.0f, 100.0f}, {100, 40}, "First Level", [this]
                                    { setGameCode(Managers::GameCode::START_MEDIEVAL_RUINS_LEVEL); }));
            bm.addButton(new Button({200.0f, 150.0f}, {100, 40}, "Load First Level", [this]
                                    { setGameCode(Managers::GameCode::LOAD_MEDIEVAL_RUINS_LEVEL); }));
            bm.addButton(new Button({200.0f, 300.0f}, {100, 40}, "Exit", [this]
                                    { setGameCode(Managers::GameCode::END_GAME); }));
            bm.addButton(&textInputBox);
        }
        // Destrutora da classe MainMenu.
        MainMenu::~MainMenu()
        {
        }
        int MainMenu::run()
        {
            int menuReturn = Menu::run();
            if (!printed && textInputBox.getReadyText())
            {
                printed = true;
                std::cout << "O texto digitado foi --> " << textInputBox.getText() << std::endl;
            }
            return menuReturn;
        }
    }
}