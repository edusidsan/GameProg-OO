#include "Dragon.hpp"
#include "../../../Levels/Level.hpp"
#include "../../Projectiles/Fire.hpp"
#include "../../../Utilities/RandomGenerator.hpp"
#include "../../../Menus/RankingInsert.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {

                // Construtora da classe Dragon.
                Dragon::Dragon(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath) : Enemy(pos, s, "../assets/Dragon.png")
                {
                    // Atribui um ID ao Dragon.
                    id = 104;
                    if (Life > (MAX_LIFE / 100))
                    {
                        Life = MAX_LIFE / 100;
                    }
                }
                Dragon::Dragon(nlohmann::json source) : Enemy(Utilities::gameVector2F{static_cast<float>(source["position x"]), static_cast<float>(source["position y"])}, Utilities::gameVector2F{static_cast<float>(source["speed x"]), static_cast<float>(source["speed y"])}, "../assets/Dragon.png", static_cast<unsigned int>(source["life"]))
                {
                    // Atribui um ID ao Dragon.
                    id = 104;
                }
                // Destrutora da classe Dragon.
                Dragon::~Dragon()
                {
                }
                // Método carrega a textura do Dragon na window e inicializa gerenciadores do mesmo.
                void Dragon::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
                {
                    // Carrega textura no player.
                    pGraphicManager->loadAsset(texturePath);
                    // Retorna dimensão da imagem.
                    dimension = pGraphicManager->getDimensionsOfAsset(texturePath);

                    // Adiciona Dragon na lista de entidades físicas colidiveis.
                    cm.addToLCollidablesPhysicalEntities((this));
                    currentLevel = this->getLevel();
                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Dragon::collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther)
                {
                    // Caso colida com Player1.
                    if ((idOther == 100) || (idOther == 101))
                    {
                        if (clock.getCurrent() / 1000 - timeReference > 3)
                        {
                            // Caso o contato seja maior que 2s causa dano
                            --Life;
                            std::cout << "Dano!, Dragao:" << Life << std::endl;
                            timeReference = clock.getCurrent() / 1000;
                        }
                    }
                }
                void Dragon::update(float t)
                {
                    // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
                    position += speed * t;
                    position += adjusts;
                    adjusts = Utilities::gameVector2F(0, 0);

                    if (this->Life == 0)
                    {
                        pGraphicManager->zoomIn();
                        // MUDA DE FASE.
                        Menus::RankingInsert::addNewHighScore(currentLevel->getRankingScore());
                        currentLevel->goNextLevel();
                    }

                    if (projectileInterval > 0)
                    {
                        projectileInterval--;
                    }
                    else
                    {

                        projectileInterval = Utilities::RandomGenerator::getInstance()->getRandomIntInRange(450, 800);

                        Utilities::gameVector2F playerPosition = currentLevel->getMainPlayerPosition();
                        // Utilities::gameVector2F playerPosition;
                        Utilities::gameVector2F playerDirection = (playerPosition - position);

                        if (playerDirection.vModule() < 500)
                        {
                            currentLevel->addPhysicalEntity(new Projectiles::Fire({position.coordX - 50, position.coordY + 30}, playerDirection.unitVector() * 50));
                        }
                    }
                }
            }
        }
    }
}