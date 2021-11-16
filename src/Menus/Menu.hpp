#ifndef _MENU_HPP_
#define _MENU_HPP_

#include "../Managers/ButtonsManager.hpp"
//#include "../Managers/EventsManager.hpp"
#include "../Entity.hpp"
// #include "../Managers/GraphicManager.hpp"
#include "../State.hpp"

// #include "../Managers/GraphicManager.hpp"
// #include "GerenciadorGrafico.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        class Menu : public Entity, public State
        {
        private:
            int gameCode;

        protected:
            Managers::EventsManager em;
            Managers::ButtonsManager bm;
            // Managers::GraphicManager *pGraphicManager;
            // GerenciadorGrafico &gg;

        public:
            // Construtora da classe Menu.
            Menu();
            // Destrutora da classe Menu.
            virtual ~Menu();
            virtual int run();

        protected:
            void setGameCode(int _gameCode);
        };
    }
}
#endif