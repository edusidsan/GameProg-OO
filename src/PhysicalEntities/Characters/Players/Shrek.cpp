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
                Shrek::Shrek(Utilities::gameVector2F pos, const char *tPath) : Player(pos, "../assets/Shrek.png")
                {
                    // Atribui um ID ao player.
                    id = 100;
                }
                // Destrutora da classe Shrek.
                Shrek::~Shrek()
                {
                }
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
