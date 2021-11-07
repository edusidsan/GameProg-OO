#ifndef _MENU_HPP_
#define _MENU_HPP_


namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        class Menu
        {
        public:
        
            // Construtora da classe Level.
            Menu();
            // Destrutora da classe Level.
            virtual ~Menu();
            // Método run virtual puro -> TORNA CLASSE ABSTRATA.
            virtual void run() = 0;
        };
    }
}
#endif