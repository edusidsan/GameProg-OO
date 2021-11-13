#ifndef _SCREENMANAGER_HPP_
#define _SCREENMANAGER_HPP_

#include "StateManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities
    {
        namespace Characters
        {
            namespace Players
            {
                class Shrek;
            }
        }

    }
    namespace Managers // Namespace do Pacote Managers.
    {
        enum GameCode
        {
            continueGame,
            endGame,
            toFirstLevel
        };

        class ScreenManager : public StateManager
        {

        private:
            // Atributo que aponta para a classe do player Shrek.
            PhysicalEntities::Characters::Players::Shrek *player1;

        public:
            ScreenManager(PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr);
            ~ScreenManager();

        protected:

            bool handleCode(int GameCode);
        };
    }
}

#endif