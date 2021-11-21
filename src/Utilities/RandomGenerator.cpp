#include "RandomGenerator.hpp"

#include <cstdlib>
#include <ctime>

namespace Ogro{
    namespace Utilities{

      RandomGenerator* RandomGenerator::instance{nullptr};  
    
      RandomGenerator::RandomGenerator() {
        std::srand(std::time(nullptr));
    }
    
    RandomGenerator::~RandomGenerator(){

    }

    const RandomGenerator* RandomGenerator::getInstance(){
      if (instance == nullptr) {
        instance = new RandomGenerator();
      } 
      return instance;
    }

    bool RandomGenerator::getRandomBool(unsigned short probability) const {
      if (probability == 0) return false;
      if (probability >= 100) return true;
      else return ((std::rand() % 100) + 1) >= probability;
    }

    // the highest  is not included
    int RandomGenerator::getRandomIntInRange(int lowest, int highest) const {
      if (lowest >= highest) return 0;
      return std::rand() % (highest - lowest) + lowest;
    }

    // tanto o primeiro quanto o segundo argumentos estão incluídos
    float RandomGenerator::getRandomFloatInRange(float min, float max) const {
      if (min == max) return min;
      else if (min >= max) return 0;
      else {
        return min + (getRandomIntInRange(0, 1000001) / 1000000.0f) * (max - min);
      }
    }
  }
}