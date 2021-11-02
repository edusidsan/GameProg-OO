#ifndef _OBSTACLES_HPP_
#define _OBSTACLES_HPP_

#include "../PhysicalEntity.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Obstacles // Namespace do Pacote Obstacles.
        {
            class Obstacle : public PhysicalEntity
            {
            public:
                // Construtora da classe Obstacle.
                Obstacle();
                // Destrutora da classe Obstacle.
                ~Obstacle();
            };
        }
    }
}
#endif