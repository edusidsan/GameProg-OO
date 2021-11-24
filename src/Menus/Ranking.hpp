#ifndef _RANKING_HPP_
#define _RANKING_HPP_

#include "Menu.hpp"
#include <map>
#include <string>

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        class Ranking : public Menu
        {
        private:
            std::multimap<unsigned int, std::string> scores;
            int scrollOffset;

        public:
            Ranking();
            ~Ranking();

            void initialize() override;
            void loadScores();
            void draw() override;
            void handleEvent();

            int run() override;
        };
    }
}

#endif