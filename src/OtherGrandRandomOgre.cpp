#include "OtherGrandRandomOgre.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    // Construtora da classe OtherGrandRandomOgre
    /* Lista de inicialização da construtora com:
        booleana closedWindowEvent setada para false,
        object Window é instanciada para um tamanho de 800px X 600px e com o nome OgrO.
    */
    OtherGrandRandomOgre::OtherGrandRandomOgre() : closeWindowEvent{false}
    {
        // Criação de instâncias de novas entidades físicas.
        players.insert(new PhysicalEntities::PhysicalEntity(Utilities::myVector2F(0.0f, 0.0f), Utilities::myVector2F(5, 5), "../assets/player.png"));
        players.insert(new PhysicalEntities::PhysicalEntity(Utilities::myVector2F(400.0f, 300.0f), Utilities::myVector2F(10, 0), "../assets/player.png"));
        players.insert(new PhysicalEntities::PhysicalEntity(Utilities::myVector2F(200.0f, 200.0f), Utilities::myVector2F(0, 5), "../assets/player.png"));
        // Carrega as imagens nas entidades físicas e inicializa os gerenciadores de eventos.
        players.initializePhysicalEntities(graphicManager, eventsManager);
        // Executa o jogo.
        OtherGrandRandomOgre::run();
    }
    // Destrutora da classe OtherGrandRandomOgre
    OtherGrandRandomOgre::~OtherGrandRandomOgre()
    {
        // Deleta dinamicamente os objetos das entidades físicas.
        // players.destroyCharacters();
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
            if (graphicManager.getWindow()->pollEvent(event))
            {
                // Caso o código do event seja referente ao clique no botão fechar da window.
                if (event.type == sf::Event::Closed)
                {
                    closeWindowEvent = true;
                }
            }
            // Limpa a window.
            graphicManager.clear();
            // Atualiza a lista dos Personagens, passando como parametro o tempo da aplicação em segundos.
            players.updatePhysicalEntities(t.asSeconds());
            // Desenha os personagens na window.
            players.drawPhysicalEntities(graphicManager);
            // Mostra a window para o usuário.
            graphicManager.display();
        }
        return 0;
    }
}