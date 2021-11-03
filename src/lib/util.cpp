#include "../headers/util.hpp"
#include "../headers/files.hpp"
#include<conio.h>
/* Implementacion de primitivas*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from start (in place)
void leftTrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from end (in place)
void rightTrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from both ends (in place)
void trim(std::string &s) {
    leftTrim(s);
    rightTrim(s);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


int contieneElemento(int matriz[][2], int elemento){
    int val=-1;
    int filas = sizeof (matriz)/sizeof (matriz[0]);
  //  int columnas = (sizeof(matriz[0])/sizeof(matriz[0][0]))
    for (int i=0;i<=filas;i++){
        if(matriz[i][0]==elemento) {val=i;}
    }

    return val;

}

void agregoElemento(int matriz[][2], int elemento){
    int filas = sizeof(matriz)/sizeof(matriz[0]);
    //int columnas = sizeof(matriz[0])/sizeof(int);
    if(contieneElemento(matriz,elemento)==-1){
            matriz[filas+1][1]=1;
    }
    else matriz[contieneElemento(matriz,elemento)][1]++;

    }





void mostrarElementos(int matriz[][2]){
    int filas = (sizeof(matriz)/sizeof(matriz[0]));
    //int columnas = (sizeof(&matriz[0])/sizeof(int));
    for (int i=0;i<=filas;i++){
            for(int j=0;j<2;j++){

            std::cout<<matriz[i][j]<<std::endl;
            }


    }
}

Vino* findWineById(List wines, int id)
{
    bool found = false;
    Node* cursor = new Node;
	Node* aux = new Node;
	Vino* ptrVino = new Vino;
    cursor = wines.head;

    while (cursor != NULL || found)
    {
        ptrVino = (Vino*) cursor->ptrData;

        if (ptrVino->id == id)
        {
           found = true;
        }

		aux = cursor;
        cursor = cursor->next;
    }

    return ptrVino;
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

void ordenarArrayAlfabeticamente(r1 miArray[]){
	r1 temporal;

	for (int i = 0;i < 14; i++){
		for (int j = 0; j< 14-1; j++){
			if (miArray[j].sCellar > miArray[j+1].sCellar){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
			temporal = miArray[j];
			miArray[j] = miArray[j+1];
			miArray[j+1] = temporal;
			}
		}
	}
}

void rankingYear()
{
	List listUsuarios;
	List listVinos;
	List listSeleccion;

	Node* cursor1 = new Node; //Nodo lista vinos


    readUsers(listUsuarios);
	readWines(listVinos);
	readSeleccion(listSeleccion);
    //tamaño de mi array
	int cant=length(listVinos);
	cout << "Tamaño de la lista "<<cant<<endl;
	//arreglo para el reporte
	r1 *arregloStructWines = new r1[cant];


    Vino* ptrVino = new Vino;
    cursor1 = listVinos.head;
    int v=0;
    while (cursor1 != NULL)   //leo lista de vinos y cargo arreglo de reporte
    {
        ptrVino = (Vino*) cursor1->ptrData;
        cout << ptrVino->id <<endl;
        //cursor1->ptrData = findWineById(listVinos, ptrVino->id);
        arregloStructWines[v]={ptrVino->id,ptrVino->sLabel,0};
        //cout <<arregloStructWines[v].id << " " << arregloStructWines[v].cant <<endl;
        v++;
        cursor1 = cursor1->next;

    }

    // imprimo para validar que esté cargado el arreglo
    for (int i=0;i<cant;i++){
        cout <<arregloStructWines[i].id << " " << arregloStructWines[i].nombre<< " "<<arregloStructWines[i].cant <<endl;
    }
    Node* cursor = new Node;
	Seleccion* ptrSeleccion = new Seleccion;
    cursor = listSeleccion.head;
    int i=0;
    while (cursor != NULL)
    {
        ptrSeleccion = (Seleccion*) cursor->ptrData;

		cursor->ptrData = findWineById(listVinos, ptrSeleccion->id);




		if( ptrSeleccion->year==2021){ //valido año
		    for (int i=0;i<cant;i++){
                for(int j=0;j<6;j++){
                        if (ptrSeleccion->wines[j].id==arregloStructWines[i].id) //valido id de seleccion sea igual al id del arreglo
                            arregloStructWines[i].cant++;
		    }

		    }



    }cursor = cursor->next;
}
ordenarArray(arregloStructWines);
// imprimo para validar que esté cargado y ordenado

cout << "************ ARREGLO CARGADO Y ORDENADO *****************" <<endl;
    for (int i=0;i<cant;i++){
            if(arregloStructWines[i].id>0)
        cout <<arregloStructWines[i].id << " " << arregloStructWines[i].nombre<< " "<<arregloStructWines[i].cant <<endl;
    }
/* //LISTA DE USUARIOS

	Usuario* ptrUsuarioTest = new Usuario;
    cursor = listUsuarios.head;

    while (cursor != NULL)
    {
        ptrUsuarioTest = (Usuario*) cursor->ptrData;

		cout << ptrUsuarioTest->sName << endl;

        cursor = cursor->next;
    }*/

    cout<<"Pulse una tecla para continuar";
    getch();
}

void rankingCellar(){

	List listUsuarios;
	List listVinos;
	List listSeleccion;

	Node* cursor1 = new Node; //Nodo lista vinos


    readUsers(listUsuarios);
	readWines(listVinos);
	readSeleccion(listSeleccion);
    //tamaño de mi array
	int cant=length(listVinos);
	cout << "Tamaño de la lista "<<cant<<endl;
	//arreglo para el reporte
	r1 *arregloStructWines = new r1[cant];
	r1 *arregloStructWinesFinal = new r1[cant];


    Vino* ptrVino = new Vino;
    cursor1 = listVinos.head;
    int v=0;
    while (cursor1 != NULL)   //leo lista de vinos y cargo arreglo de reporte
    {
        ptrVino = (Vino*) cursor1->ptrData;
        cout << ptrVino->id <<endl;
        //cursor1->ptrData = findWineById(listVinos, ptrVino->id);
        arregloStructWines[v]={ptrVino->id,ptrVino->sLabel,0,ptrVino->sCellar};
        //cout <<arregloStructWines[v].id << " " << arregloStructWines[v].cant <<endl;
        v++;
        cursor1 = cursor1->next;
    }

    // imprimo para validar que esté cargado el arreglo
    for (int i=0;i<cant;i++){
        cout <<arregloStructWines[i].id << " " << arregloStructWines[i].nombre<< " "<<arregloStructWines[i].cant <<endl;
    }
    Node* cursor = new Node;
	Seleccion* ptrSeleccion = new Seleccion;
    cursor = listSeleccion.head;
    while (cursor != NULL)
    {
        ptrSeleccion = (Seleccion*) cursor->ptrData;

		cursor->ptrData = findWineById(listVinos, ptrSeleccion->id);




		if( ptrSeleccion->year==2021){ //valido año
		    for (int i=0;i<cant;i++){
                for(int j=0;j<6;j++){
                        if (ptrSeleccion->wines[j].id==arregloStructWines[i].id) //valido id de seleccion sea igual al id del arreglo
                            arregloStructWines[i].cant++;
		    }

		    }



    }cursor = cursor->next;
}
ordenarArray(arregloStructWines);
// imprimo para validar que esté cargado y ordenado

cout << "************ ARREGLO CARGADO Y ORDENADO *****************" <<endl;
    for (int i=0;i<cant;i++){
            if(arregloStructWines[i].id>0)
        cout <<arregloStructWines[i].id << " " << arregloStructWines[i].nombre<< " "<<arregloStructWines[i].cant <<endl;
    }
    ordenarArrayAlfabeticamente(arregloStructWines);

    cout<<"***Arreglo de vinos ordenado por bodega***"<<endl;
    for (int i=0;i<cant;i++){
            if(arregloStructWines[i].cant!=0)
        cout << arregloStructWines[i].id <<" " <<arregloStructWines[i].sCellar<<" " <<arregloStructWines[i].cant<<endl;
    }


    string auxCellar;
    for (int i=0;i<cant;i++){
            if  (arregloStructWines[i].sCellar!=auxCellar){
                auxCellar=arregloStructWines[i].sCellar;
            }
            else{
                arregloStructWines[i].cant=arregloStructWines[i].cant+arregloStructWines[i-1].cant;
            }

            cout << arregloStructWines[i].id <<" "<< arregloStructWines[i].sCellar <<" " <<arregloStructWines[i].cant<<endl;
    }

    for(int i=0;i<cant;i++){
        if(arregloStructWines[i].sCellar!=arregloStructWines[i-1].sCellar){
            arregloStructWinesFinal[i]=arregloStructWines[i-1];
            //cout << arregloStructWines[i-1].id <<" "<< arregloStructWines[i-1].sCellar <<" " <<arregloStructWines[i-1].cant<<endl;
        }
    }
    arregloStructWinesFinal[cant-1]=arregloStructWines[cant-1];

        cout<<" "<<endl;
        cout<<"***Arreglo de bodegas***"<<endl;
    ordenarArray(arregloStructWinesFinal);
    for(int i=0;i<cant;i++){
            if(arregloStructWinesFinal[i].cant!=0){
        cout<<arregloStructWinesFinal[i].id <<" "<<arregloStructWinesFinal[i].sCellar <<" " <<arregloStructWinesFinal[i].cant<<endl;
            }
    }
    cout<<"Pulse una tecla para continuar";
    getch();

}

/*
void mostrarMatriz(int **punteroM){
    for (int i=0;i<cantiFilasMatriz(punteroM)+1;i++){
        for(int j=0;j<2;j++){
            std::cout<<punteroM[i][j];
        }
    }


}
*/
/*void agrandarMatriz(int &punteroM){

    int **puntero2,fila, col;
    fila=cantiFilasMatriz(punteroM)+1;
    std::cout<<fila;
    col=2;
    puntero2 = new int*[fila];
    for (int i=0;i<fila;i++){
        puntero2[i]=new int[col];
    }
    std::cout<<sizeof(puntero2)<<std::endl;
    std::cout<<sizeof(punteroM)<<std::endl;
    memcpy(&puntero2,&punteroM,sizeof(punteroM));
       delete &punteroM;
       std::cout<<sizeof(punteroM)<<std::endl;

           punteroM = **puntero2;

           std::cout<<sizeof(punteroM)<<std::endl;
}

*/
