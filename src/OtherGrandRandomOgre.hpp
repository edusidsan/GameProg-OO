#ifndef _OTHERGRANDRANDOMOGRE_HPP_
#define _OTHERGRANDRANDOMOGRE_HPP_

#include "Managers/GraphicManager.hpp"
#include "Menus/Menu.hpp"
#include "PhysicalEntities/Characters/Players/Shrek.hpp"
#include "Levels/MedievalRuins.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    class OtherGrandRandomOgre
    {
    private:
        // Atributo ponteiro do gerenciador gráfico criado para o jogo na Classe GraphicManager.
        // Utiliza o padrão de projeto Singleton.
        Managers::GraphicManager *pGraphicManager;
        //
        Menus::Menu menu;
        // Atributo que cria objeto da classe do player Shrek.
        PhysicalEntities::Characters::Players::Shrek player1;
        // Atributo que indica se a fase deve ser finalizada.
        bool endLevel;
        //
        Levels::MedievalRuins firstLevel;

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