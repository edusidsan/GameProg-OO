#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_ 
#include <SFML/Graphics.hpp>

namespace Personagens
{
    class Personagem
    {
    private:
        sf::Texture *text;
        sf::RectangleShape corpo;
        float x, y;

    public:
        Personagem(float xInicial, float yInicial, const char *caminhoTextura);
        ~Personagem();
        void atualizar();
        void desenhar(sf::RenderWindow *janela);
    };
}
#endif //