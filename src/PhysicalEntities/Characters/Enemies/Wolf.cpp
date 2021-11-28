
#include "Wolf.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {

                // Construtora da classe Wolf.
                Wolf::Wolf(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath) : Enemy(pos, s, "../assets/Wolf.png"),
                                                                                                        collidingFlag(false)
                {
                    // Atribui um ID ao Wolf.
                    id = 103;
                }
                Wolf::Wolf(nlohmann::json source) : Enemy(Utilities::gameVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::gameVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])}, "../assets/Wolf.png")
                {
                    // Atribui um ID ao Wolf.
                    id = 103;
                }
                // Destrutora da classe Wolf.
                Wolf::~Wolf()
                {
                }
                // Método carrega a textura do Wolf na window e inicializa gerenciadores do mesmo.
                void Wolf::initialize()
                {
                    // Carrega textura no player.
                    pGraphicManager->loadAsset(texturePath);
                    // Retorna dimensão da imagem.
                    dimension = pGraphicManager->getDimensionsOfAsset(texturePath);

                    // Adiciona Wolf na lista de entidades físicas colidiveis.
                    pCollisionManager->addToLCollidablesPhysicalEntities((this));
                }
                void Wolf::update(float t)
                {
                    // Gravidade
                    speed.coordY += 100 * t;
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
                    adjusts = Utilities::gameVector2F(0, 0);

                    if (clock.getCurrent() / 1000 - timeReference > 5)
                    {

                        // Muda o sentido da velocidade em x.
                        speed.coordX *= -1;
                        timeReference = clock.getCurrent() / 1000;
                    }
                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Wolf::collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther)
                {
                    // Caso colida com Enemy.
                    if ((idOther == 102) || (idOther == 103))
                    {
                        // Cálculo da distância entre os enemy no momento da colisão.
                        Utilities::gameVector2F distance = position - positionOther;
                        // Medida para não manter um enemy preso dentro do outro.
                        position += distance * (0.5);
                    }
                    //Chão
                    if ((idOther == 14) || (idOther == 55))
                    {
                        collidingFlag = true;
                        float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                        float distY = (position.coordY + (dimension.coordY / 2)) - abs(positionOther.coordY - (dimensionOther.coordY / 2));
                        if (distX * distY > .001 * dimension.coordX * dimension.coordY)
                        { // passa a ignorar colisões ignoráveis (bem as problemáticas)
                            if (distX < distY)
                            {
                                // colisão em X
                                if (distX > abs(adjusts.coordX))
                                {
                                    adjusts.coordX = distX * (position.coordX + (dimension.coordX) / 2 > positionOther.coordX + dimensionOther.coordX / 2 ? -0.5 : 0.5);
                                }
                            }
                            else
                            {
                                // colisão em Y
                                if (distY > abs(adjusts.coordY))
                                {
                                    adjusts.coordY = distY * (position.coordY + (dimension.coordY / 2) > positionOther.coordY - (dimensionOther.coordY / 2) ? -0.5 : 0.5);
                                }
                            }
                        }
                        speed.coordY = 0.f;
                        maxSpeedX = MAXSPEEDX;
                    }
                    // Espinho
                    else if (idOther == 51)
                    {

                        float distY = (position.coordY + (dimension.coordY / 2)) - abs(positionOther.coordY - (dimensionOther.coordY / 2));
                        // colisão em Y
                        if (distY > abs(adjusts.coordY))
                        {
                            adjusts.coordY = distY * (position.coordY + (dimension.coordY / 2) > positionOther.coordY - (dimensionOther.coordY / 2) ? -0.5 : 0.5);
                        }
                        if (collidingFlag)
                        {
                            speed.coordX *= -1;
                            collidingFlag = false;
                        }
                        // timeReference = clock.getCurrent()/1000;
                        speed.coordY = 0.f;
                    }

                    // Parede
                    else if (idOther == 1)
                    {
                        float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                        // colisão em X
                        if (distX > abs(adjusts.coordX))
                        {
                            // adjusts.coordX = distX * (position.coordX + (dimension.coordX / 2) > positionOther.coordX - (dimensionOther.coordX / 2) ? -0.5 : 0.5);
                        }
                        speed.coordX = 0.f;
                    }
                    // Obstaculo que faz pular.
                    else if (idOther == 54)
                    {
                        float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                        // colisão em X
                        if (distX > abs(adjusts.coordX))
                        {
                            position.coordY -= 0.5f;
                            speed.coordY -= maxSpeedY;
                        }
                    }
                    // Obstaculo troca de fase.
                    else if (idOther == 35)
                    {
                    }
                    // Obstaculo que reduz velocidade.
                    else if (idOther == 6)
                    {
                        float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                        float distY = (position.coordY + (dimension.coordY / 2)) - abs(positionOther.coordY - (dimensionOther.coordY / 2));
                        if (distX * distY > .001 * dimension.coordX * dimension.coordY)
                        { // passa a ignorar colisões ignoráveis (bem as problemáticas)
                            if (distX < distY)
                            {
                                // colisão em X
                                if (distX > abs(adjusts.coordX))
                                {
                                    adjusts.coordX = distX * (position.coordX + (dimension.coordX) / 2 > positionOther.coordX + dimensionOther.coordX / 2 ? -0.5 : 0.5);
                                }
                            }
                            else
                            {
                                // colisão em Y
                                if (distY > abs(adjusts.coordY))
                                {
                                    adjusts.coordY = distY * (position.coordY + (dimension.coordY / 2) > positionOther.coordY - (dimensionOther.coordY / 2) ? -0.5 : 0.5);
                                    maxSpeedX = MAXSPEEDX / 2.0f;
                                }
                            }
                        }
                        speed.coordY = 0.f;
                    }
                }

            }
        }
    }
}