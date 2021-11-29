#ifndef _THREADWITCH_HPP__
#define _THREADWITCH_HPP__
#include "../PhysicalEntities/Characters/Enemies/Witch.hpp"
#include "Threads.hpp"

namespace OgrO
{
    namespace MultiplesThreads
    {

        class ThreadWitch : public Threads, public PhysicalEntities::Characters::Enemies::Witch
        {
        private:
            bool continueThreadWitch;
            bool paused;
            int run();

        public:
            ThreadWitch(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath = nullptr);
            ~ThreadWitch();
            void initialize();
            void setPaused(bool pause);
        };
    }

}
#endif