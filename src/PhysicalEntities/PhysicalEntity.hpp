#ifndef _PHYSICALENTITY_HPP_
#define _PHYSICALENTITY_HPP_

#include "../Entity.hpp"
#include "../Utilities/Vector2D.hpp"
#include "../Managers/CollisionManager.hpp"
#include "../Managers/GraphicManager.hpp"
#include "../Managers/EventsManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        class PhysicalEntity : public Entity
        {
        protected:
            // Ponteiro que indica o caminho da textura.
            const char *texturePath;
            Utilities::myVector2F position, // Atributo de posição do PhysicalEntity
                speed,                      // Atributo de velocidade do PhysicalEntity
                dimension;                  // Atributo de dimensão do PhysicalEntity

        public:
            // Construtora da classe PhysicalEntity. Atributos default configurados
            PhysicalEntity(Utilities::myVector2F pos = {0.0f, 0.0f}, Utilities::myVector2F s = {0.0f, 0.0f}, const char *tPath = nullptr);
            // Destrutora da classe PhysicalEntity.
            virtual ~PhysicalEntity();
            // Método carrega a textura do PhysicalEntity na window.
            virtual void initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm);
            // Método atualizar de PhysicalEntity. Tem como parâmetro uma variável float que representa o tempo.
            virtual void update(float t);
            // Método desenhar de PhysicalEntity. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
            virtual void draw(Managers::GraphicManager &gm);
            // Método retorna a posição da entidade física.
            const Utilities::myVector2F getPosition() const;
            // Método retorna a dimensão da entidade fisica.
            const Utilities::myVector2F getDimension() const;
            // Método retorna ID atribuído ao ente.
            // Caso ID > 100, ente é entidade física.
            virtual const int getID() const;
            // Método verifica colisão entre dois objetos da classe Entidade Física.
            virtual void collided(int Id, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther) = 0;
        };
    }
}
#endif