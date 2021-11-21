#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

namespace Ogro {
    namespace Utilities{

        class RandomGenerator 
        {
            private:
                RandomGenerator();
                static RandomGenerator* instance;

            public:
                ~RandomGenerator();
                static const RandomGenerator* getInstance();
                bool getRandomBool(unsigned short probability) const;
                //Método que pega um valor int random em determinada escala
                int getRandomIntInRange(int lowest, int highest) const;
                //Método que pega um valor float random em determinada escala
                float getRandomFloatInRange(float min, float max) const;
                
        };
    }
}

#endif 