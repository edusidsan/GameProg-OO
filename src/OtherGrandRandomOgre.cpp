
#include "OtherGrandRandomOgre.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    // Construtora da classe OtherGrandRandomOgre
    /* Lista de inicialização da construtora com:
        booleana closedWindowEvent setada para false,
        object Window é instanciada para um tamanho de 800px X 600px e com o nome OgrO.
    */
    OtherGrandRandomOgre::OtherGrandRandomOgre() : closeWindowEvent{false},
                                                   window{new sf::RenderWindow(sf::VideoMode(800, 600), "OgrO")}
    {
        // Criação de instâncias de novos personagens.
        players.insert(new Characters::Character(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(5, 5), "../assets/player.png"));
        players.insert(new Characters::Character(sf::Vector2f(400.0f, 300.0f), sf::Vector2f(10, 0), "../assets/player.png"));
        players.insert(new Characters::Character(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(0, 5), "../assets/player.png"));
        // Executa o jogo.
        OtherGrandRandomOgre::run();
    }
    // Destrutora da classe OtherGrandRandomOgre
    OtherGrandRandomOgre::~OtherGrandRandomOgre()
    {
        // Deleta dinamicamente o objeto Window.
        delete window;
        // Deleta dinamicamente os objetos dos Personagens.
        players.destroyCharacters();
    }
    // Método executar de OtherGrandRandomOgre
    int OtherGrandRandomOgre::run()
    {
        // Reseta a contagem do clock.
        clock.restart();
        // Cria uma váriavel event (verifica o fechamento da Window).
        sf::Event event;

        while (!closeWindowEvent)
        {
            // Atribui a t o tempo em que a aplicação está rodando.
            sf::Time t = clock.getElapsedTime();
            // Reseta a contagem do clock.
            clock.restart();
            // Caso o método pollEvent de window ocorra.
            if (window->pollEvent(event))
            {
                // Caso o código do event seja referente ao clique no botão fechar da window.
                if (event.type == sf::Event::Closed)
                {
                    closeWindowEvent = true;
                }
            }
            // Limpa a window.
            window->clear();
            // Atualiza a lista dos Personagens, passando como parametro o tempo da aplicação em segundos.
            players.updateCharacters(t.asSeconds());
            // Desenha os personagens na window.
            players.drawCharacters(window);
            // Mostra a window para o usuário.
            window->display();
        }
        return 0;
    }
}