
#include "Dragon.hpp"
#include "../../../Levels/Level.hpp"
#include "../../Projectiles/Fire.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {

                // Construtora da classe Dragon.
                Dragon::Dragon(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath) : Enemy(pos, s, "../assets/Dragon.png")
                //"../assets/Dragon.png"
                {
                    // Atribui um ID ao Dragon.
                    id = 104;
                }
                Dragon::Dragon(nlohmann::json source) : Enemy(Utilities::myVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::myVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])}, "../assets/Dragon.png")
                {
                    // Atribui um ID ao Dragon.
                    id = 104;
                }
                // Destrutora da classe Dragon.
                Dragon::~Dragon()
                {
                }
                // Método carrega a textura do Dragon na window e inicializa gerenciadores do mesmo.
                // void Dragon::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm)
                void Dragon::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
                {
                    // Carrega textura no player.
                    pGraphicManager->loadAsset(texturePath);
                    // Retorna dimensão da imagem.
                    dimension = pGraphicManager->getDimensionsOfAsset(texturePath);

                    // Adiciona Dragon na lista de entidades físicas colidiveis.
                    cm.addToLCollidablesPhysicalEntities((this));
                    currentLevel = this->getLevel();
                    // this->setLife(MAX_LIFE/100);
                    Life = MAX_LIFE / 100;
                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Dragon::collided(int IDOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
                {
                    // Caso colida com Player1.
                    if ((IDOther == 100) || (IDOther == 101))
                    {
                        // std::cout << "OBJETO ENEMY >>> COLISAO COM PLAYER1::SHREK1." << std::endl;
                    }
                    // Caso colida com Enemy.
                    if ((IDOther == 102) || (IDOther == 103))
                    {
                        // Cálculo da distância entre os enemy no momento da colisão.
                        // Utilities::myVector2F distance = position - positionOther;
                        // Medida para não manter um enemy preso dentro do outro.
                        // position += distance * (1 / 2);
                        // std::cout << "OBJETO ENEMY >>> COLISAO COM OBJETO ENEMY." << std::endl;
                        // // std::cout<<"AAAAAAAAA"<<std::endl;
                        // // Caso colida com Player1.
                        // if (IDOther == 101)
                        // {
                        //     // std::cout << "OBJETO Dragon >>> COLISAO COM PLAYER1::SHREK1." << std::endl;
                        // }
                        // // Caso colida com Dragon.
                        // else if (IDOther == 102)
                        // {
                        //     // Cálculo da distância entre os Dragon no momento da colisão.
                        //     Utilities::myVector2F distance = position - positionOther;
                        //     // Medida para não manter um Dragon preso dentro do outro.
                        //     position += distance * (1 / 2);
                        //     // std::cout << "OBJETO Dragon >>> COLISAO COM OBJETO Dragon." << std::endl;
                        //     // Muda o sentido da velocidade em x.
                        //     speed.coordX *= -1;
                        //     // Muda o sentido da velocidade em y.
                        //     speed.coordY *= -1;
                    }
                    //Chão
                    if (IDOther == 14)
                    {

                        // float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                        // float distY = (position.coordY + (dimension.coordY / 2)) - abs(positionOther.coordY - (dimensionOther.coordY / 2));
                        // if (distX * distY > .001 * dimension.coordX * dimension.coordY)
                        // { // passa a ignorar colisões ignoráveis (bem as problemáticas)
                        //     if (distX < distY)
                        //     {
                        //         // colisão em X
                        //         if (distX > abs(adjusts.coordX))
                        //         {
                        //             adjusts.coordX = distX * (position.coordX + (dimension.coordX) / 2 > positionOther.coordX + dimensionOther.coordX / 2 ? -0.5 : 0.5);
                        //         }
                        //     }
                        //     else
                        //     {
                        //         // colisão em Y
                        //         if (distY > abs(adjusts.coordY))
                        //         {
                        //             adjusts.coordY = distY * (position.coordY + (dimension.coordY / 2) > positionOther.coordY - (dimensionOther.coordY / 2) ? -0.5 : 0.5);
                        //         }
                        //     }
                        // }
                        // speed.coordY = 0.f;
                        // maxSpeedX = MAXSPEEDX;
                    }
                    // Espinho
                    else if (IDOther == 51)
                    {

                        // float distY = (position.coordY + (dimension.coordY / 2)) - abs(positionOther.coordY - (dimensionOther.coordY / 2));
                        // // colisão em Y
                        // if (distY > abs(adjusts.coordY))
                        // {
                        //     adjusts.coordY = distY * (position.coordY + (dimension.coordY / 2) > positionOther.coordY - (dimensionOther.coordY / 2) ? -0.5 : 0.5);
                        // }
                        // // timeReference = clock.getCurrent()/1000;
                        // speed.coordY = 0.f;
                    }

                    // Parede
                    else if (IDOther == 1)
                    {
                        // float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                        // // colisão em X
                        // if (distX > abs(adjusts.coordX))
                        // {
                        //     // adjusts.coordX = distX * (position.coordX + (dimension.coordX / 2) > positionOther.coordX - (dimensionOther.coordX / 2) ? -0.5 : 0.5);
                        // }
                        // speed.coordX = 0.f;
                    }
                    // Obstaculo que faz pular.
                    else if (IDOther == 54)
                    {
                        // float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                        // // colisão em X
                        // if (distX > abs(adjusts.coordX))
                        // {
                        //     position.coordY -= 0.5f;
                        //     speed.coordY -= maxSpeedY;
                        // }
                    }
                    // Obstaculo troca de fase.
                    else if (IDOther == 35)
                    {
                    }
                    // Obstaculo que reduz velocidade.
                    else if (IDOther == 6)
                    {
                        // float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                        // float distY = (position.coordY + (dimension.coordY / 2)) - abs(positionOther.coordY - (dimensionOther.coordY / 2));
                        // if (distX * distY > .001 * dimension.coordX * dimension.coordY)
                        // { // passa a ignorar colisões ignoráveis (bem as problemáticas)
                        //     if (distX < distY)
                        //     {
                        //         // colisão em X
                        //         if (distX > abs(adjusts.coordX))
                        //         {
                        //             adjusts.coordX = distX * (position.coordX + (dimension.coordX) / 2 > positionOther.coordX + dimensionOther.coordX / 2 ? -0.5 : 0.5);
                        //         }
                        //     }
                        //     else
                        //     {
                        //         // colisão em Y
                        //         if (distY > abs(adjusts.coordY))
                        //         {
                        //             adjusts.coordY = distY * (position.coordY + (dimension.coordY / 2) > positionOther.coordY - (dimensionOther.coordY / 2) ? -0.5 : 0.5);
                        //             maxSpeedX = MAXSPEEDX / 2.0f;
                        //         }
                        //     }
                        // }
                        // speed.coordY = 0.f;
                    }
                }
                void Dragon::update(float t)
                {

                    if (abs(speed.coordX) > maxSpeedX)
                    {
                        speed.coordX = maxSpeedX * (speed.coordX > 0 ? 1 : -1);
                    }
                    if (abs(speed.coordY) > maxSpeedY)
                    {
                        speed.coordY = maxSpeedY * (speed.coordY > 0 ? 1 : -1);
                    }
                    // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
                    position += speed * t;
                    position += adjusts;
                    adjusts = Utilities::myVector2F(0, 0);

                    if (projectileInterval > 0)
                    {
                        projectileInterval--;
                    }
                    else
                    {
                        projectileInterval = 450;

                        Utilities::myVector2F playerPosition = currentLevel->getMainPlayerPosition();
                        // Utilities::myVector2F playerPosition;
                        Utilities::myVector2F playerDirection = (playerPosition - position);

                        if (playerDirection.vModule() < 500)
                        {
                            currentLevel->addPhysicalEntity(new Projectiles::Fire({position.coordX - 50, position.coordY + 30}, playerDirection.unitVector() * 50));
                        }
                    }
                }
            }
        }
    }
}