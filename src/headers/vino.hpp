#include <iostream>

using namespace std;

#ifndef __VINO_HPP__
#define __VINO_HPP__

/* Definicion de tipos de datos */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Datos del Vino */

typedef struct {
    int id;
    string sLabel;
    string sCellar;
    string sWineSegment;
    string sStrain;
    int year;
    string sTerroir;
} Vino;

/* Definicion de primitivas */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void createVino(
	Vino &vino,
    int id,
    string sLabel,
    string sCellar,
    string sWineSegment,
    string sStrain,
    int year,
    string sTerroir);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene el id del vino
  PRE : Vino creado.
  POST: Devuelve el dato contenido en el campo id.

  Vino: Instancia sobre la cual se invoca la primitiva.
*/
int getId(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea el id del vino
  PRE : Vino creado.
  POST: El campo id pasa a contener el dato ingresado.

  Vino: Instancia sobre la cual se invoca la primitiva.
  id: campo a ingresar.
*/
void setId(Vino &vino, int id);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene el nombre del vino
  PRE : Vino creado.
  POST: Devuelve el dato contenido en el campo sLabel.

  Vino: Instancia sobre la cual se invoca la primitiva.
*/
string getLabel(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea el nombre del vino
  PRE : Vino creado.
  POST: El campo sLabel pasa a contener el dato ingresado.

  Vino: Instancia sobre la cual se invoca la primitiva.
  sLabel: campo a ingresar.
*/
void setLabel(Vino &vino, string sLabel);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene la bodega del vino
  PRE : Vino creado.
  POST: Devuelve el dato contenido en el campo sCellar.

  Vino: Instancia sobre la cual se invoca la primitiva.
*/
string getCellar(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea la bodega del vino
  PRE : Vino creado.
  POST: El campo sCellar pasa a contener el dato ingresado.

  Vino: Instancia sobre la cual se invoca la primitiva.
  sCellar: campo a ingresar.
*/
void setCellar(Vino &vino, string sCellar);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene el segmento del vino
  PRE : Vino creado.
  POST: Devuelve el dato contenido en el campo sWineSegment.

  Vino: Instancia sobre la cual se invoca la primitiva.
*/
string getWineSegment(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea el segmento del vino
  PRE : Vino creado.
  POST: El campo sWineSegment pasa a contener el dato ingresado.

  Vino: Instancia sobre la cual se invoca la primitiva.
  sWineSegment: campo a ingresar.
*/
void setWineSegment(Vino &vino, string sWineSegment);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene el varietal del vino
  PRE : Vino creado.
  POST: Devuelve el dato contenido en el campo sStrain.

  Vino: Instancia sobre la cual se invoca la primitiva.
*/
string getStrain(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea el varietal del vino
  PRE : Vino creado.
  POST: El campo sStrain pasa a contener el dato ingresado.

  Vino: Instancia sobre la cual se invoca la primitiva.
  sStrain: campo a ingresar.
*/
void setStrain(Vino &vino, string sStrain);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene el año del vino
  PRE : Vino creado.
  POST: Devuelve el dato contenido en el campo year.

  Vino: Instancia sobre la cual se invoca la primitiva.
*/
int getYear(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea el año del vino
  PRE : Vino creado.
  POST: El campo year pasa a contener el dato ingresado.

  Vino: Instancia sobre la cual se invoca la primitiva.
  year: campo a ingresar.
*/
void setYear(Vino &vino, int year);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene el terroir del vino
  PRE : Vino creado.
  POST: Devuelve el dato contenido en el campo Terroir.

  Vino: Instancia sobre la cual se invoca la primitiva.
*/
string getTerroir(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea el terroir del vino
  PRE : Vino creado.
  POST: El campo sTerroir pasa a contener el dato ingresado.

  Vino: Instancia sobre la cual se invoca la primitiva.
  sTerroir: campo a ingresar.
*/
void setTerroir(Vino &vino, string sTerroir);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif // __VINO_HPP__
