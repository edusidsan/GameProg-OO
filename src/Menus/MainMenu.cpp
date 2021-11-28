#include "MainMenu.hpp"
#include "../Managers/ScreenManager.hpp"
#include "../Utilities/Color.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        bool MainMenu::twoPlayers = true;

        // Construtora da classe MainMenu.
        MainMenu::MainMenu() : Menu()
        {
            Menu::initialize();
            Utilities::gameVector2F screenSize = pGraphicManager->getScreenSize();

            bm.addButton(new Button(
                1, Utilities::gameVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 1), {170, 30}, "Level 1 - Medieval Ruins", [this]
                { setGameCode(Managers::GameCode::START_MEDIEVAL_RUINS_LEVEL); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                2, Utilities::gameVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 2), {170, 30}, "Load - Medieval Ruins", [this]
                { setGameCode(Managers::GameCode::LOAD_MEDIEVAL_RUINS_LEVEL); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                3, Utilities::gameVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 3), {170, 30}, "Level 2 - Castle", [this]
                { setGameCode(Managers::GameCode::START_CASTLE_LEVEL); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                4, Utilities::gameVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 4), {170, 30}, "Load - Castle", [this]
                { setGameCode(Managers::GameCode::LOAD_CASTLE_LEVEL); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                5, Utilities::gameVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 5), {170, 30}, "Ranking", [this]
                { setGameCode(Managers::GameCode::RANKING); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                6, Utilities::gameVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 6), {170, 30}, "Number of players:", [this]
                { setGameCode(Managers::GameCode::CONTINUE_GAME); },
                15U, Utilities::Color{127, 0, 0}));
            bm.addButton(new Button(
                7, Utilities::gameVector2F(screenSize.coordX / 4, screenSize.coordY / 8 * 7), {170, 30}, "Exit", [this]
                { setGameCode(Managers::GameCode::END_GAME); },
                15U, Utilities::Color{127, 0, 0}));
        }
        // Destrutora da classe MainMenu.
        MainMenu::~MainMenu()
        {
        }

        void MainMenu::initialize()
        {
        }

        int MainMenu::run()
        {
            Utilities::gameVector2F screenSize = pGraphicManager->getScreenSize();
            pGraphicManager->centerCamera(screenSize * 0.5);
            gameCode = Managers::CONTINUE_GAME;

            idMouseEvent = pEventsManager->addMouseListener(
                [this](const sf::Event e)
                {
                    if (e.type == sf::Event::MouseButtonReleased)
                    {
                        Utilities::gameVector2F pos = pGraphicManager->getMousePosition();
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

            while (gameCode == Managers::CONTINUE_GAME)
            {
                pGraphicManager->clear();
                pEventsManager->handleEvent();
                Utilities::gameVector2F viewsize = pGraphicManager->getScreenSize();
                bm.draw();
                pGraphicManager->drawText(((twoPlayers) ? "2" : "1"), Utilities::gameVector2F((viewsize.coordX * 0.85) / 2, viewsize.coordY / 8 * (5.95)), 15);
                pGraphicManager->display();
            }
            removeListeners();
            return gameCode;
        }
        
        const bool MainMenu::twoPlayersSelected()
        {
            return twoPlayers;
        }
    }
}