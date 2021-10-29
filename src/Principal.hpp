#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_

// #include <SFML/Graphics.hpp>
#include "Personagem.hpp"

namespace jogoOO
{
    class Principal
    {
    private:
        // Atributo da window criada para o jogo.
        sf::RenderWindow *window;
        // Atributo referente ao personagem "player1".
        Personagens::Personagem player1;
     
    public:
        // Construtora de Principal.
        Principal();
        // Destrutora de Principal.
        ~Principal();
        // Método executar de Principal.
        int run();
    };
}

#endif //