
#include "Ranking.hpp"
#include "../Managers/ScreenManager.hpp"
#include <fstream>

#include "../json.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        Ranking::Ranking() : Menu(),
                             scores{},
                             scrollOffset{0}
        {
            initialize();
        }

        Ranking::~Ranking()
        {
        }

        void Ranking::initialize()
        {
            Menu::initialize();
            Utilities::myVector2F screenSize = pGraphicManager->getScreenSize();
            pGraphicManager->centerCamera(pGraphicManager->getScreenSize() * 0.5);
            bm.addButton(new Button(
                1, Utilities::myVector2F(screenSize.coordX / 7, screenSize.coordY / 10), {100, 30}, "Main Menu", [this]
                { setGameCode(Managers::GameCode::MAIN_MENU); },
                15U, Utilities::Color{127, 0, 0}));

            loadScores();
            // run();
        }

        void Ranking::loadScores()
        {
            const char *path = "../savedGame/highScore.json";
            std::ifstream file(path);
            if (!file.is_open())
            {
                std::cout << "Atencao! Arquivo no caminho \"" << path << "\" não pode ser aberto!" << std::endl;
                exit(1);
            }
            std::string name;
            unsigned int score;

            nlohmann::json json;
            file >> json;
            // Retorna os objetos alocados na primeira posição do array json.

            for (nlohmann::json data : json["scores"])
            {
                name = data["name"];
                score = static_cast<unsigned int>(data["score"]);
                scores.emplace(score, name);
            }
            file.close();
        }

        void Ranking::draw()
        {
            Utilities::myVector2F screenSize = pGraphicManager->getScreenSize();
            pGraphicManager->centerCamera(screenSize * 0.5);
            Utilities::myVector2F positionText = Utilities::myVector2F(screenSize.coordX / 2, screenSize.coordY / 8);
            unsigned int windowMapScroll = scrollOffset;
            std::string str;
            for (auto scoreIterator : scores)
            {
                if (windowMapScroll > 0)
                {
                    --windowMapScroll;
                    continue;
                }

                str = std::to_string(scoreIterator.first);
                str += " - ";
                str += scoreIterator.second;
                pGraphicManager->drawText(str, positionText, 10);
                positionText += Utilities::myVector2F(0, 15);
                if (positionText.coordY >= screenSize.coordY)
                    break;
            }
        }

        int Ranking::run()
        {
            gameCode = Managers::RANKING;
            while (gameCode == Managers::RANKING)
            {
                pGraphicManager->clear(0, 0, 0);
                pEventsManager->handleEvent();
                bm.draw();
                this->draw();
                this->handleEvent();
                pGraphicManager->display();
            }
            removeListeners();
            return gameCode;
        }

        void Ranking::handleEvent()
        {
            idMouseEvent = pEventsManager->addMouseListener([this](sf::Event e)
                                                            {
                                                                if (e.type == sf::Event::MouseWheelScrolled)
                                                                {
                                                                    if (e.mouseWheelScroll.delta > 0)
                                                                    {
                                                                        --scrollOffset;
                                                                    }
                                                                    else
                                                                    {
                                                                        ++scrollOffset;
                                                                    }
                                                                }
                                                                if (scrollOffset < 0)
                                                                    scrollOffset = 0;
                                                                else if (scrollOffset > static_cast<int>(scores.size()) - 1)
                                                                    scrollOffset = static_cast<int>(scores.size()) - 1;
                                                            });
        }
    }
}
