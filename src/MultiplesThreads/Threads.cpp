#include "Threads.hpp"

#include <iostream>

namespace OgrO
{
  namespace MultiplesThreads
  {

    pthread_mutex_t Threads::mutex = PTHREAD_MUTEX_INITIALIZER;

    Threads::Threads() : threadID()
    {
    }

    Threads::~Threads()
    {
    }

    void *Threads::runThread(void *pThread)
    {
      Threads *threads = static_cast<Threads *>(pThread);

      if (threads != nullptr)
      {
        threads->run();
      }
      else
      {
        std::cout << "thread inexistente" << std::endl;
      }

      return nullptr;
    }

    void Threads::start()
    {
      pthread_create(&threadID, nullptr, runThread, static_cast<void *>(this));
    }

    void Threads::yield()
    {
      sched_yield();
    }

    void Threads::lock()
    {
      pthread_mutex_lock(&mutex);
    }

    void Threads::unlock()
    {
      pthread_mutex_unlock(&mutex);
    }

  }
}