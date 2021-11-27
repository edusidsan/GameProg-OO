#include "TextInputBox.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {

        TextInputBox::TextInputBox(unsigned short _maxLength, Utilities::gameVector2F _position, unsigned int _font) : pGraphicManager(Managers::GraphicManager::getInstance()),
                                                                                                                       pEventsManager(Managers::EventsManager::getInstance()),
                                                                                                                       idKeyboardEvent(0),
                                                                                                                       centerPosition(_position),
                                                                                                                       fontSize(_font),
                                                                                                                       maxLenght(_maxLength),
                                                                                                                       done(false),
                                                                                                                       str("")
        {
        }
        // Destrutora da classe TextInputBox.
        TextInputBox::~TextInputBox()
        {
            pGraphicManager = nullptr;
            pEventsManager = nullptr;
        }
        void TextInputBox::initialize()
        {
        }
        void TextInputBox::setCenter(const Utilities::gameVector2F _pos)
        {
            centerPosition = _pos;
        }
        void TextInputBox::setFontSize(const unsigned int _s)
        {
            fontSize = _s;
        }
        void TextInputBox::draw() const
        {
            pGraphicManager->drawText("Insert your name", {centerPosition.coordX, centerPosition.coordY - 50}, fontSize);
            pGraphicManager->drawSolidRect(centerPosition, Utilities::gameVector2F{170, 30}, Utilities::Color{255, 255, 255, 60});
            pGraphicManager->drawText(str, centerPosition, fontSize);
        }
        void TextInputBox::removeListeners()
        {
            if (idKeyboardEvent != 0)
            {
                pEventsManager->removeKeyboardListener(idKeyboardEvent);
                idKeyboardEvent = 0;
            }
        }
        void TextInputBox::startStringCapture()
        {
            idKeyboardEvent = pEventsManager->addKeyboardListener([this](sf::Event e)
                                                                  {
                                                                      if (e.type == sf::Event::EventType::TextEntered)
                                                                      {
                                                                          if (str.size() <= 20)
                                                                          {
                                                                              char c = (e.text.unicode < 128) ? static_cast<char>(e.text.unicode) : '\0';

                                                                              if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
                                                                              {
                                                                                  str += c;
                                                                              }
                                                                          }
                                                                          std::cout << "Enter text:" << str << std::endl;
                                                                      }
                                                                      else if (e.type == sf::Event::KeyReleased)
                                                                      {
                                                                          if (e.key.code == sf::Keyboard::BackSpace)
                                                                          {
                                                                              if (str.size() > 0)
                                                                              {
                                                                                  str.pop_back();
                                                                              }
                                                                          }
                                                                          else if (e.key.code == sf::Keyboard::Enter)
                                                                          {
                                                                              done = true;
                                                                              removeListeners();
                                                                          }
                                                                      }
                                                                  });
        }
        bool TextInputBox::captureDone() const
        {
            return done;
        }
        std::string TextInputBox::getCapture()
        {

            done = false;
            std::string cpy{str};
            return cpy;
        }

    }
}