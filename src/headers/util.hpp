#include <algorithm>
#include<iostream>
#include <cctype>
#include <locale>
#include "list.hpp"
#include "vino.hpp"

#ifndef __UTIL_HPP__
#define __UTIL_HPP__

/*
*   LIBRERIA DE UTILIDADES
*
*   - TRIM y variedades: para recortar un string, quitando espacios vacios
*/

/* Definicion de primitivas */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
//estructura provisoria para cargar el reporte de vinos
typedef struct r1{
int id;
string nombre;
int cant=0;
string sCellar;
};
// trim from start (in place)
void leftTrim(std::string &s);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from end (in place)
void rightTrim(std::string &s);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from both ends (in place)
void trim(std::string &s);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

//contiene elemendo en array
int contieneElemento(int matriz[][2], int elemento);
//void agregoElemento(r1 arreglo[], int elemento);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void mostrarElementos(int matriz[][2]);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void mostrarMatriz(int **);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Vino* findWineById(List wines, int id);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
//User* findUserById(List users, int id);
void ordenarArray(r1 miArray[]);


void rankingYear();

void rankingCellar();
#endif // _!_UTIL_HPP__
