#include "Button.hpp"
#include "../Managers/GraphicManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        // Construtora da classe Button.
        Button::Button(Utilities::myVector2F _position, Utilities::myVector2F _size, std::string _text, std::function<void(void)> _buttonPressed, unsigned int _textSize, Utilities::Color _color) : position{_position},
                                                                                                                                                                                                     size{_size},
                                                                                                                                                                                                     text{_text},
                                                                                                                                                                                                     buttonPressed{_buttonPressed},
                                                                                                                                                                                                     textSize{_textSize},
                                                                                                                                                                                                     color{_color}
        {
        }

        // Destrutora da classe Button.
        Button::~Button()
        {
        }
        void Button::draw(Managers::GraphicManager *pGraphicManager) const
        {
            pGraphicManager->drawSolidRect(position, size, color);
            pGraphicManager->drawText(text, position, textSize);
        }
        Utilities::myVector2F Button::getPosition() const
        {
            return position;
        }
        Utilities::myVector2F Button::getSize() const
        {
            return size;
        }
        void Button::pushButton() const
        {
            buttonPressed();
        }
    }
}