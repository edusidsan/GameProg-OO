#include "PhysicalEntity.hpp"
#include "Characters/Character.hpp"
// #include "../Levels/Level.hpp"
#include "../json.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        // Construtora da classe PhysicalEntity. Atributos default configurados
        PhysicalEntity::PhysicalEntity(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath, unsigned int life) : Entity(),
                                                                                                                                   position{pos},
                                                                                                                                   speed{s},
                                                                                                                                   texturePath{tPath},
                                                                                                                                //    Life{MAX_LIFE}
                                                                                                                                   Life{life}
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
            std::cout << "texturePath Player ID: " << texturePath << std::endl;
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
        const Utilities::gameVector2F PhysicalEntity::getPosition() const
        {
            return position;
        }
        void PhysicalEntity::setPosition(Utilities::gameVector2F pos)
        {
            position = pos;
        }
        // Método retorna a velocidade da entidade física.
        const Utilities::gameVector2F PhysicalEntity::getSpeed() const
        {
            return speed;
        }
        // Método seta a velocidade da entidade física.
        void PhysicalEntity::setSpeed(Utilities::gameVector2F _speed)
        {
            speed = _speed;
        }
        // Método retorna a dimensão da entidade fisica.
        const Utilities::gameVector2F PhysicalEntity::getDimension() const
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
        void PhysicalEntity::collided(int Id, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther)
        {
        }

        nlohmann::json PhysicalEntity::toJSON()
        {
            return {
                {"id", id},
                {"life", Life},
                {"position x", position.coordX},
                {"position y", position.coordY},
                {"speed x", speed.coordX},
                {"speed y", speed.coordY},
                {"texturePath", texturePath},
                {"dimension x", dimension.coordX},
                {"dimension y", dimension.coordY}};
        }

        int PhysicalEntity::run()
        {
            std::cout << "Implementar PhysicalEntity::run()" << std::endl;
            return 0;
        }

    }
}