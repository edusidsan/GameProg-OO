#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_ 

// #include <SFML/Graphics.hpp>
#include "Personagem.hpp"

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

#endif //