#ifndef _PAUSEMENU_HPP_
#define _PAUSEMENU_HPP_

#include "Menu.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        class PauseMenu : public Menu
        {
        public:
            PauseMenu();
            ~PauseMenu();

            void init() override;

            int run() override;
        };
    }
}

#endif