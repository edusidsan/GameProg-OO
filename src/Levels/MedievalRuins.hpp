#ifndef _MEDIEVALRUINS_HPP_
#define _MEDIEVALRUINS_HPP_

#include "Level.hpp"
//#include "../Tiles/TilesManager.hpp"
#include "../PhysicalEntities/Characters/Players/Shrek.hpp"
#include "../PhysicalEntities/Characters/Players/Donkey.hpp"
//#include "../PhysicalEntities/PhysicalEntity.hpp"
#include "../State.hpp"
// #include "../Managers/GraphicManager.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        class MedievalRuins : public Level, public State
        {
        private:
            // Atributo que aponta para a classe do player Shrek.
            PhysicalEntities::Characters::Players::Shrek *player1;
            // Atributo que aponta para a classe do player Donkey.
            PhysicalEntities::Characters::Players::Donkey *player2;
            // Atributo que indica se a fase deve ser finalizada.
            bool endLevel;
            // Atributo do gerenciador de tiles criado para o jogo.
            Tiles::TilesManager tilesManager;
            // Atributo que indica a chave única do evento de fechar a window do jogo.
            unsigned int idClosedWindow;
            // Atributo de um relógio que será útil para verificação do tempo.
            sf::Clock clock;

        public:
            // Construtora da classe MedievalRuins.
            MedievalRuins(PhysicalEntities::Characters::Players::Shrek *_player1 = nullptr, PhysicalEntities::Characters::Players::Donkey *_player2 = nullptr);
            // Destrutora da classe MedievalRuins.
            virtual ~MedievalRuins();
            // Método run do MedievalRuins.
            int run();

        private:
            // Método encarregado de encerrar processo do jogo caso o evento de fechar a janela do jogo tenha ocorrido.
            void closedWindow(const sf::Event &event);
        };
    }
}
#endif