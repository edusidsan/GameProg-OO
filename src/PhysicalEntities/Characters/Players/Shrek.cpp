#include "Shrek.hpp"
#include <cmath>
namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Players // Namespace do Pacote Enemies.
            {

                // Construtora da classe Shrek.
                Shrek::Shrek(Utilities::myVector2F pos, const char *tPath) : Player(pos, "../assets/Shrek.png")
                {
<<<<<<< HEAD

                    // Atribui um ID ao Sherek.
                    id = 101;
=======
                    // Atribui um ID ao player.
                    id = 100;
>>>>>>> eduDevelop
                }
                // Destrutora da classe Shrek.
                Shrek::~Shrek()
                {
                }
<<<<<<< HEAD
                // Método carrega a textura do Sherek na window.
                // void Shrek::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm)
                void Shrek::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
                {
                    // // Carrega textura no Sherek.
                    // gm.loadAsset(texturePath);
                    // // Retorna dimensão da imagem.
                    // dimension = gm.getDimensionsOfAsset(texturePath);

                    // Carrega textura no Sherek.
                    pGraphicManager->loadAsset(texturePath);
                    // Retorna dimensão da imagem.
                    dimension = pGraphicManager->getDimensionsOfAsset(texturePath);

                    // Adiciona chave ouvinte de teclado.
                    keyEvent = em.addKeyboardListener([this](const sf::Event &event)
                                                      { handleEvent(event); });

                    // Adiciona Sherek na lista de entidades físicas colidiveis.
                    // cm.addToLCollidablesPhysicalEntities(static_cast<PhysicalEntities::PhysicalEntity *>(this));
                    cm.addToLCollidablesPhysicalEntities((this));
                }
                // Método atualizar do Sherek. Tem como parâmetro uma variável float que representa o tempo.
                void Shrek::update(float t)
                {
                    if (abs(speed.coordY) <= 5)
                        jumping = false;
                    else
                        jumping = true;
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
                }
                // Método desenhar do Sherek.
                void Shrek::draw(Managers::GraphicManager &gm)
                {
                    // Desenha a forma do Sherek atual na window.
                    // gm.draw(texturePath, position, {1, 6}, {0, 5});
                    gm.draw(texturePath, position, this->direction);
                    // Atribui a posição do Sherek na posição da view.
                    gm.centerCamera(position);
                }
=======
>>>>>>> eduDevelop
                // Método de tratamento de evento ocorrido.
                void Shrek::handleEvent(const sf::Event &ev)
                {
                    if (ev.type == sf::Event::KeyPressed)
                    {
                        switch (ev.key.code)
                        {
                        case sf::Keyboard::Key::Right:
                            speed.coordX += maxSpeedX;
                            this->direction = 0;
                            break;
                        case sf::Keyboard::Key::Left:
                            speed.coordX -= maxSpeedX;
                            this->direction = 1;
                            break;
                        case sf::Keyboard::Key::Up:
                            if (!jumping)
                            {
                                jumping = true;
                                speed.coordY -= 0.5 * maxSpeedY;
                            }
                            break;
                        default:
                            break;
                        }
                    }
                    else if (ev.type == sf::Event::KeyReleased)
                    {
                        switch (ev.key.code)
                        {
                        case sf::Keyboard::Key::Right:
                            speed.coordX = 0;
                            break;
                        case sf::Keyboard::Key::Left:
                            speed.coordX = 0;
                            break;
                        case sf::Keyboard::Key::Up:
                            break;
                        default:
                            break;
                        }
                    }
                }
            }

        }
    }
}
