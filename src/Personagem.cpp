#include "Personagem.hpp"
namespace jogoOO
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f s, const char *texturePath) : position{pos},
                                                                                            speed{s},
                                                                                            texture{nullptr}
        {
            // Tamanho do body
            body.setSize(sf::Vector2f(200.0f, 200.0f));
            // Origem do body
            body.setOrigin(body.getSize() / 2.0f);
            // Textura do body
            if (texturePath)
            {
                texture = new sf::Texture;
                texture->loadFromFile(texturePath);
                body.setTexture(texture);
            }
        }

        Personagem::~Personagem()
        {
            delete texture;
        }
        void Personagem::update(float t)
        {
            position = speed * t;
            body.setPosition(position);
            // body.move(speed * t);
        }
        void Personagem::draw(sf::RenderWindow *window)
        {
            window->draw(body);
        }
    }
}