#ifndef _VECTOR2D_HPP_
#define _VECTOR2D_HPP_

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Utilities // Namespace do Pacote Utilidades.
    {
        // Classe Vector2D será um template para ser usada em qualquer ponto do projeto.
        template <typename T>
        class Vector2D
        {
        public:
            // Atributos de coordenada x e y usados no template.
            T coordX, coordY;
            // Construtora da classe Template Vector2D. Valor default de posição é 0.0.
            Vector2D(T x = 0.0, T y = 0.0);
            // Destrutora da classe Template Vector2D.
            ~Vector2D();
            // Sobrecarga do operador (+) entre objetos da classe Vector2D.
            Vector2D operator+(Vector2D v);
            // Sobrecarga do operador (-) entre objetos da classe Vector2D.
            Vector2D operator-(Vector2D v);
            // Sobrecarga do operador (*) entre objetos da classe Vector2D e um inteiro.
            Vector2D operator*(int i);
            // Sobrecarga do operador (*) entre objetos da classe Vector2D e um float.
            Vector2D operator*(float f);
            // Sobrecarga do operador (*) entre objetos da classe Vector2D e um double.
            Vector2D operator*(double d);

            // Sobrecarga do operador (+=) entre objetos da classe Vector2D.
            void operator+=(Vector2D v);
            // Sobrecarga do operador (-=) entre objetos da classe Vector2D.
            void operator-=(Vector2D v);
            // Sobrecarga do operador (*=) entre objetos da classe Vector2D e um inteiro.
            void operator*=(int i);
            // Sobrecarga do operador (*=) entre objetos da classe Vector2D e um float.
            void operator*=(float f);
            // Sobrecarga do operador (*=) entre objetos da classe Vector2D e um double.
            void operator*=(double d);

            // Sobrecarga do operador (*) entre objetos da classe Vector2D. Retorna o produto interno dos Vector2D.
            T operator*(Vector2D v);
            // Retorna o módulo do Vector2D.
            T vModule();
            // Retorna o vetor unitário do Vector2D.
            Vector2D unitVector();
            // Retorna a projeção ortogonal desse vetor na direção do parâmetro v do tipo Vector2D.
            Vector2D projection(Vector2D v);
        };

        // Define um novo nome para o Vector2D de float.
        typedef Vector2D<float> myVector2F;
        // Define um novo nome para o Vector2D de unsigned.
        typedef Vector2D<unsigned> myVector2U;
    }
}
// Inclue a implementação dos métodos da classe Vector2D. Relizada dessa maneira por ser template.
#include "Vector2DMethods.hpp"
#endif