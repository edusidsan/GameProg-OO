#include "PhysicalEntityList.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Lists // Namespace do Pacote Lists.
    {
        // Construtora da classe PhysicalEntityList.
        PhysicalEntityList::PhysicalEntityList() : Mementos::Memento(),
                                                   list()
        {
        }
        // Destrutora da classe PhysicalEntityList.
        PhysicalEntityList::~PhysicalEntityList()
        {
            // Método desaloca cada objeto dentro da lista de entidades físicas.
            destroyPhysicalEntities();
        }
        // Método insere entidades físicas na lista de entidades físicas.
        void PhysicalEntityList::insert(PhysicalEntities::PhysicalEntity *info)
        {
            // Insere Entidade física na lista.
            list.insert(info);
        }
        // Método remove o primeiro elemento da lista de entidades físicas.
        void PhysicalEntityList::removeFirst(PhysicalEntities::PhysicalEntity *p)
        {
            list.removeFirst(p);
        }
        // Método carrega as texturas e inicializa o gerenciador de eventos e de colisão das entidades físicas na window.
        void PhysicalEntityList::initializePhysicalEntities( )
        {
            // Ponteiro auxiliar que recebe o primeiro elemento da lista.
            PhysicalEntities::PhysicalEntity *p = list.backStart();
            // Enquanto p ainda encontrar elementos na lista.
            while (p)
            {
                // Inicializa o elemento.

                p->initialize();
                // Recebe o endereço do próximo elemento da lista.
                p = list.goNext();
            }
        }

        // Método atualiza cada elemento dentro da lista de entidades físicas, passando como parametro o tempo da aplicação em segundos.
        void PhysicalEntityList::updatePhysicalEntities(float t)
        {
            // Ponteiro auxiliar que recebe o primeiro elemento da lista.
            PhysicalEntities::PhysicalEntity *p = list.backStart();
            // Enquanto p ainda encontrar elementos na lista.
            while (p)
            {
                // Atualiza os atributos do elemento.
                p->update(t);
                // Recebe o endereço do próximo elemento da lista.
                p = list.goNext();
            }
        }
        // Método desenha na window cada elemento dentro da lista de entidades físicas.
        void PhysicalEntityList::drawPhysicalEntities()
        {
            // Ponteiro auxiliar que recebe o primeiro elemento da lista.
            PhysicalEntities::PhysicalEntity *p = list.backStart();
            // Enquanto p ainda encontrar elementos na lista.
            while (p)
            {
                // Desenha o elemento na window.
                p->draw();
                // Recebe o endereço do próximo elemento da lista.
                p = list.goNext();
            }
        }
        // Método desaloca cada objeto dentro da lista de entidades físicas.
        void PhysicalEntityList::destroyPhysicalEntities()
        {
            // Ponteiro auxiliar que recebe o primeiro elemento da lista.
            PhysicalEntities::PhysicalEntity *p = list.backStart();
            // Enquanto p ainda encontrar elementos na lista.
            while (p)
            {
                // Desaloca dinamicamente o objeto elemento (entidade física) na váriavel auxiliar.
                delete (p);
                // Recebe o endereço do próximo elemento da lista.
                p = list.goNext();
            }
            // Método desaloca e aterra objetos e atributos usados na classe.
            list.clear();
        }

        nlohmann::json PhysicalEntityList::toJSON()
        {
            nlohmann::json result = nlohmann::json::array();
            int position = 0;
            // Ponteiro auxiliar que recebe o primeiro elemento da lista.
            PhysicalEntities::PhysicalEntity *p = list.backStart();
            // Enquanto p ainda encontrar elementos na lista.
            while (p)
            {
                result[position++] = p->toJSON();
                // Recebe o endereço do próximo elemento da lista.
                p = list.goNext();
            }
            return result;
        }
    }
}