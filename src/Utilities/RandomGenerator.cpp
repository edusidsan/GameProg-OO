#include "RandomGenerator.hpp"
#include <cstdlib>
#include <ctime>

namespace OgrO
{
    namespace Utilities
    {

        RandomGenerator *RandomGenerator::instance{nullptr};
        RandomGenerator::RandomGenerator()
        {
            std::srand(std::time(nullptr));
        }

        RandomGenerator::~RandomGenerator()
        {
        }
        const RandomGenerator *RandomGenerator::getInstance()
        {
            if (instance == nullptr)
            {
                instance = new RandomGenerator();
            }
            return instance;
        }
        // the highest  is not included
        int RandomGenerator::getRandomIntInRange(int lowest, int highest) const
        {
            if (lowest >= highest)
                return 0;
            return std::rand() % (highest - lowest) + lowest;
        }
    }
}