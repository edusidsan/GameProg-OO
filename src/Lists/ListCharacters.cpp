#include "ListCharacters.hpp"
namespace OgrO // Namespace com o nome do jogo.
{
    namespace Lists // Namespace do Pacote Lists.
    {
        //----------------------------------------------------------------
        // Inicio das definições da Classe Aninhada Element
        // Construtora da classe Element.
        ListCharacters::Element::Element(Characters::Character *info, Element *prev, Element *next) : pInfo{info},
                                                                                                      pPrev{prev},
                                                                                                      pNext{next}
        {
        }
        // Destrutora da classe Element.
        ListCharacters::Element::~Element()
        {
            // Aterra os atribuitos que são ponteiros.
            pInfo = nullptr;
            pPrev = nullptr;
            pNext = nullptr;
        }
        // Retorna ponteiro com as informações daquele personagem a partir do atributo privado pInfo.
        Characters::Character *ListCharacters::Element::getInfo()
        {
            return pInfo;
        }
        // Atribui ao atributo privado pInfo o endereço do parâmetro info.
        void ListCharacters::Element::setInfo(Characters::Character *info)
        {
            pInfo = info;
        }
        // Retorna ponteiro com o endereço do elemento anterior a partir do atributo privado pPrev.
        ListCharacters::Element *ListCharacters::Element::getPrev()
        {
            return pPrev;
        }
        // Atribui ao atributo privado pPrev o endereço do parâmetro prev.
        void ListCharacters::Element::setPrev(Element *prev)
        {
            pPrev = prev;
        }
        // Retorna ponteiro com o endereço do próximo elemento a partir do atributo privado pNext.
        ListCharacters::Element *ListCharacters::Element::getNext()
        {
            return pNext;
        }
        // Atribui ao atributo privado pNext o endereço do parâmetro next.
        void ListCharacters::Element::setNext(Element *next)
        {
            pNext = next;
        }
        // Fim das definições da Classe Aninhada Element
        //----------------------------------------------------------------

        // Construtora da classe ListCharacters.
        ListCharacters::ListCharacters() : pFirst{nullptr},
                                           pLast{nullptr},
                                           pCurrent{nullptr}
        {
        }
        // Destrutora da classe ListCharacters.
        ListCharacters::~ListCharacters()
        {
            // Método desaloca e aterra objetos e atributos usados na classe.
            clear();
        }
        // Método insere personagens na lista de personagens.
        void ListCharacters::insert(Characters::Character *info)
        {
            // Caso ponteiro info passado como parâmetro não seja nulo.
            if (info)
            {
                // Cria dinamicamente um novo Element na lista.
                Element *newElement = new Element(info);
                // Verifica se o primeiro elemento da lista é vazio, ou seja, se a lista está vazia.
                if (!pFirst)
                {
                    // Atribui o endereço do elemento ao ponteiro da posição inicial da lista.
                    pFirst = newElement;
                    // Atribui o endereço do elemento ao ponteiro da posição final da lista.
                    pLast = newElement;
                }
                // Caso a lista não esteja vazia.
                else
                {
                    // Atribui o endereço do novo elemento ao ponteiro PRÓXIMO no último elemento da lista.
                    pLast->setNext(newElement);
                    // O ponteiro ANTERIOR do novo elemento aponta para o, até então, último elemento da lista.
                    newElement->setPrev(pLast);
                    // O novo elemento é o ultimo elemento da lista.
                    pLast = newElement;
                }
            }
        }
        // Método desaloca e aterra objetos e atributos usados na classe.
        void ListCharacters::clear()
        {
            // Variável auxiliar para percorrer a lista.
            Element *pAux = pFirst;
            // Ponteiro da posição atual aponta para o endereço do primeiro elemento.
            pCurrent = pFirst;
            // Enquanto o endereço do ponteiro da posição atual não for nulo.
            while (pCurrent != nullptr)
            {
                // Ponteiro com o endereço da posição atual recebe o endereço do próximo elemento.
                pCurrent = pCurrent->getNext();
                // Desaloca dinamicamente o elemento na váriavel auxiliar.
                delete pAux;
                // Ponteiro auxilar aponta para o próximo elemento configurado no elemento atual.
                pAux = pCurrent;
            }
            // Aterramento dos ponteiros.
            pFirst = nullptr;
            pLast = nullptr;
            pCurrent = nullptr;
        }
        // Método retorna o primeiro elemento da lista.
        Characters::Character *ListCharacters::backStart()
        {
            // Ponteiro da posição atual aponta para o endereço do primeiro elemento.
            pCurrent = pFirst;
            // Caso a lista exista, retorna o primeiro elemento da lista.
            return (pCurrent) ? pCurrent->getInfo() : nullptr;
        }
        // Método desloca o ponteiro para o próximo elemento da lista e retorna o mesmo.
        Characters::Character *ListCharacters::goNext()
        {
            // Ponteiro da posição atual aponta para o endereço do próximo elemento da lista.
            pCurrent = pCurrent->getNext();
            // Caso a lista exista, retorna o próximo elemento da lista.
            return (pCurrent) ? pCurrent->getInfo() : nullptr;
        }
        // Método carrega as texturas dos personagens na window.
        void ListCharacters::initializeCharacters(Managers::GraphicManager &gm)
        {
            // Ponteiro auxiliar que recebe o primeiro elemento da lista.
            Characters::Character *p = backStart();
            // Enquanto p ainda encontrar elementos na lista.
            while (p)
            {
                // Inicializa o elemento.
                p->initializeCharacter(gm);
                // Recebe o endereço do próximo elemento da lista.
                p = goNext();
            }
        }

        // Método atualiza cada elemento dentro da lista dos Personagens, passando como parametro o tempo da aplicação em segundos.
        void ListCharacters::updateCharacters(float t)
        {
            // Ponteiro auxiliar que recebe o primeiro elemento da lista.
            Characters::Character *p = backStart();
            // Enquanto p ainda encontrar elementos na lista.
            while (p)
            {
                // Atualiza os atributos do elemento.
                p->update(t);
                // Recebe o endereço do próximo elemento da lista.
                p = goNext();
            }
        }
        // Método desenha na window cada elemento dentro da lista dos Personagens.
        void ListCharacters::drawCharacters(Managers::GraphicManager &gm)
        {
            // Ponteiro auxiliar que recebe o primeiro elemento da lista.
            Characters::Character *p = backStart();
            // Enquanto p ainda encontrar elementos na lista.
            while (p)
            {
                // Desenha o elemento na window.
                p->draw(gm);
                // Recebe o endereço do próximo elemento da lista.
                p = goNext();
            }
        }
        // Método desaloca cada objetos dentro da lista dos Personagens.
        void ListCharacters::destroyCharacters()
        {
            // Ponteiro auxiliar que recebe o primeiro elemento da lista.
            Characters::Character *p = backStart();
            // Enquanto p ainda encontrar elementos na lista.
            while (p)
            {
                // Desaloca dinamicamente o objeto elemento (personagem) na váriavel auxiliar.
                delete (p);
                // Recebe o endereço do próximo elemento da lista.
                p = goNext();
            }
            // Método desaloca e aterra objetos e atributos usados na classe.
            clear();
        }
    }
}