#include "Character.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Characters // Namespace do Pacote Characters.
    {
        // Construtora da classe Personagem.
        Character::Character(sf::Vector2f pos, sf::Vector2f s, const char *texturePath) : position{pos},
                                                                                          speed{s},
                                                                                          texture{nullptr}
        {
            // Tamanho da forma.
            body.setSize(sf::Vector2f(200.0f, 200.0f));
            // Ponto cartesiano de origem da forma.
            body.setOrigin(body.getSize() / 2.0f);

            // Atribuição da textura da forma.
            if (texturePath)
            {
                // Cria dinamicamente uma nova textura.
                texture = new sf::Texture;
                // Carrega textura a partir do caminho do arquivo.
                texture->loadFromFile(texturePath);
                // Atribui textura à forma.
                body.setTexture(texture);
            }
        }
        // Destrutora da classe Personagem.
        Character::~Character()
        {
            // Deleta dinamicamente a textura da forma.
            delete texture;
        }
        // Método atualizar de Personagem. Tem como parâmetro uma variável float que representa o tempo.
        void Character::update(float t)
        {
            // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
            position += speed * t;
            // Atribui posição à forma.
            body.setPosition(position);
        }
        // Método desenhar de Personagem. Tem como parâmetro um ponteiro que aponta para a window desenhada.
        void Character::draw(sf::RenderWindow *window)
        {
            // Desenha a forma do personagem atual na window.
            window->draw(body);
        }
    }
}