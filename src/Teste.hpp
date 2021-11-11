#ifndef _TESTE_HPP_
#define _TESTE_HPP_

#include "Managers/GraphicManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{

        class Teste 
        {
        public:
        
            // Construtora da classe Menu.
            // Menu(Managers::GraphicManager &gm);
            Teste();
            Teste(Managers::GraphicManager *gm);
            // Destrutora da classe Menu.
            virtual ~Teste();
        };
    
}
#endif