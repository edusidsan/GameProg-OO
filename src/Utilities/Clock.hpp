#ifndef _CLOCK_HPP_
#define _CLOCK_HPP_

#include <time.h>

namespace OgrO
{
    namespace Utilities
    {
        class MyClock
        {
        private:
            clock_t last;
            clock_t current;
            double dt;
            bool stopped;

        public:
            MyClock();
            ~MyClock();
            double getTime();
            void restart();
            void pause();
        };
    }
}
#endif