
#include "MainMenu.hpp"
#include "../Managers/ScreenManager.hpp"
#include "../Utilities/Color.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {

        // Construtora da classe MainMenu.
        MainMenu::MainMenu() : Menu(),
                               twoPlayers{true}
        //    printed{false}
        //    textInputBox{em, 15, {200.0f, 50.0f}, {100, 40}}
        {
            Menu::init();
            Utilities::myVector2F screenSize = pGraphicManager->getScreenSize();

            bm.addButton(new Button(
                1, Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 1), {170, 30}, "Level 1 - Medieval Ruins", [this]
                { setGameCode(Managers::GameCode::START_MEDIEVAL_RUINS_LEVEL); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                2, Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 2), {170, 30}, "Load - Medieval Ruins", [this]
                { setGameCode(Managers::GameCode::LOAD_MEDIEVAL_RUINS_LEVEL); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                3, Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 3), {170, 30}, "Level 2 - ", [this]
                { setGameCode(Managers::GameCode::END_GAME); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                4, Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 4), {170, 30}, "Load - ", [this]
                { setGameCode(Managers::GameCode::END_GAME); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                5, Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 5), {170, 30}, "Leaderboard", [this]
                { setGameCode(Managers::GameCode::LEADERBOARD); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                6, Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 6), {170, 30}, "Number of players:", [this]
                { setGameCode(Managers::GameCode::continueGame); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                7, Utilities::myVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 7), {170, 30}, "Exit", [this]
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
        }

        int MainMenu::run()
        {
            // int menuReturn = Menu::run();
            // gameCode = Managers::continueGame;

            Utilities::myVector2F screenSize = pGraphicManager->getScreenSize();
            pGraphicManager->centerCamera(screenSize * 0.5);
            gameCode = Managers::continueGame;

            idMouseEvent = pEventsManager->addMouseListener(
                [this](const sf::Event e)
                {
                    if (e.type == sf::Event::MouseButtonReleased)
                    {
                        Utilities::myVector2F pos = pGraphicManager->getMousePosition();
                        for (auto &b : bm.buttons)
                        {
                            if (b->getPosition().coordX >= pos.coordX - (170 / 2) && b->getPosition().coordX <= pos.coordX + (170 / 2) &&
                                b->getPosition().coordY >= pos.coordY - (30 / 2) && b->getPosition().coordY <= pos.coordY + (30 / 2))
                            {
                                if (b->getButtonId() == 6)
                                {
                                    twoPlayers = !twoPlayers;
                                }
                            }
                        }
                    }
                });

            while (gameCode == Managers::continueGame)
            {
                pGraphicManager->clear();
                pEventsManager->handleEvent();
                Utilities::myVector2F viewsize = pGraphicManager->getScreenSize();
                bm.draw();
                pGraphicManager->drawText(((twoPlayers) ? "2" : "1"), Utilities::myVector2F((viewsize.coordX * 0.85) / 2, viewsize.coordY / 8 * (5.95)), 15);
                pGraphicManager->display();
            }

            // if (!printed && textInputBox.getReadyText())
            // {
            //     printed = true;
            //     std::cout << "O texto digitado foi --> " << textInputBox.getText() << std::endl;
            // }

            removeListeners();
            return gameCode;
        }
        const bool MainMenu::twoPlayersSelected() const
        {
            return twoPlayers;
        }
    }
}