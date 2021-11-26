#ifndef _SHREK_HPP_
#define _SHREK_HPP_

#include "Player.hpp"
#include <iostream>
namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Players // Namespace do Pacote Enemies.
            {
                class Shrek : public Player
                {
                public:
                    // Construtora da classe Sherek.
                    Shrek(Utilities::gameVector2F pos = {0.0f, 0.0f}, const char *tPath = nullptr);
                    // Destrutora da classe Sherek.
                    ~Shrek();
                    // Método de tratamento de evento ocorrido.
                    void handleEvent(const sf::Event &ev);
                };
            }
        }
    }
}
#endif
