#include "usuario.hpp"
#include "vino.hpp"
#include "seleccion.hpp"
#include "list.hpp"
#include <iostream>
#include <cstdlib>
#define EXIT_SUCCESS 0

using namespace std;


void llamarMenu(){
	
    int opc=0;
	
	while(1){
		
		cout<<"*****Bienvenido al Sistema De Gestion de Membresia para vinos.******\n"<<endl;
		cout<<"1-Ranking general de vinos seleccionados en el ultimo año."<<endl;
		cout<<"2-Ranking por bodegas elegidas en el ultimo año."<<endl;
		cout<<"3-Ranking de varietales elegidos por rango etario."<<endl;
		cout<<"4-Salir."<<endl;
		cin>>opc;

		switch (opc){
			case 1:
				cout<<"Funcion RANKING GENERAL"<<endl;
				break;
			case 2:
				cout<<"Funcion RANKING POR BODEGAS"<<endl;
				break;
			case 3:
				cout<<"Funcion RANKING VARIETALES"<<endl;
				break;
			case 4:
				exit(EXIT_SUCCESS);
		}
	}
}

int main()
{
    llamarMenu();
	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

    Usuario* usuario = new Usuario;

    createUsuario(*usuario, 1, "Alan", 21, "Micasa");

    cout << getName(*usuario) << endl;

    setName(*usuario, "Rob");

    cout << getName(*usuario) << endl;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

	Vino* vino_1 = new Vino;

	createVino(*vino_1, 1, "Malbec", "Villa Tintos", "Tinto", "Malbec", 2018, "Tierrita sabrosa");

	cout << getLabel(*vino_1) << endl;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

	Vino vinitos[6];

	vinitos[0] = *vino_1;

	Seleccion* seleccion = new Seleccion;

	createSeleccion(*seleccion, getId(*usuario), SEPTIEMBRE, 2021, vinitos);

	cout << getLabel(*(getVinos(*seleccion))) << endl;

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

	cout << "\n\n\n" << endl;

	List list;

	Usuario* usuario2 = new Usuario;

    createUsuario(*usuario2, 2, "Ramon", 21, "Micasa");

	addNode(list, usuario);
	addNode(list, usuario2);

	Node* cursor = new Node;
	Usuario* ptrUsuario = new Usuario;
    cursor = list.head;

    while (cursor != NULL)
    {
        ptrUsuario = (Usuario*) cursor->ptrData;

		cout << ptrUsuario->sName << endl;

        cursor = cursor->next;
    }
	
	cout << "probando deleteNode (enter)" << endl;
	getchar();
	
	cursor = list.head;
	
	deleteNode(list, aux);
	
	while (cursor != NULL)
    {
        ptrUsuario = (Usuario*) cursor->ptrData;
		
		cout << ptrUsuario->sName << endl;
		
		aux = cursor;
        cursor = cursor->next;
    }

    return 0;
}


