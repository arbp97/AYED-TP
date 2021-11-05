#include "headers/usuario.hpp"
#include "headers/vino.hpp"
#include "headers/seleccion.hpp"
#include "headers/list.hpp"
#include "headers/util.hpp"
#include "headers/files.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#define EXIT_SUCCESS 0
#include<string>


using namespace std;

void menu(List listUsuarios,List listVinos,List listSeleccion);

//limpia la pantalla en la consola (LINUX)
void clearScreen();

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

        //se cargan los vinos de la seleccion
        for (size_t i = 0; i < WINE_QTY; i++)
            ptrSeleccion->wines[i] = *findWineById(listVinos, ptrSeleccion->wines[i].id);

        //se guarda la nueva informacion
        cursor->ptrData = ptrSeleccion;

        cursor = cursor->next;
    }

    menu(listUsuarios, listVinos, listSeleccion);

    return 0;
}

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

void menu(List listUsuarios,List listVinos,List listSeleccion){

    char opc; // modifique por un char para que no tire error en caso de seleccionar una letra
	while(1){

		clearScreen();

		cout<<"\n*****Bienvenido al Sistema De Gestion de Membresia para vinos.******\n"<<endl;
		cout<<"1-Ranking general de vinos seleccionados en el ultimo año."<<endl;
		cout<<"2-Ranking por bodegas elegidas en el ultimo año."<<endl;
		cout<<"3-Ranking de varietales elegidos por rango etario."<<endl;
		cout<<"4-Salir."<<endl;

		cin>>opc;

		switch (opc){
			case '1':
                rankingAnualDeVinos(listVinos, listSeleccion);
                break;
			case '2':
				rankingAnualDeBodegas(listVinos, listSeleccion);
				break;
			case '3':
				rankingVarietalPorEdad(listUsuarios, listVinos, listSeleccion);
				break;
            case '4':
				exit(EXIT_SUCCESS);
            default:
                cout<<"Ingrese una opcion correcta"<<endl; break;
		}
	}
}

