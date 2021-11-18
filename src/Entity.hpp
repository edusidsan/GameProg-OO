#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "Managers/GraphicManager.hpp"
#include "Managers/EventsManager.hpp"
#include "Mementos/Memento.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    class Entity : public Mementos::Memento
    {
    protected:
        // Atributo que aponta para o gerenciador gráfico criado para o jogo.
        Managers::GraphicManager *pGraphicManager;
        int id;

    public:
        // Construtora da classe Entity. Atributos default configurados
        Entity();
        // Destrutora da classe Entity.
        virtual ~Entity();
        // Método desenhar de Entity.
        virtual void draw();

        virtual void init();
        // virtual void init(Managers::EventsManager& e);
        // Método run virtual puro -> TORNA CLASSE ABSTRATA.
        virtual int run() = 0;

 

        // nlohmann::json toJSON();
    };

}
#endif