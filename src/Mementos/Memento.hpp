#ifndef _MEMENTO_HPP_
#define _MEMENTO_HPP_

#include "../json.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Mementos
    {
        class Memento
        {
        public:
            Memento();
            virtual ~Memento();
            virtual nlohmann::json toJSON();
        };
    }
}

#endif