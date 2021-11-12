#include "ScreenManager.hpp"
#include "../Levels/MedievalRuins.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {
        // GerenciadorTelas(GraphicManager &gg, Heroi *jogador1 = nullptr);
        ScreenManager::ScreenManager(PhysicalEntities::Characters::Players::Shrek *_player1) : player1{_player1}
        {
            push(new Levels::MedievalRuins(player1));
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
            default:
                return false;
            }
        }
    }
}
