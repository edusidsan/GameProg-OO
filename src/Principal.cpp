#include <SFML/Graphics.hpp>
#include "Principal.hpp"

namespace jogoOO
{
    // Construtora de Principal
    Principal::Principal() : janela{new sf::RenderWindow(sf::VideoMode(800, 600), "Game-OO")},
                             amigo{0, 0, "../assets/player.png"}
    {
        Principal::executar();
    }
    // Destrutora de Principal
    Principal::~Principal()
    {
        delete janela;
    }
    // Método executar de Principal
    int Principal::executar()
    {
        while (true)
        {
            janela->clear();
            amigo.atualizar();
            amigo.desenhar(janela);
            janela->display();
        }
        return 0;
    }
}