#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "Managers/GraphicManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    class Entity
    {
    protected:
        // Atributo que aponta para o gerenciador gráfico criado para o jogo.
        Managers::GraphicManager *pGraphicManager;
        int id;

    public:
        // Construtora da classe Entity. Atributos default configurados
        Entity();
        Entity(Managers::GraphicManager *gm);
        // Destrutora da classe Entity.
        virtual ~Entity();
        // Método desenhar de Entity.
        virtual void draw();

        // void setGraphicManager(Managers::GraphicManager gm);
        // Método run virtual puro -> TORNA CLASSE ABSTRATA.
        // virtual void run() = 0;
    };

}
#endif