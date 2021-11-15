#include "CollisionManager.hpp"
#include "../Utilities/Vector2D.hpp"
#include "../PhysicalEntities/Characters/Enemies/Enemy.hpp"
#include "../PhysicalEntities/Characters/Players/Player.hpp"
//#include "../PhysicalEntities/Characters/Players/Shrek.hpp"
#include "../PhysicalEntities/Obstacles/Obstacle.hpp"
#include "../PhysicalEntities/PhysicalEntity.hpp"
#include <algorithm>
#include <iostream>
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {

        // Construtora da classe CollisionManager.
        CollisionManager::CollisionManager() : LCollidablesPhysicalEntities(),
                                               LEs(),
                                               LOs(),
                                               LPs()
        //pPlayer{nullptr}
        {
        }
        // Destrutora da classe CollisionManager.
        CollisionManager::~CollisionManager()
        {
            LCollidablesPhysicalEntities.clear();
            LEs.clear();
            LOs.clear();
            LPs.clear();
            //pPlayer = nullptr;
        }

        // Método que retorna se duas entidades físicas colidem.
        bool CollisionManager::colliding(PhysicalEntities::PhysicalEntity *e1, PhysicalEntities::PhysicalEntity *e2)
        {
            // Position1 recebe posição do primeiro elemento passado por parâmetro.
            Utilities::myVector2F position1 = e1->getPosition();
            // Position2 recebe posição do segundo elemento passado por parâmetro.
            Utilities::myVector2F position2 = e2->getPosition();
            // Dimension1 recebe dimensões do primeiro elemento passado por parâmetro.
            Utilities::myVector2F dimension1 = e1->getDimension();
            // Dimension2 recebe dimensões do segundo elemento passado por parâmetro.
            Utilities::myVector2F dimension2 = e2->getDimension();

            Utilities::myVector2F distance = position1 - position2;

            if (e1 == e2)
            {
                return false;
            }
            // Caso as distâncias entre os centros em qualquer um dos eixos for menor que a metade da soma das dimensões naquele eixo, está ocorrendo colisão.
            return (abs(distance.coordX) < ((dimension1.coordX + dimension2.coordX) / 2) &&
                    abs(distance.coordY) < ((dimension1.coordY + dimension2.coordY) / 2));
        }

        // Método que adiciona um elemento de Enemy na lista de possíveis objetos que colidem.
        void CollisionManager::addToLCollidablesPhysicalEntities(PhysicalEntities::Characters::Enemies::Enemy *pPE)
        {
            // Adiciona um elemento de Enemy no vector de Enemy.
            LEs.push_back(pPE);
            LCollidablesPhysicalEntities.push_back((static_cast<PhysicalEntities::PhysicalEntity *>(pPE)));
        }
        // Método que adiciona um elemento de Obstacle na lista de possíveis objetos que colidem.
        void CollisionManager::addToLCollidablesPhysicalEntities(PhysicalEntities::Obstacles::Obstacle *pPE)
        {
            // Adiciona um elemento de Obstacle na list de Obstacle.
            LOs.push_back(pPE);
            LCollidablesPhysicalEntities.push_back((static_cast<PhysicalEntities::PhysicalEntity *>(pPE)));
        }
        // Método que adiciona um elemento de player::shrek na lista de possíveis objetos que colidem.
        void CollisionManager::addToLCollidablesPhysicalEntities(PhysicalEntities::Characters::Players::Player *pPE)
        {
            // Adiciona um elemento de pPlayer no vector de Players.
            LPs.push_back(pPE);
            LCollidablesPhysicalEntities.push_back((static_cast<PhysicalEntities::PhysicalEntity *>(pPE)));
        }
        // Método que limpa a lista de possíveis objetos que colidem.
        void CollisionManager::removeAll()
        {
            LCollidablesPhysicalEntities.clear();
            LEs.clear();
            LOs.clear();
            LPs.clear();
        }

        // Método que verifica se houve colisão entre entidades físicas.
        void CollisionManager::checkCollisions()
        {

            // Primeiro iterador do vetor Enemy.
            std::vector<PhysicalEntities::Characters::Enemies::Enemy *>::iterator itLEs1 = LEs.begin();
            // itLEs1 = LEs.begin();
            // Segundo iterador do vetor Enemy.
            std::vector<PhysicalEntities::Characters::Enemies::Enemy *>::iterator itLEs2 = LEs.begin();
            // Váriavel indica tamanho do vetor Enemy.
            const short int LEsSize = LEs.size();

            // Primeiro iterador da list Obstacle.
            std::list<PhysicalEntities::Obstacles::Obstacle *>::iterator itLOs1 = LOs.begin();
            // Segundo iterador da list Obstacle.
            std::list<PhysicalEntities::Obstacles::Obstacle *>::iterator itLOs2 = LOs.begin();
            // Váriavel indica tamanho da list Obstacle.
            const short int LOsSize = LOs.size();

            // Váriavel indica quantidade de players.
            std::vector<PhysicalEntities::Characters::Players::Player *>::iterator itLPs1 = LPs.begin();
            const short int LPsSize = LPs.size();
            //std::cout << "LPs:" << LPsSize<<"LOs:"<<LOsSize<<"LEs:"<<LEsSize << std::endl;
            //std::cout<<"Size Players:"<<LPsSize<<std::endl;
            // Sequência de veirficação.
            /*----------------------------
                VETOR ENEMY        LIST OBSTACLES      PLAYER
            {O x * * * * * * *}  {* * * * * * * * *}    **

                VETOR ENEMY        LIST OBSTACLES      PLAYER
            {O * x * * * * * *}  {* * * * * * * * *}    **

                VETOR ENEMY        LIST OBSTACLES      PLAYER
            {O * * * * * * * *}  {* * * * * * * * *}    x

                VETOR ENEMY        LIST OBSTACLES      PLAYER
            {* O x * * * * * *}  {* * * * * * * * *}    **

                VETOR ENEMY        LIST OBSTACLES      PLAYER
            {* O * x * * * * *}  {* * * * * * * * *}    **
            */
            // Laço de repetição para o tamanho completo de entidades físicas que colidem.
            for (short int i = 0; i < LEsSize + LOsSize + LPsSize; ++i)
            {
                // Nessa condição, está sendo analisado um elemento da classe Enemy. (firstElement vai ser da classe Enemy.)
                if (i < LEsSize)
                {
                    // Segundo iterador do vetor de Enemy aponta para a posição do primeiro iterator.
                    itLEs2 = itLEs1;
                    // Segundo iterador do vetor de Enemy desloca uma posição.
                    itLEs2++;

                    // Forjamento de elemento apontado pelo iterador do vector Enemy para a classe de entidade física. Necessário para método collided.
                    PhysicalEntities::PhysicalEntity *firstElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLEs1);

                    // Preeche vetor de tiles se houverem colisões.
                    std::vector<Tiles::TilesManager::tilesManagerAttributes> collidingTiles = {};

                    collidingTiles = pTileManager->checkCollisions(firstElement->getID(), firstElement->getPosition(), firstElement->getDimension());

                    // Iterador do vetor collidingTiles.
                    std::vector<Tiles::TilesManager::tilesManagerAttributes>::iterator itCollidingTiles = collidingTiles.begin();
                    // Colide de fato os elementos do vetor de colisões com o firstElement.
                    while (itCollidingTiles != collidingTiles.end())
                    {
                        firstElement->collided((*itCollidingTiles).id, (*itCollidingTiles).position, (*itCollidingTiles).dimension);
                        itCollidingTiles++;
                    }
                    // Laço de repetição para o tamanho completo de entidades físicas que colidem.
                    for (short int j = i + 1; j < LEsSize + LOsSize + LPsSize; ++j)
                    {
                        // Inicialização do ponteiro secondElement.
                        PhysicalEntities::PhysicalEntity *secondElement = nullptr;
                        // Nessa condição, está sendo analisado um elemento da classe Enemy. (secondElement vai ser da classe Enemy.)
                        if (j < LEsSize)
                        {
                            // Forjamento de elemento apontado pelo iterador do vector Enemy para a classe de entidade física. Necessário para método collided.
                            secondElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLEs2);
                        }
                        // Nessa condição, está sendo analisado um elemento da classe Obstacle. (secondElement vai ser da classe Obstacle.)
                        else if ((j >= LEsSize) && (j < LOsSize))
                        {
                            // Forjamento de elemento apontado pelo iterador da list Obstacle para a classe de entidade física. Necessário para método collided.
                            secondElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLOs1);
                            // Incremento no primeiro contador da list Obstacle.
                            itLOs1++;
                        }

                        // Nessa condição, está sendo analisado um elemento da classe Player. (secondElement vai ser da classe Player.)
                        // Montar vector para Player !!!!!!!!!!! <-------------------------------------
                        else
                        {
                            // Forjamento de elemento apontado pelo iterador do vector Player para a classe de entidade física. Necessário para método collided.
                            secondElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLPs1);
                            // Reseta posição do contador da list Obstacle.
                            itLOs1 = LOs.begin();
                            itLPs1++;
                        }
                        // Testa se houve colisão entre os elementos analisados.
                        if (colliding(firstElement, secondElement))
                        {
                            // Primeiro elemento impacta atributos da entidade física do outro elemento.
                            firstElement->collided(secondElement->getID(), secondElement->getPosition(), secondElement->getDimension());
                            // Outro elemento impacta atributos da entidade física do primeiro elemento.
                            secondElement->collided(firstElement->getID(), firstElement->getPosition(), firstElement->getDimension());
                        }
                        // Incremento no segundo contador do vector Enemy.
                        itLEs2++;
                        
                    }
                    // Incremento no primeiro contador do vector Enemy.
                    itLEs1++;
                    // std::cout << "Iterador Players:" << *itLPs1 << std::endl;
                    itLPs1 = LPs.begin();
                    
                }

                // Nessa condição, está sendo analisado um elemento da classe Obstacle. (firstElement vai ser da classe Obstacle.)
                else if ((i >= LEsSize) && (i < LOsSize))
                {
                    // Segundo iterador da lista de Obstacle aponta para a posição do primeiro iterator.
                    itLOs2 = itLOs1;
                    // Segundo iterador do a lista de Obstacle desloca uma posição.
                    itLOs2++;

                    // Forjamento de elemento apontado pelo iterador do vector Enemy para a classe de entidade física. Necessário para método collided.
                    PhysicalEntities::PhysicalEntity *firstElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLOs1);

                    // Preeche vetor de tiles se houverem colisões.
                    std::vector<Tiles::TilesManager::tilesManagerAttributes> collidingTiles = {};
                    collidingTiles = pTileManager->checkCollisions(firstElement->getID(), firstElement->getPosition(), firstElement->getDimension());

                    // Iterador do vetor collidingTiles.
                    std::vector<Tiles::TilesManager::tilesManagerAttributes>::iterator itCollidingTiles = collidingTiles.begin();
                    // Colide de fato os elementos do vetor de colisões com o firstElement.
                    while (itCollidingTiles != collidingTiles.end())
                    {
                        firstElement->collided((*itCollidingTiles).id, (*itCollidingTiles).position, (*itCollidingTiles).dimension);
                        itCollidingTiles++;
                    }
                    // Laço de repetição para o tamanho completo de entidades físicas que colidem.
                    for (int j = i + 1; j < LEsSize + LOsSize + LPsSize; j++)
                    {
                        // Forjamento de elemento apontado pelo iterador da list Obstacle para a classe de entidade física. Necessário para método collided.
                        PhysicalEntities::PhysicalEntity *firstElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLOs1);
                        // Inicialização do ponteiro secondElement.
                        PhysicalEntities::PhysicalEntity *secondElement = nullptr;
                        // Nessa condição, está sendo analisado um elemento da classe Obstacle. (secondElement vai ser da classe Obstacle.)
                        if ((j >= LEsSize) && (j < LOsSize))
                        {
                            // Forjamento de elemento apontado pelo iterador da list Obstacle para a classe de entidade física. Necessário para método collided.
                            secondElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLOs2);
                            // Incremento no segundo contador da list Obstacle.
                            itLOs2++;
                        }
                        // Nessa condição, está sendo analisado um elemento da classe Player. (secondElement vai ser da classe Player.)
                        // Montar vector para Player !!!!!!!!!!! <-------------------------------------
                        else
                        {
                            // Forjamento de elemento apontado pelo iterador do vector Player para a classe de entidade física. Necessário para método collided.
                            secondElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLPs1);
                            // Reseta posição do contador da list Obstacle.
                            itLOs1 = LOs.begin();
                            // Reseta posição do contador da list Obstacle.
                            itLOs2 = LOs.begin();
                            itLPs1++;
                        }
                        // else
                        // {
                        //     // Forjamento de elemento apontado pelo iterador do vector Player para a classe de entidade física. Necessário para método collided.
                        //     secondElement = static_cast<PhysicalEntities::PhysicalEntity *>(pPlayer);
                        //     // Reseta posição do contador da list Obstacle.
                        //     itLOs1 = LOs.begin();
                        //     // Reseta posição do contador da list Obstacle.
                        //     itLOs2 = LOs.begin();
                        // }
                        // Testa se houve colisão entre os elementos analisados.
                        if (colliding(firstElement, secondElement))
                        {
                            // Primeiro elemento impacta atributos da entidade física do outro elemento.
                            firstElement->collided(secondElement->getID(), secondElement->getPosition(), secondElement->getDimension());
                            // Outro elemento impacta atributos da entidade física do primeiro elemento.
                            secondElement->collided(firstElement->getID(), firstElement->getPosition(), firstElement->getDimension());
                        }
                        // Incremento no segundo contador da list Obstacle.
                        itLOs2++;
                    }
                    // Incremento no primeiro contador da list Obstacle.
                    itLOs1++;
                    itLPs1 = LPs.begin();
                }
                // Nessa condição, está sendo analisado um elemento da classe Player. (firstElement vai ser da classe player.)
                else
                {
                    for (itLPs1 = LPs.begin(); itLPs1 != LPs.end(); itLPs1++)
                    //for (int j = i + 1; j < LEsSize + LOsSize + LPsSize; j++)
                    {
                        // Forjamento de elemento apontado pelo iterador do vector Enemy para a classe de entidade física. Necessário para método collided.
                        PhysicalEntities::PhysicalEntity *firstElement = static_cast<PhysicalEntities::PhysicalEntity *>(*itLPs1);

                        // Preeche vetor de tiles se houverem colisões.
                        std::vector<Tiles::TilesManager::tilesManagerAttributes> collidingTiles = {};

                        collidingTiles = pTileManager->checkCollisions(firstElement->getID(), firstElement->getPosition(), firstElement->getDimension());

                        // Iterador do vetor collidingTiles.
                        std::vector<Tiles::TilesManager::tilesManagerAttributes>::iterator itCollidingTiles = collidingTiles.begin();
                        // Colide de fato os elementos do vetor de colisões com o firstElement.
                        while (itCollidingTiles != collidingTiles.end())
                        {
                            firstElement->collided((*itCollidingTiles).id, (*itCollidingTiles).position, (*itCollidingTiles).dimension);
                            itCollidingTiles++;
                        }
                        //std::cout << "Iterador Players:" << *itLPs1 << std::endl;
                        //std::cout << "J:" << j << std::endl;

                       // itLPs1++;
                    }
                }
            }
        }
        void CollisionManager::setTilesManager(Tiles::TilesManager *pTm)
        {
            // Verifica se ponteiro não é nulo.
            if (pTm)
            {
                pTileManager = pTm;
            }
        }
    }
}