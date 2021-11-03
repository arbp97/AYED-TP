#include "../headers/list.hpp"

/* Implementacion de primitivas*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void addNode(List &list, Data data)
{
	Node* temp = new Node;
	temp->ptrData = data;
	temp->next = NULL;
	temp->prev = NULL;

	if(isEmpty(list))
	{
		/* Si la lista se encuentra vacia, entonces se agrega el nuevo nodo
		 * como cabeza y cola al mismo tiempo. */

		list.head = temp;
		list.tail = temp;
	}
	else
	{
		if(list.head == list.tail)
		{
			/* si la cola y la cabeza son iguales, hay solo un objeto en la lista.
			 * Se agrega el nuevo nodo al final de la lista, y se acomodan las
			 * referencias next y prev: el anterior de la cola es la cabeza, y el
			 * siguiente de la cabeza es la cola. */

			list.tail = temp;
			list.tail->prev = list.head;
			list.head->next = list.tail;
		}
		else
		{
			/* Si la cabeza y la cola no son iguales, existe mas de un objeto.
			 * Primero se agrega la referencia al objeto anterior al nuevo nodo,
			 * luego se agrega el nuevo nodo al final de la lista, y por ultimo
			 * se mueve la referencia a la cola de la lista a este nuevo objeto. */

			 temp->prev = list.tail;
			 list.tail->next = temp;
			 list.tail = temp;
		}
	}
	temp = NULL;
	delete temp;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

bool isEmpty(List &list)
{
	bool value = true;

	if(list.head != NULL)
	{
		value = false;
	}

	return value;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int length(List &list)
{
	Node* temp = new Node;
    temp = list.head;
    int length=0;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

	temp = NULL;
	delete temp;

    return length;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void deleteNode(List &list, Node* ptrNode)
{
	/* Primero se verifica si la lista no esta vacia y el puntero es valido */
	if((!isEmpty(list) && (ptrNode != NULL)))
	{

		if(ptrNode == list.head)
		{
			/* Si el nodo a eliminar es el primero de la lista, se asigna como
			 * primero de la lista al proximo de este. Hecho esto, se limpia
			 * el puntero al previo nodo de la nueva cabeza (ya que ahora es
			 * el primero) */

			list.head = list.head->next;
			list.head->prev = NULL;
		}
		else
		{
			/* Si el nodo a eliminar no es el primero, entonces se busca el nodo
			 * siguiente del ANTERIOR del nodo a eliminar, y se le asigna como
			 * proximo al nodo SIGUIENTE de dicho nodo a eliminar. */

			ptrNode->prev->next = ptrNode->next;
		}

		delete ptrNode;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
