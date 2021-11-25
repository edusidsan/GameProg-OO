#include "Apple.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote PhysicalEntities.
    {
        namespace Projectiles // Namespace do Pacote Projectiles.
        {
            // Construtora da classe Apple.
            Apple::Apple(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath) : Projectile{pos, s, "../assets/Apple.png"}
            {
                id = 200;
            }
            Apple::Apple(nlohmann::json source) : Projectile(Utilities::myVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::myVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])}, "../assets/Apple.png")
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
            void Apple::collided(int idOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
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
