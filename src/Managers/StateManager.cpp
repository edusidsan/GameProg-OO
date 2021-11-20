#include "StateManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {
        StateManager::~StateManager()
        {
            cleanStack();
        }
        int StateManager::run()
        {
            return handleCode((stateStack.top())->run());
        }
        void StateManager::push(State *p)
        {
            if (p != nullptr)
            {
                stateStack.push(p);
            }
        }
        void StateManager::pop()
        {
            delete stateStack.top();
            stateStack.pop();
        }
        State *StateManager::top()
        {
            return stateStack.top();
        }
        void StateManager::cleanStack()
        {
            while (stateStack.size() != 0)
            {
                pop();
            }
        }
    }
}