#include "../headers/files.hpp"
#include "../headers/util.hpp"
#include <fstream>
#include<string>

/* Implementacion de primitivas*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void loadUser(Usuario &user, string text)
{
	string aux;
	bool isIdSet = false;
	bool isNameSet = false;
	bool isAddressSet = false;

	//recorre todo el string correspondiente al usuario
	for (unsigned int i = 0; i < text.length(); i++)
	{
		// estos signos significan cambio de campo o EOF
		if ((text.at(i) == '-') or (text.at(i) == ';'))
		{
            trim(aux); // se quitan los espacios en blanco

			/*
				aqui revisamos los flags para cada
				campo a cargar.
				si el flag no esta levantado, significa
				que hay que setear ese campo.
				estan en el orden que deberia tener
				el string.
			*/

			if (!isIdSet)
			{
				isIdSet = true;

				setId(user, stoi(aux));
			}
			else if(!isNameSet)
			{
				isNameSet = true;

				setName(user, aux);
			}
			else if(!isAddressSet)
			{
				isAddressSet = true;

				setAddress(user, aux);
			}
			else
			{
				setAge(user, stoi(aux));
			}

			aux = "";
		}
		else
		{
			// si no hay signo, sigue siendo el mismo
			// campo 
			aux = aux + text.at(i);
		}

	}

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void readUsers(List &listUsuarios)
{
	string text;
	ifstream file("data/usuarios.txt");

	//lee los archivos de usuario hasta EOF
	while(getline(file, text))
	{
		Usuario* newUser = new Usuario;

		//carga el usuario
		loadUser(*newUser, text);

		//agrega el usuario a la lista
        addNode(listUsuarios, newUser);
	}

	file.close();
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

//Funcion carga del TDA de vinos
void loadWine(Vino &vino, string text)
{
	string aux;
	bool isIdSet = false;
	bool isLabelSet= false;
	bool isCellarSet = false;
	bool isWineSegmentSet = false;
	bool isStrainSet = false;
    bool isYearSet = false;

	//recorre todo el string correspondiente al vino
	for (unsigned int i = 0; i < text.length(); i++)
	{
		// chequea si cambia de campo o termina
		if ((text.at(i) == '-') or (text.at(i) == ';'))
		{
			//se remueven los espacios en blanco
            trim(aux);

			/*
				aqui revisamos los flags para cada
				campo a cargar.
				si el flag no esta levantado, significa
				que hay que setear ese campo.
				estan en el orden que deberia tener
				el string.
			*/

			if (!isIdSet)
			{
				isIdSet = true;

				setId(vino, stoi(aux));
			}
			else if(!isLabelSet)
			{
				isLabelSet = true;

				setLabel(vino, aux);
			}
			else if(!isCellarSet)
			{
				isCellarSet = true;

				setCellar(vino, aux);
			}
			else if(!isWineSegmentSet)
			{
				isWineSegmentSet = true;

				setWineSegment(vino, aux);
			}
			else if (!isStrainSet)
			{
				isStrainSet = true;

				setStrain(vino, aux);
			}
            else if (!isYearSet)
			{
				isYearSet = true;

				setYear(vino, stoi(aux));
			}
			else
            {
                setTerroir(vino,aux);
			}
			aux = "";
		}
		else
		{
			aux = aux + text.at(i);
		}

	}

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void readWines(List &listVinos)
{
	string text;
	ifstream file("data/vinos.txt");

	// lee archivo de vinos hasta EOF
	while(getline(file, text))
	{
		Vino* newVino = new Vino;

		// carga el vino
		loadWine(*newVino, text);

		// agrega el vino a la lista
        addNode(listVinos, newVino);
	}

	file.close();
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void loadSeleccion(Seleccion &seleccion, string text)
{
	/*
		mismo funcionamiento que las funciones
		load* anteriores
	*/
    
	string aux;
	bool isIdSet = false;
	bool isMonthSet = false;
	bool isYearSet = false;
    bool isWineSet1 = false;
	bool isWineSet2 = false;
	bool isWineSet3 = false;
	bool isWineSet4 = false;
	bool isWineSet5 = false;

	for (unsigned int i = 0; i < text.length(); i++)
	{
		if ((text.at(i) == '-') or (text.at(i) == ';'))
		{
            trim(aux);

			if (!isIdSet)
			{
				isIdSet = true;

				setId(seleccion, stoi(aux));
			}
			else if(!isMonthSet)
			{
				isMonthSet = true;
                Month auxMonth;

                switch (stoi(aux))
                {
                case 1: auxMonth = ENERO; break;
                case 2: auxMonth = FEBRERO; break;
                case 3: auxMonth = MARZO; break;
                case 4: auxMonth = ABRIL; break;
                case 5: auxMonth = MAYO; break;
                case 6: auxMonth = JUNIO; break;
                case 7: auxMonth = JULIO; break;
                case 8: auxMonth = AGOSTO; break;
                case 9: auxMonth = SEPTIEMBRE; break;
                case 10: auxMonth = OCTUBRE; break;
                case 11: auxMonth = NOVIEMBRE; break;
                case 12: auxMonth = DICIEMBRE; break;

                default:
                    break;
                }

				setMonth(seleccion, auxMonth);
			}
			else if(!isYearSet)
			{
				isYearSet = true;

				setYear(seleccion, stoi(aux));
			}

            //de los vinos solo se carga su id en esta parte
            else if (!isWineSet1)
            {
                isWineSet1 =true;
                getVinos(seleccion)[0].id = stoi(aux);
            }
            else if (!isWineSet2)
            {
                isWineSet2 =true;
                getVinos(seleccion)[1].id = stoi(aux);
            }
            else if (!isWineSet3)
            {
                isWineSet3 =true;
                getVinos(seleccion)[2].id = stoi(aux);
            }
            else if (!isWineSet4)
            {
                isWineSet4 =true;
                getVinos(seleccion)[3].id = stoi(aux);
            }
            else if (!isWineSet5)
            {
                isWineSet5 =true;
                getVinos(seleccion)[4].id = stoi(aux);
            }
            else
            {
                getVinos(seleccion)[5].id = stoi(aux);
            }

			aux = "";
		}
		else
		{
			aux = aux + text.at(i);
		}

	}

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void readSeleccion(List &listSeleccion)
{
	/*
		mismo funcionamiento que las
		funciones read* anteriores
	*/

	string text;
	ifstream file("data/seleccion.txt");

	while(getline(file, text))
	{
		Seleccion* newSeleccion = new Seleccion;
        createSeleccion(*newSeleccion);

		loadSeleccion(*newSeleccion, text);

        addNode(listSeleccion, newSeleccion);

	}

	file.close();

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
