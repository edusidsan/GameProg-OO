#ifndef _STATEMANAGER_HPP_
#define _STATEMANAGER_HPP_

#include "../State.hpp"
#include <stack>

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {
        class StateManager
        {
        private:
            std::stack<State *> stateStack;

        public:
            virtual ~StateManager();
            int run();

        protected:
            void push(State *p);
            void pop();
            void cleanStack();
            virtual bool handleCode(int GameCode) = 0;
        };
    }
}

#endif