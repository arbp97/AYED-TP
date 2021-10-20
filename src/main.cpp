#include "usuario.hpp"
#include "vino.hpp"
#include "seleccion.hpp"
#include "list.hpp"
#include "util.hpp"
#include "files.hpp"
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
/*
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
*/

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
/*
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
*/


void llamarMenu(){

    char opc; // modifique por un char para que no tire error en caso de seleccionar una letra
    int year=0;
	while(1){

		cout<<"*****Bienvenido al Sistema De Gestion de Membresia para vinos.******\n"<<endl;
		cout<<"1-Ranking general de vinos seleccionados en el ultimo a�o."<<endl;
		cout<<"2-Ranking por bodegas elegidas en el ultimo a�o."<<endl;
		cout<<"3-Ranking de varietales elegidos por rango etario."<<endl;
		cout<<"4-Llamar readUsers"<<endl;
		cout<<"5-Llamar readWines"<<endl;
		cout<<"6-Llamar readSeleccion"<<endl;
		cout<<"7-Salir."<<endl;

		cin>>opc;

		switch (opc){
			case '1':

            cout<< "ingrese a�o que desee calcular: ";
            cin>>year;

          // rankingYear(year);
           //rankingYear();
			break;
			case '2':
				cout<<"Funcion RANKING POR BODEGAS"<<endl;
				break;
			case '3':
				cout<<"Funcion RANKING VARIETALES"<<endl;
				break;
			case '4':
				//readUsers();
				break;
			case '5':
               // readWines();
                break;
			case '6':
		    //readSeleccion();
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
	List listUsuarios;
	List listVinos;
	List listSeleccion;

	Node* cursor = new Node;

    readUsers(listUsuarios);
	readWines(listVinos);
	readSeleccion(listSeleccion);

	//cargando las selecciones por completo (con readSeleccion solo queda el id)
	Seleccion* ptrSeleccion = new Seleccion;
    cursor = listSeleccion.head;

    while (cursor != NULL)
    {
        ptrSeleccion = (Seleccion*) cursor->ptrData;

		cursor->ptrData = findWineById(listVinos, ptrSeleccion->id);

		cout << ptrSeleccion->year << endl;

        cursor = cursor->next;
    }


	Usuario* ptrUsuarioTest = new Usuario;
    cursor = listUsuarios.head;

    while (cursor != NULL)
    {
        ptrUsuarioTest = (Usuario*) cursor->ptrData;

		cout << ptrUsuarioTest->sName << endl;

        cursor = cursor->next;
    }

    getchar();

    llamarMenu();

    return 0;
}
