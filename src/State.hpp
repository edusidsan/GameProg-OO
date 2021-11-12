#ifndef _STATE_HPP_
#define _STATE_HPP_

namespace OgrO // Namespace com o nome do jogo.
{
    class State
    {
    public:
        virtual ~State();
        virtual int run() = 0;
    };
}
#endif