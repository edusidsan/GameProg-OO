#ifndef _MAINMENU_HPP_
#define _MAINMENU_HPP_

#include "Menu.hpp"
#include "TextInputBox.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        class MainMenu : public Menu
        {
        private:
            TextInputBox textInputBox;
            bool printed;

        public:
            // Construtora da classe MainMenu.
            MainMenu();
            // Destrutora da classe MainMenu.
            ~MainMenu();
            int run() override;
        };
    }
}
#endif