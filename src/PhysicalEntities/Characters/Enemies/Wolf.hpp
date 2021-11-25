#ifndef _WOLF_HPP_
#define _WOLF_HPP_

#include "Enemy.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {
                class Wolf : public Enemy
                {
                private:
                    bool collidingFlag;
                public:
                    // Construtora da classe Wolf.
                    Wolf(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath = nullptr);
                    Wolf(nlohmann::json source);
                    // Destrutora da classe Wolf.
                    ~Wolf();
                    // Método carrega a textura do Wolf na window e inicializa gerenciadores do mesmo.
                    // void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm);
                    void initialize(Managers::EventsManager &em, Managers::CollisionManager &cm);
                     // Método verifica colisão entre dois objetos da classe Entidade Física.
                    void collided(int idOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther);
                    //tentativa de usar tempo
                    void update(float t);
                    
                    
                };
            }
        }
    }
}
#endif