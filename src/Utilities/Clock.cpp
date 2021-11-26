#include "Clock.hpp"

namespace OgrO
{
    namespace Utilities
    {
        GameClock::GameClock() : last{clock()},
                             current{0},
                             dt{0},
                             stopped{false}
        {
        }
        GameClock::~GameClock()
        {
        }
        double GameClock::getTime()
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
        void GameClock::restart()
        {
            stopped = false;
            last = clock();
        }
        void GameClock::pause()
        {
            stopped = true;
        }
        double GameClock::getCurrent(){
            current = clock();
            return (double) current;
        }

    }
}