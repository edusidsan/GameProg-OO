#ifndef _TILESMAP_HPP_
#define _TILESMAP_HPP_

#include "../Utilities/Vector2D.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Tiles // Namespace do Pacote Tiles.
    {
        class TileMap
        {
        private:
            // Atributos privados:
            // Atributo de dimensão do TileMap
            Utilities::myVector2U tileMapDimension;
            // Atributo ponteiro de ponteiro (matriz) que retorna os dados da matriz desenhavelque representa o TileMap.
            unsigned short **map;
            // Atributo do caminho onde se encontra o arquivo TileMap.
            const char *path;
            // Método privado:
            // Método 
            //Utilities::myVector2U tileMapSize;

        public:
            //---------------------------------------------------------------- Classe aninhada.
            class TileMapLine
            {
            private:
                const unsigned short *tileLine;
                unsigned int tileLength;

            public:
                // Construtora da classe TileMapLine.
                TileMapLine(unsigned short *__tileLine = nullptr, unsigned int __tileLength = 0);
                // Destrutora da classe TileMapLine.
                ~TileMapLine();
                // Método permite acessar elementos da TileMapLine a partir de [].
                unsigned short operator[](unsigned int i) const;
            };
            //---------------------------------------------------------------- Classe aninhada.
            // Construtora da classe TileMap.
            TileMap(const char *filePath = nullptr);
            // Destrutora da classe TileMap.
            ~TileMap();
            // Método que retorna as dimensões do TileMap.
            const Utilities::myVector2U getTileMapDimension() const;
            // Método imprime TileMap no terminal.
            void printTileMap() const;
            // Método que atribui na matriz map qual o id do elemento. Ex -> id:1 é chão.
            void setTile(Utilities::myVector2U position, unsigned short newID);
            // Método permite acessar elementos da TileMapLine a partir de [].
            const TileMapLine operator[](unsigned int i) const;
            // Método que carrega o TileMap.
            void loadTileMap(const char *path);
        };
    }
}
#endif