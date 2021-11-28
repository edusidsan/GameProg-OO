#ifndef _THREADWITCH_HPP__
#define _THREADWITCH_HPP__
#include "../PhysicalEntities/Characters/Enemies/Witch.hpp"
#include "Threads.hpp"

namespace OgrO{
    namespace MultiplesThreads{
       

        class ThreadWitch : public Threads, public PhysicalEntities::Characters::Enemies::Witch
        {
            private:
                bool keep_going;
                bool paused;
                void roll();
            public:
                ThreadWitch(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath = nullptr);
                //ThreadWitch(nlohmann::json source);
                ~ThreadWitch();
                void stopRunning();
                void initialize();
                void setPaused(bool pause);
        }; 
    }

}
#endif
// #ifndef THREADEDCASTER_HPP
// #define THREADEDCASTER_HPP

// #include "../Entities/Enemies/Caster.hpp"
// #include "Thread.hpp"

// namespace DIM {
//   namespace Concurrent {

//     class ThreadedCaster : public Thread, public Entities::Mobs::Caster {
//     private:
//       bool keep_going;
//       bool paused;
//       void run();
//     public:
//       ThreadedCaster(Utils::VectorF pos);
//       ~ThreadedCaster();

//       void stopRunning();
//       void setPaused(bool pause);
//     };

//   }
// }

// #endif