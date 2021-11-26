#include "Character.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Characters.
        {
            // Construtora da classe Personagem.
            Character::Character(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath, unsigned int life) : PhysicalEntity(pos, s, tPath, life),
                                                                                                                             maxSpeedX{MAXSPEEDX},
                                                                                                                             maxSpeedY{220},
                                                                                                                             jumping(false),
                                                                                                                             adjusts{Utilities::gameVector2F(0, 0)},
                                                                                                                             timeReference{0}

            {
            }
            // Destrutora da classe Personagem.
            Character::~Character()
            {
            }
            // Método carrega a textura do personagem na window.
            // void Character::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm)
            void Character::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
            {
                // gm.loadAsset(texturePath);
                pGraphicManager->loadAsset(texturePath);
            }
            // Método atualizar de Personagem. Tem como parâmetro uma variável float que representa o tempo.
            void Character::update(float t)
            {
                // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
                position += speed * t;
            }
            // Método desenhar de Personagem. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
            void Character::draw(Managers::GraphicManager &gm)
            {
                // Desenha a forma do personagem atual na window.
                gm.draw(texturePath, position);
            }
            // void Character::run()
            // {
            // }
        }
    }
}