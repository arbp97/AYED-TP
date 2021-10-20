#include "util.hpp"

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