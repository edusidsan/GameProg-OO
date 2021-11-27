#ifndef _MENU_HPP_
#define _MENU_HPP_

#include "../Managers/ButtonsManager.hpp"
#include "../Entity.hpp"
#include "../State.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        class Menu : public Entity, public State
        {
        protected:
            int gameCode;
            unsigned int idKeyboardEvent;
            unsigned int idMouseEvent;
            unsigned int idOtherEvent;
            Managers::EventsManager *pEventsManager;
            Managers::ButtonsManager bm;

        public:
            // Construtora da classe Menu.
            Menu();
            // Destrutora da classe Menu.
            virtual ~Menu();
            virtual void initialize() override;

            virtual int run() override;

            void removeListeners();

        protected:
            // Método encarregado de encerrar processo do jogo caso o evento de fechar a janela do jogo tenha ocorrido.
            void closedWindowButton(const sf::Event &event);
            void setGameCode(int _gameCode);
        };
    }
}
#endif