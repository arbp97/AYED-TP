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

void createUsuario(Usuario& usuario, int id, string sName, int iAge, string sAddress);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getId(Usuario& usuario);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setId(Usuario& usuario, int id);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getName(Usuario& usuario);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setName(Usuario& usuario, string sName);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getAge(Usuario& usuario);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setAge(Usuario& usuario, int iAge);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getAddress(Usuario &usuario);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setAddress(Usuario &usuario, string sAddress);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif // __USUARIO_HPP__
