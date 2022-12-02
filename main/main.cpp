#include "FUNCIONES.h"
#include "iri.cpp" //incluyo iri cpp xq sino no me toma el BASE_PATH, no tengo idea xq (loren)

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
	int sizeApp = 0;

	string routePac = (BASE_PATH + "../data_files/input/Pacientes.csv"); //queda lindo y funciona 10 puntos
	string routeCon = (BASE_PATH + "../data_files/input/Contactos.csv");
	string routeDoc = (BASE_PATH + "../data_files/input/Medicos.csv");
	string routeApp = (BASE_PATH + "../data_files/input/Consultas.csv");

	//CONSEGUI QUE ME ABRA Y LEA TODOS LOS ARCHIVOS!!!!! YA PUEDO MORIR TRANQUILO :)
	
	rPac.open(routePac, ios::in);
	pacient* listPac = new pacient[sizePac];
	readPac(rPac, listPac, sizePac); //me lleno la lista de pacientes
	rPac.close();
	
	rCon.open(routeCon, ios::in);
	contact* listCon = new contact[sizeCon]; //me lleno la lista de contactos
	readCon(rCon, listCon, sizeCon);
	rCon.close();

	rApp.open(routeApp, ios::in);
	appointment* listApp = new appointment[sizeApp]; //me lleno la lista de consultas
	readApp(rApp, listApp, sizeApp);
	rApp.close();

	rDoc.open(routeDoc, ios::in);
	doctor* listDoc = new doctor[sizeDoc]; //me lleno la lista de medicos
	readDoc(rDoc, listDoc, sizeDoc);
	rDoc.close();
	
	//HASTA ACA FUNCIONA TODO EN TEORÍA :):)

	//me creo las listas de recuperables e irrecuperables
	int sizeUnrecoverable = 0;
	int sizeRecoverable = 0;
	pacient* listUnrecoverable = new pacient[sizeUnrecoverable];
	secretaryList* listRecoverable = new secretaryList[sizeRecoverable]; 
	writeLists(listPac, sizePac, listUnrecoverable, sizeUnrecoverable, listRecoverable, sizeRecoverable, sizeApp, listApp, listCon, sizeCon); //escribo las dos listas de pacientes que me interesan

	string routeRecoverable = (BASE_PATH + "../data_files/output/Recoverable.csv");
	string routeUnrecoverable = (BASE_PATH + "../data_files/output/Unrecoverable.csv");


	fstream rUnrecoverable;
	rUnrecoverable.open(routeUnrecoverable, ios::out);//abro el archivo de irrecuperables para escritura
	writeFileUnrecoverable(rUnrecoverable, sizeUnrecoverable, listUnrecoverable); //escribo el archivo irrecuperables a partir de la lista irrecuperables
	rUnrecoverable.close();
	delete[]listUnrecoverable;//libera la memoria de la lista de irrecuperables
	listUnrecoverable = NULL;

	

	//ARCHIVO SECRETARÍA.
	fstream rRecoverable;
	rRecoverable.open(routeRecoverable, ios::out); //abro el archivo de recuperables para escritura
	writeFileRecoverable(rRecoverable, sizeRecoverable, listRecoverable); //escribo el archivo recuperables a partir de la lista recuperables
	rRecoverable.close();
	delete[]listRecoverable; //libera la memoria de la lista de recuperables
	listRecoverable = NULL;

	//LEO EL ARCHIVO PARA PASARLO A MEMORIA DINÁMICA
	//nos parece poco eficiente tener que pasarle un archivo a la secretaría para tener que volver 
	//a abrirlo, leerlo en un array y guardarlo en memoria cuando directamente le podríamos haber pasado la lista que teníamos desde antes. 
	//Igualmente la consigna dice que se debe escribir un archivo para pasar a la secretaría y que posteriormente sea modificado. 
	fstream newrRecoverable;
	int newSizeRecoverable=0;
	secretaryList* newListRecoverable = new secretaryList[newSizeRecoverable];
	newrRecoverable.open(routeRecoverable, ios::in);
	readFileRecoverable(newrRecoverable, newListRecoverable, newSizeRecoverable);
	newrRecoverable.close();

	//me creo un array con la os con las que trabaja el hospital
	int sizeInsuranceList = 0;
	string* insuranceList = new string[sizeInsuranceList]; //lista dinamica con las obras sociales
	generateInsuranceList(listPac, sizePac, insuranceList, sizeInsuranceList); //genera una lista con las obras sociales

	//PARA HACER EL APPEND EN EL ARCHIVO DE CONSULTAS CON LAS NUEVAS
	int sizeNewAppointments = 0;
	appointment* listNewAppointments = new appointment[sizeNewAppointments];
	pacientsUpdate(newListRecoverable, newSizeRecoverable, insuranceList, sizeInsuranceList, listNewAppointments, sizeNewAppointments);
	
	fstream fApp2;
	fApp2.open(routeApp, ios::app);
	appendAppointment(fApp2, listNewAppointments, sizeNewAppointments);
	fApp2.close();

	//SOBREESCRIVO EL ARCHIVO DE SECRETARÍA
	fstream newrRecoverable2;
	newrRecoverable2.open(routeRecoverable, ios::out); //abro el archivo de recuperables para escritura
	writeFileRecoverable(newrRecoverable2, newSizeRecoverable, newListRecoverable); //escribo el archivo recuperables a partir de la lista recuperables
	newrRecoverable2.close();
	delete[]newListRecoverable; //libera la memoria de la lista de recuperables
	newListRecoverable = NULL;

	//LIBERO MEMORIA
	delete[] listCon;
	listCon = NULL;
	delete[] listApp;
	listApp = NULL;
	delete[] listDoc;
	listDoc = NULL;
	delete[] listPac;
	listPac = NULL;
	
}
