#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "Managers/GraphicManager.hpp"

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
            // Método desenhar de Entity. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
            virtual void draw(Managers::GraphicManager &gm);
            //
            virtual void run();
        };
    
}
#endif