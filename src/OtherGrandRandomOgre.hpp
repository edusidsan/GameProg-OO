#ifndef _OTHERGRANDRANDOMOGRE_HPP_
#define _OTHERGRANDRANDOMOGRE_HPP_

#include "PhysicalEntities/PhysicalEntity.hpp"
#include "Lists/PhysicalEntityList.hpp"
#include "Managers/GraphicManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    class OtherGrandRandomOgre
    {
    private:
        // Atributo que verifica se botão de fechar da janela do SFML foi clicado.
        bool closeWindowEvent;
        // Atributo do gerenciador gráfico criado para o jogo.
        Managers::GraphicManager graphicManager;
        // Atributo do gerenciador de eventos criado para o jogo.
        Managers::EventsManager eventsManager;
        // Atributo de um relógio que será útil para verificação do tempo.
        sf::Clock clock;
        // Atributo referente a lista de entidades físicas.
        Lists::PhysicalEntityList players;

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