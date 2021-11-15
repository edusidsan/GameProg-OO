#include "PromisseText.hpp"
#include <iostream>

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        // Construtora da classe PromisseText.
        PromisseText::PromisseText(Managers::EventsManager &_em, unsigned short _maxLength) : keyKeyboardEvent{0},
                                                                                              inputStarted{false},
                                                                                              textReady{false},
                                                                                              em{_em},
                                                                                              maxLength{_maxLength}
        {
        }
        // Destrutora da classe PromisseText.
        PromisseText::~PromisseText()
        {
            em.removeKeyboardListener(keyKeyboardEvent);
        }
        void PromisseText::inputStart()
        {
            if (inputStarted)
            {
                return;
            }
            inputStarted = true;

            text.clear(); //Tira os conteúdos antigos da string

            keyKeyboardEvent = em.addKeyboardListener([this](const sf::Event &e)
                                                      { readingText(e); });
        }
        bool PromisseText::getReadyText() const
        {
            return textReady;
        }
        const std::string &PromisseText::getText() const
        {
            return text;
        }
        void PromisseText::readingText(const sf::Event &e)
        {
            if (e.type == sf::Event::EventType::TextEntered)
            {
                if (text.size() <= maxLength)
                {
                    char c = (e.text.unicode < 128) ? static_cast<char>(e.text.unicode) : '\0';

                    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || c == '_')
                        text += c;
                }
            }
            else if (e.type == sf::Event::EventType::KeyReleased)
            {
                if (e.key.code == sf::Keyboard::Key::Backspace)
                {
                    if (text.size() > 0)
                    {
                        text.pop_back();
                    }
                }
                else if (e.key.code == sf::Keyboard::Key::Enter)
                {
                    textReady = true;
                    inputStarted = false;
                    em.removeKeyboardListener(keyKeyboardEvent);
                    keyKeyboardEvent = 0;
                }
            }
        }
    }
}