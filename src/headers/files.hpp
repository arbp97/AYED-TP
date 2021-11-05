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

/* Extrae los datos de la línea del usuario leída por readUsers.
   Pre:Debe estar leída la línea.
   Post:Interpreta la línea de entrada de usuario y devuelve sus atributos.
*/
void loadUser(Usuario &user, string text);

/* Lee el documento de texto de usuarios, Crea el TDA usuario y lo agrega a la lista de usuarios.
   Pre:El documento de texto debe existir y la struct Usuario debe estar Creada.
   Post:Interpreta el documento de texto y rellena los TDAs usuario con sus respectivos atributos.
*/
void readUsers(List &listUsuarios);

/* Extrae los datos de la línea del vino leída por readWines.
   Pre:Debe estar leída la línea.
   Post:Interpreta la línea de entrada de vino y devuelve sus atributos.
*/
void loadWine(Vino &vino, string text);

/* Lee el documento de texto de vinos, Crea el TDA vino y lo agrega a la lista de vinos.
   Pre:El documento de texto debe existir y la struct Vino debe estar Creada.
   Post:Interpreta el documento de texto y rellena los TDAs vino con sus respectivos atributos.
*/
void readWines(List &listVinos);

/* Extrae los datos de la línea de la selección leída por readSeleccion.
   Pre:Debe estar leída la línea.
   Post:Interpreta la línea de entrada de la selección y devuelve sus atributos.
*/
void loadSeleccion(Seleccion &seleccion, string text);
/* Lee el documento de texto de las selecciones de los vinos, Crea el TDA selección y lo agrega a la lista de selecciones.
   Pre:El documento de texto debe existir y la struct selección debe estar creada.
   Post:Interpreta el documento de texto y rellena los TDAs selección con sus respectivos atributos.
*/
void readSeleccion(List &listSeleccion);

#endif // __FILES_HPP__
