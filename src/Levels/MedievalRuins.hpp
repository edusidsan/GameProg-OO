#ifndef _MEDIEVALRUINS_HPP_
#define _MEDIEVALRUINS_HPP_

// #include "../Tiles/TilesManager.hpp"
#include "../Utilities/RandomGenerator.hpp"
#include "Level.hpp"
// #include "../PhysicalEntities/Characters/Players/Donkey.hpp"


namespace OgrO // Namespace com o nome do jogo.
{
    namespace Utilities{
        
        class RandomGenerator;
    }
    namespace Levels // Namespace do Pacote Levels.
    {
        class MedievalRuins : public Level
        {
        // private:
        //     static int const xEnemies;
        public:
            // Construtora da classe MedievalRuins.
            MedievalRuins(PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr, PhysicalEntities::Characters::Players::Donkey *_player2 = nullptr, const std::string _backgroundPath = "");
            // Destrutora da classe MedievalRuins.
            virtual ~MedievalRuins();
            // Método initialize do MedievalRuins.
            void initialize() override;

            nlohmann::json toJSON() override;
            void load (const std::string& path);
        };
    }
}
#endif