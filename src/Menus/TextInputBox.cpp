#include "TextInputBox.hpp"
#include "../Managers/GraphicManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {

        // Construtora da classe TextInputBox.
        TextInputBox::TextInputBox(Managers::EventsManager &_em, unsigned short _maxLength, Utilities::myVector2F _position,
                                   Utilities::myVector2F _size, unsigned int _textSize, Utilities::Color _color) : Button{_position, _size, "", [this]()
                                                                                                                          { inputStart(); },
                                                                                                                          _textSize, _color},
                                                                                                                   promisseText{_em, _maxLength}
        {
        }
        // Destrutora da classe TextInputBox.
        TextInputBox::~TextInputBox()
        {
        }

        const std::string &TextInputBox::getText() const
        {
            if (!getReadyText())
            {
                throw "Erro! String pedida sem ter sido terminada antes. Cheque getReadyText() antes de chamar esse método";
            }
            return promisseText.getText();
        }
        bool TextInputBox::getReadyText() const
        {
            return promisseText.getReadyText();
        }
        void TextInputBox::draw(Managers::GraphicManager *pGraphicManager) const
        {
            pGraphicManager->drawSolidRect(position, size, color);
            pGraphicManager->drawText(promisseText.getText(), position, textSize, false);
        }
        void TextInputBox::inputStart()
        {
            promisseText.inputStart();
        }

    }
}