
#include "MainMenu.hpp"
#include "../Managers/ScreenManager.hpp"
#include "../Utilities/Color.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {

        // Construtora da classe MainMenu.
        MainMenu::MainMenu() : Menu()
        //    printed{false}
        //    textInputBox{em, 15, {200.0f, 50.0f}, {100, 40}}
        {
            Menu::init();
            Utilities::myVector2F screenSize = pGraphicManager->getScreenSize();

            bm.addButton(new Button(
                Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 1), {170, 30}, "Level 1 - Medieval Ruins", [this]
                { setGameCode(Managers::GameCode::START_MEDIEVAL_RUINS_LEVEL); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 2), {170, 30}, "Load - Medieval Ruins", [this]
                { setGameCode(Managers::GameCode::LOAD_MEDIEVAL_RUINS_LEVEL); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 3), {170, 30}, "Level 2 - ", [this]
                { setGameCode(Managers::GameCode::END_GAME); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 4), {170, 30}, "Load - ", [this]
                { setGameCode(Managers::GameCode::END_GAME); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 5), {170, 30}, "Leaderboard", [this]
                { setGameCode(Managers::GameCode::END_GAME); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 6), {170, 30}, "Number of players:", [this]
                { setGameCode(Managers::GameCode::END_GAME); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 7), {170, 30}, "Exit", [this]
                { setGameCode(Managers::GameCode::END_GAME); },
                15U, Utilities::Color{127, 0, 0}));
            // bm.addButton(&textInputBox);
        }
        // Destrutora da classe MainMenu.
        MainMenu::~MainMenu()
        {
        }

        void MainMenu::init()
        {
            std::cout << "Implementar MainMenu::init()" << std::endl;
            pGraphicManager->centerCamera(pGraphicManager->getScreenSize() * 0.5);
        }

        int MainMenu::run()
        {
            int menuReturn = Menu::run();
            // if (!printed && textInputBox.getReadyText())
            // {
            //     printed = true;
            //     std::cout << "O texto digitado foi --> " << textInputBox.getText() << std::endl;
            // }
            return menuReturn;
            // return (Managers::GameCode::continueGame);
            // return 0;
        }
    }
}