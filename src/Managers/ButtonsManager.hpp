#ifndef _BUTTONSMANAGER_HPP_
#define _BUTTONSMANAGER_HPP_

#include "GraphicManager.hpp"
#include "EventsManager.hpp"
#include "../Menus/Button.hpp"

#include <vector>

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {
        class ButtonsManager
        {
        private:
            EventsManager &em;
            GraphicManager &gm;
            unsigned int keyMouseEvent;
  

        public:
            std::vector<Menus::Button *> buttons;
            // Construtora da classe ButtonsManager.
            ButtonsManager(GraphicManager &_gm, EventsManager &_em, std::vector<Menus::Button *> _buttons = {});
            // Destrutora da classe ButtonsManager.
            ~ButtonsManager();
            void draw() const;
            void handleMouseEvent(const sf::Event &e);
            void addButton(Menus::Button *b);
            const short int getButtonId() const;
        };
    }
}
#endif