#include "../headers/util.hpp"
#include "../headers/files.hpp"
#include <iomanip>

/* Implementacion de primitivas*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from start (in place)
void leftTrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                    { return !std::isspace(ch); }));
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from end (in place)
void rightTrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); })
                .base(),
            s.end());
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// trim from both ends (in place)
void trim(std::string &s)
{
    leftTrim(s);
    rightTrim(s);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

Vino *findWineById(List wines, int id)
{
    bool found = false;
    Node *cursor = new Node;
    Vino *ptrVino = new Vino;
    cursor = wines.head;

    while ((cursor != NULL) && !found)
    {
        ptrVino = (Vino *)cursor->ptrData;

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

Usuario *findUserById(List users, int id)
{
    bool found = false;
    Node *cursor = new Node;
    Usuario *ptrUser = new Usuario;
    cursor = users.head;

    while ((cursor != NULL) && !found)
    {
        ptrUser = (Usuario *)cursor->ptrData;

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

int maxYear(List listSeleccion)
{
    Node *cursor = new Node;
    Seleccion *ptrSeleccion = new Seleccion;
    cursor = listSeleccion.head;
    int max = 0;
    while (cursor != NULL)
    {
        ptrSeleccion = (Seleccion *)cursor->ptrData;

        if (ptrSeleccion->year > max)
        { //valido año
            max = ptrSeleccion->year;
        }
        cursor = cursor->next;
    }
    return max;
}

void ordenarArray(WineAndQuantityStruct miArray[], int tamanio)
{
    WineAndQuantityStruct temporal;

    for (int i = 0; i < tamanio; i++)
    {
        for (int j = 0; j < tamanio - 1; j++)
        {
            if (miArray[j].cant < miArray[j + 1].cant)
            { // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
                temporal = miArray[j];
                miArray[j] = miArray[j + 1];
                miArray[j + 1] = temporal;
            }
        }
    }
}

//ordena una lista de varietales auxiliar de mayor a menor
void orderListStrains(List listStrains)
{
    Node *cursor = new Node;
    StrainAndQuantityStruct *ptrStrain = new StrainAndQuantityStruct;
    Node *temp = new Node;

    for (size_t i = 0; i < length(listStrains); i++)
    {
        cursor = listStrains.head;
        while (cursor != NULL) //recorre hasta el ultimo elemento
        {
            temp = cursor;

            while (temp->next != NULL) //recorre hasta el segundo ultimo elemento
            {
                if (((StrainAndQuantityStruct *)temp->ptrData)->cant <
                    ((StrainAndQuantityStruct *)temp->next->ptrData)->cant)
                {
                    ptrStrain = (StrainAndQuantityStruct *)temp->ptrData;
                    temp->ptrData = temp->next->ptrData;
                    temp->next->ptrData = ptrStrain;
                }

                temp = temp->next;
            }

            cursor = cursor->next;
        }
    }
}

//ordena la lista de bodegas de mayor a menor
void orderListCellar(List listCellar)
{
    Node *cursor = new Node;
    WineAndQuantityStruct *ptrCellar = new WineAndQuantityStruct;
    Node *temp = new Node;

    for (size_t i = 0; i < length(listCellar); i++)
    {
        cursor = listCellar.head;
        while (cursor != NULL) //recorre hasta el ultimo elemento
        {
            temp = cursor;

            while (temp->next != NULL) //recorre hasta el segundo ultimo elemento
            {
                if (((WineAndQuantityStruct *)temp->ptrData)->cant <
                    ((WineAndQuantityStruct *)temp->next->ptrData)->cant)
                {
                    ptrCellar = (WineAndQuantityStruct *)temp->ptrData;
                    temp->ptrData = temp->next->ptrData;
                    temp->next->ptrData = ptrCellar;
                }

                temp = temp->next;
            }

            cursor = cursor->next;
        }
    }
}

void rankingAnualDeVinos(List listVinos, List listSeleccion)
{
    Node *cursor = new Node; //Nodo lista vinos

    int max = maxYear(listSeleccion); //año maximo

    //tamaño de mi array
    int cant = length(listVinos);

    //arreglo para el reporte
    WineAndQuantityStruct *arregloStructWines = new WineAndQuantityStruct[cant];

    Vino *ptrVino = new Vino;
    cursor = listVinos.head;
    int v = 0;
    while (cursor != NULL) //leo lista de vinos y cargo arreglo de reporte
    {
        ptrVino = (Vino *)cursor->ptrData;

        arregloStructWines[v] = {ptrVino->id, ptrVino->sLabel, 0};
        v++;
        cursor = cursor->next;
    }

    Seleccion *ptrSeleccion = new Seleccion;
    cursor = listSeleccion.head;

    while (cursor != NULL)
    {
        ptrSeleccion = (Seleccion *)cursor->ptrData;

        if (ptrSeleccion->year == max)
        { //valido año

            for (size_t i = 0; i < cant; i++)
            {

                for (size_t j = 0; j < WINE_QTY; j++)
                {
                    if (ptrSeleccion->wines[j].id == arregloStructWines[i].id) //valido id de seleccion sea igual al id del arreglo
                        arregloStructWines[i].cant++;
                }
            }
        }

        cursor = cursor->next;
    }

    ordenarArray(arregloStructWines, cant);
    // imprimo para validar que esté cargado y ordenado

    cout << "Ranking de Vinos del " << max << endl;
    cout << setw(42) << setfill('-') << '\n'
         << setfill(' ') << '\n';
    cout << "| " << left << setw(25) << "Vino"
         << " | " << left << setw(10) << "Cantidad"
         << " |";
    cout << setw(42) << setfill('-') << '\n'
         << setfill(' ') << '\n';

    for (int i = 0; i < cant; i++)
    {
        if (arregloStructWines[i].id > 0)
            cout << "| "
                 << setw(25) << arregloStructWines[i].nombre
                 << " | "
                 << setw(10) << arregloStructWines[i].cant
                 << " |"
                 << endl;
    }
    cout << setw(42) << setfill('-') << '-' << setfill(' ') << '\n';

    cout << "Pulse una tecla para continuar > ";
    cin.ignore();
    cin.get();
}

//revisa si ya existe el varietal en una lista auxiliar de bodegas
bool isCellarInWinesList(List listVinosAux, string cellar)
{
    bool found = false;
    Node *cursor = new Node;
    WineAndQuantityStruct *ptrCellar = new WineAndQuantityStruct;
    cursor = listVinosAux.head;

    while ((cursor != NULL) && !found)
    {
        ptrCellar = (WineAndQuantityStruct *)cursor->ptrData;

        if (ptrCellar->sCellar == cellar)
        {
            found = true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return found;
}

//encuentra y devuelve en varietal en una lista auxiliar de bodegas
WineAndQuantityStruct *findWineStructByCellar(List listVinosAux, string cellar)
{
    bool found = false;
    Node *cursor = new Node;
    WineAndQuantityStruct *ptrCellar = new WineAndQuantityStruct;
    cursor = listVinosAux.head;

    while ((cursor != NULL) && !found)
    {
        ptrCellar = (WineAndQuantityStruct *)cursor->ptrData;

        if (ptrCellar->sCellar == cellar)
        {
            found = true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return ptrCellar;
}

void rankingAnualDeBodegas(List listVinos, List listSeleccion)
{
    List listBodegas;
    Node *cursor = new Node;
    cursor = listVinos.head;
    Vino *ptrVino = new Vino;
    string cellarAux = "startFlag";
    int year = maxYear(listSeleccion); //ultimo año

    //se cuenta la cantidad de bodegas
    while (cursor != NULL)
    {
        ptrVino = (Vino *)cursor->ptrData;

        //cuando inicia el bucle
        if (cellarAux == "startFlag")
        {
            cellarAux = ptrVino->sCellar;
        }

        if (ptrVino->sCellar != "") //chequea si es correcto el formato de la bodega
        {
            //si la bodega no esta en las listas entonces se agrega
            if (!isCellarInWinesList(listBodegas, ptrVino->sCellar))
            {
                WineAndQuantityStruct *newStruct = new WineAndQuantityStruct;

                newStruct->sCellar = ptrVino->sCellar;

                addNode(listBodegas, newStruct);
            }
        }

        cellarAux = ptrVino->sCellar;

        cursor = cursor->next;
    }

    // ahora toca acomodar la cantidad de bodegas en sus listas por edad de usuario

    cursor = listSeleccion.head;
    Seleccion *ptrSeleccion = new Seleccion;
    Node *cursorCellar = new Node;
    WineAndQuantityStruct *ptrCellar = new WineAndQuantityStruct;

    while (cursor != NULL) //recorre todas las selecciones
    {
        ptrSeleccion = (Seleccion *)cursor->ptrData;

        for (size_t i = 0; i < WINE_QTY; i++) //recorre todos los vinos de la seleccion
        {
            if (ptrSeleccion->year == year) //debe ser una seleccion del ultimo año
            {
                findWineStructByCellar(listBodegas, ptrSeleccion->wines[i].sCellar)->cant++;
            }
        }

        cursor = cursor->next;
    }

    orderListCellar(listBodegas);

    std::cout << "\nRanking de Bodegas del "<< year << std::endl;

    cout << setw(42) << setfill('-') << '\n'
         << setfill(' ') << '\n';
    cout << "| " << left << setw(25) << "Bodega"
         << " | " << left << setw(10) << "Cantidad"
         << " |";
    cout << setw(42) << setfill('-') << '\n'
         << setfill(' ') << '\n';

    cursorCellar = listBodegas.head;

    while (cursorCellar != NULL)
    {
        ptrCellar = (WineAndQuantityStruct *)cursorCellar->ptrData;
        cout << "| "
             << setw(25) << ptrCellar->sCellar
             << " | "
             << setw(10) << ptrCellar->cant
             << " |"
             << endl;

        cursorCellar = cursorCellar->next;
    }
    cout << setw(42) << setfill('-') << '-' << setfill(' ') << '\n';

    cout << "Pulse una tecla para continuar > ";
    cin.ignore();
    cin.get();
}

// R3

//revisa si ya existe el varietal en una lista auxiliar de varietales
bool isStrainInWinesList(List listVinosAux, string strain)
{
    bool answer = false;
    Node *cursor = new Node;
    cursor = listVinosAux.head;
    StrainAndQuantityStruct *ptrStrain = new StrainAndQuantityStruct;

    while (cursor != NULL && !answer)
    {
        ptrStrain = (StrainAndQuantityStruct *)cursor->ptrData;

        if (ptrStrain->sStrain == strain) //si encuentra la uva
        {
            answer = true;
        }
        cursor = cursor->next;
    }

    return answer;
}

//encuentra y devuelve en varietal en una lista auxiliar de varietales
StrainAndQuantityStruct *findWineStructByStrain(List listVinosAux, string strain)
{
    bool found = false;
    Node *cursor = new Node;
    StrainAndQuantityStruct *ptrStrain = new StrainAndQuantityStruct;
    cursor = listVinosAux.head;

    while ((cursor != NULL) && !found)
    {
        ptrStrain = (StrainAndQuantityStruct *)cursor->ptrData;

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
    Node *cursor = new Node;
    cursor = listVinos.head;
    Vino *ptrVino = new Vino;
    string strainAux = "startFlag";
    int year = maxYear(listSeleccion); //ultimo año

    while (cursor != NULL)
    {
        ptrVino = (Vino *)cursor->ptrData;

        //cuando inicia el bucle
        if (strainAux == "startFlag")
        {
            strainAux = ptrVino->sStrain;
        }

        if(ptrVino->sStrain != "") //chequea si es correcto el formato de la uva
        {
             //si la uva no esta en las listas entonces se agrega
            if (!isStrainInWinesList(listMenosDe30, ptrVino->sStrain))
            {
                StrainAndQuantityStruct *newStruct_1 = new StrainAndQuantityStruct;
                StrainAndQuantityStruct *newStruct_2 = new StrainAndQuantityStruct;
                StrainAndQuantityStruct *newStruct_3 = new StrainAndQuantityStruct;

                newStruct_1->sStrain = ptrVino->sStrain;
                newStruct_2->sStrain = ptrVino->sStrain;
                newStruct_3->sStrain = ptrVino->sStrain;

                addNode(listEntre30y50, newStruct_1);
                addNode(listMenosDe30, newStruct_2);
                addNode(listMasDe50, newStruct_3);
            }
        }

        strainAux = ptrVino->sStrain;

        cursor = cursor->next;
    }

    // ahora toca acomodar la cantidad de varietales en sus listas por edad de usuario

    cursor = listSeleccion.head;
    Seleccion *ptrSeleccion = new Seleccion;
    Usuario *ptrUsuario = new Usuario;
    Node *cursorStrains = new Node;
    StrainAndQuantityStruct *ptrStrain = new StrainAndQuantityStruct;

    while (cursor != NULL) //recorre todas las selecciones
    {
        ptrSeleccion = (Seleccion *)cursor->ptrData;

        ptrUsuario = findUserById(listUsuarios, ptrSeleccion->id);

        for (size_t i = 0; i < WINE_QTY; i++) //recorre todos los vinos de la seleccion
        {
            if (ptrSeleccion->year == year) //debe ser una seleccion del ultimo año
            {
                if (ptrUsuario->iAge < 30)
                {
                    findWineStructByStrain(listMenosDe30, ptrSeleccion->wines[i].sStrain)->cant++;
                }
                else if ((ptrUsuario->iAge > 30) && (ptrUsuario->iAge < 50))
                {
                    findWineStructByStrain(listEntre30y50, ptrSeleccion->wines[i].sStrain)->cant++;
                }
                else // + 50
                {
                    findWineStructByStrain(listMasDe50, ptrSeleccion->wines[i].sStrain)->cant++;
                }
            }
        }

        cursor = cursor->next;
    }

    cout << "Ranking de Varietales por Rango Etario del " << year << endl;
    cout << setw(42) << setfill('-') << '\n'
         << setfill(' ') << '\n';
    cout << "| " << left << setw(25) << "Menos de 30 Años"
         << " | " << left << setw(10) << "Cantidad"
         << " |";
    cout << setw(42) << setfill('-') << '\n'
         << setfill(' ') << '\n';

    orderListStrains(listMenosDe30);
    cursorStrains = listMenosDe30.head;

    while (cursorStrains != NULL)
    {
        ptrStrain = (StrainAndQuantityStruct *)cursorStrains->ptrData;
        cout << "| "
             << setw(25) << ptrStrain->sStrain
             << " | "
             << setw(10) << ptrStrain->cant
             << " |"
             << endl;

        cursorStrains = cursorStrains->next;
    }

    cout << setw(42) << setfill('-') << '-' << setfill(' ') << '\n';
    cout << setw(42) << setfill('-') << '\n'
         << setfill(' ') << endl;
    cout << "| " << left << setw(25) << "Entre 30 y 50 Años"
         << " | " << left << setw(10) << "Cantidad"
         << " |";
    cout << setw(42) << setfill('-') << '\n'
         << setfill(' ') << '\n';

    orderListStrains(listEntre30y50);
    cursorStrains = listEntre30y50.head;

    while (cursorStrains != NULL)
    {
        ptrStrain = (StrainAndQuantityStruct *)cursorStrains->ptrData;

        cout << "| "
             << setw(25) << ptrStrain->sStrain
             << " | "
             << setw(10) << ptrStrain->cant
             << " |"
             << endl;

        cursorStrains = cursorStrains->next;
    }

    cout << setw(42) << setfill('-') << '-' << setfill(' ') << '\n';
    cout << setw(42) << setfill('-') << '\n'
         << setfill(' ') << endl;
    cout << "| " << left << setw(25) << "Mas de 50 Años"
         << " | " << left << setw(10) << "Cantidad"
         << " |";
    cout << setw(42) << setfill('-') << '\n'
         << setfill(' ') << '\n';

    orderListStrains(listMasDe50);
    cursorStrains = listMasDe50.head;

    while (cursorStrains != NULL)
    {
        ptrStrain = (StrainAndQuantityStruct *)cursorStrains->ptrData;

        cout << "| "
             << setw(25) << ptrStrain->sStrain
             << " | "
             << setw(10) << ptrStrain->cant
             << " |"
             << endl;

        cursorStrains = cursorStrains->next;
    }
    cout << setw(42) << setfill('-') << '-' << setfill(' ') << '\n';
    cout << "Pulse una tecla para continuar > ";
    cin.ignore();
    cin.get();
}
