#ifndef THREADS_HPP
#define THREADS_HPP

#include <pthread.h>

namespace OgrO {
  namespace MultiplesThreads
   {

    class Threads {
    private:
      pthread_t threadID;
      static pthread_mutex_t mutex;

      static void* runThread(void* pThread);
      virtual void run() = 0;
    public:
      Threads();
      virtual ~Threads();

      void start();
      void join();
      void yield();

      void lock();
      void unlock();
    };

  }
}

#endif