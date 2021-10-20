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

void loadUser(Usuario &user, string text);

void readUsers(List &listUsuarios);

//Funcion carga del TDA de vinos
void loadWine(Vino &vino, string text);

//test function para leer archivo de vinos
void readWines(List &listVinos);

void loadSeleccion(Seleccion &seleccion, string text);

void readSeleccion(List &listSeleccion);

int readCantWines();

#endif // __FILES_HPP__