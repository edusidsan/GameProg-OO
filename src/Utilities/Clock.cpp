#include "Clock.hpp"

namespace OgrO
{
    namespace Utilities
    {
        MyClock::MyClock() : last{clock()},
                             current{0},
                             dt{0},
                             stopped{false}
        {
        }
        MyClock::~MyClock()
        {
        }
        double MyClock::getTime()
        {
            if (stopped)
            {
                restart();
                return 0.0;
            }

            current = clock();

            dt = (double)(current - last) / CLOCKS_PER_SEC;

            last = current;

            return dt;
        }
        void MyClock::restart()
        {
            stopped = false;
            last = clock();
        }
        void MyClock::pause()
        {
            stopped = true;
        }

    }
}