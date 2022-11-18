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
int keepingUpWithThePacients(pacient paux, int sizeListApp, appointment* listApp);
appointment lastApp(unsigned int dniAux, int sizeListApp, appointment* listApp);
time_t convertDate(string dato); //LA COPIE DE LA CARPETITA DE AGOS, SI CAMBIAMOS LO QUE DIJO EZE HAY QUE CORREGIRLA !!!!!!
int compareDates(string fDate, string sDate); // LA MISMA QUE HABÍAMOS HECHO PERO CON LA ÚLTIMA LÍNEA AHÍ PORQUE NO SÉ POR QUÉ









