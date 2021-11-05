#include <algorithm>
#include<iostream>
#include <cctype>
#include <locale>
#include "list.hpp"
#include "vino.hpp"
#include "usuario.hpp"

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

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    PRE:Debe existir la cadena de caracteres creada.
    POST:Elimina los espacios que hay a la izquierda del dato de la l�nea.
*/
void leftTrim(std::string &s);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    PRE:Debe existir la cadena de caracteres creada.
    POST:Elimina los espacios que hay a la derecha del dato de la l�nea.
*/
void rightTrim(std::string &s);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    PRE:Debe existir la cadena de caracteres creada.
    POST:Elimina los espacios que hay en ambos lados del dato de la l�nea.
*/
void trim(std::string &s);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    PRE:Debe existir el TDA vino.
    POST:Busca por id y devuelve el puntero al TDA vino con dicho id.
*/
Vino* findWineById(List wines, int id);

Usuario* findUserById(List users, int id);

int maxYear(List listSeleccion);

void orderListStrains(List listStrains);

void orderListCellar(List listCellar);

bool isCellarInWinesList(List listVinosAux, string cellar);

WineAndQuantityStruct* findWineStructByCellar(List listVinosAux, string cellar);

bool isStrainInWinesList(List listVinosAux, string strain);

StrainAndQuantityStruct* findWineStructByStrain(List listVinosAux, string strain);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    PRE:Debe existir el array.
    POST:Ordena el array ingresado por su cantidad.
*/
void ordenarArray(WineAndQuantityStruct miArray[]);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    PRE:Deben existir el TDA vino, selecci�n y usuario, con sus respectivas listas.
    POST:Realiza un ranking anual de los vinos m�s solicitados.
*/
void rankingAnualDeVinos(List listVinos, List listSeleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    PRE:Deben existir el TDA vino, selecci�n y usuario, con sus respectivas listas.
    POST:Realiza un ranking anual de las bodegas con m�s vinos elegidos.
*/
void rankingAnualDeBodegas(List listVinos, List listSeleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    PRE:Deben existir el TDA vino, selecci�n y usuario, con sus respectivas listas.
    POST:Realiza un ranking de los varietales elegidos por rango etario.
*/
void rankingVarietalPorEdad(List listUsuarios, List listVinos, List listSeleccion);


#endif // _!_UTIL_HPP__
