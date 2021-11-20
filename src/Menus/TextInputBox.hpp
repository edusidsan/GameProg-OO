#ifndef _TEXTINPUTBOX_HPP_
#define _TEXTINPUTBOX_HPP_

#include "Button.hpp"
#include "PromisseText.hpp"
//#include "../Managers/EventsManager.hpp"
//#include "../Utilities/Vector2D.hpp"
//#include "../Utilities/Color.hpp"

#include <string>

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers
    {
        class GraphicManager;
    }
    namespace Menus // Namespace do Pacote Menus.
    {
        class TextInputBox : public Button
        {
        private:
            PromisseText promisseText;

        public:
            // Construtora da classe TextInputBox.
            TextInputBox(Managers::EventsManager &_em, unsigned short _maxLength, Utilities::myVector2F _position = {0.0f, 0.0f}, Utilities::myVector2F _size = {0.0f, 0.0f}, unsigned int _textSize = 15U, Utilities::Color _color = {128, 128, 128});
            // Destrutora da classe TextInputBox.
            ~TextInputBox();
            const std::string &getText() const;
            bool getReadyText() const;
            void draw(Managers::GraphicManager *pGraphicManager) const;
            void inputStart();
        };
    }
}
#endif