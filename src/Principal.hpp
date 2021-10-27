#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_

// #include <SFML/Graphics.hpp>
#include "Personagem.hpp"

namespace jogoOO
{
    class Principal
    {
    private:
        // Atributo da janela criada para o jogo.
        sf::RenderWindow *janela;
        // Atributo referente ao personagem "amigo".
        Personagens::Personagem amigo;

    public:
        // Construtora de Principal.
        Principal();
        // Destrutora de Principal.
        ~Principal();
        // Método executar de Principal.
        int executar();
    };
}

#endif //