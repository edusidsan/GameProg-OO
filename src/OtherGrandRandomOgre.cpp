#include "OtherGrandRandomOgre.hpp"
#include "PhysicalEntities/Characters/Enemies/Enemy.hpp"
#include "PhysicalEntities/Characters/Players/Shrek.hpp"
#include "Tiles/Tile.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    // Construtora da classe OtherGrandRandomOgre
    /* Lista de inicialização da construtora com:
        booleana closedWindowEvent setada para false
    */
    OtherGrandRandomOgre::OtherGrandRandomOgre() : pGraphicManager(Managers::GraphicManager::getInstance()),
                                                   menu(),
                                                   player1{PhysicalEntities::Characters::Players::Shrek(Utilities::myVector2F(64.0f, 64.0f))},
                                                   endLevel{false},
                                                   firstLevel{&player1}

    //    menu()

    {
        // menu.setGraphicManager(graphicManager);
    }
    // Destrutora da classe OtherGrandRandomOgre
    OtherGrandRandomOgre::~OtherGrandRandomOgre()
    {
    }
    // Método executar de OtherGrandRandomOgre
    int OtherGrandRandomOgre::run()
    {
        while (!endLevel)
        {
            // Limpa a window.
            // graphicManager.clear();
            pGraphicManager->clear();

            firstLevel.run();

            // Mostra a window para o usuário.
            // graphicManager.display();
            pGraphicManager->display();
        }
        return 0;
    }
}
