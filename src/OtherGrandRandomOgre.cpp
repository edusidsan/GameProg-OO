#include "OtherGrandRandomOgre.hpp"
#include "PhysicalEntities/Characters/Enemies/Enemy.hpp"
#include "PhysicalEntities/Characters/Players/Shrek.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    // Construtora da classe OtherGrandRandomOgre
    /* Lista de inicialização da construtora com:
        booleana closedWindowEvent setada para false
    */
    OtherGrandRandomOgre::OtherGrandRandomOgre() : closeWindowEvent{false},
                                                   // lambda-expression.
                                                   idClosedWindow{eventsManager.addOtherListener([this](const sf::Event &event)
                                                                                                 { closedWindow(event); })}
    {
        // Criação de instâncias de novas entidades físicas.
        players.insert(new PhysicalEntities::Characters::Players::Shrek(Utilities::myVector2F(400.0f, 300.0f)));
        players.insert(new PhysicalEntities::Characters::Enemies::Enemy(Utilities::myVector2F(400.0f, 300.0f), Utilities::myVector2F(10, 0)));
        players.insert(new PhysicalEntities::Characters::Enemies::Enemy(Utilities::myVector2F(200.0f, 200.0f), Utilities::myVector2F(0, 5)));
        players.insert(new PhysicalEntities::Characters::Enemies::Enemy(Utilities::myVector2F(300.0f, 50.0f), Utilities::myVector2F(0, 5)));
        players.insert(new PhysicalEntities::Characters::Enemies::Enemy(Utilities::myVector2F(100.0f, 0.0f), Utilities::myVector2F(0, 5)));
        // Carrega as imagens nas entidades físicas e inicializa os gerenciadores de eventos.
        players.initializePhysicalEntities(graphicManager, eventsManager);
        // Atribui ao gerenciador de eventos a window que está sendo utilizada pelo gerenciador gráfico.
        eventsManager.setWindow(graphicManager.getWindow());
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
        while (!closeWindowEvent)
        {
            // Atribui a t o tempo em que a aplicação está rodando.
            sf::Time t = clock.getElapsedTime();
            // Reseta a contagem do clock.
            clock.restart();
            // Verifica se ocorreu algum evento.
            eventsManager.handleEvent();
            // Limpa a window.
            graphicManager.clear();
            // Atualiza a lista das entidades físicas, passando como parametro o tempo da aplicação em segundos.
            players.updatePhysicalEntities(t.asSeconds());
            // Desenha as entidades físicas na window.
            players.drawPhysicalEntities(graphicManager);
            // Mostra a window para o usuário.
            graphicManager.display();
        }
        return 0;
    }
    // Método encarregado de encerrar processo do jogo caso o evento de fechar a janela do jogo tenha ocorrido.
    void OtherGrandRandomOgre::closedWindow(const sf::Event &event)
    {
        if (event.type == sf::Event::Closed)
        {
            closeWindowEvent = true;
        }
    }
}
