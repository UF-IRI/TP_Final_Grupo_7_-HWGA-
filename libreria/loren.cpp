#include "FUNCIONES.h"

void writeFileUnrecoverable(fstream rUnrecoverable, int sizeUnrecoverable, pacient* listUnrecoverable)
{
	if (listUnrecoverable == nullptr || !(rUnrecoverable.is_open()))
		return;
	rUnrecoverable << "NamePacient" << " , " << "LastNamePacient" << " , " << "DNI" << " , " << "State" << endl;
	int i = 0;
	while (i < sizeUnrecoverable)
	{
		rUnrecoverable << listUnrecoverable[i].namePacient << "," << listUnrecoverable[i].lastNAmePacient
			<< "," << listUnrecoverable[i].dni << "," << listUnrecoverable[i].state << endl;
		i++;
	}
	return;
}


void writeFileRecoverable(fstream rRecoverable, int sizeRecoverable, secretaryList* listRecoverable)
{
	if (listRecoverable == nullptr || !(rRecoverable.is_open()))
		return;
	rRecoverable << "NamePacient" << " , " << "LastNamePacient" << " , " << "DNI" << " , " << "MedicalInsurance" << " , " 
		<< "IdDoctor" << " , " << "CellPhoneNumber" << " , " << "Answer" << endl;
	int i = 0;
	while (i < sizeRecoverable)
	{
		rRecoverable << listRecoverable[i].namePacientSecl << " , " << listRecoverable[i].lastNamePacientSecL << " , "
			<< listRecoverable[i].dniSecL << " , " << listRecoverable[i].medicalInsuranceSecL << " , " << listRecoverable[i].idDoctorSecL
			<< listRecoverable[i].cellphoneNumberSecL << " , " << "." << endl;
		i++;
	}
	return;
}