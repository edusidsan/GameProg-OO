#ifndef _COLLISIONMANAGER_HPP_
#define _COLLISIONMANAGER_HPP_

#include <list>
#include <vector>
#include <set>

namespace OgrO // Namespace com o nome do jogo.
{
    /*---------------------------- Atribuição de classes para não ocorrer conflito de inclusão recursiva.*/
    namespace PhysicalEntities
    {
        class PhysicalEntity;
        namespace Characters
        {
            namespace Enemies
            {
                class Enemy;
            }
            namespace Players
            {
                class Shrek;
            }
        }
        namespace Obstacles
        {
            class Obstacle;
        }
    }
    /*--------------------------------------------------------------------------------------------------*/

    namespace Managers // Namespace do Pacote Managers.
    {
        class CollisionManager
        {
        private:
            // Set(contaniner associativo de valores únicos) que incorpora todas as entidades físicas que poderão se colidir.
            // std::set<PhysicalEntities::PhysicalEntity *> LCollidablesPhysicalEntities;
            std::list<PhysicalEntities::PhysicalEntity *> LCollidablesPhysicalEntities;
            // Vetor representando uma lista de inimigos.
            std::vector<PhysicalEntities::Characters::Enemies::Enemy *> LEs;
            // Lista representando um conjunto de obstáculos.
            std::list<PhysicalEntities::Obstacles::Obstacle *> LOs;
            // Atributo que aponta para o player.
            PhysicalEntities::Characters::Players::Shrek *pPlayer = nullptr;
            // Atributo que retorna se duas entidades físicas colidem.
            bool colliding(PhysicalEntities::PhysicalEntity *e1, PhysicalEntities::PhysicalEntity *e2);

        public:
            // Construtora da classe CollisionManager.
            CollisionManager();
            // Destrutora da classe CollisionManager.
            ~CollisionManager();
            // Método que adiciona um elemento de Enemy na lista de possíveis objetos que colidem.
            void addToLCollidablesPhysicalEntities(PhysicalEntities::Characters::Enemies::Enemy *pPE);
            // Método que adiciona um elemento de Obstacle na lista de possíveis objetos que colidem.
            void addToLCollidablesPhysicalEntities(PhysicalEntities::Obstacles::Obstacle *pPE);
            // Método que adiciona um elemento de player::shrek na lista de possíveis objetos que colidem.
            void addToLCollidablesPhysicalEntities(PhysicalEntities::Characters::Players::Shrek *pPE);

            // Método que adiciona um elemento de entidade física na lista de possíveis objetos que colidem.
            // void addToLCollidablesPhysicalEntities(PhysicalEntities::PhysicalEntity *pPE);
            // Método que remove um elemento de entidade física na lista de possíveis objetos que colidem.
            // void removeFromLCollidablesPhysicalEntities(PhysicalEntities::PhysicalEntity *pPE);
            // Método que limpa a lista de possíveis objetos que colidem.
            void removeAll();
            // Método que verifica se houve colisão entre entidades físicas.
            void checkCollisions();
        };
    }
}
#endif