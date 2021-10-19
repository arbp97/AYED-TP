#include "usuario.hpp"
#include "vino.hpp"
#include "seleccion.hpp"
#include "list.hpp"
#include "util.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#define EXIT_SUCCESS 0
#include<string>

using namespace std;

//estructura provisoria para cargar el reporte de vinos
typedef struct r1{
int id;
int cant=0;
};





//test function para cargar TDA desde un string de archivo (mover a su propia libreria)
void loadUser(Usuario &user, string text)
{
	string aux;
	bool isIdSet = false;
	bool isNameSet = false;
	bool isAddressSet = false;
	bool isAgeSet = false;

	for (int i = 0; i < text.length(); i++)
	{
		if ((text.at(i) == '-') or (text.at(i) == ';'))
		{
            trim(aux);

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
				isAgeSet = true;

				setAge(user, stoi(aux));
			}

			aux = "";
		}
		else
		{
			aux = aux + text.at(i);
		}

	}

}

//test function para leer archivo de usuarios
void readUsers()
{
	string text;
	ifstream file("data/usuarios.txt");

	while(getline(file, text))
	{
		Usuario* tempUser = new Usuario;

		loadUser(*tempUser, text);
		cout << tempUser->sName << endl;
		cout << tempUser->iAge << endl;

		delete tempUser;
	}

	file.close();
}


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
    bool isTerroirSet = false;

	for (int i = 0; i < text.length(); i++)
	{
		if ((text.at(i) == '-') or (text.at(i) == ';'))
		{
            trim(aux);

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
			else {
                isTerroirSet =true;
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

//test function para leer archivo de vinos
void readWines()
{
	string text;
	ifstream file("data/vinos.txt"); //prestar atencion al nombre del archivo

	while(getline(file, text))
	{
		Vino* tempVino = new Vino;

		loadWine(*tempVino, text);
		cout << tempVino->id << endl;
		cout << tempVino->sLabel << endl;

		delete tempVino;
	}

	file.close();
}



// TDA de Seleccion, me quedé en el seteo de vinos

void loadSeleccion(Seleccion &seleccion, string text)
{
    string aux;
	bool isIdSet = false;
	bool isMonthSet = false;
	bool isYearSet = false;
	bool isWineSet1 = false;
	bool isWineSet2 = false;
	bool isWineSet3 = false;
	bool isWineSet4 = false;
	bool isWineSet5 = false;
	bool isWineSet6 = false;


	for (int i = 0; i < text.length(); i++)
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
				setMonth(seleccion, stoi(aux));
			}
			else if(!isYearSet)
			{
				isYearSet = true;

				setYear(seleccion, stoi(aux));
			}
			else if (!isWineSet1)
            {
                isWineSet1 =true;
                setVino1(seleccion, stoi(aux));
            }
            else if (!isWineSet2)
            {
                isWineSet2 =true;
                setVino2(seleccion, stoi(aux));
            }
            else if (!isWineSet3)
            {
                isWineSet3 =true;
                setVino3(seleccion, stoi(aux));
            }
            else if (!isWineSet4)
            {
                isWineSet4 =true;
                setVino4(seleccion, stoi(aux));
            }
            else if (!isWineSet5)
            {
                isWineSet5 =true;
                setVino5(seleccion, stoi(aux));
            }
            else
            {
                isWineSet6 =true;
                setVino6(seleccion, stoi(aux));
            }


			aux = "";
		}
		else
		{
			aux = aux + text.at(i);
		}

	}

}

void readSeleccion()
{
	string text;
	ifstream file("data/seleccion.txt");
    int cont=0;
	while(getline(file, text))
	{
		Seleccion* tempSeleccion = new Seleccion;


		loadSeleccion(*tempSeleccion, text);
		cout << tempSeleccion->id << endl;
		cout << tempSeleccion->year << endl;

		//cont++;
		delete tempSeleccion;
	}

	file.close();

}
int readCantWines()
{
	int cont=0;
	string text;
	ifstream file("data/vinos.txt"); //prestar atencion al nombre del archivo

	while(getline(file, text))
	{
		Vino* tempVino = new Vino;

		loadWine(*tempVino, text);
		cont++;
		delete tempVino;
	}

	file.close();
	return cont;
}


void ordenarArray(r1 miArray[]){
	r1 temporal;

	for (int i = 0;i < 14; i++){
		for (int j = 0; j< 14-1; j++){
			if (miArray[j].cant < miArray[j+1].cant){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
			temporal = miArray[j];
			miArray[j] = miArray[j+1];
			miArray[j+1] = temporal;
			}
		}
	}
}

void rankingYear(int y){

    int cant=readCantWines();
 cout<< "cantidad de filas: "<<cant<<endl;
    r1 *arregloStructWines = new r1[cant];

    int i=0;
    string text;
	ifstream file("data/vinos.txt");

        while(getline(file, text)){

		Vino* tempVino = new Vino;

		loadWine(*tempVino, text);


                cout<<"Estoy en i="<<i<<endl;
		arregloStructWines[i]= {tempVino->id,0} ;
		i++;

		delete tempVino;

    }

    cout<<"***Arreglo de vinos creado***"<<endl;
    for (int i=0;i<cant;i++){
        cout << arregloStructWines[i].id <<" " <<arregloStructWines[i].cant<<endl;
    }
    file.close();

    //cargo el archivo de seleccion para llenar el arreglo
    string text2;
	ifstream file2("data/seleccion.txt");







	while(getline(file2, text2))
	{
		Seleccion* tempSeleccion = new Seleccion;
		loadSeleccion(*tempSeleccion, text2);

		if (tempSeleccion->year==y){
                for (int j=0;j<cant;j++){
                        //cout<<"Estoy en j="<<j<<endl;
                    if (arregloStructWines[j].id==tempSeleccion->wine1){
                        arregloStructWines[j].cant++;
                    }
                    else if (arregloStructWines[j].id==tempSeleccion->wine2){
                        arregloStructWines[j].cant++;
                    }
                    if (arregloStructWines[j].id==tempSeleccion->wine3){
                        arregloStructWines[j].cant++;
                    }
                    else if (arregloStructWines[j].id==tempSeleccion->wine4){
                        arregloStructWines[j].cant++;
                    }
                    if (arregloStructWines[j].id==tempSeleccion->wine5){
                        arregloStructWines[j].cant++;
                    }
                    else if(arregloStructWines[j].id==tempSeleccion->wine6){
                        arregloStructWines[j].cant++;
                    }
                }

		}


		delete tempSeleccion;

	}
    cout<<"***Arreglo de vinos cargado***"<<endl;
    for (int i=0;i<cant;i++){
            if(arregloStructWines[i].cant!=0)
        cout << arregloStructWines[i].id <<" " <<arregloStructWines[i].cant<<endl;
    }
    ordenarArray(arregloStructWines);

    cout<<"***Arreglo de vinos ordenado***"<<endl;
    for (int i=0;i<cant;i++){
            if(arregloStructWines[i].cant!=0)
        cout << arregloStructWines[i].id <<" " <<arregloStructWines[i].cant<<endl;
    }
	file2.close();


}



void llamarMenu(){

    char opc; // modifique por un char para que no tire error en caso de seleccionar una letra
    int year=0;
	while(1){

		cout<<"*****Bienvenido al Sistema De Gestion de Membresia para vinos.******\n"<<endl;
		cout<<"1-Ranking general de vinos seleccionados en el ultimo año."<<endl;
		cout<<"2-Ranking por bodegas elegidas en el ultimo año."<<endl;
		cout<<"3-Ranking de varietales elegidos por rango etario."<<endl;
		cout<<"4-Llamar readUsers"<<endl;
		cout<<"5-Llamar readWines"<<endl;
		cout<<"6-Llamar readSeleccion"<<endl;
		cout<<"7-Salir."<<endl;

		cin>>opc;

		switch (opc){
			case '1':

            cout<< "ingrese año que desee calcular: ";
            cin>>year;

           rankingYear(year);
           //rankingYear();
			break;
			case '2':
				cout<<"Funcion RANKING POR BODEGAS"<<endl;
				break;
			case '3':
				cout<<"Funcion RANKING VARIETALES"<<endl;
				break;
			case '4':
				readUsers();
				break;
			case '5':
                readWines();
                break;
			case '6':
		    readSeleccion();
			    break;
            case '7':
				exit(EXIT_SUCCESS);
            default:
                cout<<"Ingrese una opcion correcta"<<endl; break;
		}
	}
}


int main()
{
    llamarMenu();

    return 0;
}
