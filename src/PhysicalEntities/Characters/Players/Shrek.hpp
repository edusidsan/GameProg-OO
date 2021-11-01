#ifndef _SHREK_HPP_
#define _SHREK_HPP_

#include "../Character.hpp"

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

                public:
                    // Construtora da classe Enemy.
                    Shrek(Utilities::myVector2F pos);
                    // Destrutora da classe Enemy.
                    ~Shrek();
                    // Método carrega a textura do Player na window.
                    void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em);
                    // Método atualizar do Player. Tem como parâmetro uma variável float que representa o tempo.
                    void update(float t);
                    // Método desenhar do Player.
                    void draw(Managers::GraphicManager &gm);
                    // Método de tratamento de evento ocorrido.
                    void handleEvent(const sf::Event &ev);
                };
            }
        }
    }
}
#endif
