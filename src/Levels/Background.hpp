#ifndef _BACKGROUND_HPP_
#define _BACKGROUND_HPP_

#include "../PhysicalEntities/PhysicalEntity.hpp"
// #include "Level.hpp"

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Levels // Namespace do Pacote Levels.
    {
        // class Background : public PhysicalEntities::PhysicalEntity
        class Background : public Entity
        // class Background : public Level
        {
        private:
            const char *tPath;

        public:
            // Construtora da classe Background.
            Background(const char *_tPath = nullptr);
            // Destrutora da classe Background.
            virtual ~Background();
            // Método carrega a textura do PhysicalEntity na window.
            void initialize();
            // Método atualizar de PhysicalEntity. Tem como parâmetro uma variável float que representa o tempo.
            // virtual void update(float t);
            // Método desenhar de PhysicalEntity. Tem como parâmetro o endereço do gerenciador gráfico que irá desenhar o persoangem na window.
            void draw();
            // Método retorna a posição da entidade física.

            nlohmann::json toJSON();

            // const Utilities::myVector2F getPosition() const;
            // Método retorna a dimensão da entidade fisica.
            // const Utilities::myVector2F getDimension() const;
            // Método retorna ID atribuído ao ente.
            // Caso ID > 100, ente é entidade física.
            // virtual const int getID() const;
        };
    }
}
#endif