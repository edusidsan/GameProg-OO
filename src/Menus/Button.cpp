#include "Button.hpp"
#include "../Managers/GraphicManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        // Construtora da classe Button.
        Button::Button(short int _buttonId, Utilities::gameVector2F _position, Utilities::gameVector2F _size, std::string _text, std::function<void(void)> _buttonPressed, unsigned int _textSize, Utilities::Color _color) : pGraphicManager(Managers::GraphicManager::getInstance()),
                                                                                                                                                                                                                              buttonId{_buttonId},
                                                                                                                                                                                                                              position{_position},
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
        void Button::draw() const
        {
            pGraphicManager->drawSolidRect(position, size, color);
            pGraphicManager->drawText(text, position, textSize);
        }
        Utilities::gameVector2F Button::getPosition() const
        {
            return position;
        }
        Utilities::gameVector2F Button::getSize() const
        {
            return size;
        }
        void Button::pushButton() const
        {
            buttonPressed();
        }
        const short int Button::getButtonId() const
        {
            return buttonId;
        }
    }
}