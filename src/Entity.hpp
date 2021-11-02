#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_
namespace OgrO // Namespace com o nome do jogo.
{
    class Entity
    {
    protected:
        int id;

    public:
        // Construtora da classe Entity. Atributos default configurados
        Entity();
        // Destrutora da classe Entity.
        virtual ~Entity();
        // Método desenhar de Entity.
        virtual void draw();
        // Método run virtual puro -> TORNA CLASSE ABSTRATA.
        // virtual void run() = 0;
    };

}
#endif