
#include "Menu.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        // Construtora da classe Level.

        Menu::Menu() : Entity()
        {
        }
        Menu::Menu(Managers::GraphicManager *gm) : Entity(gm)
        {
            // setGraphicManager(gm);
        }
        // Destrutora da classe Level.
        Menu::~Menu()
        {
        }
    }
}
