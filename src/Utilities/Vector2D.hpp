#ifndef _VECTOR2D_HPP_
#define _VECTOR2D_HPP_

#include <cmath>

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

        /*Implementação dos métodos do template*/
        // Construtora da classe Template Vector2D.
        template <typename T>
        Vector2D<T>::Vector2D(T x, T y) : coordX{x},
                                          coordY{y}
        {
        }

        // Destrutora da classe Template Vector2D.
        template <typename T>
        Vector2D<T>::~Vector2D()
        {
        }

        // Sobrecarga do operador (+) entre objetos da classe Vector2D.
        template <typename T>
        Vector2D<T> Vector2D<T>::operator+(Vector2D<T> v)
        {
            return Vector2D<T>(coordX + (v.coordX), coordY + (v.coordY));
        }

        // Sobrecarga do operador (-) entre objetos da classe Vector2D.
        template <typename T>
        Vector2D<T> Vector2D<T>::operator-(Vector2D<T> v)
        {
            return Vector2D<T>(coordX - (v.coordX), coordY - (v.coordY));
        }

        // Sobrecarga do operador (*) entre objetos da classe Vector2D e um inteiro.
        template <typename T>
        Vector2D<T> Vector2D<T>::operator*(int i)
        {
            return Vector2D<T>(coordX * i, coordY * i);
        }

        // Sobrecarga do operador (*) entre objetos da classe Vector2D e um float.
        template <typename T>
        Vector2D<T> Vector2D<T>::operator*(float f)
        {
            return Vector2D<T>(coordX * f, coordY * f);
        }

        // Sobrecarga do operador (*) entre objetos da classe Vector2D e um double.
        template <typename T>
        Vector2D<T> Vector2D<T>::operator*(double d)
        {
            return Vector2D<T>(coordX * d, coordY * d);
        }

        // Sobrecarga do operador (+=) entre objetos da classe Vector2D.
        template <typename T>
        void Vector2D<T>::operator+=(Vector2D<T> v)
        {
            coordX += v.coordX;
            coordY += v.coordY;
        }

        // Sobrecarga do operador (-=) entre objetos da classe Vector2D.
        template <typename T>
        void Vector2D<T>::operator-=(Vector2D<T> v)
        {
            coordX -= v.coordX;
            coordY -= v.coordY;
        }

        // Sobrecarga do operador (*=) entre objetos da classe Vector2D e um inteiro.
        template <typename T>
        void Vector2D<T>::operator*=(int i)
        {
            coordX *= i;
            coordY *= i;
        }

        // Sobrecarga do operador (*=) entre objetos da classe Vector2D e um float.
        template <typename T>
        void Vector2D<T>::operator*=(float f)
        {
            coordX *= f;
            coordY *= f;
        }

        // Sobrecarga do operador (*=) entre objetos da classe Vector2D e um double.
        template <typename T>
        void Vector2D<T>::operator*=(double d)
        {
            coordX *= d;
            coordY *= d;
        }

        // Sobrecarga do operador (*) entre objetos da classe Vector2D. Retorna o produto interno dos Vector2D.
        template <typename T>
        T Vector2D<T>::operator*(Vector2D v)
        {
            return (coordX * v.coordX + coordY * v.coordY);
        }

        // Retorna o módulo do Vector2D.
        template <typename T>
        T Vector2D<T>::vModule()
        {
            return sqrt(pow(coordX, 2) + pow(coordY, 2));
        }

        // Retorna o vetor unitário do Vector2D.
        template <typename T>
        Vector2D<T> Vector2D<T>::unitVector()
        {
            // vunit = v/||v||
            return this->operator*(1.0 / vModule());
        }

        // Retorna a projeção ortogonal desse vetor na direção do parâmetro v do tipo Vector2D<T>.
        template <typename T>
        Vector2D<T> Vector2D<T>::projection(Vector2D<T> v)
        {
            // ProjeçãoOrtogonal = prodExt(v,prodInt(u,v)/(||v||²))
            return v * (this->operator*(v) / pow(v.vModule(), 2));
        }
    }
}
#endif