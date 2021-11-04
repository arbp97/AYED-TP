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
//estructura para cargar el reporte de vinos
typedef struct WineAndQuantityStruct{
    int id;
    string nombre;
    int cant=0;
    string sCellar;
};

//estructura de uvas
typedef struct StrainAndQuantityStruct{
    string sStrain;
    int cant=0;
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

Vino* findWineById(List wines, int id);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
//User* findUserById(List users, int id);
void ordenarArray(WineAndQuantityStruct miArray[]);

void rankingAnualDeVinos(List listVinos, List listSeleccion);

void rankingAnualDeBodegas(List listVinos, List listSeleccion);

void rankingVarietalPorEdad(List listUsuarios, List listVinos, List listSeleccion);


#endif // _!_UTIL_HPP__
