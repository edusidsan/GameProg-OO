#include "PhysicalEntity.hpp"
#include "../json.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        // Construtora da classe PhysicalEntity. Atributos default configurados
        PhysicalEntity::PhysicalEntity(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath) : Entity(),
                                                                                                                position{pos},
                                                                                                                speed{s},
                                                                                                                texturePath{tPath}
        {
        }
        // Destrutora da classe PhysicalEntity.
        PhysicalEntity::~PhysicalEntity()
        {
        }
        // Método carrega a textura do PhysicalEntity na window.
        // void PhysicalEntity::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm)
        void PhysicalEntity::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
        {
            // gm.loadAsset(texturePath);
            pGraphicManager->loadAsset(texturePath);
        }
        // Método atualizar de PhysicalEntity. Tem como parâmetro uma variável float que representa o tempo.
        void PhysicalEntity::update(float t)
        {
            // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
            position += speed * t;
        }
        // Método desenhar de PhysicalEntity. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
        void PhysicalEntity::draw(Managers::GraphicManager &gm)
        {
            // Desenha a forma da entidade fisica na window.
            gm.draw(texturePath, position);
        }
        // Método retorna a posição da entidade física.
        const Utilities::myVector2F PhysicalEntity::getPosition() const
        {
            return position;
        }
        // Método retorna a dimensão da entidade fisica.
        const Utilities::myVector2F PhysicalEntity::getDimension() const
        {
            return dimension;
        }
        // Método retorna ID atribuído ao ente.
        // Caso ID > 100, ente é entidade física.
        const int PhysicalEntity::getID() const
        {
            return id;
        }
        // Método verifica colisão entre dois objetos da classe Entidade Física.
        void PhysicalEntity::collided(int Id, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
        {
        }

        nlohmann::json PhysicalEntity::toJSON()
        {
            return {
                // {"id", id},
                // {"position", position.toJSON()},
                // {"speed", speed.toJSON()},
                // {"texturePath", texturePath},
                // {"dimension", dimension.toJSON()}};

                {"id", id},
                {"position x", position.coordX},
                {"position y", position.coordY},
                {"speed x", speed.coordX},
                {"speed y", speed.coordY},
                {"texturePath", texturePath},
                {"dimension x", dimension.coordX},
                {"dimension y", dimension.coordY}};
        }
    }
}