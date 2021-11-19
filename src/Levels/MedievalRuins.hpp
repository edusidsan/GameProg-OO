#ifndef _MEDIEVALRUINS_HPP_
#define _MEDIEVALRUINS_HPP_

#include "Level.hpp"
// #include "Background.hpp"
// #include "../Tiles/TilesManager.hpp"
// #include "../PhysicalEntities/Characters/Players/Shrek.hpp"
// #include "../PhysicalEntities/Characters/Players/Donkey.hpp"
// #include "../PhysicalEntities/PhysicalEntity.hpp"
// #include "../State.hpp"
// #include "../Managers/GraphicManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        class MedievalRuins : public Level
        {
        public:
            // Construtora da classe MedievalRuins.
            MedievalRuins(PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr, PhysicalEntities::Characters::Players::Donkey *_player2 = nullptr, Background _backgroundImage = "");
            // Destrutora da classe MedievalRuins.
            virtual ~MedievalRuins();
            // Método run do MedievalRuins.
            // int run();
            void initialize() override;

            nlohmann::json toJSON() override;
            void load (const std::string& path);
        };
    }
}
#endif