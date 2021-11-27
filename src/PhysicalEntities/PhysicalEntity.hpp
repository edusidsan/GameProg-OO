#ifndef _PHYSICALENTITY_HPP_
#define _PHYSICALENTITY_HPP_

#include "../Entity.hpp"
#include "../Utilities/Vector2D.hpp"
#include "../Managers/CollisionManager.hpp"
#include "../Managers/EventsManager.hpp"
#include "../Utilities/Clock.hpp"

#define MAX_LIFE 1000
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        class Level;
    }

    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        class PhysicalEntity : public Entity
        {
        protected:
            // Ponteiro que indica o caminho da textura.
            const char *texturePath;
            Utilities::gameVector2F position, // Atributo de posição do PhysicalEntity
                speed,                      // Atributo de velocidade do PhysicalEntity
                dimension;                  // Atributo de dimensão do PhysicalEntity
            unsigned int Life;

        public:
            // Construtora da classe PhysicalEntity. Atributos default configurados
            PhysicalEntity(Utilities::gameVector2F pos = {0.0f, 0.0f}, Utilities::gameVector2F s = {0.0f, 0.0f}, const char *tPath = nullptr, unsigned int life = MAX_LIFE);
            // Destrutora da classe PhysicalEntity.
            virtual ~PhysicalEntity();
            // Método carrega a textura do PhysicalEntity na window.
            // virtual void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm);
            virtual void initialize(Managers::EventsManager &em, Managers::CollisionManager &cm);
            // Método atualizar de PhysicalEntity. Tem como parâmetro uma variável float que representa o tempo.
            virtual void update(float t);
            // Método desenhar de PhysicalEntity. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
            virtual void draw();
            // Método retorna a posição da entidade física.
            const Utilities::gameVector2F getPosition() const;
            // Método seta a posição da entidade física.
            virtual void setPosition(Utilities::gameVector2F pos);
            // Método retorna a velocidade da entidade física.
            const Utilities::gameVector2F getSpeed() const;
            // Método seta a velocidade da entidade física.
            virtual void setSpeed(Utilities::gameVector2F _speed);
            // Método retorna a dimensão da entidade fisica.
            const Utilities::gameVector2F getDimension() const;
            // Método retorna ID atribuído ao ente.
            // Caso ID > 100, ente é entidade física.
            virtual const int getID() const;
            // Método verifica colisão entre dois objetos da classe Entidade Física.
            virtual void collided(int Id, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther) = 0;
            // Método run virtual puro -> TORNA CLASSE ABSTRATA.
            virtual int run();
            // Método
            nlohmann::json toJSON();
        };
    }
}
#endif