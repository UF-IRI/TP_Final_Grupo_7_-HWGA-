#include "FUNCIONES.h"
using namespace std;

int main()
{
	fstream rPac;
	fstream rCon;
	fstream rDoc;
	fstream rApp;

	int sizePac = 0;
	int sizeCon = 0;
	int sizeDoc = 0;
	int sizeApp=0;

	string routePac = (BASE PATH + "../data_files/input/Pacientes.csv"); //no tengo idea si esta bien pero queda lindo
	string routeCon = (BASE PATH + "../data_files/input/Contactos.csv");
	string routeDoc = (BASE PATH + "../data_files/input/Medicos.csv");
	string routeApp = (BASE PATH + "../data_files/input/Consultas.csv");

	//NO ANDANNNNNN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//NO ME ENTIENDE LOS ARRAYSSSS --> COMO LOS PASO SI PUSE *& ?????? (pochi). //creo q hay q pasarlos sin nada. Ej: listPac (Loren)
	//ES NECESARIO ABRIR Y LEER TODOS LOS ARCHIVOS AL PRINCIPIO?? , NO HAY ALGUNO QUE USEMOS DESPUES? (loren).

	rPac.open(routePac, ios::in);
	pacient* listPac = new pacient[sizePac];
	readPac(rPac, listPac, &sizePac);
	rPac.close();
	
	rCon.open(routeCon, ios::in);
	contact* listCon = new contact[sizeCon];
	readCon(rCon, listCon, &sizeCon);
	rCon.close();

	rApp.open(routeApp, ios::in);
	appointment* listApp = new appointment[sizeApp];
	readApp(rApp, listApp, &sizeApp);
	rApp.close();

	rDoc.open(routeDoc, ios::in);
	doctor* listDoc = new doctor[sizeDoc];
	readDoc(rDoc, listDoc, &sizeDoc);
	readDoc.close();


	//LABURAR ACAAAAAA

	string routeRecoverable = (BASE PATH + "../data_files/output/Recoverable.csv");
	string routeUnrecoverable = (BASE PATH + "../data_files/output/Unrecoverable.csv");

	//LIBERO MEMORIA
	delete[] listPac;
	delete[] listCon;
	delete[] listApp;
	delete[] listDoc;

}
