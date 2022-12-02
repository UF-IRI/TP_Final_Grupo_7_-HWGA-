#include "FUNCIONES.h"

void writeFileUnrecoverable(fstream &rUnrecoverable, int sizeUnrecoverable, pacient* listUnrecoverable)
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


void writeFileRecoverable(fstream &rRecoverable, int sizeRecoverable, secretaryList* listRecoverable)
{
	if (listRecoverable == nullptr || !(rRecoverable.is_open()))
		return;
	rRecoverable << "NamePacient" << " , " << "LastNamePacient" << " , " << "DNI" << " , " << "MedicalInsurance" << " , " 
		<< "IdDoctor" << " , " << "CellPhoneNumber" << " , " << "Answer" << endl;
	int i = 0;
	while (i < sizeRecoverable-1)
	{
		rRecoverable << listRecoverable[i].namePacientSecL << " , " << listRecoverable[i].lastNamePacientSecL << " , "
			<< listRecoverable[i].dniSecL << " , " << listRecoverable[i].medicalInsuranceSecL << " , " << listRecoverable[i].idDoctorSecL
			<< " , " << listRecoverable[i].cellphoneNumberSecL << " , " << listRecoverable[i].answerSecL << endl;
		i++;
	}
	return;
}


void readFileRecoverable(fstream &newrRecoverable, secretaryList *& newListRecoverable, int& sizeNewListRecoverable)															 
{
	if (!(newrRecoverable.is_open()) || newListRecoverable == nullptr)
		return;
	string dummy;
	secretaryList aux;
	newrRecoverable >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy;
	
	while (newrRecoverable)
	{
		newrRecoverable >> aux.namePacientSecL >> dummy >> aux.lastNamePacientSecL >> dummy >> aux.dniSecL >> dummy >> aux.medicalInsuranceSecL 
			>> dummy >> aux.idDoctorSecL >> dummy >> aux.cellphoneNumberSecL >> dummy >> aux.answerSecL;
		addSecretary(newListRecoverable, sizeNewListRecoverable, aux);
	}
	return;
}