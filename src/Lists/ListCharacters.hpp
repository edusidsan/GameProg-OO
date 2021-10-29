#ifndef _LISTCHARACTERS_HPP_
#define _LISTCHARACTERS_HPP_

#include "../Entities/Character.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Lists // Namespace do Pacote Lists.
    {
        class ListCharacters
        {
        private:
            // Classe Aninhada
            class Element // Elementos de uma lista duplamente encadeada.
            {
            private:
                // Ponteiro apontando para o endereço das informações do Personagem.
                Characters::Character *pInfo;
                // Ponteiro apontando para o endereço do próximo elemento da lista.
                Element *pPrev;
                // Ponteiro apontando para o endereço do elemento anterior da lista.
                Element *pNext;

            public:
                // Construtora da classe Element.
                Element(Characters::Character *info = nullptr, Element *prev = nullptr, Element *next = nullptr);
                // Destrutora da classe Element.
                ~Element();
                // Retorna ponteiro com as informações daquele personagem a partir do atributo privado pInfo.
                Characters::Character *getInfo();
                // Atribui ao atributo privado pInfo o endereço do parâmetro info.
                void setInfo(Characters::Character *info);
                // Retorna ponteiro com o endereço do elemento anterior a partir do atributo privado pPrev.
                Element *getPrev();
                // Atribui ao atributo privado pPrev o endereço do parâmetro prev.
                void setPrev(Element *prev);
                // Retorna ponteiro com o endereço do próximo elemento a partir do atributo privado pNext.
                Element *getNext();
                // Atribui ao atributo privado pNext o endereço do parâmetro next.
                void setNext(Element *next);
            };
            // Ponteiro apontando para o endereço do primeiro elemento da lista.
            Element *pFirst;
            // Ponteiro apontando para o endereço do último elemento da lista.
            Element *pLast;
            // Ponteiro apontando para o endereço do elemento atual da lista.
            Element *pCurrent;

        public:
            // Construtora da classe ListCharacters.
            ListCharacters();
            // Destrutora da classe ListCharacters.
            ~ListCharacters();
            // Método insere personagens na lista de personagens.
            void insert(Characters::Character *info);
            // Método desaloca e aterra objetos e atributos usados na classe.
            void clear();
            // Método retorna o primeiro elemento da lista.
            Characters::Character *backStart();
            // Método desloca o ponteiro para o próximo elemento da lista e retorna o mesmo.
            Characters::Character *goNext();
            // Método atualiza cada elemento dentro da lista dos Personagens, passando como parametro o tempo da aplicação em segundos.
            void updateCharacters(float t);
            // Método desenha na window cada elemento dentro da lista dos Personagens.
            void drawCharacters(sf::RenderWindow *window);
            // Método desaloca cada objetos dentro da lista dos Personagens.
            void destroyCharacters();
        };
    }
}
#endif