#include "ThreadWitch.hpp"
#include <iostream>
#include <chrono>

namespace OgrO
{
  namespace MultiplesThreads
  {

    int ThreadWitch::run()
    {

      continueThreadWitch = true;
      while (continueThreadWitch)
      {
        if (!paused)
        {

          lock();
          //delay = 0; // sempre que chega aqui atira
          // update(0.0f); // não sai do lugar mas atira

          // espera por 1 segundo antes de soltar o mutex
          std::chrono::duration<double> wait_for = std::chrono::milliseconds(1000);
          auto wait_start = std::chrono::steady_clock::now();
          while (wait_for > std::chrono::milliseconds(0))
          {
            // se estiver pausado o tempo não passa
            if (!paused && continueThreadWitch)
            {
              wait_for -= std::chrono::steady_clock::now() - wait_start;
            }
            wait_start = std::chrono::steady_clock::now();
            yield();
          }
          unlock();

          // espera por mais 100 ms para que dê tempo de algum outro pegar o mutex
          wait_for = std::chrono::milliseconds(100);
          wait_start = std::chrono::steady_clock::now();
          while (wait_for > std::chrono::milliseconds(0))
          {
            if (!paused && continueThreadWitch)
            {
              wait_for -= std::chrono::steady_clock::now() - wait_start;
            }
            wait_start = std::chrono::steady_clock::now();
            yield();
          }
        }
        else
        {
          // quando estiver pausado minimiza o uso do processador
          yield();
        }
      }
      return continueThreadWitch;
    }

    ThreadWitch::ThreadWitch(Utilities::gameVector2F pos, Utilities::gameVector2F s, const char *tPath) : Threads(),
                                                                                                          PhysicalEntities::Characters::Enemies::Witch(pos, s, tPath),
                                                                                                          continueThreadWitch{true},
                                                                                                          paused{false}
    {
    }

    ThreadWitch::~ThreadWitch()
    {
    }
    void ThreadWitch::initialize()
    {
      // Carrega textura no player.
      pGraphicManager->loadAsset(texturePath);
      // std::cout << "texturePath Player ID: " << texturePath << std::endl;

      // Retorna dimensão da imagem.
      dimension = pGraphicManager->getDimensionsOfAsset(texturePath);

      // Adiciona Witch na lista de entidades físicas colidiveis.
      pCollisionManager->addToLCollidablesPhysicalEntities((this));

      currentLevel = this->getLevel();
    }

    void ThreadWitch::setPaused(bool pause)
    {
      paused = pause;
    }

  }
}