#include "seleccion.hpp"

using namespace std;

/* Implementacion de primitivas*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void createSeleccion(Seleccion &seleccion, int id, Month month, int year, Vino wines[WINE_QTY])
{
	seleccion.id = id;
	seleccion.month = month;
	seleccion.year = year;
	setVinos(seleccion, wines);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

//empty constructor
void createSeleccion(Seleccion &seleccion)
{
	seleccion.id = -1;
	seleccion.month = MARZO;
	seleccion.year = 0;

	for(int i=0;i<WINE_QTY;i++)
	{
		Vino* vino = new Vino;
		seleccion.wines[i] = *vino;
	}
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

Month getMonth(Seleccion &seleccion)
{
	return seleccion.month;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setMonth(Seleccion &seleccion, Month month)
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

Vino* getVinos(Seleccion &seleccion)
{
	return seleccion.wines;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setVinos(Seleccion &seleccion, Vino wines[WINE_QTY])
{
	for(int i=0;i<WINE_QTY;i++)
	{
		seleccion.wines[i] = *(wines + i);
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setVino(Seleccion &seleccion, Vino &wine, int place)
{
	if ((place >= 0) && (place < WINE_QTY))
	{
		seleccion.wines[place] = wine;
	}
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */