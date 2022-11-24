#include "FUNCIONES.h"

secretaryList convertToSecretary(pacient paux, appointment* listApp, int sizeApp, contact* listCon, int sizeCon)
{
	secretaryList error; //struct del tipo secretaria lleno con 0s que devuelvo en caso de error
	error.answerSecL = '0';
	error.cellphoneNumberSecL = '0';
	error.dniSecL = 0;
	error.idDoctorSecL = '0';
	error.lastNamePacientSecL = '0';
	error.medicalInsuranceSecL = '0';
	error.namePacientSecL='0';

	if (listApp == nullptr || listCon == nullptr)
		return error;

	secretaryList newPacient; //lleno los campos del struct con los datos que ya conozco
	newPacient.namePacientSecL = paux.namePacient;
	newPacient.lastNamePacientSecL = paux.lastNAmePacient;
	newPacient.dniSecL = paux.dni;
	newPacient.medicalInsuranceSecL = paux.idInsurance;

	int i;

	for (i = 0; i < sizeCon; i++) //recorro la lista de contactos hasta encontrarlo y me guardo su celular
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

void appendAppointment(fstream& appAppointment, appointment* newAppointments, int howMany) //para agregar las nuevas consultas programadas en el archivo de consultas
{
	if (newAppointments == nullptr || !(appAppointment.is_open()))
		return;

	for (int i = 0; i < howMany; i++)
	{
		appAppointment << newAppointments[i].dniPacient << " , " << newAppointments[i].dateRequest << " , " << newAppointments[i].dateAppointment << " , " << newAppointments[i].asistance << " , " << newAppointments[i].idDoctor << endl;
	}

	return;
}

void pacientsUpdate(secretaryList*& recoverableList, int sizeRec, string*InsuranceList, int sizeIL, appointment*&newApp, int &sizeNewApp) //funcion de actualizacion de datos
{
	if (recoverableList == nullptr|| InsuranceList==nullptr|| newApp==nullptr)
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
					newAppDate = generateRandomAppDate();
					if (!(newAppDate == "error"))
					{
						aux.dniPacient = recoverableList[i].dniSecL;
						aux.dateAppointment = newAppDate;
						aux.dateRequest = today; //hoy
						aux.asistance = 0; //porque es a futuro asi que segurno no fue
						aux.idDoctor = recoverableList[i].idDoctorSecL;
						addAppointment(newApp, sizeNewApp, aux); //agrego la nueva consulta en la lista

						recoverableList[i].answerSecL = "NuevaConsulta";

						changeMI = rand() % 2;//0:no quiere cambiar su obra social, 1:la quiere cambiar
						if (changeMI == 1)
						{
							string repeated = recoverableList[i].medicalInsuranceSecL;
							do
							{
								newInsurance = rand() % sizeIL; 
								recoverableList[i].medicalInsuranceSecL = InsuranceList[newInsurance];

							} while (repeated == recoverableList[i].medicalInsuranceSecL); //para que no vuelva a ser la misma de antes
						} 
						//no tiene sentido agregar un else porque quedaria igual su obra social
					}
					else
						recoverableList[i].answerSecL = "NoSeGeneroUnaNuevaConsulta";
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

void writeLists(pacient* totalList, int totalSize, pacient*& listUnrecoverable, int& sizeUnrecoverable, secretaryList*& listRecoverable, int& sizeRecoverable, int sizeApp, appointment* listApp, contact*listCon, int sizeCon) //por que la lista de recuperables es de tipo paciente y no secretary list? (loren)
{
	if (totalList == nullptr || listUnrecoverable == nullptr || listRecoverable == nullptr || listApp == nullptr)
		return;

	int i;
	int cat;
	secretaryList aux;

	for (i = 0; i < totalSize; i++)
	{
		cat = keepingUpWithThePacients(totalList[i], sizeApp, listApp);
		switch (cat)
		{
		case 1://recuperable
		{
			aux = convertToSecretary(totalList[i], listApp, sizeApp, listCon, sizeCon); //lo paso al struct del tipo secretaria
			addSecretary(listRecoverable, sizeRecoverable, aux); //lo agrego a la lista de recuperables
			break;
		}
		case 2: //irrecuperable
		{
			addPacient(listUnrecoverable, sizeUnrecoverable, totalList[i]); //lo agrego a la lista de irrecuperables
			break;
		}
		//no pongo deffault porque no nos interesan
		}
	}

	return;
}
//le paso una lista con todos los pacientes y me devuelve dos listas separadas de recuperables/no recuperables

