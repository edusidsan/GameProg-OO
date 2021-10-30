#include "GraphicManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {
        // Construtora da classe GraphicManager.
        GraphicManager::GraphicManager() : window{new sf::RenderWindow(sf::VideoMode(800, 600), "OgrO")},
                                           camera{sf::Vector2f(400, 300), sf::Vector2f(800, 600)}

        {
            // Atribuindo view Camera para a window.
            window->setView(camera);
        }
        // Destrutora da classe GraphicManager.
        GraphicManager::~GraphicManager()
        {
            // Desaloca dinamicamente o objeto Window.
            delete window;
            // Percorre Map de texturas para desalocar dinamicamente todos os elementos ali armazenados.
            for (auto i = textures.begin(); i != textures.end(); ++i)
            {
                // Desaloca dinamicamente apenas a textura na estrutura Map.
                delete i->second;
            }
            // Limpa os elementos da estrutura de dados Map (textures).
            textures.clear();
        }
        // Método cria a tela gráfica para o usuário.
        void GraphicManager::display()
        {
            // Mostra a window para o usuário.
            window->display();
        }
        // Método Limpa a window com os parâmetros de cores.
        void GraphicManager::clear(int r, int g, int b)
        {
            // Limpa a window.
            window->clear(sf::Color(r, g, b));
        }
        // Método desenhar. Tem como parâmetro um ponteiro que aponta para a window desenhada.
        void GraphicManager::draw(const std::string path, const Utilities::myVector2F position)
        {
            // Caso encontre alguma textura que tenha a chave unitária de map igual o parâmetro passado por path, desenha imagem na window.
            if (textures.count(path) == 0)
            {
                std::cout << "Nao foi possivel encontrar a imagem em: " << path << " !" << std::endl;
                std::cout << "Programa finalizado!" << std::endl;
                // Indica término anormal do programa, por não ter encontrado o caminho da imagem.
                exit(1);
            }
            else
            {
                // Atribui ao ponteiro auxiliar textureAux o endereço da textura que tem a chave path.
                sf::Texture *textureAux = textures[path];
                //  Classe referente a biblioteca SFML que é uma representação "desenhavel" de uma textura.
                sf::Sprite sprite(*textureAux);

                // sprite.setTexture(*textureAux);
                // Atribui ao sprite a posição na qual será desenhada na window.
                sprite.setPosition(position.coordX, position.coordY);
                // Desenha sprite na window.
                window->draw(sprite);
            }
        }
        // Método carrega a textura de acordo com o caminho passado como parâmetro.
        // Caso textura não exista, o método já se encarrega de criar, se possível.
        bool GraphicManager::loadAsset(const std::string path)
        {
            // Caso encontre alguma textura que tenha a chave unitária de map igual o parâmetro passado por path, retorna true.
            if (textures.count(path) == 1)
            {
                // Retorna true, dando a entender que a textura foi carregada.
                return true;
            }
            else
            {
                // Cria dinamicamente uma textura nova e atribui endereço ao ponteiro textureAux.
                sf::Texture *textureAux = new sf::Texture();
                // Verifica se caminho de imagem passado por parâmetro é válido.
                if (!textureAux->loadFromFile(path))
                {
                    std::cout << "Nao foi possivel encontrar a imagem em: " << path << " !" << std::endl;
                    std::cout << "Programa finalizado!" << std::endl;
                    // Indica término anormal do programa, por não ter encontrado o caminho da imagem.
                    exit(1);
                }
                // Adiciona dentro da estrutura de dados Map a chave com o caminho path e a textura com a nova texturaAux.
                textures.emplace(path, textureAux);
                // Retorna true, dando a entender que a textura foi carregada.
                return true;
            }
        }
        // Método utilizado para centralizar a View.
        void GraphicManager::centerCamera(const Utilities::myVector2F center)
        {
            // Centraliza o View (camera)
            camera.setCenter(sf::Vector2f(center.coordX, center.coordY));
        }
        // Método utilizado para retornar window do tipo *RenderWindow e assim, ser possível utilizar seus métodos.
        sf::RenderWindow *GraphicManager::getWindow() const
        {
            return window;
        }
    }
}