#include "CollisionManager.hpp"
#include "../Utilities/Vector2D.hpp"
#include "../PhysicalEntities/Characters/Enemies/Enemy.hpp"
#include "../PhysicalEntities/Characters/Players/Shrek.hpp"
#include "../PhysicalEntities/Obstacles/Obstacle.hpp"
#include "../PhysicalEntities/PhysicalEntity.hpp"
#include <algorithm>
#include <iostream>
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {

        // Método que retorna se duas entidades físicas colidem.
        bool CollisionManager::colliding(PhysicalEntities::PhysicalEntity *e1, PhysicalEntities::PhysicalEntity *e2)
        {
            Utilities::myVector2F position1 = e1->getPosition();
            Utilities::myVector2F position2 = e2->getPosition();
            Utilities::myVector2F dimension1 = e1->getDimension();
            Utilities::myVector2F dimension2 = e2->getDimension();

            Utilities::myVector2F c1 = position1 + dimension1 * .5;
            Utilities::myVector2F c2 = position2 + dimension2 * .5;

            return (abs(c1.coordX - c2.coordX) < (dimension1.coordX + dimension2.coordX) / 2 &&
                    abs(c1.coordY - c2.coordY) < (dimension1.coordY + dimension2.coordY) / 2);
        }

        // Construtora da classe CollisionManager.
        CollisionManager::CollisionManager() : LCollidablesPhysicalEntities(),
                                               LEs(),
                                               LOs(),
                                               pPlayer{nullptr}
        {
        }
        // Destrutora da classe CollisionManager.
        CollisionManager::~CollisionManager()
        {
            LCollidablesPhysicalEntities.clear();
            LEs.clear();
            LOs.clear();
            pPlayer = nullptr;
        }

        // // Método que adiciona um elemento de entidade física na lista de possíveis objetos que colidem.
        // void CollisionManager::addToLCollidablesPhysicalEntities(PhysicalEntities::PhysicalEntity *pPE)
        // {
        //     if (pPE)
        //     {
        //         LCollidablesPhysicalEntities.insert(pPE);
        //     }
        // }

        // Método que adiciona um elemento de Enemy na lista de possíveis objetos que colidem.
        void CollisionManager::addToLCollidablesPhysicalEntities(PhysicalEntities::Characters::Enemies::Enemy *pPE)
        {
            LEs.push_back(pPE);
            LCollidablesPhysicalEntities.push_back((static_cast<PhysicalEntities::PhysicalEntity *>(pPE)));
        }
        // Método que adiciona um elemento de Obstacle na lista de possíveis objetos que colidem.
        void CollisionManager::addToLCollidablesPhysicalEntities(PhysicalEntities::Obstacles::Obstacle *pPE)
        {
            LOs.push_back(pPE);
            LCollidablesPhysicalEntities.push_back((static_cast<PhysicalEntities::PhysicalEntity *>(pPE)));
        }
        // Método que adiciona um elemento de player::shrek na lista de possíveis objetos que colidem.
        void CollisionManager::addToLCollidablesPhysicalEntities(PhysicalEntities::Characters::Players::Shrek *pPE)
        {
            pPlayer = pPE;
            LCollidablesPhysicalEntities.push_back((static_cast<PhysicalEntities::PhysicalEntity *>(pPE)));
        }
        // Método que adiciona um elemento de entidade física na lista de possíveis objetos que colidem.
        // void CollisionManager::addToLCollidablesPhysicalEntities(PhysicalEntities::PhysicalEntity *pPE)
        // {
        //     if (pPE)
        //     {
        //         LCollidablesPhysicalEntities.push_back(pPE);
        //     }
        // }

        // // Método que remove um elemento de entidade física na lista de possíveis objetos que colidem.
        // void CollisionManager::removeFromLCollidablesPhysicalEntities(PhysicalEntities::PhysicalEntity *pPE)
        // {
        //     if (pPE)
        //     {
        //         LCollidablesPhysicalEntities.erase(pPE);
        //     }
        // }

        // Método que limpa a lista de possíveis objetos que colidem.
        void CollisionManager::removeAll()
        {
            LCollidablesPhysicalEntities.clear();
            LEs.clear();
            LOs.clear();
        }

        // Método que verifica se houve colisão entre entidades físicas.
        void CollisionManager::checkCollisions()
        {
            std::vector<PhysicalEntities::Characters::Enemies::Enemy *>::iterator itLEs = LEs.begin();

            PhysicalEntities::PhysicalEntity *firstElement = nullptr;
            PhysicalEntities::PhysicalEntity *secondElement = nullptr;
            // std::list<PhysicalEntities::Obstacles::Obstacle *>::iterator itLOs = LOs.begin();
            int j;
            for (int i = 0; i < LEs.size() + 1; i++)
            {
                std::cout << "Entrou no for ";
                std::cout << "i:" << i << "\n";

                // firstElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLEs);
                auto pAux = itLEs;
                if (i < LEs.size())
                {
                    // firstElement = static_cast<PhysicalEntities::PhysicalEntity *>(*pAux);
                    firstElement = (*pAux);
                    // auto pAux = itLEs;

                    for (j = i + 1; j < LEs.size() + 1; j++)
                    {
                        std::cout << "      Entrou no for ";
                        std::cout << "j:" << j << " ";
                        if (j < LEs.size())
                        {
                            itLEs++;
                            // secondElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLEs);
                            secondElement = (*itLEs);
                            std::cout << secondElement->getID() << "\n";
                        }
                        else
                        {
                            itLEs = pAux;
                            // secondElement = static_cast<PhysicalEntities::PhysicalEntity *>(pPlayer);
                            secondElement = (pPlayer);
                        }

                        if (colliding(firstElement, secondElement))
                        {
                            std::cout << "itLES:" << *itLEs << "\n";
                            firstElement->collided(secondElement->getID(), secondElement->getPosition(), secondElement->getDimension());
                            secondElement->collided(firstElement->getID(), firstElement->getPosition(), firstElement->getDimension());
                            // itLEs = LEs.begin();
                        }
                        std::cout << std::endl;
                    }
                }
                pAux = pAux++;
                itLEs = pAux;
            }

            // for (auto firstElement = LCollidablesPhysicalEntities.begin(); firstElement != LCollidablesPhysicalEntities.end(); firstElement++)
            // {

            //     auto secondElement = firstElement;
            //     secondElement++;

            //     for (; secondElement != LCollidablesPhysicalEntities.end(); secondElement++)
            //     {
            //         PhysicalEntities::PhysicalEntity *p1 = *firstElement;
            //         PhysicalEntities::PhysicalEntity *p2 = *secondElement;

            //         if (colliding(p1, p2))
            //         {
            //             std::cout << "it:" << *secondElement << "\n";
            //             p1->collided(p2->getID(), p2->getPosition(), p2->getDimension());
            //             p2->collided(p1->getID(), p1->getPosition(), p1->getDimension());
            //         }
            //     }

            //     //std::cout << '\n' << std::endl;
            // }
        }
    }
}