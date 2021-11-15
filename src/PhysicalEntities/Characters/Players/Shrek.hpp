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
                    Shrek(Utilities::myVector2F pos = {0.0f, 0.0f}, const char *tPath = nullptr);
                    // Destrutora da classe Sherek.
                    ~Shrek();
<<<<<<< HEAD
                    // Método carrega a textura do Sherek na window.
                    // void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm);
                    void initialize(Managers::EventsManager &em, Managers::CollisionManager &cm);
                    // Método atualizar do Sherek. Tem como parâmetro uma variável float que representa o tempo.
                    void update(float t);
                    // Método desenhar do Sherek.
                    void draw(Managers::GraphicManager &gm);
=======
>>>>>>> eduDevelop
                    // Método de tratamento de evento ocorrido.
                    void handleEvent(const sf::Event &ev);

                };
            }
        }
    }
}
#endif
