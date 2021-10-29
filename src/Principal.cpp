#include <SFML/Graphics.hpp>
#include "Principal.hpp"

namespace jogoOO
{
    // Construtora de Principal
    Principal::Principal() : window{new sf::RenderWindow(sf::VideoMode(800, 600), "Game-OO")},
                             player1{"../assets/player.png"}
    {
        Principal::run();
    }
    // Destrutora de Principal
    Principal::~Principal()
    {
        delete window;
    }
    // Método executar de Principal
    int Principal::run()
    {
        while (true)
        {
            window->clear();
            player1.update();
            player1.draw(window);
            window->display();
        }
        return 0;
    }
}