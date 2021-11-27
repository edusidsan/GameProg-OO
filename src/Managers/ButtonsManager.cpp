#include "ButtonsManager.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {
        // Construtora da classe ButtonsManager.
        ButtonsManager::ButtonsManager(GraphicManager &_gm, EventsManager &_em, std::vector<Menus::Button *> _buttons) : pGraphicManager(Managers::GraphicManager::getInstance()),
                                                                                                                         pEventsManager(Managers::EventsManager::getInstance()),
                                                                                                                         keyMouseEvent(0),
                                                                                                                         buttons(_buttons)
        {
            keyMouseEvent = pEventsManager->addMouseListener([this](const sf::Event &e)
                                                             { handleMouseEvent(e); });
        }
        // Destrutora da classe ButtonsManager.
        ButtonsManager::~ButtonsManager()
        {
            pEventsManager->removeMouseListener(keyMouseEvent);
        }
        void ButtonsManager::draw() const
        {
            for (Menus::Button *b : buttons)
            {
                b->draw(pGraphicManager);
            }
        }
        void ButtonsManager::handleMouseEvent(const sf::Event &e)
        {
            if (e.type == sf::Event::MouseButtonReleased)
            { //se ocorrer um clique, verificar se foi em cima de algum botão

                Utilities::gameVector2F mousePosition = pGraphicManager->getMousePosition();
                for (Menus::Button *b : buttons)
                {
                    Utilities::gameVector2F buttonCenterPosition = b->getPosition();
                    Utilities::gameVector2F buttonSize = b->getSize();
                    Utilities::gameVector2F mouseCenterDistance = mousePosition - buttonCenterPosition;
                    if (fabs(mouseCenterDistance.coordX) < buttonSize.coordX / 2 && fabs(mouseCenterDistance.coordY) < buttonSize.coordY / 2)
                    {
                        b->pushButton();
                    }
                }
            }
        }
        void ButtonsManager::addButton(Menus::Button *b)
        {
            if (b)
            {
                buttons.push_back(b);
            }
        }

    }
}