#ifndef __FILES_HPP__
#define __FILES_HPP__
#include "list.hpp"
#include "usuario.hpp"
#include "vino.hpp"
#include "seleccion.hpp"

/*
    Libreria con funciones relacionadas a la lectura de los archivos
    del proyecto.
*/

/* Extrae los datos de la l�nea del usuario le�da por readUsers.
   Pre:Debe estar le�da la l�nea.
   Post:Interpreta la l�nea de entrada de usuario y devuelve sus atributos.
*/
void loadUser(Usuario &user, string text);

/* Lee el documento de texto de usuarios, Crea el TDA usuario y lo agrega a la lista de usuarios.
   Pre:El documento de texto debe existir y la struct Usuario debe estar Creada.
   Post:Interpreta el documento de texto y rellena los TDAs usuario con sus respectivos atributos.
*/
void readUsers(List &listUsuarios);

/* Extrae los datos de la l�nea del vino le�da por readWines.
   Pre:Debe estar le�da la l�nea.
   Post:Interpreta la l�nea de entrada de vino y devuelve sus atributos.
*/
void loadWine(Vino &vino, string text);

/* Lee el documento de texto de vinos, Crea el TDA vino y lo agrega a la lista de vinos.
   Pre:El documento de texto debe existir y la struct Vino debe estar Creada.
   Post:Interpreta el documento de texto y rellena los TDAs vino con sus respectivos atributos.
*/
void readWines(List &listVinos);

/* Extrae los datos de la l�nea de la selecci�n le�da por readSeleccion.
   Pre:Debe estar le�da la l�nea.
   Post:Interpreta la l�nea de entrada de la selecci�n y devuelve sus atributos.
*/
void loadSeleccion(Seleccion &seleccion, string text);
/* Lee el documento de texto de las selecciones de los vinos, Crea el TDA selecci�n y lo agrega a la lista de selecciones.
   Pre:El documento de texto debe existir y la struct selecci�n debe estar creada.
   Post:Interpreta el documento de texto y rellena los TDAs selecci�n con sus respectivos atributos.
*/
void readSeleccion(List &listSeleccion);

#endif // __FILES_HPP__
