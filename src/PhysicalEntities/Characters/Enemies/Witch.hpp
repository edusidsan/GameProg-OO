#ifndef _WITCH_HPP_
#define _WITCH_HPP_

#include "Enemy.hpp"


namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {
                class Witch : public Enemy
                {
                public:
                    // Construtora da classe Witch.
                    Witch(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath = nullptr);
                    // Destrutora da classe Witch.
                    ~Witch();
                    // Método carrega a textura do Witch na window e inicializa gerenciadores do mesmo.
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