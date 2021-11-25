#ifndef _PROJECTILE_HPP_
#define _PROJECTILE_HPP_

#include "../PhysicalEntity.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote PhysicalEntities.
    {
        namespace Projectiles // Namespace do Pacote Projectiles.
        {
            class Projectile : public PhysicalEntity
            {
            public:
                // Construtora da classe Projectile.
                Projectile(Utilities::myVector2F pos = {0.0f, 0.0f}, Utilities::myVector2F s = {0.0f, 0.0f}, const char *tPath = nullptr);
                // Destrutora da classe Projectile.
                ~Projectile();
                // Método carrega a textura do Projectile na window.
                virtual void initialize(Managers::EventsManager &em, Managers::CollisionManager &cm) override;
                // Método atualizar do Projectile. Tem como parâmetro uma variável float que representa o tempo.
                virtual void update(float t) override;
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                virtual void collided(int idOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther) override;
            };
        }
    }
}
#endif