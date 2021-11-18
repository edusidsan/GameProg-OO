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
                    Enemy(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath = nullptr);
                    Enemy(nlohmann::json source);
                    // Destrutora da classe Enemy.
                    ~Enemy();
                    // Método carrega a textura do enemy na window e inicializa gerenciadores do mesmo.
                    // void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm);
                    void initialize(Managers::EventsManager &em, Managers::CollisionManager &cm);
                     // Método verifica colisão entre dois objetos da classe Entidade Física.
                    void collided(int IDOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther);
                };
            }
        }
    }
}
#endif