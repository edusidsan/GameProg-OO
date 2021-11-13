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
                                                   screenManager{&player1},
                                                   player1{PhysicalEntities::Characters::Players::Shrek(Utilities::myVector2F(64.0f, 64.0f))},
                                                   endLevel{false}
    {
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
            pGraphicManager->clear();

            endLevel = screenManager.run();

            // Mostra a window para o usuário.
            pGraphicManager->display();
        }
        return 0;
    }
}
