#include "Donkey.hpp"
#include <cmath>

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Players // Namespace do Pacote Enemies.
            {
                // Construtora da classe Donkey.
                Donkey::Donkey(Utilities::myVector2F pos, const char *tPath) : Player(pos, "../assets/Donkey.png")
               {
                    // Atribui um ID ao player.
                    id = 101;
                }
                // Destrutora da classe Donkey.
                Donkey::~Donkey()
                {
                }
                // Método de tratamento de evento ocorrido.
                void Donkey::handleEvent(const sf::Event &ev)
                {
                    if (ev.type == sf::Event::KeyPressed)
                    {
                        switch (ev.key.code)
                        {
                        case sf::Keyboard::Key::D:
                            speed.coordX += maxSpeedX;
                            this->direction = 0;
                            break;
                        case sf::Keyboard::Key::A:
                            speed.coordX -= maxSpeedX;
                            this->direction = 1;
                            break;
                        case sf::Keyboard::Key::W:
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
                        case sf::Keyboard::Key::D:
                            speed.coordX = 0;
                            break;
                        case sf::Keyboard::Key::A:
                            speed.coordX = 0;
                            break;
                        case sf::Keyboard::Key::W:
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
