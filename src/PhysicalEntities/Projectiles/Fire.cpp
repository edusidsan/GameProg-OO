#include "Fire.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote PhysicalEntities.
    {
        namespace Projectiles // Namespace do Pacote Projectiles.
        {
            // Construtora da classe Fire.
            Fire::Fire(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath) : Projectile{pos, s, "../assets/Fire.png"}
            {
                id = 201;
            }
            Fire::Fire(nlohmann::json source) : Projectile(Utilities::gameVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::gameVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])}, "../assets/Fire.png")
            {
            }
            // Destrutora da classe Fire.
            Fire::~Fire()
            {
            }
            // Método atualizar do Fire. Tem como parâmetro uma variável float que representa o tempo.
            void Fire::update(float t)
            {
                Projectile::update(t);
            }
            // Método verifica colisão entre dois objetos da classe Entidade Física.
            void Fire::collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther)
            {
                if (idOther == 100 || idOther == 101)
                {
                    // std::cout << "Acertei um dos players" << std::endl;
                    // delete this;
                }
            }
        }
    }
}
