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

/*
    Crear Selecci�n
  PRE : La selecci�n no debe haber sido creada.
  POST: La selecci�n queda creada y preparada para ser usada.
*/
void createSeleccion(Seleccion &seleccion, int id, Month month, int year, Vino wines[WINE_QTY]);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


/*
    Crea la Selecci�n
  PRE : La selecci�n no debe haber sido creada.
  POST: La selecci�n queda creada y preparada para ser usada.
  En esta funcion se crea el id en -1, el mes en marzo y el a�o en 0.
*/
void createSeleccion(Seleccion &seleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*Obtiene el id de la selecci�n
  PRE : Selecci�n creada con createSeleccion().
  POST: Devuelve el dato contenido en el campo id.

  Selecci�n: Instancia sobre la cual se invoca la primitiva.
*/
int getId(Seleccion &seleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*Setea el id
  PRE : Selecci�n creada con createSeleccion().
  POST: El campo id pasa a contener el dato ingresado.

  Selecci�n: Instancia sobre la cual se invoca la primitiva.
  id: campo a ingresar.
*/
void setId(Seleccion &seleccion, int id);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene el mes de la selecci�n
  PRE : Selecci�n creada con createSeleccion().
  POST: Devuelve el dato contenido en el campo month.

  Selecci�n: Instancia sobre la cual se invoca la primitiva.
*/
Month getMonth(Seleccion &seleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea el mes de la selecci�n
  PRE : Selecci�n creada con createSeleccion().
  POST: El campo month pasa a contener el dato ingresado.

  Selecci�n: Instancia sobre la cual se invoca la primitiva.
  Month: campo a ingresar.
*/
void setMonth(Seleccion &seleccion, Month month);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene el a�o de la selecci�n
  PRE : Selecci�n creada con createSeleccion().
  POST: Devuelve el dato contenido en el campo year.

  Selecci�n: Instancia sobre la cual se invoca la primitiva.
*/
int getYear(Seleccion &seleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea el a�o de la selecci�n
  PRE : Selecci�n creada con createSeleccion().
  POST: El campo year pasa a contener el dato ingresado.

  Selecci�n: Instancia sobre la cual se invoca la primitiva.
  Year: campo a ingresar.
*/
void setYear(Seleccion &seleccion, int year);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*
   PRE: debe existir el array de vinos.
   POST: Devuelve un puntero al primer elemento del array de vinos.

   Selecci�n: Instancia sobre la cual se invoca la primitiva.
 */
Vino* getVinos(Seleccion &seleccion);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    PRE:Debe existir el arreglo de vinos y el TDA vino.
    POST:Recorre el arreglo de vinos y los setea en el TDA selecci�n.
*/
void setVinos(Seleccion &seleccion, Vino wines[WINE_QTY]);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    PRE:Debe existir el TDA vino.
    POST:setea el vino en el TDA selecci�n.
*/
void setVino(Seleccion &seleccion, Vino &wine, int place);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif // __SELECCION_HPP__
