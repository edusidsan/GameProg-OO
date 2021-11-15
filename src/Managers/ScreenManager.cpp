#include "ScreenManager.hpp"
#include "../Levels/MedievalRuins.hpp"
#include "../Menus/MainMenu.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {
        // GerenciadorTelas(GraphicManager &gg, Heroi *jogador1 = nullptr);
        ScreenManager::ScreenManager(PhysicalEntities::Characters::Players::Shrek *_player1, PhysicalEntities::Characters::Players::Donkey *_player2) : player1{_player1},
                                                                                                                                                        player2{_player2}
        {
            push(new Menus::MainMenu());
        }
        ScreenManager::~ScreenManager()
        {
        }
        bool ScreenManager::handleCode(int GameCode)
        {
            switch (GameCode)
            {
            case endGame:
                return true;
            case toFirstLevel:
                push(new Levels::MedievalRuins(player1, player2));
                return false;
                break;
            default:
                return false;
            }
        }
    }
}
