#ifndef _COLOR_HPP_
#define _COLOR_HPP_

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Utilities // Namespace do Pacote Utilidades.
    {
        class Color
        {
        public:
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;

            Color(unsigned char R = 0, unsigned char G = 0, unsigned char B = 0, unsigned char A = 255);
        };
    }
}

#endif