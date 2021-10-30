#ifndef _GRAPHICMANAGER_HPP_
#define _GRAPHICMANAGER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>
#include "../Utilities/Vector2D.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {
        class GraphicManager
        {
        private:
            // Atributo da window criada para o jogo.
            sf::RenderWindow *window;
            // Atributo da camera criada para o jogo.
            sf::View camera;
            // Atributo textures utlizado para encontrar as texturas de cada ente através de uma string.
            std::map<const std::string, sf::Texture *> textures;

        public:
            // Construtora da classe GraphicManager.
            GraphicManager();
            // Destrutora da classe GraphicManager.
            ~GraphicManager();
            // Método cria a tela gráfica para o usuário.
            void display();
            // Método Limpa a window com os parâmetros de cores.
            void clear(int r = 0, int g = 0, int b = 0);
            // Método desenhar. Tem como parâmetro um ponteiro que aponta para a window desenhada.
            void draw(const std::string path, const Utilities::myVector2F position);
            // Método carrega a textura de acordo com o caminho passado como parâmetro.
            // Caso textura não exista, o método já se encarrega de criar, se possível.
            bool loadAsset(const std::string path);
            // Método utilizado para centralizar a View.
            void centerCamera(const Utilities::myVector2F center);
            // Método utilizado para retornar window do tipo *RenderWindow e assim, ser possível utilizar seus métodos.
            sf::RenderWindow *getWindow() const;
        };
    }
}
#endif