#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        class Level
        {
        public:
        
            // Construtora da classe Level.
            Level();
            // Destrutora da classe Level.
            virtual ~Level();
            // Método run virtual puro -> TORNA CLASSE ABSTRATA.
            virtual void run() = 0;
        };
    }
}
#endif