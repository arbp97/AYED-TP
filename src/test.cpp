#include "usuario.hpp"
#include "vino.hpp"
#include "seleccion.hpp"
#include "list.hpp"
#include "files.hpp"
#include "util.hpp"
#include <iostream>
#include <cstdlib>
#define EXIT_SUCCESS 0

using namespace std;

int test()
{
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
	Node* aux = new Node;
	Usuario* ptrUsuario = new Usuario;
    cursor = list.head;

    while (cursor != NULL)
    {
        ptrUsuario = (Usuario*) cursor->ptrData;

		cout << ptrUsuario->sName << endl;
	
		aux = cursor;
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
		
        cursor = cursor->next;
    }

    return 0;
}
