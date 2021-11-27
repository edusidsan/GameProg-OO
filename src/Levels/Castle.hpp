#ifndef _CASTLE_HPP_
#define _CASTLE_HPP_

#include "Level.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        class Castle : public Level
        {
        public:
            // Construtora da classe Castle.
            Castle(PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr, PhysicalEntities::Characters::Players::Donkey *_player2 = nullptr, const std::string _backgroundPath = "");
            // Destrutora da classe Castle.
            virtual ~Castle();
            // Método initialize do Castle.
            void initialize() override;
            // Método que salva para arquivo JSON.
            nlohmann::json toJSON() override;
            void load (const std::string& path);
        };
    }
}
#endif