
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
                Wolf::Wolf(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath) : Enemy(pos, s, "../assets/Wolf.png")
                //"../assets/Wolf.png"
                {
                    // Atribui um ID ao Wolf.
                    id = 103;
                }
                Wolf::Wolf(nlohmann::json source) : Enemy(Utilities::myVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::myVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])}, "../assets/Wolf.png")
                {
                    // Atribui um ID ao Wolf.
                    id = 103;
                }
                // Destrutora da classe Wolf.
                Wolf::~Wolf()
                {
                }
                // Método carrega a textura do Wolf na window e inicializa gerenciadores do mesmo.
                // void Wolf::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm)
                void Wolf::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
                {
                    // Carrega textura no player.
                    pGraphicManager->loadAsset(texturePath);
                    // Retorna dimensão da imagem.
                    dimension = pGraphicManager->getDimensionsOfAsset(texturePath);

                    // Adiciona Wolf na lista de entidades físicas colidiveis.
                    cm.addToLCollidablesPhysicalEntities((this));
                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Wolf::collided(int IDOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
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
                        Utilities::myVector2F distance = position - positionOther;
                        // Medida para não manter um enemy preso dentro do outro.
                        position += distance * (1 / 2);
                        // std::cout << "OBJETO ENEMY >>> COLISAO COM OBJETO ENEMY." << std::endl;
                        // // std::cout<<"AAAAAAAAA"<<std::endl;
                        // // Caso colida com Player1.
                        // if (IDOther == 101)
                        // {
                        //     // std::cout << "OBJETO Wolf >>> COLISAO COM PLAYER1::SHREK1." << std::endl;
                        // }
                        // // Caso colida com Wolf.
                        // else if (IDOther == 102)
                        // {
                        //     // Cálculo da distância entre os Wolf no momento da colisão.
                        //     Utilities::myVector2F distance = position - positionOther;
                        //     // Medida para não manter um Wolf preso dentro do outro.
                        //     position += distance * (1 / 2);
                        //     // std::cout << "OBJETO Wolf >>> COLISAO COM OBJETO Wolf." << std::endl;
                        //     // Muda o sentido da velocidade em x.
                        //     speed.coordX *= -1;
                        //     // Muda o sentido da velocidade em y.
                        //     speed.coordY *= -1;
                    }
                    //Chão
                    if (IDOther == 14)
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
                                }
                            }
                        }
                        speed.coordY = 0.f;
                        maxSpeedX = MAXSPEEDX;
                    }
                    // Espinho
                    else if (IDOther == 51)
                    {
                        float distY = (position.coordY + (dimension.coordY / 2)) - abs(positionOther.coordY - (dimensionOther.coordY / 2));
                        // colisão em Y
                        if (distY > abs(adjusts.coordY))
                        {
                            adjusts.coordY = distY * (position.coordY + (dimension.coordY / 2) > positionOther.coordY - (dimensionOther.coordY / 2) ? -0.5 : 0.5);
                        }
                        speed.coordY = 0.f;
                    }
                    // Parede
                    else if (IDOther == 1)
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
                    else if (IDOther == 54)
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
                    else if (IDOther == 35)
                    {
                    }
                    // Obstaculo que reduz velocidade.
                    else if (IDOther == 6)
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
                void Wolf::update(float t)
                {

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
                    adjusts = Utilities::myVector2F(0, 0);

                    if (clock.getCurrent() / 1000 - timeReference > 5)
                    {

                        // Muda o sentido da velocidade em x.
                        speed.coordX *= -1;
                        timeReference = clock.getCurrent() / 1000;
                    }
                }
            }
        }
    }
}