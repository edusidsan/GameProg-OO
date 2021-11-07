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
                Shrek::Shrek(Utilities::myVector2F pos) : Character(pos, Utilities::myVector2F(), "../assets/Shrek.png"),
                                                          gravity{700.f},
                                                          direction{0}

                {

                    // Atribui um ID ao player.
                    id = 101;
                }
                // Destrutora da classe Shrek.
                Shrek::~Shrek()
                {
                }
                // Método carrega a textura do Player na window.
                void Shrek::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm)
                {
                    // Carrega textura no player.
                    gm.loadAsset(texturePath);
                    // Retorna dimensão da imagem.
                    dimension = gm.getDimensionsOfAsset(texturePath);
                    // Adiciona chave ouvinte de teclado.
                    keyEvent = em.addKeyboardListener([this](const sf::Event &event)
                                                      { handleEvent(event); });

                    // Adiciona player na lista de entidades físicas colidiveis.
                    // cm.addToLCollidablesPhysicalEntities(static_cast<PhysicalEntities::PhysicalEntity *>(this));
                    cm.addToLCollidablesPhysicalEntities((this));
                }
                // Método atualizar do Player. Tem como parâmetro uma variável float que representa o tempo.
                void Shrek::update(float t)
                {
                    // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
                    position += speed * t;
                    speed.coordY += 98.1f * t;
                }
                // Método desenhar do Player.
                void Shrek::draw(Managers::GraphicManager &gm)
                {
                    // Desenha a forma do player atual na window.
                    // gm.draw(texturePath, position, {1, 6}, {0, 5});
                    gm.draw(texturePath, position, this->direction);
                    // Atribui a posição do player na posição da view.
                    gm.centerCamera(position);
                }
                // Método de tratamento de evento ocorrido.
                void Shrek::handleEvent(const sf::Event &ev)
                {
                    if (ev.type == sf::Event::KeyPressed)
                    {
                        switch (ev.key.code)
                        {
                        case sf::Keyboard::Key::Right:
                            speed.coordX += 75;
                            this->direction = 0;
                            break;
                        case sf::Keyboard::Key::Left:
                            speed.coordX -= 75;
                            this->direction = 1;
                            break;
                        case sf::Keyboard::Key::Up:
                            // speed.coordY -= 75;
                            speed.coordY = -sqrt(2 * 9.81f * gravity);
                            break;
                        case sf::Keyboard::Key::Down:
                            // speed.coordY += 75;
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
                            // speed.coordX -= 75;
                            speed.coordX = 0;
                            break;
                        case sf::Keyboard::Key::Left:
                            // speed.coordX += 75;
                            speed.coordX = 0;
                            break;
                        case sf::Keyboard::Key::Up:
                            // speed.coordY = 0.5f;
                            break;
                        case sf::Keyboard::Key::Down:
                            // speed.coordY -= 75;
                            break;

                        default:
                            break;
                        }
                    }
                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Shrek::collided(int idOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
                {
                    // std::string terminalPrint;

                    switch (idOther)
                    {
                    case 22:
                    case 23:
                    case 24:
                        // terminalPrint = "Bate no chão!";
                        speed.coordY = 0;
                        break;
                    // case 2:
                    //     terminalPrint = "fui ludibriado";
                    //     break;
                    case 3:
                        // terminalPrint = "escada";
                        speed.coordX = 0;
                        speed.coordY = 0;
                        break;
                    // case 4:
                    //     terminalPrint = "mano o que ta acontecendo";
                    //     break;
                    // case 5:
                    //     terminalPrint = "pontudo";
                    //     break;
                    // case 6:
                    //     terminalPrint = "estou livre";
                    //     break;
                    // case 7:
                    //     terminalPrint = "bonk";
                    //     break;
                    default:
                        break;
                        // terminalPrint = "eita";
                    }

                    // std::cout << terminalPrint << " idOther: " << idOther << std::endl;
                }

            }
        }
    }
}
