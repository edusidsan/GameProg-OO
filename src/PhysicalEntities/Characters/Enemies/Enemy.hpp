#ifndef _ENEMY_HPP_
#define _ENEMY_HPP_

#include "../Character.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {
                class Enemy : public Character
                {
                public:
                    // Construtora da classe Enemy.
                    Enemy(Utilities::myVector2F pos, Utilities::myVector2F s);
                    // Destrutora da classe Enemy.
                    ~Enemy();
                };
            }
        }
    }
}
#endif