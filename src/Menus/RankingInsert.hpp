#ifndef _RANKINGINSERT_HPP_
#define _RANKINGINSERT_HPP_

#include "Menu.hpp"
#include "TextInputBox.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        class RankingInsert : public Menu
        {
        private:
            TextInputBox box;
            const char *path;
            static bool addingScore;
            static unsigned int score;
            static std::string playerName;
            nlohmann::json rankingArray;

        public:
            RankingInsert();
            ~RankingInsert();

            void initialize() override;
            int run() override;
            static void addNewHighScore(const int _score);
            bool save(const std::string &path);
            bool load(const std::string &path);
            nlohmann::json toJSON();
        };
    }
}

#endif