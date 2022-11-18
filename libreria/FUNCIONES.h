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
	long unsigned int dni;
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
	long unsigned int dniSecL;
	string medicalInsuranceSecL;
	string idDoctorSecL;
	string cellphoneNumberSecL;
	string answerSecL;
}secretaryList;


//POCHI
int keepingUpWithThePacients(pacient paux, int sizeListApp, appointment* listApp);









