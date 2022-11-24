#include "FUNCIONES.h"

secretaryList convertToSecretary(pacient paux, appointment* listApp, int sizeApp, contact* listCon, int sizeCon)
{
	if (listApp == nullptr || listCon == nullptr)
		return;

	secretaryList newPacient;
	newPacient.namePacientSecL = paux.namePacient;
	newPacient.lastNamePacientSecL = paux.lastNAmePacient;
	newPacient.dniSecL = paux.dni;
	newPacient.medicalInsuranceSecL = paux.idInsurance;

	int i;

	for (i = 0; i < sizeCon; i++)
	{
		if (listCon[i].dniContact == newPacient.dniSecL)
		{
			newPacient.cellphoneNumberSecL = listCon[i].numberPhone;
			break; //asumo que el paciente aparece una unica vez en la lista de contactos porque para que guardaria su numero 20 veces
		}
	}

	appointment aux = lastApp(newPacient.dniSecL, sizeApp, listApp); //lamo a la funcion de last app para que me devuelva la ult consulta del paciente y asi guardarme su medico
	newPacient.idDoctorSecL = aux.idDoctor;
	newPacient.answerSecL = '.'; //lo lleno con un punto hasta que la secretaria lo contacte

	if (i == sizeCon||newPacient.dniSecL==0) 
		newPacient.dniSecL = 0; //en caso de error lleno el cajon del dni con un 0, despues hay que chequearlo

	return newPacient;

}

void appendAppointment(fstream& appAppointment, appointment* newAppointments, int howMany)
{
	if (newAppointments == nullptr || !(appAppointment.is_open()))
		return;

	for (int i = 0; i < howMany; i++)
	{
		appAppointment << newAppointments[i].dniPacient << " , " << newAppointments[i].dateRequest << " , " << newAppointments[i].dateAppointment << " , " << newAppointments[i].asistance << " , " << newAppointments[i].idDoctor << endl;
	}

	return;
}

void pacientsUpdate(secretaryList*& recoverableList, int sizeRec, string*InsuranceList, int sizeIL, appointment*&newApp, int sizeNewApp)
{
	if (recoverableList == nullptr|| totalList==nullptr|| newApp==nullptr)
		return;

	//datos generados por random
	srand(NULL);
	int comeBack, changeMI, answered, newInsurance;

	int a; //para ver cuantas veces lo llame

	//para la lista de consultas
	sizeNewApp = 0; 
	appointment aux;
	time_t current = time(0); //fecha de hoy en time_t
	string today = convertDateToString(current); //la paso a string 
	string newAppDate;

	for (int i = 0; i < sizeRec; i++)
	{
		for (a = 0; a < 10; a++) //llamo como maximo 10 veces a cada paciente
		{
			answered = rand() % 2; //0: no contesto, 1:contesto
			if (answered == 1)
			{
				comeBack = rand() % 2; //0:no va a volver, 1:quiere una nueva consulta
				if (comeBack == 0)
					recoverableList[i].answerSecL = "NoVaAVolver";
				else
				{
					//newAppDate=generateApp()
					if (!(newAppDate == "error"))
					{
						aux.dniPacient = recoverableList[i].dniSecL;
						//aux.dateAppointment = newAppDate;
						aux.dateRequest = today; //hoy
						aux.asistance = 0; //porque es a futuro asi que segurno no fue
						aux.idDoctor = recoverableList[i].idDoctorSecL;
						addAppointment(newApp, sizeNewApp, aux); //agrego la nueva consulta en la lista

						recoverableList[i].answerSecL = "NuevaConsulta";
					}
					else
						recoverableList[i].answerSecL = "NoSeGeneroUnaNuevaConsulta";

					changeMI = rand() % 2;//0:no quiere cambiar su obra social, 1:la quiere cambiar
					if (change == 1)
					{
						string repeated = recoverableList[i].medicalInsuranceSecL;
						do
						{
							newInsurance = rand() % sizeIL; 
							recoverableList[i].medicalInsuranceSecL = InsuranceList[newInsurance];

						} while (repeated == recoverableList[i].medicalInsurance); //para que no vuelva a ser la misma de antes
					} 
					//no tiene sentido agregar un else porque quedaria igual su obra social
				}

				break; //si contesto dejo de llamarlo y sigo con los demas pacientes
			}
		}
		if (a == 10)
			recoverableList[i].answerSecL = "NoContesto";
	}

	delete[] InsuranceList;
	InsuranceList = NULL;

}


