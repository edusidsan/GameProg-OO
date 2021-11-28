#ifndef _RANDOMGENERATOR_HPP_
#define _RANDOMGENERATOR_HPP_

namespace OgrO {
    namespace Utilities{

        class RandomGenerator 
        {
            private:
                RandomGenerator();
                static RandomGenerator* instance;

            public:
                ~RandomGenerator();
                static const RandomGenerator* getInstance();
                //Método que pega um valor int random em determinada escala
                int getRandomIntInRange(int lowest, int highest) const;

                
        };
    }
}

#endif 