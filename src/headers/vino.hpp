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
	Vino& vino,
    int id,
    string sLabel,
    string sCellar,
    string sWineSegment,
    string sStrain,
    int year,
    string sTerroir);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getId(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setId(Vino &vino, int id);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getLabel(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setLabel(Vino &vino, string sLabel);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getCellar(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setCellar(Vino &vino, string sCellar);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getWineSegment(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setWineSegment(Vino &vino, string sWineSegment);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getStrain(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setStrain(Vino &vino, string sStrain);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getYear(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setYear(Vino &vino, int year);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getTerroir(Vino &vino);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setTerroir(Vino &vino, string sTerroir);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif // __VINO_HPP__
