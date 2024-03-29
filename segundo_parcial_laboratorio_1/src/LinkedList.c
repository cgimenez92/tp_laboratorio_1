#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


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
    LinkedList* this=NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
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
    int ret=-1;
    if(this!=NULL)
    {
    	ret=this->size;
    }
    return ret;
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
	Node* pAux=NULL;
	int i=0;

	if(this!=NULL && nodeIndex>=0 && ll_len(this)>nodeIndex)
	{
		pAux = this->pFirstNode;

		while(pAux!=NULL)
		{
			if(i == nodeIndex)
			{
				break;
			}
			pAux=pAux->pNextNode;
			i++;
		}
	}

    return pAux;
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
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int ret=-1;
	Node* auxNode=NULL;
	Node* previousNode=NULL;

	auxNode = (Node*)malloc(sizeof(Node*));

	if(this!=NULL && auxNode!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
	{
		auxNode->pElement = pElement;

		if(nodeIndex==0)
		{
			auxNode->pNextNode = this->pFirstNode;
			this->pFirstNode = auxNode;
			this->size++;
			ret=0;
		}
		else
		{
			previousNode = getNode(this,nodeIndex-1);

			if(previousNode != NULL)
			{
				auxNode->pNextNode = previousNode->pNextNode;
				previousNode->pNextNode = auxNode;
				this->size++;
				ret=0;
			}
		}
	}
    return ret;
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
    int ret=-1;
    if(this!=NULL)
    {
    	ret=addNode(this, ll_len(this), pElement);
    }
    return ret;
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
    void* ret=NULL;
    Node* auxNode=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	auxNode=getNode(this, index);

    	if(auxNode!=NULL)
    	{
    		ret=auxNode->pElement;
    	}
    }
    return ret;
}

/** \brief Inserta un elemento en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param Index int ubicacion del elemento a agregar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
   int ret=-1;
   Node* auxNode=NULL;

   if(this!=NULL && index>=0 && index<ll_len(this))
   {
		auxNode=getNode(this, index);

		if(auxNode!=NULL)
		{
			auxNode->pElement=pElement;
			ret=0;
		}
   }
    return ret;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param Index int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
    int ret=-1;
    Node* auxNode=NULL;
	Node* previousNode=NULL;

	if(this!=NULL && index>=0 && index<ll_len(this))
	{
		auxNode = getNode(this, index);

		if(index==0 && auxNode!=NULL)
		{
			this->pFirstNode = auxNode->pNextNode;
			free(auxNode);
			this->size--;
			ret=0;
		}
		else
		{
			previousNode = getNode(this, index-1);

			if(previousNode!=NULL && auxNode!=NULL)
			{
				previousNode->pNextNode = auxNode->pNextNode;
				free(auxNode);
				this->size--;
				ret=0;
			}
		}
	}
    return ret;
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
    int ret=-1;

    if(this!=NULL)
    {
    	for(int i=0; i<ll_len(this); i++)
    	{
    		ll_remove(this, i);
    		ret=0;
    	}
    }
    return ret;
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
    int ret=-1;

    if(this!=NULL && ll_clear(this)==0)
    {
		free(this);
		ret=0;
    }

    return ret;
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
    int ret=-1;
    void* auxElement=NULL;

    if(this!=NULL)
    {
		for(int i=0; i<ll_len(this); i++)
		{
			auxElement=ll_get(this, i); //No se usa getNode por que te otorga la posicion de memoria del nodo, no el elemento del nodo. Necesitamos saber en que posicion se encuentra el elemento pasado como parametro

			if(auxElement==pElement)
			{
				ret=i;
				break;
			}
		}
    }
    return ret;
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
    int ret=-1;
    if(this!=NULL)
    {
    	ret=0;
    	if(this->pFirstNode==NULL && this->size==0)
    	{
    		ret=1;
    	}
    }
    return ret;
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
    int ret = -1;

    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
    	ret = addNode(this, index, pElement);
    }

    return ret;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index)
{
    void* ret=NULL;
    Node* auxNode=NULL;

	if(this!=NULL && index>=0 && index<ll_len(this))
	{
		auxNode=getNode(this, index);

		if(auxNode!=NULL)
		{
			ret=auxNode->pElement;
			ll_remove(this, index);
		}

	}
    return ret;
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
    int ret=-1;
	if(this!=NULL)
	{
		if(ll_indexOf(this, pElement)>=0)
		{
			ret=1;
		}
		else
			{
				ret=0;
			}
	}
    return ret;
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
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int ret=-1;
    void* auxElement=NULL;

    if(this!=NULL && this2!=NULL)
    {
    	ret=1; //Consultar por "error" la logica indica que deberia ir despues del else de all_contains

		for(int i=0; i<ll_len(this2); i++)
		{
			auxElement=ll_get(this2, i);

			if(!ll_contains(this, auxElement))
			{
				ret=0;
				break;
			}
		}
    }
    return ret;
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
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* auxList=NULL;
    void* auxElement=NULL;
    int i;

    if(this!=NULL && from>=0 && to>from && to<=ll_len(this))
    {
    	auxList=ll_newLinkedList();

    	if(auxList!=NULL)
    	{
			for(i=from; i<=to; i++)
			{
				auxElement=ll_get(this, i);
				ll_add(auxList, auxElement);
			}
			auxList->size = i;
    	}
    }

    return auxList;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* auxList=NULL;

    if(this!=NULL)
    {
    	auxList=ll_subList(this, 0, ll_len(this));
    }

    return auxList;
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
    int ret=-1;
    void* aux=NULL;
    void* aux2=NULL;
    int flagSwap;

	if(this!=NULL && pFunc!=NULL && ll_len(this) > 0 && (order==0 || order==1))
	{
		do
		{
			flagSwap = 0;

			for(int i=0; i<ll_len(this)-1; i++)
			{
				aux=ll_get(this, i);
				aux2=ll_get(this, i+1);

				if (order == 0 && (pFunc((aux),(aux2))<0))
				{
					ll_set(this, i+1, aux);
					ll_set(this, i, aux2);
					flagSwap = 1;
				}
				else if(order == 1 && (pFunc((aux),(aux2))>0))
						{
							ll_set(this, i+1, aux);
							ll_set(this, i, aux2);
							flagSwap = 1;
						}
			 }

		}while(flagSwap);

		ret=0;
	}

    return ret;
}


int ll_count(LinkedList* this, int (*pFunc)(void*))
{
	int qElements=0;
	int pFuncResult;
	void* aux=NULL;

	if(this != NULL && pFunc != NULL)
	{
		for(int i=0;i<ll_len(this);i++)
		{
			aux = ll_get(this, i);
			pFuncResult = pFunc(aux);

			if(pFuncResult>-1)
			{
				qElements +=  pFuncResult;
			}
		}
	}
	return qElements;
}


//int count(struct Node* head, int search_for) // pFunc de ll_count
//{
//    struct Node* current = head;
//    int count = 0;
//    while (current != NULL) {
//        if (current->data == search_for)
//            count++;
//        current = current->next;
//    }
//    return count;
//}


//int ll_map(LinkedList* this, int (*pFunc)(void* pElement))
//{
//    int returnAux = -1;
//    int len;
//    void* pElement;
//
//    if(this != NULL && pFunc != NULL)
//    {
//        len = ll_len(this);
//        for(int i=0;i<len;i++)
//        {
//            pElement = ll_get(this, i);
//            pFunc(pElement);
//        }
//        returnAux = 0;
//    }
//    return returnAux;
//}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* this2 = NULL;
	void* pElement;

	if(this != NULL && pFunc != NULL)
	{
		this2 = ll_newLinkedList();
		if(this2 != NULL)
		{
			for(int i=0;i<ll_len(this);i++)
			{
				pElement = ll_get(this, i);
				if(pFunc(pElement) == 1)
				{
					ll_add(this2, pElement);
				}
			}
		}
	}
	return this2;
}
