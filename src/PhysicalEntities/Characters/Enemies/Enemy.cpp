
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
                Enemy::Enemy(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath, unsigned int life) : Character(pos, s, tPath, life),
                                                                                                                         timeReference{0},
                                                                                                                         projectileInterval{0}
                {
                    // Atribui um ID ao Enemy.
                    // id = 102;
                }

                Enemy::Enemy(nlohmann::json source) : Enemy(Utilities::gameVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::gameVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])}, "", static_cast<unsigned int>(source["life"]))
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
                void Enemy::update(float t)
                {
                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Enemy::collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther)
                {
                    // Caso colida com Player1.
                    if ((idOther == 100) || (idOther == 101))
                    {
                        // std::cout << "OBJETO ENEMY >>> COLISAO COM PLAYER1::SHREK1." << std::endl;
                    }
                    // Caso colida com Enemy.
                    else if ((idOther == 102) || (idOther == 103))
                    {
                        // Cálculo da distância entre os enemy no momento da colisão.
                        Utilities::gameVector2F distance = position - positionOther;
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