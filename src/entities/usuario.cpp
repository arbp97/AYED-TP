#include "usuario.hpp"

using namespace std;

/* Implementacion de primitivas*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void createUsuario(Usuario &usuario, int id, string sName, int iAge, string sAddress)
{
    usuario.id = id;
    usuario.sName = sName;
    usuario.iAge = iAge;
    usuario.sAddress = sAddress;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getId(Usuario &usuario)
{
    return usuario.id;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setId(Usuario &usuario, int id)
{
    usuario.id = id;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getName(Usuario &usuario)
{
    return usuario.sName;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setName(Usuario &usuario, string sName)
{
    usuario.sName = sName;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getAge(Usuario &usuario)
{
    return usuario.iAge;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setAge(Usuario &usuario, int iAge)
{
    usuario.iAge = iAge;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getAddress(Usuario &usuario)
{
    return usuario.sAddress;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setAddress(Usuario &usuario, string sAddress)
{
    usuario.sAddress = sAddress;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
