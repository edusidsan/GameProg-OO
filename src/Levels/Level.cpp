#include "Level.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        // Construtora da classe Level.
        Level::Level() : Entity()
        {
        }
        // Destrutora da classe Level.
        Level::~Level()
        {
            // Deleta dinamicamente os objetos das entidades físicas.
            players.destroyPhysicalEntities();
        }
        // int Level::run()
        // {
 
        // }
        // Método que gerencia as colisões nas fases.
        void Level::handleCollisions()
        {
            // Gerenciador de colissões verifica se houve colisão entre entidades físicas.
            collisionManager.checkCollisions();
        }
        // Método que gerencia os eventos nas fases.
        void Level::handleEvents()
        {
            // Verifica se ocorreu algum evento.
            eventsManager.handleEvent();
        }
    }
}