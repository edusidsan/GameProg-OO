#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include "../Utilities/Vector2D.hpp"
#include "../Utilities/Color.hpp"
// #include "Menu.hpp"
#include <string>
#include <functional>

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers
    {
        class GraphicManager;
    }
    namespace Menus // Namespace do Pacote Menus.
    {
        class Button
        {

        private:
            std::function<void(void)> buttonPressed;

        protected:
            Utilities::gameVector2F position;
            Utilities::gameVector2F size;
            Utilities::Color color;
            unsigned int textSize;
            std::string text;
            short int buttonId;

        public:
            // Construtora da classe Button.
            Button(short int _buttonId, Utilities::gameVector2F _position = {0.0f, 0.0f}, Utilities::gameVector2F _size = {0.0f, 0.0f}, std::string _text = "", std::function<void(void)> _buttonPressed = std::function<void(void)>(), unsigned int _textSize = 15U, Utilities::Color _color = {128, 128, 128});
            // Destrutora da classe Button.
            virtual ~Button();
            virtual void draw(Managers::GraphicManager *pGraphicManager) const;
            Utilities::gameVector2F getPosition() const;
            Utilities::gameVector2F getSize() const;
            void pushButton() const;
            const short int getButtonId() const;
        };
    }
}
#endif