#include "PhysicalEntity.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        // Construtora da classe PhysicalEntity. Atributos default configurados
        PhysicalEntity::PhysicalEntity(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath) : position{pos},
                                                                                                                speed{s},
                                                                                                                texturePath{tPath}
        {
        }
        // Destrutora da classe PhysicalEntity.
        PhysicalEntity::~PhysicalEntity()
        {
        }
        // Método carrega a textura do PhysicalEntity na window.
        void PhysicalEntity::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em)
        {
            gm.loadAsset(texturePath);
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
    }
}