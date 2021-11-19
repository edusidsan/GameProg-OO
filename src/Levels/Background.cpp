#include "Background.hpp"
#include "../Utilities/Vector2D.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {

        // Construtora da classe Background.
        Background::Background(const char *_tPath) : Entity(),
                                                     tPath{_tPath}
        {
        }
        // Destrutora da classe Background.
        Background::~Background()
        {
        }
        // Método carrega a textura do Background na window.
        void Background::initialize()

        {
            // Carrega textura no player.
            pGraphicManager->loadAsset(tPath);
        }
        // Método desenhar de Background. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
        void Background::draw()
        {
            pGraphicManager->draw(tPath, Utilities::myVector2F{800.0f, 280.0f});
        }
        nlohmann::json Background::toJSON()
        {
            return "";
        }
        int Background::run()
        {
            std::cout << "Implementar Background::run()" << std::endl;
            return 0;
        }
    }
}
