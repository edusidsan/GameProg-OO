#ifndef _OTHERGRANDRANDOMOGRE_HPP_
#define _OTHERGRANDRANDOMOGRE_HPP_

#include "Entities/Character.hpp"
#include "Lists/ListCharacters.hpp"
#include <SFML/Graphics.hpp>

namespace OgrO // Namespace com o nome do jogo.
{
    class OtherGrandRandomOgre
    {
    private:
        // Atributo que verifica se botão de fechar da janela do SFML foi clicado.
        bool closeWindowEvent;
        // Atributo da janela criada para o jogo.
        sf::RenderWindow *window;
        // Atributo de um relógio que será útil para verificação do tempo.
        sf::Clock clock;
        // Atributo referente a lista de personagens.
        Lists::ListCharacters players;

    public:
        // Construtora da classe OtherGrandRandomOgre.
        OtherGrandRandomOgre();
        // Destrutora da classe OtherGrandRandomOgre.
        ~OtherGrandRandomOgre();
        // Método executar de OtherGrandRandomOgre.
        int run();
    };
}
#endif