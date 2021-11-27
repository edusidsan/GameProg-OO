
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
                Witch::Witch(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath) : Enemy(pos, s, "../assets/Witch.png")
                //"../assets/Witch.png"
                {
                    // Atribui um ID ao Witch.
                    id = 102;
                }
                Witch::Witch(nlohmann::json source) : Enemy(Utilities::gameVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::gameVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])}, "../assets/Witch.png")
                {
                    // Atribui um ID ao Witch.
                    id = 102;
                }
                // Destrutora da classe Witch.
                Witch::~Witch()
                {
                }
                // Método carrega a textura do Witch na window e inicializa gerenciadores do mesmo.
                void Witch::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
                {
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
                    if (abs(speed.coordY) > maxSpeedY)
                    {
                        speed.coordY = maxSpeedY * (speed.coordY > 0 ? 1 : -1);
                    }
                    // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
                    position += speed * t;
                    position += adjusts;
                    adjusts = Utilities::gameVector2F(0, 0);

                    // Gravidade
                    speed.coordY += 10 * t;

                    if (projectileInterval > 0)
                    {
                        projectileInterval--;
                    }
                    else
                    {
                        projectileInterval = 800;

                        Utilities::gameVector2F playerPosition = currentLevel->getMainPlayerPosition();
                        // Utilities::gameVector2F playerPosition;
                        Utilities::gameVector2F playerDirection = (playerPosition - position);

                        if (playerDirection.vModule() < 300)
                        {

                            currentLevel->addPhysicalEntity(new Projectiles::Apple(position + getDimension() * 0.5, playerDirection.unitVector() * 50));
                        }
                    }
                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Witch::collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther)
                {

                    // Caso colida com Enemy.
                    if ((idOther == 102) || (idOther == 103))
                    {
                        // Cálculo da distância entre os enemy no momento da colisão.
                        Utilities::gameVector2F distance = position - positionOther;
                        // Medida para não manter um enemy preso dentro do outro.
                        position += distance * (1 / 2);
                        // std::cout << "OBJETO ENEMY >>> COLISAO COM OBJETO ENEMY." << std::endl;
                        // Muda o sentido da velocidade em x.
                        speed.coordX *= -1;
                        // Muda o sentido da velocidade em y.
                        speed.coordY *= -1;
                    }
                    //Chão
                    if ((idOther == 14) || (idOther == 55) || (idOther == 51) || (idOther == 54) || (idOther == 6))
                    {                       
                        speed.coordY -= 5.0f;
                        maxSpeedX = MAXSPEEDX;
                    }
                }
            }
        }
    }
}