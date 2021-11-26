#ifndef _APPLE_HPP_
#define _APPLE_HPP_

#include "Projectile.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote PhysicalEntities.
    {
        namespace Projectiles // Namespace do Pacote Projectiles.
        {
            class Apple : public Projectile
            {
            public:
                // Construtora da classe Apple.
                Apple(Utilities::gameVector2F pos = {0.0f, 0.0f}, Utilities::gameVector2F s = {0.0f, 0.0f}, const char *tPath = nullptr);
                Apple(nlohmann::json source);
                // Destrutora da classe Apple.
                ~Apple();
                // Método atualizar do Apple. Tem como parâmetro uma variável float que representa o tempo.
                virtual void update(float t) override;
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                virtual void collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther) override;
            };
        }
    }
}
#endif