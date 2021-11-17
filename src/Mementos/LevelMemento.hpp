#ifndef _LEVELMEMENTO_HPP_
#define _LEVELMEMENTO_HPP_

#include "Memento.hpp"

namespace OgrO
{
    namespace Mementos
    {
        class LevelMemento : public Memento
        {
        public:
            LevelMemento();
            ~LevelMemento();
            bool save(const std::string &path) const;
            virtual void load(const std::string &path) = 0;
        };

    }
}

#endif