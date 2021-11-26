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
                Fire(Utilities::gameVector2F pos = {0.0f, 0.0f}, Utilities::gameVector2F s = {0.0f, 0.0f}, const char *tPath = nullptr);
                Fire(nlohmann::json source);
                // Destrutora da classe Fire.
                ~Fire();
                // Método atualizar do Fire. Tem como parâmetro uma variável float que representa o tempo.
                virtual void update(float t) override;
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                virtual void collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther) override;
            };
        }
    }
}
#endif