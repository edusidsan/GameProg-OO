#ifndef _PHYSICALENTITYLIST_HPP_
#define _PHYSICALENTITYLIST_HPP_

#include "List.hpp"
#include "../PhysicalEntities/PhysicalEntity.hpp"
#include "../Mementos/Memento.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Lists // Namespace do Pacote Lists.
    {
        class PhysicalEntityList : public Mementos::Memento
        {
        private:
            // Atributo de List template com parâmetro de ponteiro de Entidades Físicas (que são representáveis).
            List<PhysicalEntities::PhysicalEntity *> list;

        public:
            // Construtora da classe PhysicalEntityList.
            PhysicalEntityList();
            // Destrutora da classe PhysicalEntityList.
            ~PhysicalEntityList();
            // Método insere entidades físicas na lista de entidades físicas.
            void insert(PhysicalEntities::PhysicalEntity *info);
            // Método remove o primeiro elemento da lista de entidades físicas..
            void removeFirst(PhysicalEntities::PhysicalEntity *p);
            // Método retorna o primeiro elemento da lista de entidades físicas.
            PhysicalEntities::PhysicalEntity *backStart();
            // Método desloca o ponteiro para o próximo elemento da lista e retorna o mesmo.
            PhysicalEntities::PhysicalEntity *goNext();
            // Método carrega as texturas e inicializa o gerenciador de eventos e de colisões das entidades físicas na window.
            void initializePhysicalEntities(Managers::CollisionManager &cm);
            // Método atualiza cada elemento dentro da lista de entidades físicas, passando como parametro o tempo da aplicação em segundos.
            void updatePhysicalEntities(float t);
            // Método desenha na window cada elemento dentro da lista de entidades físicas.
            void drawPhysicalEntities();
            // Método desaloca cada objeto dentro da lista de entidades físicas.
            void destroyPhysicalEntities();

            nlohmann::json toJSON();

        };
    }
}
#endif