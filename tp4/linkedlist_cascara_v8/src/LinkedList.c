#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if (this!=NULL)
    {
        this->size=0;
        this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int retorno = -1;
    if (this!=NULL)
    {
        retorno=this->size;
    }

    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i;
    Node* pNode=NULL;
    if (this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        pNode=this->pFirstNode;

        for (i=0; i<nodeIndex;i++)
        {
            pNode=pNode->pNextNode;

        }

    }
    return pNode;
    //return NULL;

}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int retorno = -1;
    Node* pNodoAnt;
    Node* pNodo;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        pNodo = (Node*) malloc(sizeof(Node));
        if(pNodo != NULL)
        {
            pNodo->pElement = pElement;
            if(nodeIndex == 0)
            {
                if(this->pFirstNode == NULL)
                {
                    pNodo->pNextNode = NULL;
                }
                if(this->pFirstNode != NULL)
                {
                    pNodo->pNextNode = this->pFirstNode;
                }
                this->pFirstNode = pNodo;
            }
            else
            {
                pNodoAnt = getNode(this,nodeIndex-1);
                pNodo->pNextNode = pNodoAnt->pNextNode;
                pNodoAnt->pNextNode = pNodo;
            }
            this->size++;
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int aux;
    if(this != NULL){
        aux=addNode(this,ll_len(this),pElement);
        if (!aux){
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* retorno = NULL;

    Node* pNode=NULL;

    if (this!=NULL && index>=0 && index<ll_len(this))
    {
        pNode=getNode(this,index);
        if (pNode!=NULL)
        {
            retorno=pNode->pElement;
        }
    }
    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno = -1;
    Node* pNode=NULL;

    if (this!=NULL && index>=0)
    {
        pNode=getNode(this,index);
        if (pNode!=NULL)
        {
            pNode->pElement=pElement;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int retorno = -1;

    Node* pNodoSig=NULL;
    Node* pNodoAnt=NULL;
    Node* pNodo=NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        pNodoAnt=getNode(this,index-1);
        pNodo=getNode(this,index);
        pNodoSig=getNode(this,index+1);

        if (pNodo!=NULL && pNodoAnt!=NULL)
        {
            pNodoAnt->pNextNode=pNodoSig;
        }
        else
        {
            this->pFirstNode=pNodoSig;
        }
        free(pNodo);
        this->size--;
        retorno = 0;
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int retorno = -1;
    int i;

    if (this!=NULL)
    {
        for (i=0;i<ll_len(this);i++)
        {
            ll_remove(this,i);
        }
        retorno=0;
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno = -1;
    if (this!=NULL)
    {
        free(this);
        retorno=0;
    }

    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int i;
    Node* pNode=NULL;
    if (this!=NULL)
    {
        for (i=0;i<ll_len(this);i++)
        {
            pNode=getNode(this,i);
            if (pNode->pElement==pElement)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;
    Node* pNode=NULL;

    if (this!=NULL)
    {
        pNode=getNode(this,0);
        if (pNode==NULL)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;

    if (this!=NULL && index>=0 && index<=ll_len(this))
    {
        if (addNode(this,index,pElement)==0)
        {
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{

    void* retorno = NULL;
    Node* pNode=NULL;

    if (this!=NULL && index>=0 && index<ll_len(this))
    {
        pNode=getNode(this,index);
        retorno=pNode->pElement;
        ll_remove(this,index);
    }
    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno = -1;
    Node* pNodo=NULL;
    int i;
    int flagEncontrado=0;

    if (this!=NULL)
    {
        for (i=0;i<ll_len(this);i++)
        {
            pNodo=getNode(this,i);
            if (pNodo!=NULL)
            {
                if (pNodo->pElement==pElement)
                {
                    retorno=1;
                    flagEncontrado=1;
                    break;
                }
            }
            else
            {
                retorno=-1;
                flagEncontrado=1;
                break;
            }
        }
        if (flagEncontrado==0)
        {
            retorno=0;
        }
    }
    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno = -1;
    Node* pNodo=NULL;
    int i;

    if (this!=NULL && this2!=NULL)
    {
        retorno=1;
        for (i=0;i<ll_len(this);i++)
        {
            pNodo=getNode(this2,i);

            if (ll_contains(this,pNodo->pElement)==0)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* copiaArray = NULL;
    Node* pNode=NULL;
    int i;
    int aux=0;

    if (this!=NULL && from>=0 && from <= ll_len(this) && to>=0 && to<=ll_len(this)){
        copiaArray=this;
        copiaArray->size=0;

        for (i=from;i<=to;i++){
            pNode=getNode(this,i);
            if (pNode!=NULL){
                aux=addNode(copiaArray,i,pNode);
                if (aux==0){
                    copiaArray->size++;
                }
            }else{
                break;
            }
        }
    }
    return copiaArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* copiaArray = NULL;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        copiaArray = ll_newLinkedList();
        copiaArray = ll_subList(this, 0, len);
    }
    return copiaArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    int r;

    void* p1;
    void* p2;
    void* aux;

    if (this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
        returnAux=0;
        for (i=0;i<ll_len(this)-1;i++)
        {
            for (j = i+1; j < ll_len(this); j++)
            {
                p1=((void* ) ll_get(this,i));
                p2=((void* ) ll_get(this,j));

                r=pFunc(p1,p2); // r=0 Iguales - r=1 p1>p2 - r=-1 p1<p2

                if ((order==0 && r==-1) || (order==1 && r==1)){
                    //ord=1;//descendente || ord=0;//ascendente

                    aux=p1;
                    ll_set(this,i,p2);
                    ll_set(this,j,aux);
                }

                /*
                switch (order)
                {
                    case 0:
                        if (r==-1)
                        {
                            aux=p1;
                            ll_set(this,i,p2);
                            ll_set(this,j,aux);
                        }
                        returnAux=1;
                        break;
                    case 1:
                        if (r==1)
                        {
                            aux=p1;
                            ll_set(this,i,p2);
                            ll_set(this,j,aux);
                        }
                        returnAux=0;
                        break;
                    default:
                        returnAux=-1;
                        break;
                }
                */
            }
        }
    }
    return returnAux;
}
