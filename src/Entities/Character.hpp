#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include "../Utilities/Vector2D.hpp"
#include "../Managers/GraphicManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Characters // Namespace do Pacote Personagens.
    {
        class Character
        {
        private:
            // Ponteiro que indica o caminho da textura.
            const char *texturePath;
            Utilities::myVector2F position, // Atributo de posição do personagem
                speed;                      // Atributo de velocidade do personagem

        public:
            // Construtora da classe Personagem. Atributos default configurados
            Character(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath = nullptr);
            // Destrutora da classe Personagem.
            ~Character();
            // Método carrega a textura do personagem na window.
            void initializeCharacter(Managers::GraphicManager &gm);
            // Método atualizar de Personagem. Tem como parâmetro uma variável float que representa o tempo.
            void update(float t);
            // Método desenhar de Personagem. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
            void draw(Managers::GraphicManager &gm);
        };
    }
}
#endif //