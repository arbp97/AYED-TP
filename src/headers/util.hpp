#include <algorithm>
#include <cctype>
#include <locale>

#ifndef __UTIL_HPP__
#define __UTIL_HPP__

/*
*   LIBRERIA DE UTILIDADES
*
*   - TRIM y variedades: para recortar un string, quitando espacios vacios
*/

/* Definicion de primitivas */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from start (in place)
void leftTrim(std::string &s);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from end (in place)
void rightTrim(std::string &s);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from both ends (in place)
void trim(std::string &s);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif // _!_UTIL_HPP__
