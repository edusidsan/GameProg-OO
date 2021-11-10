#ifndef _OTHERGRANDRANDOMOGRE_HPP_
#define _OTHERGRANDRANDOMOGRE_HPP_

// #include "PhysicalEntities/PhysicalEntity.hpp"
// #include "Lists/PhysicalEntityList.hpp"
#include "Managers/GraphicManager.hpp"
// #include "Managers/EventsManager.hpp"
// #include "Managers/CollisionManager.hpp"
// #include "Tiles/TilesManager.hpp"
#include "Menus/Menu.hpp"
#include "PhysicalEntities/Characters/Players/Shrek.hpp"
#include "Levels/MedievalRuins.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    class OtherGrandRandomOgre
    {
    private:
        // Atributo do gerenciador gráfico criado para o jogo.
        Managers::GraphicManager graphicManager;
        // Atributo que cria objeto da classe do player Shrek.
        PhysicalEntities::Characters::Players::Shrek player1;
        // Atributo que indica se a fase deve ser finalizada.
        bool endLevel;

        Levels::MedievalRuins firstLevel;
        
        Menus::Menu menu;

    public:
        // Construtora da classe OtherGrandRandomOgre.
        OtherGrandRandomOgre();
        // Destrutora da classe OtherGrandRandomOgre.
        ~OtherGrandRandomOgre();
        // Método executar de OtherGrandRandomOgre.
        int run();
        // Método encarregado de encerrar processo do jogo caso o evento de fechar a janela do jogo tenha ocorrido.
        void closedWindow(const sf::Event &event);
    };
}
#endif