#ifndef _SHREK_HPP_
#define _SHREK_HPP_

#include "../Character.hpp"
#include <iostream>
namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Players // Namespace do Pacote Enemies.
            {
                class Shrek : public Character
                {
                private:
                    // Atributo que indica o código do evento ocorrido.
                    unsigned int keyEvent;
                    float maxSpeedX;
                    float maxSpeedY;
                    int direction;
                    bool jumping;
                    Utilities::myVector2F adjusts;

                public:
                    // Construtora da classe Enemy.
                    Shrek(Utilities::myVector2F pos = {0.0f, 0.0f});
                    // Destrutora da classe Enemy.
                    ~Shrek();
                    // Método carrega a textura do Player na window.
                    // void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm);
                    void initialize(Managers::EventsManager &em, Managers::CollisionManager &cm);
                    // Método atualizar do Player. Tem como parâmetro uma variável float que representa o tempo.
                    void update(float t);
                    // Método desenhar do Player.
                    void draw(Managers::GraphicManager &gm);
                    // Método de tratamento de evento ocorrido.
                    void handleEvent(const sf::Event &ev);
                    // Método verifica colisão entre dois objetos da classe Entidade Física.
                    void collided(int idOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther);
                };
            }
        }
    }
}
#endif
