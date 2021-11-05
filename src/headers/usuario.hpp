#include <iostream>

using namespace std;

#ifndef __USUARIO_HPP__
#define __USUARIO_HPP__

/* Definicion de tipos de datos */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Datos del Uusuario */

typedef struct {
    int id;
    string sName;
    int iAge;
    string sAddress; // Podria ser una clase adicional con la info separada
} Usuario;

/* Definicion de primitivas */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*
    Crear el usuario
  PRE : El usuario no debe haber sido creado.
  POST: El usuario queda creado y preparado para ser usado.
*/
void createUsuario(Usuario& usuario, int id, string sName, int iAge, string sAddress);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene el id del usuario
  PRE : Usuario creado con createUsuario().
  POST: Devuelve el dato contenido en el campo id.

  Usuario: Instancia sobre la cual se invoca la primitiva.
*/
int getId(Usuario& usuario);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea el id del usuario
  PRE : Usuario creado con createUsuario().
  POST: El campo id pasa a contener el dato ingresado.

  Usuario: Instancia sobre la cual se invoca la primitiva.
  id: campo a ingresar.
*/
void setId(Usuario& usuario, int id);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene el Nombre del usuario
  PRE : Usuario creado con createUsuario().
  POST: Devuelve el dato contenido en el campo sName.

  Usuario: Instancia sobre la cual se invoca la primitiva.
*/
string getName(Usuario& usuario);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea el Nombre del usuario
  PRE : Usuario creado con createUsuario().
  POST: El campo sName pasa a contener el dato ingresado.

  Usuario: Instancia sobre la cual se invoca la primitiva.
  sName: campo a ingresar.
*/
void setName(Usuario& usuario, string sName);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene la edad del usuario
  PRE : Usuario creado con createUsuario().
  POST: Devuelve el dato contenido en el campo iAge.

  Usuario: Instancia sobre la cual se invoca la primitiva.
*/
int getAge(Usuario& usuario);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea la edad del usuario
  PRE : Usuario creado con createUsuario().
  POST: El campo iAge pasa a contener el dato ingresado.

  Usuario: Instancia sobre la cual se invoca la primitiva.
  iAge: campo a ingresar.
*/
void setAge(Usuario& usuario, int iAge);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Obtiene la dirección del usuario
  PRE : Usuario creado con createUsuario().
  POST: Devuelve el dato contenido en el campo sAdress.

  Usuario: Instancia sobre la cual se invoca la primitiva.
*/
string getAddress(Usuario &usuario);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*Setea la dirección del usuario
  PRE : Usuario creado con createUsuario().
  POST: El campo sAddress pasa a contener el dato ingresado.

  Usuario: Instancia sobre la cual se invoca la primitiva.
  sAddress: campo a ingresar.
*/
void setAddress(Usuario &usuario, string sAddress);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif // __USUARIO_HPP__
