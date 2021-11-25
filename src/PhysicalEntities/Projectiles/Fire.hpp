#ifndef _FIRE_HPP_
#define _FIRE_HPP_

#include "Projectile.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote PhysicalEntities.
    {
        namespace Projectiles // Namespace do Pacote Projectiles.
        {
            class Fire : public Projectile
            {
            public:
                // Construtora da classe Fire.
                Fire(Utilities::myVector2F pos = {0.0f, 0.0f}, Utilities::myVector2F s = {0.0f, 0.0f}, const char *tPath = nullptr);
                // Destrutora da classe Fire.
                ~Fire();
                // Método atualizar do Fire. Tem como parâmetro uma variável float que representa o tempo.
                virtual void update(float t) override;
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                virtual void collided(int idOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther) override;
            };
        }
    }
}
#endif