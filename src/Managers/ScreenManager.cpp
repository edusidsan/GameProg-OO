#include "ScreenManager.hpp"

#include "../Menus/MainMenu.hpp"
#include "../Menus/PauseMenu.hpp"
#include "../Menus/Ranking.hpp"
#include "../Entity.hpp"
#include "../PhysicalEntities/Characters/Character.hpp"

#define PATH_BACKGROUND_MEDIEVALRUINS "../assets/level1/Background_01.png"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Managers // Namespace do Pacote Managers.
    {
        // GerenciadorTelas(GraphicManager &gg, Heroi *jogador1 = nullptr);
        ScreenManager::ScreenManager(PhysicalEntities::Characters::Players::Shrek *_player1, PhysicalEntities::Characters::Players::Donkey *_player2) : player1{_player1},
                                                                                                                                                        player2{_player2}

        {
            push(new Menus::MainMenu());
        }
        ScreenManager::~ScreenManager()
        {
        }
        bool ScreenManager::handleCode(int GameCode)
        {
            switch (GameCode)
            {
            case END_GAME:
                return true;

            case START_MEDIEVAL_RUINS_LEVEL:
            {
                Levels::MedievalRuins *lvl = nullptr;
                if (Menus::MainMenu::twoPlayers)
                {
                    lvl = new Levels::MedievalRuins(player1, player2, "../assets/level1/Background.png");
                    lvl->setPlayers(player1, player2);
                }
                else
                {
                    lvl = new Levels::MedievalRuins(player1, nullptr, "../assets/level1/Background.png");
                    lvl->setPlayers(player1);
                }
                player1->setLevel(lvl);
                lvl->initialize();
                push(lvl);
                return false;
            }

            case LOAD_MEDIEVAL_RUINS_LEVEL:
            {
                Levels::MedievalRuins *lvl = new Levels::MedievalRuins(player1, player2, "../assets/level1/Background.png");
                player1->setLevel(lvl);
                try
                {
                    lvl->load("../savedGame/savedMedievalRuinsLevel.json");
                    push(lvl);
                }
                catch (char const *s)
                {
                    // std::cout << s << std::endl;
                    delete lvl;
                }
                return false;
            }

            case START_CASTLE_LEVEL:
            {
                Levels::Castle *lvl = nullptr;
                if (Menus::MainMenu::twoPlayers)
                {
                    lvl = new Levels::Castle(player1, player2, "../assets/level1/Background.png");
                    lvl->setPlayers(player1, player2);
                }
                else
                {
                    lvl = new Levels::Castle(player1, nullptr, "../assets/level1/Background.png");
                    lvl->setPlayers(player1);
                }
                player1->setLevel(lvl);
                lvl->initialize();
                push(lvl);
                return false;
            }

            case LOAD_CASTLE_LEVEL:
            {
                Levels::Castle *lvl = new Levels::Castle(player1, player2, "../assets/level1/Background.png");
                player1->setLevel(lvl);
                try
                {
                    lvl->load("../savedGame/savedCastleLevel.json");
                    push(lvl);
                }
                catch (char const *s)
                {
                    // std::cout << s << std::endl;
                    delete lvl;
                }
                return false;
            }

            case SAVE_GAME:
            {
                // POP PILHA DE ESTADOS.
                pop();
                Levels::Level *lvl = dynamic_cast<Levels::Level *>(top());
                if (!lvl)
                {
                    std::cout << "Fase nao foi encontrada" << std::endl;
                }
                else
                {
                    //Fisrt level
                    if (lvl->getId() == 1000)
                    {
                        if (!lvl->save("../savedGame/savedMedievalRuinsLevel.json"))
                        {
                            std::cout << "Fase nao foi salva" << std::endl;
                        }
                    }
                    else
                    {
                        if (!lvl->save("../savedGame/savedCastleLevel.json"))
                        {
                            std::cout << "Fase nao foi salva" << std::endl;
                        }
                    }
                }
                return false;
            }

            case PAUSE_MENU:
            {
                // push(new Menus::PauseMenu);
                push(new Menus::PauseMenu);
                return false;
            }

            case RANKING:
            {
                // push(new Menus::PauseMenu);
                push(new Menus::Ranking);
                return false;
            }
            case EXIT_PAUSE_MENU:
                pop();
                return false;

            case MAIN_MENU:

                cleanStack();
                if (player1)
                    player1->setLife(MAX_LIFE);
                if (player2)
                    player2->setLife(MAX_LIFE);
                push(new Menus::MainMenu());

            case continueGame:

            default:
                return false;
            }
        }
    }
}
