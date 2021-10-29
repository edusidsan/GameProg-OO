#ifndef _PERSONAGEM_HPP_
#define _PERSONAGEM_HPP_
#include <SFML/Graphics.hpp>
namespace jogoOO
{
    namespace Personagens
    {
        class Personagem
        {
        private:
            sf::Texture *texture;
            sf::RectangleShape body;
            sf::Vector2f position, speed;

        public:
            Personagem(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f s = sf::Vector2f(0.0f, 0.0f), const char *texturePath = nullptr);
            ~Personagem();
            void update(float t);
            void draw(sf::RenderWindow *window);
        };
    }
}
#endif //