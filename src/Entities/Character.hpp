#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_
#include <SFML/Graphics.hpp>
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Characters // Namespace do Pacote Personagens.
    {
        class Character
        {
        private:
            // Atributo de textura do personagem
            sf::Texture *texture;
            // Atributo de forma do personagem
            sf::RectangleShape body;

            sf::Vector2f position, // Atributo de posição do personagem
                speed;             // Atributo de velocidade do personagem

        public:
            // Construtora da classe Personagem. Atributos default configurados
            Character(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f s = sf::Vector2f(0.0f, 0.0f), const char *texturePath = nullptr);
            // Destrutora da classe Personagem.
            ~Character();
            // Método atualizar de Personagem. Tem como parâmetro uma variável float que representa o tempo.
            void update(float t);
            // Método desenhar de Personagem. Tem como parâmetro um ponteiro que aponta para a window desenhada.
            void draw(sf::RenderWindow *window);
        };
    }
}
#endif //