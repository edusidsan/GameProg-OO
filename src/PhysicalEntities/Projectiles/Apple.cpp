#include "Apple.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote PhysicalEntities.
    {
        namespace Projectiles // Namespace do Pacote Projectiles.
        {
            // Construtora da classe Apple.
            Apple::Apple(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath) : Projectile{pos, s, "../assets/Apple.png"}
            {
                id = 200;
            }
            Apple::Apple(nlohmann::json source) : Projectile(Utilities::gameVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::gameVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])}, "../assets/Apple.png")
            {
            }
            // Destrutora da classe Apple.
            Apple::~Apple()
            {
            }
            // Método atualizar do Apple. Tem como parâmetro uma variável float que representa o tempo.
            void Apple::update(float t)
            {
                Projectile::update(t);
            }
            // Método verifica colisão entre dois objetos da classe Entidade Física.
            void Apple::collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther)
            {
            }
        }
    }
}
