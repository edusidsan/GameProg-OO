#ifndef _PROMISSETEXT_HPP_
#define _PROMISSETEXT_HPP_

#include <string>
#include "../Managers/EventsManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Menus // Namespace do Pacote Menus.
    {
        class PromisseText
        {
        private:
            std::string text;
            unsigned int keyKeyboardEvent;
            bool inputStarted;
            bool textReady;
            Managers::EventsManager &em;
            unsigned short maxLength;

        public:
            // Construtora da classe PromisseText.
            PromisseText(Managers::EventsManager &_em, unsigned short _maxLength = 0);
            // Destrutora da classe PromisseText.
            ~PromisseText();
            void inputStart();
            bool getReadyText() const;
            const std::string &getText() const;
            void readingText(const sf::Event &e);
        };
    }
}
#endif