#include <cmath> // Biblioteca com funções matemáticas.
namespace OgrO   // Namespace com o nome do jogo.
{
    namespace Utilities // Namespace do Pacote Utilidades.
    {

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