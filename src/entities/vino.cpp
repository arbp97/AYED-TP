#include "../headers/vino.hpp"

using namespace std;

/* Implementacion de primitivas*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void createVino(
	Vino& vino,
    int id,
    string sLabel,
    string sCellar,
    string sWineSegment,
    string sStrain,
    int year,
    string sTerroir)
{
	vino.id = id;
	vino.sLabel = sLabel;
	vino.sCellar = sCellar;
	vino.sWineSegment = sWineSegment;
	vino.sStrain = sStrain;
	vino.year = year;
	vino.sTerroir = sTerroir;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getId(Vino &vino)
{
	return vino.id;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setId(Vino &vino, int id)
{
	vino.id = id;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getLabel(Vino &vino)
{
	return vino.sLabel;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setLabel(Vino &vino, string sLabel)
{
	vino.sLabel = sLabel;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getCellar(Vino &vino)
{
	return vino.sCellar;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setCellar(Vino &vino, string sCellar)
{
	vino.sCellar = sCellar;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getWineSegment(Vino &vino)
{
	return vino.sWineSegment;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setWineSegment(Vino &vino, string sWineSegment)
{
	vino.sWineSegment = sWineSegment;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getStrain(Vino &vino)
{
	return vino.sStrain;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setStrain(Vino &vino, string sStrain)
{
	vino.sStrain = sStrain;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int getYear(Vino &vino)
{
	return vino.year;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setYear(Vino &vino, int year)
{
	vino.year = year;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

string getTerroir(Vino &vino)
{
	return vino.sTerroir;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void setTerroir(Vino &vino, string sTerroir)
{
	vino.sTerroir = sTerroir;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
