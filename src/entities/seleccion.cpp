#include "seleccion.hpp"

using namespace std;

/* Implementacion de primitivas*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
void createSeleccion(Seleccion &seleccion, int id, Month month, int year, int wines[WINE_QTY])
{
	seleccion.id = id;
	seleccion.month = month;
	seleccion.year = year;
	setVinos(seleccion, wines);
}
*/


void createSeleccion(Seleccion &seleccion, int id, int month, int year, int wine1,int wine2, int wine3, int wine4, int wine5, int wine6)
{
	seleccion.id = id;
	seleccion.month = month;
	seleccion.year = year;
	seleccion.wine1 = wine1;
	seleccion.wine2 = wine2;
	seleccion.wine3 = wine3;
	seleccion.wine4 = wine4;
	seleccion.wine5 = wine5;
	seleccion.wine6 = wine6;
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getId(Seleccion &seleccion)
{
	return seleccion.id;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setId(Seleccion &seleccion, int id)
{
	seleccion.id = id;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getMonth(Seleccion &seleccion)
{
	return seleccion.month;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setMonth(Seleccion &seleccion, int month)
{
	seleccion.month = month;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getYear(Seleccion &seleccion)
{
	return seleccion.year;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setYear(Seleccion &seleccion, int year)
{
	seleccion.year = year;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Devuelve un puntero al primero del array de vinos */

int getVino1(Seleccion &seleccion)
{
    	return seleccion.wine1;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setVino1(Seleccion &seleccion, int wine1)
{
	seleccion.wine1 = wine1;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
int getVino2(Seleccion &seleccion)
{
    	return seleccion.wine2;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setVino2(Seleccion &seleccion, int wine2)
{
	seleccion.wine2 = wine2;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
int getVino3(Seleccion &seleccion)
{
    	return seleccion.wine3;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setVino3(Seleccion &seleccion, int wine3)
{
	seleccion.wine3 = wine3;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
int getVino4(Seleccion &seleccion)
{
    	return seleccion.wine4;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setVino4(Seleccion &seleccion, int wine4)
{
	seleccion.wine4 = wine4;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
int getVino5(Seleccion &seleccion)
{
    	return seleccion.wine5;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setVino5(Seleccion &seleccion, int wine5)
{
	seleccion.wine5 = wine5;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
int getVino6(Seleccion &seleccion)
{
    	return seleccion.wine6;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setVino6(Seleccion &seleccion, int wine6)
{
	seleccion.wine6 = wine6;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
