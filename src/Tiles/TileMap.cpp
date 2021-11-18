#include "TileMap.hpp"
#include <iostream>
#include <iomanip> // Biblioteca para definir um espaço mínimo na impressão cout -> " 1" ou inves de "1"
#include <fstream>
#include "../json.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Tiles // Namespace do Pacote Tiles.
    {
        //---------------------------------------------------------------- Classe aninhada.
        // Construtora da classe TileMapLine.
        TileMap::TileMapLine::TileMapLine(unsigned short *__tileLine, unsigned int __tileLength) : tileLine{__tileLine},
                                                                                                   tileLength{__tileLength}
        {
        }
        // Destrutora da classe TileMapLine.
        TileMap::TileMapLine::~TileMapLine()
        {
        }

        // Método permite acessar elementos da TileMapLine a partir de [].
        unsigned short TileMap::TileMapLine::operator[](unsigned int i) const
        {
            // Condição que limita acesso ao TileMapLine tendo como referência o parâmetro do método.
            // if (i > tileLength)
            // {
            //     std::cout << "Atenção! Não é permitido este tentativa de acesso à memória de TileMapLine." << std::endl;
            //     exit(1);
            // }
            return tileLine[i];
        }
        //--------------------------------------------------------------------------------.

        // Construtora da classe TileMap.
        TileMap::TileMap(const char *filePath) : map{nullptr},
                                                 path{filePath}
        {
            // Método que carrega o TileMap.
            loadTileMap();
        }
        // Destrutora da classe TileMap.
        TileMap::~TileMap()
        {
            // Se map possuir alocação dinâmica, é necessário desalocar.
            if (map)
            {
                // Desaloca as linhas da matriz.
                for (int i = 0; i < tileMapDimension.coordY; ++i)
                {
                    delete map[i];
                }
                // Desaloca o ponteiro que armazenava as linhas.
                delete map;
            }
        }

        // Método que carrega o TileMap.
        void TileMap::loadTileMap()
        {
            std::ifstream _file(path);
            if (!_file.is_open())
            {
                std::cout << "Atencao! Arquivo no caminho \"" << path << "\" não pode ser aberto!" << std::endl;
                exit(1);
            }
            nlohmann::json json;

            _file >> json;
            // Retorna os objetos alocados na primeira posição do array json.
            json = json["layers"][0];
            // Atribui as dimensões do arquivo no atributo tileMapDimension.
            tileMapDimension = {json["width"], json["height"]};
            std::cout << tileMapDimension << std::endl;
            // Atribui apenas os tiles do arquivo para o próprio json.
            json = json["data"];
            // Alocando a quantidade de colunas do map.
            map = new unsigned short *[tileMapDimension.coordY];
            // Alocando a quantidade de linhas do map.
            for (unsigned int i = 0; i < tileMapDimension.coordY; ++i)
            {
                map[i] = new unsigned short[tileMapDimension.coordX];
            }

            unsigned int i = 0;
            unsigned int j = 0;
            unsigned int counter = 0;
            unsigned int aux = 0;

            for (unsigned int i = 0; i < tileMapDimension.coordY; ++i)
            {
                for (unsigned int j = 0; j < tileMapDimension.coordX; ++j)
                {
                    if (i >= tileMapDimension.coordY)
                    {
                        break;
                    }
                    aux = json[counter];
                    if (aux != 0)
                    {
                        aux--;
                    }
                    map[i][j] = aux;
                    counter++;
                }
                // std::cout << std::endl;
                if (j >= tileMapDimension.coordX)
                {
                    break;
                }
            }
            printTileMap();
        }

        // Método que retorna as dimensões do TileMap.
        const Utilities::myVector2U TileMap::getTileMapDimension() const
        {
            return tileMapDimension;
        }
        // Método imprime TileMap no terminal.
        void TileMap::printTileMap() const
        {
            for (int i = 0; i < tileMapDimension.coordY; ++i)
            {
                for (int j = 0; j < tileMapDimension.coordX; ++j)
                    // Trava o tamanho da saída de cout. ex: 1 vira " 1".
                    std::cout << std::setw(2) << map[i][j] << ' ';
                std::cout << '\n';
            }
            // Esvazia o buffer da memória e print no terminal.
            std::cout.flush();
        }
        // Método que atribui na matriz map qual o id do elemento. Ex -> id:1 é chão.
        void TileMap::setTile(Utilities::myVector2U position, unsigned short newID)
        {
            if ((position.coordX > tileMapDimension.coordX) || (position.coordY > tileMapDimension.coordY))
            {
                std::cout << "Atenção! Posicao do TileMap maior que as dimensoes atribuídas ao mesmo." << std::endl;
                exit(1);
            }
            // Atribui id do objeto na posisção específicada do map.
            map[position.coordY][position.coordX] = newID;
        }
        // Método retorna linha da TileMapLine a partir de [].
        const TileMap::TileMapLine TileMap::operator[](unsigned int i) const
        {
            // // Condição que limita acesso ao TileMap tendo como referência o parâmetro do método.
            // if (i > tileMapDimension.coordY)
            // {
            //     std::cout << "Atenção! Não é permitido este tentativa de acesso à memória de TileMap." << std::endl;
            //     exit(1);
            // }
            // Retorna elemento de TileMapLine alocado na posição i do TileMapLine.
            return TileMap::TileMapLine{map[i], tileMapDimension.coordX};
        }
    }
}