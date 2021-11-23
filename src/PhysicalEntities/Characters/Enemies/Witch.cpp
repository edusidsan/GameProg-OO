
#include "Witch.hpp"
#include "../../../Levels/Level.hpp"
#include "../../Projectiles/Apple.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {

                // Construtora da classe Witch.
                Witch::Witch(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath) : Enemy(pos, s, "../assets/Witch.png")
                //"../assets/Witch.png"
                {
                    // Atribui um ID ao Witch.
                    id = 102;
                }
                Witch::Witch(nlohmann::json source) : Enemy(Utilities::myVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::myVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])}, "../assets/Witch.png")
                {
                    // Atribui um ID ao Witch.
                    id = 102;
                }
                // Destrutora da classe Witch.
                Witch::~Witch()
                {
                }
                // Método carrega a textura do Witch na window e inicializa gerenciadores do mesmo.
                // void Witch::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm)
                void Witch::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
                {
                    // // Carrega textura no player.
                    // gm.loadAsset(texturePath);
                    // // Retorna dimensão da imagem.
                    // dimension = gm.getDimensionsOfAsset(texturePath);

                    // Carrega textura no player.
                    pGraphicManager->loadAsset(texturePath);
                    // Retorna dimensão da imagem.
                    dimension = pGraphicManager->getDimensionsOfAsset(texturePath);

                    // Adiciona Witch na lista de entidades físicas colidiveis.
                    cm.addToLCollidablesPhysicalEntities((this));

                    currentLevel = this->getLevel();
                }

                void Witch::update(float t)
                {
                    if (clock.getCurrent() / 1000 - timeReference > 5)
                    {
                        // Muda o sentido da velocidade em x.
                        speed.coordY *= -1;
                        timeReference = clock.getCurrent() / 1000;
                    }

                    if (projectileInterval > 0)
                    {
                        projectileInterval--;
                    }
                    else
                    {
                        projectileInterval = 100;

                        Utilities::myVector2F playerPosition = currentLevel->getMainPlayerPosition();
                        // Utilities::myVector2F playerPosition;
                        Utilities::myVector2F playerDirection = (playerPosition - position);

                        if (playerDirection.vModule() < 300)
                        {

                            currentLevel->addPhysicalEntity(new Projectiles::Apple(position + getDimension() * 0.5, playerDirection.unitVector() * 50));
                        }
                    }
                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Witch::collided(int IDOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
                {
                    // Caso colida com Player1.
                    if ((IDOther == 100) || (IDOther == 101))
                    {
                        // std::cout << "OBJETO ENEMY >>> COLISAO COM PLAYER1::SHREK1." << std::endl;
                    }
                    // Caso colida com Enemy.
                    else if ((IDOther == 102) || (IDOther == 103))
                    {
                        // Cálculo da distância entre os enemy no momento da colisão.
                        Utilities::myVector2F distance = position - positionOther;
                        // Medida para não manter um enemy preso dentro do outro.
                        position += distance * (1 / 2);
                        // std::cout << "OBJETO ENEMY >>> COLISAO COM OBJETO ENEMY." << std::endl;
                        // Muda o sentido da velocidade em x.
                        speed.coordX *= -1;
                        // Muda o sentido da velocidade em y.
                        speed.coordY *= -1;
                    }
                }
            }
        }
    }
}