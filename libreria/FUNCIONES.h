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
	int asistance; 
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
	int active;
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

//CONSTANTES:
#define tenYears 315576000 //10 años en segundos
#define currentYear 2022

//READ:
void readPac(fstream &rPac, pacient*&listPac, int&sizePac);
void readCon(fstream &rCon, contact*& listCon, int& sizeCon);
void readApp(fstream &rApp, appointment*& listApp, int& sizeApp);
//void readDoc(fstream &rDoc, doctor*& listDoc, int& sizeDoc);
void readFileRecoverable(fstream& newrRecoverable, secretaryList*& newListRecoverable, int& sizeNewListRecoverable);

//RESIZE:
void addPacient(pacient*& listP, int& sizeP, pacient auxP);
void addAppointment(appointment*& listApp, int& sizeApp, appointment auxApp);
void addContact(contact*& listCon, int& sizeCon, contact auxCon);
//void addDoctor(doctor*& listDoc, int& sizeDoc, doctor auxDoc);
void addSecretary(secretaryList*& listSec, int& sizeSec, secretaryList auxSec);
void addString(string*& list, int& size, string auxStr);

//MANIPULAR FECHAS:
time_t convertDateToTimeT(string dato); //LA COPIE DE LA CARPETITA DE AGOS, SI CAMBIAMOS LO QUE DIJO EZE HAY QUE CORREGIRLA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int compareDates(time_t fDate, time_t sDate, double& timeBetweenDates); // paso una fecha1 y una fecha2, me devuelve el nro de la más reciente y me pasa por alias la dif
string convertDateToString(time_t dato);

//CATEGORIZAR:
int keepingUpWithThePacients(pacient paux, int sizeListApp, appointment* listApp);//categoriza el paciente
appointment lastApp(unsigned int dniAux, int sizeListApp, appointment* listApp);//le paso un dni y me devuelve la ultima consulta de ese paciente
void writeLists(pacient* totalList, int totalSize, pacient*& listUnrecoverable, int& sizeUnrecoverable, secretaryList*& listRecoverable, int& sizeRecoverable, int sizeApp, appointment* listApp, contact* listCon, int sizeCon); //le paso la lista general y me arma las dos listas

//GENERAR CON RANDOM:
string generateRandomAppDate(int x);
//lee las appointments nuevas guardadas y me genera una fecha random para la próxima

//AUXILIARES:
string UP(string word);//pasa a mayuscula una palabra
void generateInsuranceList(pacient* totalList, int sizeTotal, string*& listIn, int& sizeIn);

//ESCRIBIR ARCHIVOS:
void writeFileUnrecoverable(fstream &rUnrecoverable, int sizeUnrecoverable, pacient* listUnrecoverable);
void writeFileRecoverable(fstream &rRecoverable, int sizeRecoverable, secretaryList* listRecoverable);
void appendAppointment(fstream &appAppointment, appointment* newAppointments, int howMany);

//SECRETARÍA
secretaryList convertToSecretary(pacient paux, appointment* listApp, int sizeApp, contact* listCon, int sizeCon); //le paso un paciente y me lo convierte en el struct secretaría
void pacientsUpdate(secretaryList*& recoverableList, int sizeRec, string* InsuranceList, int sizeIL, appointment*& newApp, int& sizeNewApp);






