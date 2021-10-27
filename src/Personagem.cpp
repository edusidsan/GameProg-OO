#include "Personagem.hpp"
namespace jogoOO
{
    namespace Personagens
    {
        Personagem::Personagem(float xInicial, float yInicial, const char *caminhoTextura) : x{xInicial},
                                                                                             y{yInicial},
                                                                                             text{nullptr}
        {
            x = xInicial;
            y = yInicial;
            // Tamanho do corpo
            corpo.setSize(sf::Vector2f(200.0f, 200.0f));
            // Origem do corpo
            corpo.setOrigin(corpo.getSize() / 2.0f);
            // Textura do corpo
            if (caminhoTextura)
            {
                text = new sf::Texture;
                text->loadFromFile(caminhoTextura);
                corpo.setTexture(text);
            }
        }

        Personagem::~Personagem()
        {
            delete text;
        }
        void Personagem::atualizar()
        {
            x += 0.008;
            y += 0.006;

            corpo.setPosition(sf::Vector2f(x, y));
        }
        void Personagem::desenhar(sf::RenderWindow *janela)
        {
            janela->draw(corpo);
        }
    }
}