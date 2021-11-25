#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include "../PhysicalEntity.hpp"
#define MAXSPEEDX 80

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            class Character : public PhysicalEntity
            {
            protected:
                unsigned int keyEvent;
                float maxSpeedX;
                float maxSpeedY;
                int direction;
                bool jumping;
                Utilities::myVector2F adjusts;
                Utilities::MyClock clock;
                double timeReference;
                // unsigned int Life;
            public:
                // Construtora da classe Personagem. Atributos default configurados.
                Character(Utilities::myVector2F pos = {0.0f, 0.0f}, Utilities::myVector2F s = {0.0f, 0.0f}, const char *tPath = nullptr, unsigned int life = MAX_LIFE);
                // Destrutora da classe Personagem.
                virtual ~Character();
                // Método carrega a textura do personagem na window.
                // virtual void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm);
                virtual void initialize(Managers::EventsManager &em, Managers::CollisionManager &cm);
                // Método atualizar de Personagem. Tem como parâmetro uma variável float que representa o tempo.
                virtual void update(float t);
                // Método desenhar de Personagem. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
                virtual void draw(Managers::GraphicManager &gm);
                // Método run
                // void run();
            };
        }
    }
}
#endif