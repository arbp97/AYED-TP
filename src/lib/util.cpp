#include "../headers/util.hpp"
#include "../headers/files.hpp"

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


Vino* findWineById(List wines, int id)
{
    bool found = false;
    Node* cursor = new Node;
	Vino* ptrVino = new Vino;
    cursor = wines.head;

    while ((cursor != NULL) && !found)
    {
        ptrVino = (Vino*) cursor->ptrData;

        if (ptrVino->id == id)
        {
            found = true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return ptrVino;
}


Usuario* findUserById(List users, int id)
{
    bool found = false;
    Node* cursor = new Node;
	Usuario* ptrUser = new Usuario;
    cursor = users.head;

    while ((cursor != NULL) && !found)
    {
        ptrUser = (Usuario*) cursor->ptrData;

        if (ptrUser->id == id)
        {
           found = true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return ptrUser;
}

int maxYear(List listSeleccion){
    Node* cursor = new Node;
	Seleccion* ptrSeleccion = new Seleccion;
    cursor = listSeleccion.head;
    int max=0;
    while (cursor != NULL)
    {
        ptrSeleccion = (Seleccion*) cursor->ptrData;

		if( ptrSeleccion->year>max){ //valido año
		    max=ptrSeleccion->year;
		}
		cursor = cursor->next;
    }
return max;
}


void ordenarArray(WineAndQuantityStruct miArray[], int tamanio){
	WineAndQuantityStruct temporal;

	for (int i = 0;i < tamanio; i++){
		for (int j = 0; j< tamanio-1; j++){
			if (miArray[j].cant < miArray[j+1].cant){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
			temporal = miArray[j];
			miArray[j] = miArray[j+1];
			miArray[j+1] = temporal;
			}
		}
	}
}

//ordena una lista de varietales auxiliar de mayor a menor (WORK IN PROGRESS)
void orderListStrains(List listStrains)
{
    Node* cursor = new Node;
    cursor = listStrains.head;
	StrainAndQuantityStruct* ptrStrain = new StrainAndQuantityStruct;
    Node* temp = new Node;

	while (cursor != NULL) //recorre hasta el ultimo elemento
    {
        temp = cursor;

        while(temp->next != NULL) //recorre hasta el segundo ultimo elemento
        {
            if(((StrainAndQuantityStruct*) temp->ptrData)->cant >
             ((StrainAndQuantityStruct*) temp->next->ptrData)->cant)
            {
                ptrStrain = (StrainAndQuantityStruct*) temp->ptrData;
                temp->ptrData = temp->next->ptrData;
                temp->next->ptrData = ptrStrain;
            }

            temp = temp->next;
        }

        cursor = cursor->next;
    }

}

void ordenarArrayAlfabeticamente(WineAndQuantityStruct miArray[], int tamanio){
	WineAndQuantityStruct temporal;

	for (int i = 0;i < tamanio; i++){
		for (int j = 0; j< tamanio-1; j++){
			if (miArray[j].sCellar > miArray[j+1].sCellar){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
			temporal = miArray[j];
			miArray[j] = miArray[j+1];
			miArray[j+1] = temporal;
			}
		}
	}
}


void rankingAnualDeVinos(List listVinos, List listSeleccion)
{
	Node* cursor = new Node; //Nodo lista vinos

    int max=maxYear(listSeleccion); //año maximo

    //tamaño de mi array
	int cant=length(listVinos);

	//arreglo para el reporte
	WineAndQuantityStruct *arregloStructWines = new WineAndQuantityStruct[cant];


    Vino* ptrVino = new Vino;
    cursor = listVinos.head;
    int v=0;
    while (cursor != NULL)   //leo lista de vinos y cargo arreglo de reporte
    {
        ptrVino = (Vino*) cursor->ptrData;

        arregloStructWines[v]={ptrVino->id,ptrVino->sLabel,0};
        v++;
        cursor = cursor->next;

    }

	Seleccion* ptrSeleccion = new Seleccion;
    cursor = listSeleccion.head;

    while (cursor != NULL)
    {
        ptrSeleccion = (Seleccion*) cursor->ptrData;

		if( ptrSeleccion->year==max){ //valido año

		    for (size_t i=0;i<cant;i++){

                for(size_t j=0;j<WINE_QTY;j++){
                        if (ptrSeleccion->wines[j].id==arregloStructWines[i].id) //valido id de seleccion sea igual al id del arreglo
                            arregloStructWines[i].cant++;
		        }

		    }

        }

        cursor = cursor->next;
    }

    ordenarArray(arregloStructWines, cant);
    // imprimo para validar que esté cargado y ordenado

    cout << "************ ARREGLO CARGADO Y ORDENADO *****************" <<endl;

    for (int i=0;i<cant;i++){
            if(arregloStructWines[i].id>0)
        cout <<arregloStructWines[i].id << " " << arregloStructWines[i].nombre<< " "<<arregloStructWines[i].cant <<endl;
    }

    cout<<"Pulse una tecla para continuar" << endl;

    getchar();
}

void rankingAnualDeBodegas(List listVinos, List listSeleccion){

	Node* cursor = new Node; //Nodo lista vinos

    //tamaño de mi array
	int cant=length(listVinos);

	//arreglo para el reporte
	WineAndQuantityStruct *arregloStructWines = new WineAndQuantityStruct[cant];
	WineAndQuantityStruct *arregloStructWinesFinal = new WineAndQuantityStruct[cant];


    Vino* ptrVino = new Vino;
    cursor = listVinos.head;
    int v=0;
    while (cursor != NULL)   //leo lista de vinos y cargo arreglo de reporte
    {
        ptrVino = (Vino*) cursor->ptrData;

        arregloStructWines[v]={ptrVino->id,ptrVino->sLabel,0,ptrVino->sCellar};

        v++;
        cursor = cursor->next;

    }

	Seleccion* ptrSeleccion = new Seleccion;
    cursor = listSeleccion.head;

    while (cursor != NULL)
    {
        ptrSeleccion = (Seleccion*) cursor->ptrData;

		if( ptrSeleccion->year==maxYear(listSeleccion)){ //valido año

		    for (size_t i=0;i<cant;i++){

                for(size_t j=0;j<WINE_QTY;j++){
                        if (ptrSeleccion->wines[j].id==arregloStructWines[i].id) //valido id de seleccion sea igual al id del arreglo
                            arregloStructWines[i].cant++;
		        }

		    }

        }

        cursor = cursor->next;
    }

    ordenarArray(arregloStructWines, cant);
    // imprimo para validar que esté cargado y ordenado

    cout << "************ ARREGLO CARGADO Y ORDENADO *****************" <<endl;

    for (size_t i=0;i<cant;i++){
            if(arregloStructWines[i].id>0)
        cout <<arregloStructWines[i].id << " " << arregloStructWines[i].sCellar<< " "<<arregloStructWines[i].cant <<endl;
    }
    ordenarArrayAlfabeticamente(arregloStructWines, cant);

    cout<<"***Arreglo de vinos ordenado por bodega***"<<endl;
    for (size_t i=0;i<cant;i++){
            if(arregloStructWines[i].cant!=0)
        cout << arregloStructWines[i].id <<" " <<arregloStructWines[i].sCellar<<" " <<arregloStructWines[i].cant<<endl;
    }


    string auxCellar;
    for (size_t i=0;i<cant;i++){
            if  (arregloStructWines[i].sCellar!=auxCellar){
                auxCellar=arregloStructWines[i].sCellar;
            }
            else{
                arregloStructWines[i].cant=arregloStructWines[i].cant+arregloStructWines[i-1].cant;
            }

           // cout << arregloStructWines[i].id <<" "<< arregloStructWines[i].sCellar <<" " <<arregloStructWines[i].cant<<endl;
    }

    for(size_t i=0;i<cant;i++){
        if(arregloStructWines[i].sCellar!=arregloStructWines[i-1].sCellar){
            arregloStructWinesFinal[i]=arregloStructWines[i-1];
            //cout << arregloStructWines[i-1].id <<" "<< arregloStructWines[i-1].sCellar <<" " <<arregloStructWines[i-1].cant<<endl;
        }
    }
    arregloStructWinesFinal[cant-1]=arregloStructWines[cant-1];

        cout<<" "<<endl;
        cout<<"***Arreglo de bodegas***"<<endl;
    ordenarArray(arregloStructWinesFinal, cant);
    for(size_t i=0;i<cant;i++){
            if(arregloStructWinesFinal[i].cant!=0){
        cout<<arregloStructWinesFinal[i].id <<" "<<arregloStructWinesFinal[i].sCellar <<" " <<arregloStructWinesFinal[i].cant<<endl;
            }
    }
    cout<<"Pulse una tecla para continuar";
    getchar();

}


// R3

//revisa si ya existe el varietal en una lista auxiliar de varietales
bool isStrainInWinesList(List listVinosAux, string strain)
{
    bool answer = false;
    Node* cursor = new Node;
    cursor = listVinosAux.head;
    StrainAndQuantityStruct* ptrStrain = new StrainAndQuantityStruct;

    while (cursor != NULL && !answer)
    {
       ptrStrain = (StrainAndQuantityStruct*) cursor->ptrData;

       if(ptrStrain->sStrain == strain)
       {
           answer = true;
       }
        cursor = cursor->next;
    }

    return answer;
}

//encuentra y devuelve en varietal en una lista auxiliar de varietales
StrainAndQuantityStruct* findWineStructByStrain(List listVinosAux, string strain)
{
    bool found = false;
    Node* cursor = new Node;
	StrainAndQuantityStruct* ptrStrain = new StrainAndQuantityStruct;
    cursor = listVinosAux.head;

    while ((cursor != NULL) && !found)
    {
        ptrStrain = (StrainAndQuantityStruct*) cursor->ptrData;

        if (ptrStrain->sStrain == strain)
        {
           found = true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return ptrStrain;
}

void rankingVarietalPorEdad(List listUsuarios, List listVinos, List listSeleccion)
{
    List listMenosDe30;
    List listEntre30y50;
    List listMasDe50;

    // se cuenta la cantidad de varietales
    Node* cursor = new Node;
    cursor = listVinos.head;
    Vino* ptrVino = new Vino;
    string strainAux = "startFlag";
    int year = maxYear(listSeleccion);

    while (cursor != NULL)
    {
        ptrVino = (Vino*) cursor->ptrData;

        //cuando inicia el bucle
        if(strainAux == "startFlag")
        {
            strainAux = ptrVino->sStrain;
        }

        //si la uva no esta en las listas entonces se agrega
        else if(!isStrainInWinesList(listMenosDe30, ptrVino->sStrain))
        {
            StrainAndQuantityStruct* newStruct_1 = new StrainAndQuantityStruct;
            StrainAndQuantityStruct* newStruct_2 = new StrainAndQuantityStruct;
            StrainAndQuantityStruct* newStruct_3 = new StrainAndQuantityStruct;

            newStruct_1->sStrain = ptrVino->sStrain;
            newStruct_2->sStrain = ptrVino->sStrain;
            newStruct_3->sStrain = ptrVino->sStrain;

            addNode(listEntre30y50, newStruct_1);
            addNode(listMenosDe30, newStruct_2);
            addNode(listMasDe50, newStruct_3);
        }

        strainAux = ptrVino->sStrain;

        cursor = cursor->next;
    }

    // ahora toca acomodar la cantidad de varietales en sus listas por edad de usuario

    cursor = listSeleccion.head;
    Seleccion* ptrSeleccion = new Seleccion;
    Usuario* ptrUsuario = new Usuario;
    Node* cursorStrains = new Node;
    StrainAndQuantityStruct* ptrStrain = new StrainAndQuantityStruct;


    while(cursor != NULL) //recorre todas las selecciones
    {
        ptrSeleccion = (Seleccion*) cursor->ptrData;

        ptrUsuario = findUserById(listUsuarios, ptrSeleccion->id);

        for (size_t i = 0; i < WINE_QTY; i++) //recorre todos los vinos de la seleccion
        {
            if(ptrSeleccion->year == year)
            {
                if (ptrUsuario->iAge < 30)
                {
                    findWineStructByStrain(listMenosDe30,ptrSeleccion->wines[i].sStrain)->cant++;
                }
                else if((ptrUsuario->iAge > 30) && (ptrUsuario->iAge < 50))
                {
                    findWineStructByStrain(listEntre30y50,ptrSeleccion->wines[i].sStrain)->cant++;
                }
                else
                {
                    findWineStructByStrain(listMasDe50,ptrSeleccion->wines[i].sStrain)->cant++;
                }
            }

        }

        cursor = cursor->next;
    }

    std::cout << "MENOS DE 30" << std::endl;
    orderListStrains(listMenosDe30);
    cursorStrains = listMenosDe30.head;

    while (cursorStrains != NULL)
    {
        ptrStrain = (StrainAndQuantityStruct*) cursorStrains->ptrData;
        std::cout << ptrStrain->sStrain << " - " << ptrStrain->cant << std::endl;
        cursorStrains = cursorStrains->next;
    }

    std::cout << "ENTRE 30 Y 50" << std::endl;
    orderListStrains(listEntre30y50);
    cursorStrains = listEntre30y50.head;

    while (cursorStrains != NULL)
    {
        ptrStrain = (StrainAndQuantityStruct*) cursorStrains->ptrData;
        std::cout << ptrStrain->sStrain << " - " << ptrStrain->cant << std::endl;
        cursorStrains = cursorStrains->next;
    }

    std::cout << "MAS DE 50" << std::endl;
    orderListStrains(listMasDe50);
    cursorStrains = listMasDe50.head;

    while (cursorStrains != NULL)
    {
        ptrStrain = (StrainAndQuantityStruct*) cursorStrains->ptrData;
        std::cout << ptrStrain->sStrain << " - " << ptrStrain->cant << std::endl;
        cursorStrains = cursorStrains->next;
    }

    cout<<"Pulse una tecla para continuar" << endl;
    getchar();
}
