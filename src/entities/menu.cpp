
#include "../headers/menu.hpp"
#include <iostream>
#include "../headers/util.hpp"
using namespace std;


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
                rankingYear();
                break;
			case '2':
				rankingCellar();
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
