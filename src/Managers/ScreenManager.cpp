#include "ScreenManager.hpp"

#include "../Menus/MainMenu.hpp"
#include "../Menus/PauseMenu.hpp"
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
                std::cout << "bool twoplayersselected --> " << Menus::MainMenu::twoPlayers << std::endl;
                if (Menus::MainMenu::twoPlayers)
                {
                    lvl = new Levels::MedievalRuins(player1, player2, "../assets/level1/Background.png");
                }
                else
                {
                    lvl = new Levels::MedievalRuins(player1, nullptr, "../assets/level1/Background.png");
                    std::cout << "Apenas player 1" << std::endl;
                }
                lvl->initialize();
                push(lvl);
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
                    if (!lvl->save("../savedGame/savedGame.json"))
                    {
                        std::cout << "Fase nao foi salva" << std::endl;
                    }
                }
                return false;
            }

            case LOAD_MEDIEVAL_RUINS_LEVEL:
            {
                Levels::MedievalRuins *lvl = new Levels::MedievalRuins(player1, player2, "../assets/level1/Background.png");
                try
                {
                    lvl->load("../savedGame/savedGame.json");
                    push(lvl);
                }
                catch (char const *s)
                {
                    // std::cout << s << std::endl;
                    delete lvl;
                }
                return false;
            }

            case PAUSE_MENU:
            {
                // push(new Menus::PauseMenu);
                push(new Menus::PauseMenu);
                return false;
            }
            case EXIT_PAUSE_MENU:
                pop();
                return false;

            case MAIN_MENU:

                cleanStack();
                push(new Menus::MainMenu());

            case continueGame:

            default:
                return false;
            }
        }
    }
}

// MAIN_MENU,
//     EXIT,
//     LEADERBOARD