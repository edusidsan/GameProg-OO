#include "Shrek.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Players // Namespace do Pacote Enemies.
            {

                // Construtora da classe Shrek.
                Shrek::Shrek(Utilities::myVector2F pos) : Character(pos, Utilities::myVector2F(), "../assets/Shrek.png")
                {
                }
                // Destrutora da classe Shrek.
                Shrek::~Shrek()
                {
                }
                // Método carrega a textura do Player na window.
                void Shrek::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em)
                {
                    // Carrega textura no player.
                    gm.loadAsset(texturePath);
                    keyEvent = em.addKeyboardListener([this](const sf::Event &event)
                                                      { handleEvent(event); });
                }
                // Método atualizar do Player. Tem como parâmetro uma variável float que representa o tempo.
                void Shrek::update(float t)
                {
                    // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
                    position += speed * t;
                }
                // Método desenhar do Player.
                void Shrek::draw(Managers::GraphicManager &gm)
                {
                    // Desenha a forma do player atual na window.
                    gm.draw(texturePath, position);
                }
                // Método de tratamento de evento ocorrido.
                void Shrek::handleEvent(const sf::Event &ev)
                {
                    if (ev.type == sf::Event::KeyPressed)
                    {
                        switch (ev.key.code)
                        {
                        case sf::Keyboard::Key::Right:
                            speed.coordX += 10;
                            break;
                        case sf::Keyboard::Key::Left:
                            speed.coordX -= 10;
                            break;
                        case sf::Keyboard::Key::Up:
                            speed.coordY -= 10;
                            break;
                        case sf::Keyboard::Key::Down:
                            speed.coordY += 10;
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
                            speed.coordX -= 10;
                            break;
                        case sf::Keyboard::Key::Left:
                            speed.coordX += 10;
                            break;
                        case sf::Keyboard::Key::Up:
                            speed.coordY += 10;
                            break;
                        case sf::Keyboard::Key::Down:
                            speed.coordY -= 10;
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
