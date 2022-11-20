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

	//NO ANDANNNNNN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//NO ME ENTIENDE LOS ARRAYSSSS --> COMO LOS PASO SI PUSE *& ??????
	rPac.open("!!!!!!!!!!!!!RUTA???????????????????", ios::in);
	pacient* listPac = new pacient[sizePac];
	readPac(rPac, &listPac, &sizePac);
	rPac.close();
	
	rCon.open("!!!!!!RUTA??????", ios::in);
	contact* listCon = new contact[sizeCon];
	readCon(rCon, listCon,&sizeCon);
	rCon.close();

	rApp.open("RUTAAAA", ios::in);
	appointment* listApp = new appointment[sizeApp];
	readApp(rApp, listApp, &sizeApp);
	rApp.close();

	rDoc.open("RUTA", ios::in);
	doctor* listDoc = new doctor[sizeDoc];
	readDoc(rDoc, listDoc, &sizeDoc);
	readDoc.close();


	//LABURAR ACAAAAAA


	//LIBERO MEMORIA
	delete[] listPac;
	delete[] listCon;
	delete[] listApp;
	delete[] listDoc;

}
