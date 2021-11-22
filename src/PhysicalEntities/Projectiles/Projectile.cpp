#include "Projectile.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote PhysicalEntities.
    {
        namespace Projectiles // Namespace do Pacote Projectiles.
        {
            // Construtora da classe Projectile.
            Projectile::Projectile(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath) : PhysicalEntity(pos, s, tPath)
            {
            }
            // Destrutora da classe Projectile.
            Projectile::~Projectile()
            {
            }
            // Método carrega a textura do Projectile na window.
            void Projectile::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
            {
                // Carrega textura no Projectile.
                pGraphicManager->loadAsset(texturePath);
                // Retorna dimensão da imagem.
                dimension = pGraphicManager->getDimensionsOfAsset(texturePath);
            }
            // Método atualizar do Projectile. Tem como parâmetro uma variável float que representa o tempo.
            void Projectile::update(float t)
            {
                position += speed * t;
            }
            // Método verifica colisão entre dois objetos da classe Entidade Física.
            void Projectile::collided(int idOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
            {
            }
        }
    }
}