#include "RankingInsert.hpp"
#include "../Managers/ScreenManager.hpp"
#include <fstream>

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {

        bool RankingInsert::addingScore = true;
        unsigned int RankingInsert::score = 0;
        std::string RankingInsert::playerName = "";

        RankingInsert::RankingInsert() : Menu(),
                                         box(),
                                         path(nullptr),
                                         rankingArray()

        {
            this->initialize();
        }
        RankingInsert::~RankingInsert()
        {
            path = nullptr;
        }

        void RankingInsert::initialize()
        {
            Menu::initialize();

            Utilities::gameVector2F screenSize = pGraphicManager->getScreenSize();
            pGraphicManager->centerCamera(pGraphicManager->getScreenSize() * 0.5);

            box.setCenter(Utilities::gameVector2F(screenSize * 0.5));
        }
        void RankingInsert::addNewHighScore(const int _score)
        {
            score = _score;
            addingScore = true;
        }
        int RankingInsert::run()
        {
            Utilities::gameVector2F screenSize = pGraphicManager->getScreenSize();
            pGraphicManager->centerCamera(screenSize * 0.5);
            gameCode = Managers::CONTINUE_GAME;

            if (addingScore)
            {
                box.startStringCapture();
            }

            while (gameCode == Managers::CONTINUE_GAME)
            {
                pGraphicManager->clear();
                pEventsManager->handleEvent();
                Utilities::gameVector2F viewsize = pGraphicManager->getScreenSize();
                if (addingScore)
                {
                    if (box.captureDone())
                    {
                        std::string name = box.getCapture();
                        if (name != "")
                        {
                            playerName = name;
                            if (!save("../savedGame/highScore.json"))
                            {
                                std::cout << "Score nao foi salva" << std::endl;
                            }
                            gameCode = Managers::RANKING;
                        }
                        addingScore = false;
                        score = 0;
                    }
                }
                box.draw();
                pGraphicManager->display();
            }
            box.removeListeners();
            removeListeners();
            score = 0;
            addingScore = false;
            return gameCode;
        }
        nlohmann::json RankingInsert::toJSON()
        {
            nlohmann::json json;
            json = {
                {"name", playerName},
                {"score", score}};

            rankingArray["scores"].emplace_back(json.begin(), json.end());
            return rankingArray;
        }
        bool RankingInsert::save(const std::string &path)
        {
            load("../savedGame/highScore.json");

            std::ofstream file(path);
            if (file.fail())
            {
                return false;
            }
            file << toJSON();
            file.close();
            return true;
        }

        bool RankingInsert::load(const std::string &path)
        {
            std::ifstream file(path);
            if (file.fail())
            {
                return false;
            }
            file >> rankingArray;
            file.close();

            return true;
        }
    }
}
