#include "Entity.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    // Construtora da classe Entity. Atributos default configurados
    Entity::Entity() : id{0}
    {
    }
    // Destrutora da classe Entity.
    Entity::~Entity()
    {
    }
    // Método desenhar de Entity. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
    void Entity::draw(Managers::GraphicManager &gm)
    {
    }
    //
    void Entity::run()
    {
    }
}