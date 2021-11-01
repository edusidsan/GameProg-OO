
#include "Enemy.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {

                // Construtora da classe Enemy.
                Enemy::Enemy(Utilities::myVector2F pos, Utilities::myVector2F s) : Character(pos, s, "../assets/Witch-all.png")
                {
                }
                // Destrutora da classe Enemy.
                Enemy::~Enemy()
                {
                }

            }
        }
    }
}