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
                private:
                    // Atributo que indica o código do evento ocorrido.
                    unsigned int keyEvent;
                    float maxSpeedX;
                    float maxSpeedY;
                    int direction;
                    bool jumping;
                    Utilities::myVector2F adjusts;

                public:
                    // Construtora da classe Donkey.
                    Donkey(Utilities::myVector2F pos = {0.0f, 0.0f}, const char *tPath = nullptr);
                    // Destrutora da classe Donkey.
                    ~Donkey();
                    // Método carrega a textura do Donkey na window.
                    // void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm);
                    void initialize(Managers::EventsManager &em, Managers::CollisionManager &cm);
                    // Método atualizar do Donkey. Tem como parâmetro uma variável float que representa o tempo.
                    void update(float t);
                    // Método desenhar do Donkey.
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
