#include "FUNCIONES.h"

//READ
void readPac(fstream& rPac, pacient*& listPac, int& sizePac) //puse el fstream & xq en google me lo decia asi y ahora ya no me toma
//mas error, perdon por tocarte el codigo pochi :) (loren)
{
	if (!(rPac.is_open()) || listPac == nullptr)
		return;
	string dummy;
	pacient aux;
	rPac >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy;

	while (rPac)
	{
		rPac >> aux.dni >> dummy >> aux.namePacient >> dummy >> aux.lastNAmePacient >> dummy >> aux.sex >> dummy >> aux.dateBirth >> dummy >> aux.state >> dummy >> aux.idInsurance;
		addPacient(listPac, sizePac, aux);
	}
	return;
}
void readCon(fstream& rCon, contact*& listCon, int& sizeCon)
{
	if (!(rCon.is_open()) || listCon == nullptr)
		return;
	string dummy;
	contact aux;
	rCon >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy;

	while (rCon)
	{
		rCon >> aux.dniContact >> dummy >> aux.numberTelephone >> dummy >> aux.numberPhone >> dummy;
		getline(rCon, aux.adress, ','); //hice esto xq habia un paciente hermoso q tenia una adress separada con espacio entonces me leia hasta ahi
		//perdon pochi por tocarte el codigo pero parece q funciona :)
		rCon >> aux.mail;
		addContact(listCon, sizeCon, aux);
	}
	return;

}
void readApp(fstream& rApp, appointment*& listApp, int& sizeApp)
{
	if (!(rApp.is_open()) || listApp == nullptr)
		return;
	string dummy;
	appointment aux;
	rApp >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy;

	while (rApp)
	{
		rApp >> aux.dniPacient >> dummy >> aux.dateRequest >> dummy >> aux.dateAppointment >> dummy >> aux.asistance >> dummy >> aux.idDoctor;
		addAppointment(listApp, sizeApp, aux);
	}
	return;
}
/*
void readDoc(fstream& rDoc, doctor*& listDoc, int& sizeDoc)
{
	if (!(rDoc.is_open()) || listDoc == nullptr)
		return;
	string dummy;
	doctor aux;
	rDoc >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy >> dummy;

	while (rDoc)
	{
		rDoc >> aux.doctorId >> dummy >> aux.nameDoctor >> dummy >> aux.lastNameDoctor >> dummy >> aux.telephoneDoctor >> dummy >> aux.specialty >> dummy >> aux.active;
		addDoctor(listDoc, sizeDoc, aux);
	}
	return;
}
*/
void readFileRecoverable(fstream& newrRecoverable, secretaryList*& newListRecoverable, int& sizeNewListRecoverable)
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

//WRITE
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
//agrega en el archivo de consultas los nuevos turnos generados por la secretaría
void writeFileUnrecoverable(fstream& rUnrecoverable, int sizeUnrecoverable, pacient* listUnrecoverable)
{
	if (listUnrecoverable == nullptr || !(rUnrecoverable.is_open()))
		return;
	rUnrecoverable << "NamePacient" << " , " << "LastNamePacient" << " , " << "DNI" << " , " << "State" << endl;
	int i = 0;
	while (i < sizeUnrecoverable)
	{
		rUnrecoverable << listUnrecoverable[i].namePacient << " , " << listUnrecoverable[i].lastNAmePacient
			<< " , " << listUnrecoverable[i].dni << " , " << listUnrecoverable[i].state << endl;
		i++;
	}
	return;
}
void writeFileRecoverable(fstream& rRecoverable, int sizeRecoverable, secretaryList* listRecoverable)
{
	if (listRecoverable == nullptr || !(rRecoverable.is_open()))
		return;
	rRecoverable << "NamePacient" << " , " << "LastNamePacient" << " , " << "DNI" << " , " << "MedicalInsurance" << " , "
		<< "IdDoctor" << " , " << "CellPhoneNumber" << " , " << "Answer" << endl;
	int i = 0;
	while (i < sizeRecoverable - 1)
	{
		rRecoverable << listRecoverable[i].namePacientSecL << " , " << listRecoverable[i].lastNamePacientSecL << " , "
			<< listRecoverable[i].dniSecL << " , " << listRecoverable[i].medicalInsuranceSecL << " , " << listRecoverable[i].idDoctorSecL
			<< " , " << listRecoverable[i].cellphoneNumberSecL << " , " << listRecoverable[i].answerSecL << endl;
		i++;
	}
	return;
}

//RESIZE
void addPacient(pacient*& listP, int& sizeP, pacient auxP)
{
	if (listP == nullptr)
		return;
	pacient* newListP = new pacient[sizeP + 1];
	int i;
	for (i = 0; i < sizeP; i++)
		newListP[i] = listP[i];
	newListP[i] = auxP;

	sizeP++;
	delete[] listP;
	listP = newListP;
	return;

}
void addAppointment(appointment*& listApp, int& sizeApp, appointment auxApp)
{
	if (listApp == nullptr)
		return;
	appointment* newListApp = new appointment[sizeApp + 1];
	int i;
	for (i = 0; i < sizeApp; i++)
		newListApp[i] = listApp[i];
	newListApp[i] = auxApp;

	sizeApp++;
	delete[] listApp;
	listApp = newListApp;
	return;
}
void addContact(contact*& listCon, int& sizeCon, contact auxCon)
{
	if (listCon == nullptr)
		return;
	contact* newListCon = new contact[sizeCon + 1];
	int i;
	for (i = 0; i < sizeCon; i++)
		newListCon[i] = listCon[i];
	newListCon[i] = auxCon;

	sizeCon++;
	delete[] listCon;
	listCon = newListCon;
	return;
}
/*
void addDoctor(doctor*& listDoc, int& sizeDoc, doctor auxDoc)
{
	if (listDoc == nullptr)
		return;
	doctor* newListDoc = new doctor[sizeDoc + 1];
	int i;
	for (i = 0; i < sizeDoc; i++)
		newListDoc[i] = listDoc[i];
	newListDoc[i] = auxDoc;

	sizeDoc++;
	delete[]listDoc;
	listDoc = newListDoc;
	return;
}
*/
void addSecretary(secretaryList*& listSec, int& sizeSec, secretaryList auxSec)
{
	if (listSec == nullptr)
		return;

	secretaryList* newListSec = new secretaryList[sizeSec + 1];
	int i;
	for (i = 0; i < sizeSec; i++)
		newListSec[i] = listSec[i];
	newListSec[i] = auxSec;

	sizeSec++;
	delete[] listSec;
	listSec = newListSec;
	return;
}
void addString(string*& list, int& size, string auxStr)
{
	if (list == nullptr)
		return;

	string* newList = new string[size + 1];
	int i;

	for (i = 0; i < size; i++)
		newList[i] = list[i];
	newList[i] = auxStr;

	size++;
	delete[] list;
	list = newList;
	return;
}

//MANIPULAR FECHAS
time_t convertDateToTimeT(string dato)
{
	int i = 0;
	int day, month, year;
	int cont = 0;
	string auxD{};
	string auxM{};
	string auxY{};
	string aux;
	int cont2 = 0;
	while (i < (dato.length() - 1))
	{

		while (dato[i] != '/')
		{

			if (cont == 0)
			{
				aux = dato[i];
				auxD += aux;
			}
			else if (cont == 1)
			{
				aux = dato[i];
				auxM += aux;
			}
			else
			{
				if (cont2 >= 4)
					break;
				aux = dato[i];
				auxY += aux;
				cont2++;
			}

			i++;

		}
		cont++;
		i++;
	}


	day = stoi(auxD);
	month = stoi(auxM);
	year = stoi(auxY);


	tm date{};
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;

	time_t finalDate = mktime(&date);
	return finalDate;
}
//le doy una string y me la devuelve en time_t
string convertDateToString(time_t dato)
{
	tm* dateTM;
	dateTM = localtime(&dato);

	string dateSTR = to_string(dateTM->tm_mday) + '/' + to_string(dateTM->tm_mon + 1) + '/' + to_string(dateTM->tm_year + 1900);

	return dateSTR;

}
//le doy un time_t y me lo devuelve en string
int compareDates(time_t fDate, time_t sDate, double& timeBetweenDates) // le paso una fecha 1 y una fecha 2 y me devuelve el nro de la más reciente
{

	int lastDate;
	timeBetweenDates = difftime(sDate, fDate); //ya me llenó el double que pasé por alias
	if (timeBetweenDates == -1)
		lastDate = -1; //verifico que no me devuelva un error
	else  // hace t2-t1 entonces si es menor que 0 es porque t1 es más grande que t2 --> t1 es más nueva que t2
	{
		lastDate = (timeBetweenDates < 0) ? 1 : 2;
	}
	timeBetweenDates = abs(timeBetweenDates);
	return lastDate;
}
//le doy dos fechas, me devuelve la posición de la más reciente y me llena el double con la diferencia entre las fechas

//CATEGORIZAR PACIENTES
int keepingUpWithThePacients(pacient paux, int sizeListApp, appointment* listApp) // 1= recoverable//2=unrecoverable//3=queti
{
	if (listApp == nullptr)
		return -1; //VERIFICO ERROR <3
	int category = -1; //INICIALIZO EN -1 ASÍ LA DEVUELVO AL FINAL
	paux.state = UP(paux.state);
	if (paux.state == "INTERNADO")
		category = 3; // ya sé que está internado, no lo voy a llamar
	else
	{

		if (paux.state == "FALLECIDO")
			category = 2;//irrecuperable
		else
		{
			time_t current = time(0); //hoy
			appointment dummyApp = lastApp(paux.dni, sizeListApp, listApp); //dummy porque solo me importan la fecha y el booleano
			time_t lastAppDate = convertDateToTimeT(dummyApp.dateAppointment);
			double timeBD;
			int lastD = compareDates(current, lastAppDate, timeBD);
			switch (lastD)
			{
			case -1:
				return -1;
			case 1: //la fecha más nueva es hoy --> ya pasó
			{

				if (timeBD < tenYears)//tengo que ver si fue hace más de 10 años
				{
					if (dummyApp.asistance == 1) // hace 10 años y vino --> OK --> no me importa
						category = 3;
					else //hace menos de 10 años y no vino --> lo tengo que llamar llamar
						category = 1;
				}
				else //fue hace más de 10 años --> no lo puedo recuperar
					category = 2;
				break;
			}
			case 2://la fecha más nueva es la de la app --> todavía no fue 
			{
				category = 3;//tiene programada una appointment para el futuro --> no me importa
				break;
			}
			}
		}
	}
	return category;
}
//devuelve un int con la categoría
appointment lastApp(unsigned int dniAux, int sizeListApp, appointment* listApp)
{
	double dummy;
	appointment lastAppointment;
	lastAppointment.dniPacient = 0;//devuelve 0 en el dni por un error! --> me pasaron un null ptr o no encuentro al dni en la lista de appointment
	if (listApp != nullptr)
	{
		int i;
		bool found = false; //flag para la primera vez que lo encontro

		for (i = 0; i < sizeListApp; i++)
		{
			if (listApp[i].dniPacient == dniAux) // si recorre todo y no lo encuentra entonces no me guarda nada y el dni sigue siendo 0
			{
				if (!found)//primera vez que encuentro el paciente
				{
					lastAppointment = listApp[i];
					found = true;
				}
				else
				{
					time_t lAppGuardada = convertDateToTimeT(lastAppointment.dateAppointment);
					time_t newLA = convertDateToTimeT(listApp[i].dateAppointment);
					int lD = compareDates(lAppGuardada, newLA, dummy);// nombre=lastdate//va a ser un 1 si la que ya tenía guardada es más reciente 
					if (lD == -1)
						break;
					else if (lD == 2) //la que estoy leyendo ahora es más reciente --> las cambio
						lastAppointment = listApp[i];
				}
			}

		}
	}

	return lastAppointment;
}
//le doy un dni y me devuelve la ultima consulta del paciente
void writeLists(pacient* totalList, int totalSize, pacient*& listUnrecoverable, int& sizeUnrecoverable, secretaryList*& listRecoverable, int& sizeRecoverable, int sizeApp, appointment* listApp, contact* listCon, int sizeCon)
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

//GENERAR CON RANDOM
string generateRandomAppDate(int x)
{
	string newDate = "error"; //lo inicializo así por las dudas aunque no sé por qué no me guardaría la nueva fecha, de todos modos si no salió sabemos que es un error 

	srand(x);
	bool again = false;

	int year = rand() % 2 + 2023; //si es un 0 --> 2023; si es 1 --> 2024 asumo que no se puede programar una app para dentro de 25 años porque ya se murieron todos, abrazo // asumo que no pongo más para este año porque mis médicos tienen demora de un mes por la consulta y estamos en diciembre :))))
	int month = rand() % 12 + 1;//me da un nro de 0 a 11 y lo cambio para que sea de 1 a 12 
	int day;
	if (month == 2)
		day = rand() % 28 + 1;//no verifico que sea un año bisiesto, el 29 es dia de ñoquis y mis doctores no atienden
	else
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			day = rand() % 30 + 1;
		}
		else
			day = rand() % 31 + 1;
	newDate = to_string(day) + '/' + to_string(month) + '/' + to_string(year);//la paso a string  --> es lo que voy a devolver 

	string newDateRet = newDate;
	newDate = '0';
	return newDateRet;
}

//AUXILIARES
string UP(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = toupper(word[i]);
	}
	return word;
}
//me pasa la palabra a mayúscula
void generateInsuranceList(pacient* totalList, int sizeTotal, string*& listIn, int& sizeIn)
{
	if (totalList == nullptr || listIn == nullptr)
		return;

	bool first;
	int i;
	for (i = 0; i < sizeTotal; i++)
	{
		first = true; //vuelvo a inicializar

		for (int k = i - 1; k >= 0; k--) //recorro el array para arriba y me fijo si ya estaba la obra social del paciente que estoy leyendo
		{
			if (listIn[k] == totalList[i].idInsurance)
				first = false;
		}

		if (first)
			addString(listIn, sizeIn, totalList[i].idInsurance);
	}
	return;
}
//lee el array de pacientes y crea una lista de tipo string con las obras sociales presentes en la lista de pacientes --> asumimos que el hospital trabaja únicamente con las obras sociales de la lista (todas las os con las que trabaja e´stán incluídas)

//SECRETARÍA
secretaryList convertToSecretary(pacient paux, appointment* listApp, int sizeApp, contact* listCon, int sizeCon)
{
	secretaryList error; //struct del tipo secretaria lleno con 0s que devuelvo en caso de error
	error.answerSecL = '0';
	error.cellphoneNumberSecL = '0';
	error.dniSecL = 0;
	error.idDoctorSecL = '0';
	error.lastNamePacientSecL = '0';
	error.medicalInsuranceSecL = '0';
	error.namePacientSecL = '0';

	if (listApp == nullptr || listCon == nullptr)
		return error;

	secretaryList newPacient; //lleno los campos del struct con los datos que ya conozco
	newPacient.namePacientSecL = paux.namePacient;
	newPacient.lastNamePacientSecL = paux.lastNAmePacient;
	newPacient.dniSecL = paux.dni;
	newPacient.medicalInsuranceSecL = paux.idInsurance;
	newPacient.cellphoneNumberSecL = '0'; //inicializo en 0 por si nunca lo encuentra

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



	return newPacient;

}
//convierte un paciente al struct de secretaria 
void pacientsUpdate(secretaryList*& recoverableList, int sizeRec, string* InsuranceList, int sizeIL, appointment*& newApp, int& sizeNewApp) //funcion de actualizacion de datos
{
	if (recoverableList == nullptr || InsuranceList == nullptr || newApp == nullptr)
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

	srand(time(NULL));
	for (int i = 0; i < sizeRec; i++)
	{
		if (recoverableList[i].cellphoneNumberSecL != "0") //significaría que no existe el contacto en el archivo 
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
						int x = rand() % 100; //pongo limite x las dudas pero no se si es necesario;
						newAppDate = generateRandomAppDate(x);
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
		else
			recoverableList[i].answerSecL = "NoTengoSuTelefono";
	}

	delete[] InsuranceList;
	InsuranceList = NULL;

}
//funcion de llamado de pacientes para cambiar sus datos, generar nuevas consultas o informar que ya no van a volver a atenderse en el hospital



