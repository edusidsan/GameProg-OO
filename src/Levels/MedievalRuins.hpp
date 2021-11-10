#ifndef _MEDIEVALRUINS_HPP_
#define _MEDIEVALRUINS_HPP_

#include "Level.hpp"
#include "../Tiles/TilesManager.hpp"
#include "../PhysicalEntities/Characters/Players/Shrek.hpp"
#include "../PhysicalEntities/PhysicalEntity.hpp"
#include "../Managers/GraphicManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        class MedievalRuins : public Level
        {
        private:
            // Atributo que aponta para a classe do player Shrek.
            PhysicalEntities::Characters::Players::Shrek *player1;
            // Atributo que indica se a fase deve ser finalizada.
            bool endLevel;
            // Atributo do gerenciador de tiles criado para o jogo.
            Tiles::TilesManager tilesManager;
            // Atributo que indica a chave única do evento de fechar a window do jogo.
            unsigned int idClosedWindow;
            // Atributo de um relógio que será útil para verificação do tempo.
            sf::Clock clock;
            // // Atributo do gerenciador dgrafico criado para o jogo.
            Managers::GraphicManager graphicManager;

        public:
            // Construtora da classe MedievalRuins.
            // MedievalRuins(Managers::GraphicManager &gm, PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr);
            MedievalRuins(PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr);
            // Destrutora da classe MedievalRuins.
            virtual ~MedievalRuins();
            // Método run do MedievalRuins.
            void run();

        private:
            // Método encarregado de encerrar processo do jogo caso o evento de fechar a janela do jogo tenha ocorrido.
            void closedWindow(const sf::Event &event);
        };
    }
}
#endif