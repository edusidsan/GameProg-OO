#ifndef _MEDIEVALRUINS_HPP_
#define _MEDIEVALRUINS_HPP_

#include "Level.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        class MedievalRuins : public Level
        {
        public:
            // Construtora da classe MedievalRuins.
            MedievalRuins(PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr, PhysicalEntities::Characters::Players::Donkey *_player2 = nullptr, const std::string _backgroundPath = "");
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