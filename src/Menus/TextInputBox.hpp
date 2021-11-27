#ifndef _TEXTINPUTBOX_HPP_
#define _TEXTINPUTBOX_HPP_

#include "Button.hpp"
#include "../Managers/EventsManager.hpp"
#include "../Managers/GraphicManager.hpp"

#include <string>

namespace OgrO // Namespace com o nome do jogo.
{

    namespace Menus // Namespace do Pacote Menus.
    {
        // class TextInputBox : public Button
        class TextInputBox
        {
        private:
            Managers::GraphicManager *pGraphicManager;
            Managers::EventsManager *pEventsManager;
            unsigned int idKeyboardEvent;
            Utilities::gameVector2F centerPosition;
            unsigned int fontSize;
            unsigned short maxLenght;
            bool done;
            std::string str;

        public:
            // Construtora da classe TextInputBox.
            TextInputBox(unsigned short _maxLength = 20, Utilities::gameVector2F _position = {0.0f, 0.0f}, unsigned int _font = 16);
            // Destrutora da classe TextInputBox.
            ~TextInputBox();
            void initialize();
            void setCenter(const Utilities::gameVector2F _pos);
            void setFontSize(const unsigned int _s);
            void draw() const;
            void removeListeners();
            void startStringCapture();
            bool captureDone() const;
            std::string getCapture();
        };
    }
}
#endif