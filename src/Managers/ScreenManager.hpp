#ifndef _SCREENMANAGER_HPP_
#define _SCREENMANAGER_HPP_

#include "StateManager.hpp"
#include "../Levels/MedievalRuins.hpp"
#include "../Levels/Castle.hpp"
#include "../Menus/Ranking.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities
    {
        namespace Characters
        {
            namespace Players
            {
                class Shrek;
                class Donkey;
            }
        }
    }
    namespace Managers // Namespace do Pacote Managers.
    {
        enum GameCode
        {
            CONTINUE_GAME,
            MAIN_MENU,
            EXIT_PAUSE_MENU,
            PAUSE_MENU,
            END_GAME,
            SAVE_GAME,
            START_MEDIEVAL_RUINS_LEVEL,
            LOAD_MEDIEVAL_RUINS_LEVEL,
            START_CASTLE_LEVEL,
            LOAD_CASTLE_LEVEL,
            EXIT,
            RANKING,
            RANKING_INSERT
        };
        static GameCode gamecode;

        class ScreenManager : public StateManager
        {
        private:
            // Atributo que aponta para a classe do player Shrek.
            PhysicalEntities::Characters::Players::Shrek *player1;
            // Atributo que aponta para a classe do player Donkey.
            PhysicalEntities::Characters::Players::Donkey *player2;

        public:
            ScreenManager(PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr, PhysicalEntities::Characters::Players::Donkey *_player2 = nullptr);
            ~ScreenManager();

        protected:
            bool handleCode(int GameCode);
        };
    }
}
#endif