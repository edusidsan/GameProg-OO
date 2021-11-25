#ifndef _DRAGON_HPP_
#define _DRAGON_HPP_

#include "Enemy.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {
                class Dragon : public Enemy
                {
                public:
                    // Construtora da classe Dragon.
                    Dragon(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath = nullptr);
                    Dragon(nlohmann::json source);
                    // Destrutora da classe Dragon.
                    ~Dragon();
                    // Método carrega a textura do Dragon na window e inicializa gerenciadores do mesmo.
                    // void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm);
                    void initialize(Managers::EventsManager &em, Managers::CollisionManager &cm);

                    void update(float t);
                    // Método verifica colisão entre dois objetos da classe Entidade Física.
                    void collided(int idOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther);

                };
            }
        }
    }
}
#endif