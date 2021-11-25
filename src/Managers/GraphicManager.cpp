#include "GraphicManager.hpp"
#include <cstring>
// #include <cmath>
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {

        GraphicManager *GraphicManager::instanceGraphicManager = NULL;

        GraphicManager *GraphicManager::getInstance()
        {
            if (instanceGraphicManager == NULL)
            {
                instanceGraphicManager = new GraphicManager();
            }
            return instanceGraphicManager;
        }

        // Construtora da classe GraphicManager.
        GraphicManager::GraphicManager() : window{new sf::RenderWindow(sf::VideoMode(800, 600), "OgrO")},
                                           camera{sf::Vector2f(400, 300), sf::Vector2f(400, 300)},
                                           //    camera{sf::Vector2f(400, 300), sf::Vector2f(800, 600)},
                                           textures{}

        //    camera{sf::Vector2f(800, 600), sf::Vector2f(800, 600)}

        {
            textures.clear();
            // Atribuindo view Camera para a window.
            window->setView(camera);
            // Carrega a fonte que será utilizada.
            font.loadFromFile("../assets/sansation.ttf");
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
                // Atribui ao ponteiro de texture o endereço da textura que tem a chave path.
                texture = textures[path];

                // sprite.setTextureRect(sf::IntRect(9,16,36,43));
                // sprite.setTextureRect(sf::IntRect(0, 0, 40, 56));

                // sf::RectangleShape rect;
                // rect.setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y));
                // rect.setOutlineColor(sf:d:Color::Red);
                // rect.setOrigin(texture->getSize().x * 0.5, texture->getSize().y * 0.5);
                // rect.setOutlineThickness(0.5);
                // rect.setPosition(position.coordX, position.coordY);
                // window->draw(rect);

                sprite.setScale(1.0f, 1.0f);

                sprite.setTexture(*texture, true);
                // Centraliza a origem antes de desenhar.
                sprite.setOrigin(texture->getSize().x * 0.5, texture->getSize().y * 0.5);
                // Atribui ao sprite a posição na qual será desenhada na window.
                sprite.setPosition(position.coordX, position.coordY);
                // Desenha sprite na window.
                window->draw(sprite);
            }
        }

        // Método desenhar. Tem como parâmetro um ponteiro que aponta para a window desenhada.
        void GraphicManager::draw(const std::string path, const Utilities::myVector2F position, int direction)
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
                // Atribui ao ponteiro de texture o endereço da textura que tem a chave path.
                texture = textures[path];

                // sprite.setTextureRect(sf::IntRect(9,16,36,43));
                // sprite.setTextureRect(sf::IntRect(0, 0, 40, 56));

                // sf::RectangleShape rect;
                // rect.setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y));
                // rect.setOutlineColor(sf::Color::Red);
                // rect.setOrigin(texture->getSize().x * 0.5, texture->getSize().y * 0.5);
                // rect.setOutlineThickness(0.5);
                // rect.setPosition(position.coordX, position.coordY);

                // window->draw(rect);

                sprite.setTexture(*texture, true);
                // Centraliza a origem antes de desenhar.
                sprite.setOrigin(texture->getSize().x * 0.5, texture->getSize().y * 0.5);
                // Atribui ao sprite a posição na qual será desenhada na window.
                sprite.setPosition(position.coordX, position.coordY);

                switch (direction)
                {
                case 0:
                    sprite.setScale(1.0f, 1.0f);
                    break;
                case 1:
                    sprite.setScale(-1.0f, 1.0f);
                    break;
                default:
                    // sprite.setScale(1.0f, 1.0f);
                    break;
                }
                // Desenha sprite na window.
                window->draw(sprite);
            }
        }
       
        // Método carrega a textura de acordo com o caminho passado como parâmetro.
        // Caso textura não exista, o método já se encarrega de criar, se possível.
        bool GraphicManager::loadAsset(const std::string &path)
        // bool GraphicManager::loadAsset(const char *path)
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
                // Adiciona na estrutura de dados Map a chave com o caminho path e a textura com a nova texturaAux.
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
            // Atribui essa camera ao view da window.
            window->setView(camera);
        }

        Utilities::myVector2F GraphicManager::getScreenSize() const
        {
            return {camera.getSize().x, camera.getSize().y};
        }

        // Método utilizado para retornar window do tipo *RenderWindow e assim, ser possível utilizar seus métodos.
        sf::RenderWindow *GraphicManager::getWindow() const
        {
            return window;
        }
        // Método retorna as dimensões da imagem.
        const Utilities::myVector2F GraphicManager::getDimensionsOfAsset(const std::string &path) const
        {
            // Caso não encontre alguma textura que tenha a chave unitária de map igual o parâmetro passado por path, encerra.
            if (textures.count(path) == 0)
            {
                std::cout << "Nao foi possivel encontrar a imagem em: " << path << " !" << std::endl;
                std::cout << "Programa finalizado!" << std::endl;
                // Indica término anormal do programa, por não ter encontrado o caminho da imagem.
                exit(1);
            }
            // Variavel dimension unsigned recebe dimensões da textura encontrada.
            sf::Vector2u dimension = (textures.at(path))->getSize();
            // Retorna dimensões.
            return Utilities::myVector2F(dimension.x, dimension.y);
            // return Utilities::myVector2F(0.0f, 0.0f);
        }

        // Método utilizado para desenhar um retangulo sólido na View.
        void GraphicManager::drawSolidRect(const Utilities::myVector2F center, const Utilities::myVector2F dimension, const Utilities::Color color) const
        {
            sf::RectangleShape rectShape = sf::RectangleShape({dimension.coordX, dimension.coordY});
            rectShape.setFillColor({color.r, color.g, color.b, color.a});
            rectShape.setOrigin(dimension.coordX / 2, dimension.coordY / 2);
            rectShape.setPosition(center.coordX, center.coordY);
            window->draw(rectShape);
        }
        // Método utilizado para desenhar texto na View.
        void GraphicManager::drawText(const std::string text, const Utilities::myVector2F position, unsigned int size, const bool centralized) const
        {
            sf::Text txt = sf::Text(text, font, size);
            txt.setFillColor(sf::Color::White);
            if (centralized)
            {
                sf::FloatRect _size = txt.getGlobalBounds();
                txt.setOrigin(_size.width / 2, _size.height / 2);
            }
            txt.setPosition(position.coordX, position.coordY);
            window->draw(txt);
        }
        // Método utilizado para retornar a posição do mouse na View.
        Utilities::myVector2F GraphicManager::getMousePosition() const
        {
            sf::Vector2i windowMousePosition = sf::Mouse::getPosition(*window);
            sf::Vector2u windowSize = window->getSize();
            sf::Vector2f cameraSize = camera.getSize();
            sf::Vector2f cameraPosition = camera.getCenter() - cameraSize / 2.0f;

            return {
                (windowMousePosition.x / (float)windowSize.x) * cameraSize.x + cameraPosition.x,
                (windowMousePosition.y / (float)windowSize.y) * cameraSize.y + cameraPosition.y};
        }
    }
}