#include <string>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;


//STRUCTS:

typedef struct {
	unsigned int dniPacient;
	string dateAppointment;
	string dateRequest;
	bool asistance;
	string idDoctor;
} appointment;

typedef struct {
	unsigned int dniContact;
	string numberTelephone;
	string numberPhone;
	string adress;
	string mail;
} contact;

typedef struct {
	string doctorId;
	string nameDoctor;
	string lastNameDoctor;
	string specialty;
	string telephoneDoctor;
	bool active;
} doctor;

typedef struct {
	unsigned int idInsurance;
	string nameInsurance;
} insurance;

typedef struct {
	unsigned int dni;
	string namePacient;
	string lastNAmePacient;
	char sex;
	string dateBirth;
	string state; //muerto, internado, no se sabe
	string idInsurance;
} pacient;

typedef struct {
	string namePacientSecL;
	string lastNamePacientSecL;
	unsigned int dniSecL;
	string medicalInsuranceSecL;
	string idDoctorSecL;
	string cellphoneNumberSecL;
	string answerSecL;
}secretaryList;

#define 10ANIOS =315576000; //10 años en segundos

//POCHI
int keepingUpWithThePacients(pacient paux, int sizeListApp, appointment* listApp);//categoriza el paciente
appointment lastApp(unsigned int dniAux, int sizeListApp, appointment* listApp);//le paso un dni y me devuelve la ultima consulta de ese paciente
time_t convertDateToTimeT(string dato); //LA COPIE DE LA CARPETITA DE AGOS, SI CAMBIAMOS LO QUE DIJO EZE HAY QUE CORREGIRLA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int compareDates(string fDate, string sDate, double &timeBetweenDates); // paso una fecha1 y una fecha2, me devuelve el nro de la más reciente y me pasa por alias la dif
string UP(string word);//pasa a mayuscula una palabra
void writeLists(pacient* totalList, int totalSize, pacient*& listUnrecoverable, int& sizeUnrecoverable, pacient*& listRecoverable, int& sizeRecoverable, int sizeApp, appointment* listApp); //le paso la lista general y me arma las dos listas
void generateInsuranceList(pacient* totalList, int sizeTotal, string*& listIn, int& sizeIn);
//lee el array de pacientes y crea una lista de tipo string con las obras sociales presentes en la lista de pacientes --> asumimos que el hospital trabaja únicamente con las obras sociales de la lista (todas las os con las que trabaja e´stán incluídas)

void addPacient(pacient*& listP, int& sizeP, pacient auxP);
void addAppointment(appointment*& listApp, int& sizeApp, appointment auxApp);
void addContact(contact*& listCon, int& sizeCon, contact auxCon);
void addDoctor(doctor*& listDoc, int& sizeDoc, doctor auxDoc);
void addSecretary(secretaryList*& listSec, int& sizeSec, secretaryList auxSec);
void addString(string*& list, int& size, string auxStr);//TODAS FUNCIONES RESIZE

//FALTAN:
secretaryList convertToSecretary(pacient paux, appointment* listApp, int sizeApp, contact* listCon); //le paso un paciente y me lo convierte en el struct secretaría

/*
* PARA HACER:
* 
* 1) SI HAGO PASAJE POR REFERENCIA VERIFICO NULLPRT?
* 2) CONVERTDATETOTIMET NO SÉ SI HAY QUE CAMBIARLA
* 3) NO SÉ QUÉ ME DICE LA DE COMPAREDATES
* 4) HACE FALTA VERIFICAR NEGATIVOS, ETC EN LAS FECHAS???? PORFAS NO
* 5) EL WRITELISTS CASE 1 PREFIEREN CONVERTIRLO AHI Y AÑADIR LA SECRETARIA O HACEMOS UN ARRAY NORMAL DE PACIENTES Y DESDE EL MAIN LO CONVERTIMOS Y ARMAMOS LA NUEVA LISTA??
* 6) EL WRITE LISTS: HAGO UN DEFFAULT PARA 3 Y -1 O HACEMOS POR SEPARADO PARA VER QUE ONDA EL -1?
*/






