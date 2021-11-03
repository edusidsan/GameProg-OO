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
                }
                // Método desenhar do Player.
                void Shrek::draw(Managers::GraphicManager &gm)
                {
                    // Desenha a forma do player atual na window.
                    gm.draw(texturePath, position);
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
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Shrek::collided(int Id, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
                {
                    std::cout << "OBJETO PLAYER1::SHREK >>> COLISAO COM INIMIGO." << std::endl;
                }

            }
        }
    }
}
