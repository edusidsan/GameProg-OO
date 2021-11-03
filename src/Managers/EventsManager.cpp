#include "EventsManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {
        // Inicialização do static nextKey.
        unsigned int EventsManager::nextKey{0};

        // Construtora da classe EventsManager.
        EventsManager::EventsManager()
        {
        }
        // Destrutora da classe EventsManager.
        EventsManager::~EventsManager()
        {
        }
        // Método que trata os eventos.
        void EventsManager::handleEvent()
        {
            // Enquanto o método pollEvent de window receber algo.
            while (window->pollEvent(event))
            {
                // Caso o código do event seja referente à um evento de mouse.
                if ((event.type == sf::Event::MouseWheelScrolled) ||
                    (event.type == sf::Event::MouseMoved) ||
                    (event.type == sf::Event::MouseButtonReleased) ||
                    (event.type == sf::Event::MouseButtonPressed))
                {
                    // Percorre iterador do callback de Mouse.
                    for (auto i = mouseCallback.begin(); i != mouseCallback.end(); ++i)
                    {
                        // Chama a função dentro de map refente ao tipo de evento ocorrido.
                        i->second(event);
                    }
                }
                // Caso o código do event seja referente à um evento de teclado.
                else if ((event.type == sf::Event::KeyPressed) ||
                         (event.type == sf::Event::KeyReleased))
                {
                    // Percorre iterador do callback de teclado.
                    for (auto i = keyboardCallback.begin(); i != keyboardCallback.end(); ++i)
                    {
                        // Chama a função dentro de map refente ao tipo de evento ocorrido.
                        i->second(event);
                    }
                }
                else
                {
                    // Percorre iterador do callback de outros tipos.
                    for (auto i = otherCallback.begin(); i != otherCallback.end(); ++i)
                    {
                        // Chama a função dentro de map refente ao tipo de evento ocorrido.
                        i->second(event);
                    }
                }
            }
        }
        // Método definde a window que será utilizada.
        void EventsManager::setWindow(sf::RenderWindow *w)
        {
            window = w;
            // Garante que quando a tecla é segurada, apenas 1 código é retornado.
            window->setKeyRepeatEnabled(false);
        }
        // Método retorna a próxima key disponível dentro de map da função referente ao evento de mouse ocorrido.
        unsigned int EventsManager::addMouseListener(std::function<void(const sf::Event)> callback)
        {
            // Adiciona na estrutura de dados Map uma chave única e a função atribuída à mesma.
            mouseCallback.emplace(nextKey, callback);
            return nextKey++;
        }
        // Método remove a key dentro de map da função referente ao evento de mouse ocorrido.
        void EventsManager::removeMouseListener(int key)
        {
            // Remove na estrutura de dados Map os dados referentes a chave única.
            mouseCallback.erase(key);
        }
        // Método retorna a próxima key disponível dentro de map da função referente ao evento de teclado ocorrido.
        unsigned int EventsManager::addKeyboardListener(std::function<void(const sf::Event)> callback)
        {
            // Adiciona na estrutura de dados Map uma chave única e a função atribuída à mesma.
            keyboardCallback.emplace(nextKey, callback);
            return nextKey++;
        }
        // Método remove a key dentro de map da função referente ao evento de teclado ocorrido.
        void EventsManager::removeKeyboardListener(int key)
        {
            // Remove na estrutura de dados Map os dados referentes a chave única.
            keyboardCallback.erase(key);
        }
        // Método retorna a próxima key disponível dentro de map da função referente ao evento de outro tipo ocorrido.
        unsigned int EventsManager::addOtherListener(std::function<void(const sf::Event)> callback)
        {
            // Adiciona na estrutura de dados Map uma chave única e a função atribuída à mesma.
            otherCallback.emplace(nextKey, callback);
            return nextKey++;
        }
        // Método remove a key dentro de map da função referente ao evento de outro tipo ocorrido.
        void EventsManager::removeOtherListener(int key)
        {
            // Remove na estrutura de dados Map os dados referentes a chave única.
            otherCallback.erase(key);
        }
    }
}