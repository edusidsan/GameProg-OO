#include "Character.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Characters // Namespace do Pacote Characters.
    {
        // Construtora da classe Personagem.
        Character::Character(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath) : position{pos},
                                                                                                      speed{s},
                                                                                                      texturePath{tPath}
        {
        }
        // Destrutora da classe Personagem.
        Character::~Character()
        {
        }
        // Método carrega a textura do personagem na window.
        void Character::initializeCharacter(Managers::GraphicManager &gm)
        {
            gm.loadAsset(texturePath);
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
    }
}