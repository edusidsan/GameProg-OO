#include "Character.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Characters.
        {
            // Construtora da classe Personagem.
            Character::Character(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath, unsigned int life) : PhysicalEntity(pos, s, tPath, life),
                                                                                                                                 keyEvent(0),
                                                                                                                                 maxSpeedX(MAXSPEEDX),
                                                                                                                                 maxSpeedY(220),
                                                                                                                                 direction(0),
                                                                                                                                 jumping(false),
                                                                                                                                 adjusts(Utilities::gameVector2F(0, 0)),
                                                                                                                                 clock(),
                                                                                                                                 timeReference(0)

            {
            }
            // Destrutora da classe Personagem.
            Character::~Character()
            {
            }
            // Método carrega a textura do personagem na window.
            void Character::initialize()
            {
                pGraphicManager->loadAsset(texturePath);
            }
            // Método atualizar de Personagem. Tem como parâmetro uma variável float que representa o tempo.
            void Character::update(float t)
            {
                // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
                position += speed * t;
            }
            // Método desenhar de Personagem. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
            void Character::draw()
            {
                // Desenha a forma do personagem atual na window.
                pGraphicManager->draw(texturePath, position);
            }
        }
    }
}