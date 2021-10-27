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
}
#endif //