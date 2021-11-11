#include "Teste.hpp"
#include <iostream>
namespace OgrO // Namespace com o nome do jogo.
{

    // Construtora da classe Menu.
    // Menu(Managers::GraphicManager &gm);
    Teste::Teste()
    {
    }
    Teste::Teste(Managers::GraphicManager *gm)
    {
        std::cout << "gm: " << gm << std::endl;
    }
    // Destrutora da classe Menu.
    Teste::~Teste()
    {
    }

}