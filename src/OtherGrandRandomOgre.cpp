#include "OtherGrandRandomOgre.hpp"
//#include "PhysicalEntities/Characters/Enemies/Enemy.hpp"
//#include "PhysicalEntities/Characters/Players/Shrek.hpp"
#include "Tiles/Tile.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    // Construtora da classe OtherGrandRandomOgre
    /* Lista de inicialização da construtora com:
        booleana closedWindowEvent setada para false
    */
    OtherGrandRandomOgre::OtherGrandRandomOgre() : pGraphicManager(Managers::GraphicManager::getInstance()),
                                                   pEventsManager(Managers::EventsManager::getInstance()),
                                                   pCollisionManager(Managers::CollisionManager::getInstance()),
                                                   player1(PhysicalEntities::Characters::Players::Shrek(Utilities::gameVector2F(64.0f, 230.56f))),
                                                   player2(PhysicalEntities::Characters::Players::Donkey(Utilities::gameVector2F(80.0f, 230.56f))),
                                                   screenManager(&player1, &player2),
                                                   endLevel(false)
    {
        menu.initialize();
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
