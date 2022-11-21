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
	readPac(rPac, listPac, &sizePac); //me lleno la lista de pacientes
	rPac.close();
	
	rCon.open(routeCon, ios::in);
	contact* listCon = new contact[sizeCon]; //me lleno la lista de contactos
	readCon(rCon, listCon, &sizeCon);
	rCon.close();

	rApp.open(routeApp, ios::in);
	appointment* listApp = new appointment[sizeApp]; //me lleno la lista de consultas
	readApp(rApp, listApp, &sizeApp);
	rApp.close();

	rDoc.open(routeDoc, ios::in);
	doctor* listDoc = new doctor[sizeDoc]; //me lleno la lista de medicos
	readDoc(rDoc, listDoc, &sizeDoc);
	rDoc.close();

	int sizeUnrecoverable = 0;
	int sizeRecoverable = 0;
	pacient* listUnrecoverable = new pacient[sizeUnrecoverable];
	pacient* listRecoverable = new pacient[sizeRecoverable];
	writeLists(listPac, sizePac, listUnrecoverable, sizeUnrecoverable, listRecoverable, sizeRecoverable, sizeApp, listApp); //escribo las dos listas de pacientes que me interesan
	delete[]listPac; //como ya me cree la dos listas de pacientes q me interesan borro lo otro;
	listPac = NULL;


	string routeRecoverable = (BASE PATH + "../data_files/output/Recoverable.csv");
	string routeUnrecoverable = (BASE PATH + "../data_files/output/Unrecoverable.csv");

	fstream rUnrecoverable;
	rUnrecoverable.open(routeUnrecoverable, ios::out);//abro el archivo de irrecuperables para escritura
	writeFileUnrecoverable(rUnrecoverable, sizeUnrecoverable, listUnrecoverable);
	rUnrecoverable.close();
	delete[]listUnrecoverable;//libera la memoria de la lista de irrecuperables
	listUnrecoverable = NULL;




	//LIBERO MEMORIA
	delete[] listCon;
	delete[] listApp;
	delete[] listDoc;

}
