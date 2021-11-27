#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_
#include "../Character.hpp"
#include "../../../json.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace PhysicalEntities // Namespace do Pacote Entities.
    {
        namespace Characters // Namespace do Pacote Personagens.
        {
            namespace Players // Namespace do Pacote Enemies.
            {
                class Player : public Character
                {
                public:
                    // Construtora da classe Player.
                    Player(Utilities::gameVector2F pos = {0.0f, 0.0f}, const char *tPath = nullptr);
                    // Destrutora da classe Player.
                    virtual ~Player();
                    // Método carrega a textura do Player na window.
                    virtual void initialize( Managers::CollisionManager &cm);
                    // Método atualizar do Player. Tem como parâmetro uma variável float que representa o tempo.
                    virtual void update(float t);
                    // Método desenhar do Player.
                    virtual void draw();
                    // Método de tratamento de evento ocorrido.
                    virtual void handleEvent(const sf::Event &ev);
                    // Método verifica colisão entre dois objetos da classe Entidade Física.
                    virtual void collided(int idOther, Utilities::gameVector2F positionOther, Utilities::gameVector2F dimensionOther);

                    void initializeJSON(nlohmann::json source);
                    //Retorna quantidade de vida
                    const unsigned int getLife() const;
                    void setLife(int _life);
                };
            }
        }
    }
}
#endif
