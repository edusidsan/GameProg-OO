#ifndef _LIST_HPP_
#define _LIST_HPP_

namespace OgrO // Namespace com o nome do jogo.
{
    namespace Lists // Namespace do Pacote Lists.
    {
        // Classe List será um template para ser usada em qualquer ponto do projeto.
        template <typename TL>
        class List
        {
        private:
            // Classe Aninhada
            template <typename TE>
            class Element // Elementos de uma lista duplamente encadeada.
            {
            private:
                // Ponteiro apontando para o endereço das informações do elemento.
                TE pInfo;
                // Ponteiro apontando para o endereço do próximo elemento da lista.
                //Element<TE> *pPrev;
                // Ponteiro apontando para o endereço do elemento anterior da lista.
                Element<TE> *pNext;

            public:
                // Construtora da classe Element.
                // Element(TE info = nullptr, Element *prev = nullptr, Element *next = nullptr);
                Element(TE info = nullptr, Element *next = nullptr);
                // Destrutora da classe Element.
                ~Element();
                // Retorna ponteiro com as informações daquele elemento a partir do atributo privado pInfo.
                TE getInfo();
                // Atribui ao atributo privado pInfo o endereço do parâmetro info.
                void setInfo(TE info);
                // Retorna ponteiro com o endereço do elemento anterior a partir do atributo privado pPrev.
                // Element<TE> *getPrev();
                // Atribui ao atributo privado pPrev o endereço do parâmetro prev.
                // void setPrev(Element *prev);
                // Retorna ponteiro com o endereço do próximo elemento a partir do atributo privado pNext.
                Element<TE> *getNext();
                // Atribui ao atributo privado pNext o endereço do parâmetro next.
                void setNext(Element *next);
            };
            // Ponteiro apontando para o endereço do primeiro elemento da lista.
            Element<TL> *pFirst;
            // Ponteiro apontando para o endereço do último elemento da lista.
            Element<TL> *pLast;
            // Ponteiro apontando para o endereço do elemento atual da lista.
            Element<TL> *pCurrent;

        public:
            // Construtora da classe List.
            List();
            // Destrutora da classe List.
            ~List();
            // Método insere elemento de "qualquer tipo" na lista.
            void insert(TL info);
            // Método desaloca e aterra objetos e atributos usados na classe.
            void clear();
            // Método retorna o primeiro elemento da lista.
            TL backStart();
            // Método desloca o ponteiro para o próximo elemento da lista e retorna o mesmo.
            TL goNext();
        };

        //----------------------------------------------------------------
        // Inicio das definições da Classe Aninhada Element
        // Construtora da classe Element.
        template <typename TL>
        template <typename TE>
        List<TL>::Element<TE>::Element(TE info, Element *next) : pInfo{info},
                                                                 pNext{next}
        {
        }
        // Destrutora da classe Element.
        template <typename TL>
        template <typename TE>
        List<TL>::Element<TE>::~Element()
        {
            // Aterra os atribuitos que são ponteiros.
            pInfo = nullptr;
            // pPrev = nullptr;
            pNext = nullptr;
        }
        // Retorna ponteiro com as informações daquele elemento a partir do atributo privado pInfo.
        template <typename TL>
        template <typename TE>
        TE List<TL>::Element<TE>::getInfo()
        {
            return pInfo;
        }
        // Atribui ao atributo privado pInfo o endereço do parâmetro info.
        template <typename TL>
        template <typename TE>
        void List<TL>::Element<TE>::setInfo(TE info)
        {
            pInfo = info;
        }
        // Retorna ponteiro com o endereço do elemento anterior a partir do atributo privado pPrev.
        // template <typename TL>
        // template <typename TE>
        // List<TL>::Element<TE> *List<TL>::Element<TE>::getPrev()
        // {
        //     return pPrev;
        // }
        // Atribui ao atributo privado pPrev o endereço do parâmetro prev.
        // template <typename TL>
        // template <typename TE>
        // void List<TL>::Element<TE>::setPrev(Element<TE> *prev)
        // {
        //     pPrev = prev;
        // }
        // Retorna ponteiro com o endereço do próximo elemento a partir do atributo privado pNext.
        template <typename TL>
        template <typename TE>
        List<TL>::Element<TE> *List<TL>::Element<TE>::getNext()
        {
            return pNext;
        }
        // Atribui ao atributo privado pNext o endereço do parâmetro next.
        template <typename TL>
        template <typename TE>
        void List<TL>::Element<TE>::setNext(Element<TE> *next)
        {
            pNext = next;
        }
        // Fim das definições da Classe Aninhada Element
        //----------------------------------------------------------------

        // Construtora da classe List<T>.
        template <typename TL>
        List<TL>::List() : pFirst{nullptr},
                           pLast{nullptr}
        //    pCurrent{nullptr}
        {
        }
        // Destrutora da classe List<T>.
        template <typename TL>
        List<TL>::~List()
        { //prev
            // Método desaloca e aterra objetos e atributos usados na classe.
            clear();
        }
        // Método insere elemento de "qualquer tipo" na lista.
        template <typename TL>
        void List<TL>::insert(TL info)
        {
            // Caso ponteiro info passado como parâmetro não seja nulo.
            if (info)
            {
                // Cria dinamicamente um novo Element na lista.
                Element<TL> *newElement = new Element<TL>(info);
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
                    //newElement->setPrev(pLast);
                    // O novo elemento é o ultimo elemento da lista.
                    pLast = newElement;
                }
            }
        }
        // Método desaloca e aterra objetos e atributos usados na classe.
        template <typename TL>
        void List<TL>::clear()
        {
            // Variável auxiliar para percorrer a lista.
            Element<TL> *pAux = pFirst;
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
        template <typename TL>
        TL List<TL>::backStart()
        {
            // Ponteiro da posição atual aponta para o endereço do primeiro elemento.
            pCurrent = pFirst;
            // Caso a lista exista, retorna o primeiro elemento da lista.
            return (pCurrent) ? pCurrent->getInfo() : nullptr;
        }
        // Método desloca o ponteiro para o próximo elemento da lista e retorna o mesmo.
        template <typename TL>
        TL List<TL>::goNext()
        {
            // Ponteiro da posição atual aponta para o endereço do próximo elemento da lista.
            pCurrent = pCurrent->getNext();
            // Caso a lista exista, retorna o próximo elemento da lista.
            return (pCurrent) ? pCurrent->getInfo() : nullptr;
        }
    }

}
#endif