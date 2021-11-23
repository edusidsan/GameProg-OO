
#include "Enemy.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {

                // Construtora da classe Enemy.
                Enemy::Enemy(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath) : Character(pos, s, tPath),
                                                                                                      timeReference{0},
                                                                                                      projectileInterval{0}
                {
                    // Atribui um ID ao Enemy.
                    // id = 102;
                }

                Enemy::Enemy(nlohmann::json source) : Enemy(Utilities::myVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::myVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])})
                {
                }
                // Destrutora da classe Enemy.
                Enemy::~Enemy()
                {
                }
                // Método carrega a textura do enemy na window e inicializa gerenciadores do mesmo.
                // void Enemy::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm)
                void Enemy::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
                {
                    // // Carrega textura no player.
                    // gm.loadAsset(texturePath);
                    // // Retorna dimensão da imagem.
                    // dimension = gm.getDimensionsOfAsset(texturePath);

                    // Carrega textura no player.
                    pGraphicManager->loadAsset(texturePath);
                    // Retorna dimensão da imagem.
                    dimension = pGraphicManager->getDimensionsOfAsset(texturePath);

                    // Adiciona enemy na lista de entidades físicas colidiveis.
                    cm.addToLCollidablesPhysicalEntities((this));
                }
                void Enemy::update(float t){

                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Enemy::collided(int IDOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
                {
                    // Caso colida com Player1.
                    if ((IDOther == 100) || (IDOther == 101))
                    {
                        // std::cout << "OBJETO ENEMY >>> COLISAO COM PLAYER1::SHREK1." << std::endl;
                    }
                    // Caso colida com Enemy.
                    else if ((IDOther == 102) || (IDOther == 103))
                    {
                        // Cálculo da distância entre os enemy no momento da colisão.
                        Utilities::myVector2F distance = position - positionOther;
                        // Medida para não manter um enemy preso dentro do outro.
                        position += distance * (1 / 2);
                        // std::cout << "OBJETO ENEMY >>> COLISAO COM OBJETO ENEMY." << std::endl;
                        // Muda o sentido da velocidade em x.
                        speed.coordX *= -1;
                        // Muda o sentido da velocidade em y.
                        speed.coordY *= -1;
                    }
                }
            }
        }
    }
}