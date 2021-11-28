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
                    Witch(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath = nullptr);
                    Witch(nlohmann::json source);
                    // Destrutora da classe Witch.
                    ~Witch();
                    // Método carrega a textura do Witch na window e inicializa gerenciadores do mesmo.
                    void initialize();

                    void update(float t);
                    // Método verifica colisão entre dois objetos da classe Entidade Física.
                    void collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther);
                };
            }
        }
    }
}
#endif