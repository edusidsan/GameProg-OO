#ifndef _DONKEY_HPP_
#define _DONKEY_HPP_

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
                class Donkey : public Player
                {
                public:
                    // Construtora da classe Donkey.
                    Donkey(Utilities::myVector2F pos = {0.0f, 0.0f}, const char *tPath = nullptr);
                    // Destrutora da classe Donkey.
                    ~Donkey();
                    // Método de tratamento de evento ocorrido.
                    void handleEvent(const sf::Event &ev);
                };
            }
        }
    }
}
#endif
