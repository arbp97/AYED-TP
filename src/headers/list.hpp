#ifndef __LIST_HPP__
#define __LIST_HPP__

#ifndef NULL
#define NULL      0
#endif

/* Definicion de tipos de datos */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Puntero a la informacion del nodo de la lista*/
typedef void* Data;

/* Nodos que conforman la lista.
 * Contiene el dato y un puntero al siguiente nodo */
struct Node
{
	Data ptrData;
	Node* next;
	Node* prev; //previous
};

/* Estructura de la lista.
 * Contiene dos punteros a nodos, uno al principio de la lista, y otro al final*/
struct List
{
	Node* head = NULL;
	Node* tail = NULL;
};

/* Definicion de primitivas */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    Coloca el dato al final de la lista
   Pre: El nodo no debe estar agregado.
   Post:Agrega un nodo al final de la lista.
*/
void addNode(List &list, Data ptrData);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*
   Elimina un nodo de la lista.
   Pre: El nodo debe haber sido creado.
   Post: Elimina el nodo pasado por parámetro.
*/
void deleteNode(List &list, Node* ptrNode);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*
   Elimina una lista
*/
void deleteList(List &list);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*  Devuelve el tamaño de la lista.
    Pre:La lista debe existir.
    Post:Devuelve un int con la cantidad de elementos de la lista.
*/
int length(List &list);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Chequea si la lista esta vacia
   Pre: La lista debe existir.
   Post:Devuelve un booleano indicando si la lista está vacía o no.

*/
bool isEmpty(List &list);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif // __LIST_HPP__
