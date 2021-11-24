#ifndef _EVENTSMANAGER_HPP_
#define _EVENTSMANAGER_HPP_

#include <SFML/Graphics.hpp>
#include <map>
#include <functional> // Biblioteca útil para tratar funções como "atributos".

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {

        enum class EventType
        {
            Other = -1,
            KeyPressed = 0,
            KeyReleased,
            TextEntered,
            MouseWheelScrolledUp,
            MouseWheelScrolledDown,
            MouseButtonPressed,
            MouseButtonReleased,
        };
        class EventsManager
        {
        private:
            // Atributo referente à próxima chave utilizada nas estruturas de dados map.
            static unsigned int nextKey;
            // Atributo referente ao ponteriro da janela na qual irá ler os eventos.
            sf::RenderWindow *window;
            // Atributo de estrutura de dados do tipo map. Parametrizado com uma chave única (key) e um void referente a função Events da biblioteca SFML.
            std::map<unsigned int, std::function<void(const sf::Event &)>> mouseCallback;
            // Atributo de estrutura de dados do tipo map. Parametrizado com uma chave única (key) e um void referente a função Events da biblioteca SFML.
            std::map<unsigned int, std::function<void(const sf::Event &)>> keyboardCallback;
            // Atributo de estrutura de dados do tipo map. Parametrizado com uma chave única (key) e um void referente a função Events da biblioteca SFML.
            std::map<unsigned int, std::function<void(const sf::Event &)>> otherCallback;
            // Atributo event utilziado à partir da biblioteca SFML.
            sf::Event event;

            // Padrão Singleton
            static EventsManager *instanceEventsManager;

            // Construtora da classe EventsManager.
            EventsManager();

        public:
            // Destrutora da classe EventsManager.
            ~EventsManager();

            static EventsManager *getInstance();

            void setEvent(sf::Event ev);

            const EventType getType() const;

            // Método que trata os eventos.
            void handleEvent();
            // Método definde a window que será utilizada.
            void setWindow(sf::RenderWindow *w);
            // Método retorna a key dentro de map da função referente ao evento de mouse ocorrido.
            unsigned int addMouseListener(std::function<void(const sf::Event &)> callback);
            // Método remove a key dentro de map da função referente ao evento de mouse ocorrido.
            void removeMouseListener(int key);
            // Método retorna a key dentro de map da função referente ao evento de teclado ocorrido.
            unsigned int addKeyboardListener(std::function<void(const sf::Event &)> callback);
            // Método remove a key dentro de map da função referente ao evento de teclado ocorrido.
            void removeKeyboardListener(int key);
            // Método retorna a key dentro de map da função referente ao evento de outro tipo ocorrido.
            unsigned int addOtherListener(std::function<void(const sf::Event &)> callback);
            // Método remove a key dentro de map da função referente ao evento de outro tipo ocorrido.
            void removeOtherListener(int key);
        };
    }
}
#endif