
#include "Witch.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Enemies // Namespace do Pacote Enemies.
            {

                // Construtora da classe Witch.
                Witch::Witch(Utilities::myVector2F pos, Utilities::myVector2F s, const char *tPath) : Enemy(pos, s, "../assets/Witch.png")
                //"../assets/Witch.png"
                {
                    // Atribui um ID ao Witch.
                    id = 102;
                }
                // Destrutora da classe Witch.
                Witch::~Witch()
                {
                }
                // Método carrega a textura do Witch na window e inicializa gerenciadores do mesmo.
                // void Witch::initialize(Managers::GraphicManager &gm, Managers::EventsManager &em, Managers::CollisionManager &cm)
                void Witch::initialize(Managers::EventsManager &em, Managers::CollisionManager &cm)
                {
                    // // Carrega textura no player.
                    // gm.loadAsset(texturePath);
                    // // Retorna dimensão da imagem.
                    // dimension = gm.getDimensionsOfAsset(texturePath);

                     // Carrega textura no player.
                    pGraphicManager->loadAsset(texturePath);
                    // Retorna dimensão da imagem.
                    dimension = pGraphicManager->getDimensionsOfAsset(texturePath);

                    // Adiciona Witch na lista de entidades físicas colidiveis.
                    cm.addToLCollidablesPhysicalEntities((this));
                }
                // Método verifica colisão entre dois objetos da classe Entidade Física.
                void Witch::collided(int IDOther, Utilities::myVector2F positionOther, Utilities::myVector2F dimensionOther)
                {
                    // Caso colida com Player1.
                    if (IDOther == 101)
                    {
                        // std::cout << "OBJETO Witch >>> COLISAO COM PLAYER1::SHREK1." << std::endl;
                    }
                    // Caso colida com Player2.
                    if (IDOther == 100)
                    {
                        // std::cout << "OBJETO Witch >>> COLISAO COM PLAYER1::SHREK1." << std::endl;
                    }
                    

                  
                }
                void Witch::update(float t){
                    
                    // speed.coordY += 100 * t;
                    if (abs(speed.coordX) > maxSpeedX)
                    {
                        speed.coordX = maxSpeedX * (speed.coordX > 0 ? 1 : -1);
                    }
                    if (abs(speed.coordY) > maxSpeedY)
                    {
                        speed.coordY = maxSpeedY * (speed.coordY > 0 ? 1 : -1);
                    }
                    // Relação de posição da forma no espaço-tempo. Equação de Movimento Uniforme da Cinemática.
                    position += speed * t;
                    position += adjusts;
                    adjusts = Utilities::myVector2F(0, 0);
                    // std::cout<<"tempo: "<<clock.getCurrent()/1000<<std::endl;
                    //  std::cout<<"timeReference: "<<timeReference<<std::endl;
                    //  std::cout<<"time: "<<t*1000<<std::endl;
            
                     if ( clock.getCurrent()/1000- timeReference > 5)
                    {
                        
                        // Muda o sentido da velocidade em x.
                        speed.coordY *= -1;
                        timeReference = clock.getCurrent()/1000;
                    }
                    
                
                }
            }
        }
    }
}