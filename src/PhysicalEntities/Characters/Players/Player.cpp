#include "Player.hpp"
#include <cmath>
namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Players // Namespace do Pacote Enemies.
            {

                // Construtora da classe Player.
                Player::Player(Utilities::myVector2F pos, const char *tPath) : Character(pos, Utilities::myVector2F(), tPath)
                                                        //   maxSpeedX{80},
                                                        //   maxSpeedY{220},
                                                        //   jumping(false),
                                                        //   adjusts{Utilities::myVector2F(0, 0)},
                                                        //   direction{0}

                {

                    // Atribui um ID ao player.
                    // id = 101;
                }
                // Destrutora da classe Player.
                Player::~Player()
                {
                }
                // Método carrega a textura do Player na window.
                // void Player::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm)
                void Player::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
                {
                    // // // Carrega textura no player.
                    // // gm.loadAsset(texturePath);
                    // // // Retorna dimensão da imagem.
                    // // dimension = gm.getDimensionsOfAsset(texturePath);

                    // // Carrega textura no player.
                    // pGraphicManager->loadAsset(texturePath);
                    // // Retorna dimensão da imagem.
                    // dimension = pGraphicManager->getDimensionsOfAsset(texturePath);

                    // // Adiciona chave ouvinte de teclado.
                    // keyEvent = em.addKeyboardListener([this](const sf::Event &event)
                    //                                   { handleEvent(event); });

                    // // Adiciona player na lista de entidades físicas colidiveis.
                    // // cm.addToLCollidablesPhysicalEntities(static_cast<PhysicalEntities::PhysicalEntity *>(this));
                    // cm.addToLCollidablesPhysicalEntities((this));
                }
                // Método atualizar do Player. Tem como parâmetro uma variável float que representa o tempo.
                void Player::update(float t)
                {
                    // if (abs(speed.coordY) <= 5)
                    //     jumping = false;
                    // else
                    //     jumping = true;
                    // speed.coordY += 100 * t;
                    // if (abs(speed.coordX) > maxSpeedX)
                    // {
                    //     speed.coordX = maxSpeedX * (speed.coordX > 0 ? 1 : -1);
                    // }
                    // if (abs(speed.coordY) > maxSpeedY)
                    // {
                    //     speed.coordY = maxSpeedY * (speed.coordY > 0 ? 1 : -1);
                    // }
                    // // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
                    // position += speed * t;
                    // position += adjusts;
                    // adjusts = Utilities::myVector2F(0, 0);
                }
                // Método desenhar do Player.
                void Player::draw(Managers::GraphicManager &gm)
                {
                    // // Desenha a forma do player atual na window.
                    // // gm.draw(texturePath, position, {1, 6}, {0, 5});
                    // gm.draw(texturePath, position, this->direction);
                    // // Atribui a posição do player na posição da view.
                    // gm.centerCamera(position);
                }
                // Método de tratamento de evento ocorrido.
                void Player::handleEvent(const sf::Event &ev)
                {
                    // if (ev.type == sf::Event::KeyPressed)
                    // {
                    //     switch (ev.key.code)
                    //     {
                    //     case sf::Keyboard::Key::Right:
                    //         speed.coordX += maxSpeedX;
                    //         this->direction = 0;
                    //         break;
                    //     case sf::Keyboard::Key::Left:
                    //         speed.coordX -= maxSpeedX;
                    //         this->direction = 1;
                    //         break;
                    //     case sf::Keyboard::Key::Up:
                    //         if (!jumping)
                    //         {
                    //             jumping = true;
                    //             speed.coordY -= 0.5 * maxSpeedY;
                    //         }
                    //         break;
                    //     case sf::Keyboard::Key::Down:
                    //         // speed.coordY += 75;
                    //         break;

                    //     default:
                    //         break;
                    //     }
                    // }
                    // else if (ev.type == sf::Event::KeyReleased)
                    // {
                    //     switch (ev.key.code)
                    //     {
                    //     case sf::Keyboard::Key::Right:
                    //         // speed.coordX -= 75;
                    //         // speed.coordX -= maxSpeedX;
                    //         speed.coordX = 0;
                    //         break;
                    //     case sf::Keyboard::Key::Left:
                    //         // speed.coordX += 75;
                    //         // speed.coordX += maxSpeedX;
                    //         speed.coordX = 0;
                    //         break;
                    //     case sf::Keyboard::Key::Up:
                    //         // speed.coordY = 0.5f;
                    //         break;
                    //     case sf::Keyboard::Key::Down:
                    //         // speed.coordY -= 75;
                    //         break;

                    //     default:
                    //         break;
                    //     }
                    // }
                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Player::collided(int idOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
                {
                //     if ((idOther == 22) || (idOther == 23) || (idOther == 24))
                //     {
                //         float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                //         float distY = (position.coordY + (dimension.coordY / 2)) - abs(positionOther.coordY - (dimensionOther.coordY / 2));
                //         if (distX * distY > .001 * dimension.coordX * dimension.coordY)
                //         { // passa a ignorar colisões ignoráveis (bem as problemáticas)
                //             if (distX < distY)
                //             {
                //                 // colisão em X
                //                 if (distX > abs(adjusts.coordX))
                //                 {
                //                     adjusts.coordX = distX * (position.coordX + (dimension.coordX) / 2 > positionOther.coordX + dimensionOther.coordX / 2 ? -0.5 : 0.5);
                //                 }
                //             }
                //             else
                //             {
                //                 // colisão em Y
                //                 if (distY > abs(adjusts.coordY))
                //                 {
                //                     adjusts.coordY = distY * (position.coordY + (dimension.coordY / 2) > positionOther.coordY - (dimensionOther.coordY / 2) ? -0.5 : 0.5);
                //                 }
                //             }
                //         }
                //         speed.coordY = 0.f;
                //     }
                //     // Espinho
                //     else if (idOther == 51)
                //     {
                //         float distY = (position.coordY + (dimension.coordY / 2)) - abs(positionOther.coordY - (dimensionOther.coordY / 2));
                //         // colisão em Y
                //         if (distY > abs(adjusts.coordY))
                //         {
                //             adjusts.coordY = distY * (position.coordY + (dimension.coordY / 2) > positionOther.coordY - (dimensionOther.coordY / 2) ? -0.5 : 0.5);
                //         }
                //         speed.coordY = 0.f;
                //     }
                //     // Obstaculo que faz pular.
                //     else if (idOther == 49)
                //     {
                //         float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                //         // colisão em X
                //         if (distX > abs(adjusts.coordX))
                //         {
                //             position.coordY -= 0.5f;
                //             speed.coordY -= maxSpeedY;
                //         }
                //     }
                //     // Obstaculo troca de fase.
                //     else if (idOther == 35)
                //     {
                //     }
                //     // Obstaculo pedra que impede de andar reto.
                //     else if (idOther == 1)
                //     {
                //         float distX = (position.coordX + (dimension.coordX / 2)) - abs(positionOther.coordX - (dimensionOther.coordX / 2));
                //         // colisão em X
                //         if (distX > abs(adjusts.coordX))
                //         {
                //             // position.coordX += 0.0f;
                //         }
                //         speed.coordX = 0.0f;
                //         float distY = (position.coordY + (dimension.coordY / 2)) - abs(positionOther.coordY - (dimensionOther.coordY / 2));
                //         // colisão em Y
                //         if (distY > abs(adjusts.coordY))
                //         {
                //             adjusts.coordY = distY * (position.coordY + (dimension.coordY / 2) > positionOther.coordY - (dimensionOther.coordY / 2) ? -0.5 : 0.5);
                //         }
                //         speed.coordY = 0.f;
                //     }
                 }
            }

        }
    }
}
