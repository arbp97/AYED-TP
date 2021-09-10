#include "usuario.hpp"
#include "vino.hpp"
#include "seleccion.hpp"

using namespace std;

int main()
{
	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	
    Usuario* usuario = new Usuario;

    createUsuario(*usuario, 1, "Alan", 21, "Micasa");

    cout << getName(*usuario) << endl;

    setName(*usuario, "Rob");

    cout << getName(*usuario) << endl;
	
	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	
	Vino* vino_1 = new Vino;
	
	createVino(*vino_1, 1, "Malbec", "Villa Tintos", "Tinto", "Malbec", 2018, "Tierrita sabrosa");
	
	cout << getLabel(*vino_1) << endl;
	
	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	
	Vino vinitos[6];
	
	vinitos[0] = *vino_1;
	
	Seleccion* seleccion = new Seleccion;
	
	createSeleccion(*seleccion, getId(*usuario), SEPTIEMBRE, 2021, vinitos);
	
	cout << getLabel(*(getVinos(*seleccion))) << endl;
	
	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    return 0;
}
