#include "vino.hpp"

using namespace std;

#ifndef __SELECCION_HPP__
#define __SELECCION_HPP__

/* Definicion de tipos de datos */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Constantes */

static const int WINE_QTY = 6;

/* Lista de meses */

typedef enum
{
	ENERO = 1,
	FEBRERO = 2,
	MARZO = 3,
	ABRIL = 4,
	MAYO = 5,
	JUNIO = 6,
	JULIO = 7, 
	AGOSTO = 8,
	SEPTIEMBRE = 9,
	OCTUBRE = 10,
	NOVIEMBRE = 11,
	DICIEMBRE = 12
} Month;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Datos de la Seleccion */

typedef struct {
    int id;
    Month month;
    int year;
	Vino wines[WINE_QTY];
} Seleccion;

/* Definicion de primitivas */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void createSeleccion(Seleccion &seleccion, int id, Month month, int year, Vino wines[WINE_QTY]);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void createSeleccion(Seleccion &seleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getId(Seleccion &seleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setId(Seleccion &seleccion, int id);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Month getMonth(Seleccion &seleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setMonth(Seleccion &seleccion, Month month);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getYear(Seleccion &seleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setYear(Seleccion &seleccion, int year);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Devuelve un puntero al primero del array de vinos */

Vino* getVinos(Seleccion &seleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setVinos(Seleccion &seleccion, Vino wines[WINE_QTY]);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setVino(Seleccion &seleccion, Vino &wine, int place);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif // __SELECCION_HPP__