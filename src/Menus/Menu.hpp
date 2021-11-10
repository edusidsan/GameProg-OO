#ifndef _MENU_HPP_
#define _MENU_HPP_

// #include "../Managers/GraphicManager.hpp"
#include "../Entity.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        class Menu : public Entity
        {
        public:
        
            // Construtora da classe Menu.
            // Menu(Managers::GraphicManager &gm);
            Menu();
            Menu(Managers::GraphicManager *gm);
            // Destrutora da classe Menu.
            virtual ~Menu();
        };
    }
}
#endif