
#include"FUNCIONES.h"

int keepingUpWithThePacients(pacient paux, int sizeListApp, appointment* listApp) // 1= recoverable//2=unrecoverable//3=queti
{
	if (listApp == nullptr)
		return -1; //VERIFICO ERROR <3
	int category = -1; //INICIALIZO EN -1 ASÍ LA DEVUELVO AL FINAL
	bool went;
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
			time_t lastAppDate = convertToTimeT(dummyApp.dateAppointment);
			double timeBD;
			int LastD = compareDates(current, lastAppDate, &timeBD);
			switch (lastD)
			{
			case -1:
				return -1;
			case 1: //la fecha más nueva es hoy --> ya pasó
			{

				if (timeBD < 10ANIOS)//tengo que ver si fue hace más de 10 años
				{
					if (dummyApp.asistance) // hace 10 años y vino --> OK --> no me importa
						category = 3;
					else //hace menos de 10 años y no vino --> lo tengo que llamar llamar
						category = 1;
				}
				else //fue hace más de 10 años --> no lo puedo recuperar
					category = 2;
			}
			case 2://la fecha más nueva es la de la app --> todavía no fue 
			{
				category = 3; //tiene programada una appointment para el futuro --> no me importa
			}
			}
		}
	}
	return category;
}
//devuelve un int con la categoría
string UP(string word)
{
	for (int i = 0; i < strlen(word); i++)
	{
		word[i] = toupper(word[i]);
	}
	return word;
}
//me pasa la palabra a mayúscula
appointment lastApp(unsigned int dniAux, int sizeListApp, appointment* listApp)
{
	appointment lastAppointment;
	lastAppointment.dniPacient = 0;//devuelve 0 en el dni por un error! --> me pasaron un null ptr o no encuentro al dni en la lista de appointment
	if (listApp != nullptr)
	{
		int i;
		bool found = false; //flag para la primera vez que lo encontro

		for (i = 0; i < sizeListApp; i++)
		{
			if (listApp->dniPacient == dniAux) // si recorre todo y no lo encuentra entonces no me guarda nada y el dni sigue siendo 0
			{
				if (!found)//primera vez que encuentro el paciente
				{
					lastAppointment = *listApp[i];
					found = true;
				}
				else
				{
				
					int lD = compareDates(lastAppointment.dateAppointment, listApp[i]->dateAppointment)// nombre=lastdate//va a ser un 1 si la que ya tenía guardada es más reciente 
						if (lD == -1)
							//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!HUBO UN ERROR, DECIDIR QUE DEVUELVE O SI DIRECTAMENTE BREAKEO Y ME VOY DE LA FUNCION CON EL DATO DE LA ÚLTIMA FECHA QUE ENCONTRE ANTES DE PONER EN TRUE EL BOOLEANO !!!!!!!!!!!!!!!!!!!!
						else if (ld == 2) //la que estoy leyendo ahora es más reciente --> las cambio
							lastAppointment = *listApp[i];
				}
			}

		}
	}
	
	return lastAppointment;
}
//le doy un dni y me devuelve la ultima consulta del paciente
time_t convertDateToTimeT(string dato)
{
	int i = 0;
	int day, month, year;
	int cont = 0;
	string auxD, auxM, auxY;

	while (dato[i] != '\0')
	{
		int k = 0;
		while (dato[i] != '/')
		{

			switch (cont)
			{
			case 0:
			{
				auxM[k] = dato[i];
				break;
			}
			case 1:
			{
				auxD[k] = dato[i];
				break;
			}
			case 2:
			{
				auxY[k] = dato[i];
				break;
			}
			}
			k++;
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
int compareDates(time_t fDate, time_t sDate, double &timeBetweenDates) // le paso una fecha 1 y una fecha 2 y me devuelve el nro de la más reciente
{
	
	int lastDate;
	timeBetweenDates = difftime(sDate, fDate); //ya me llenó el double que pasé por alias
	if (timeBetweenDates == -1)
		lastDate = -1; //verifico que no me devuelva un error
	else  // hace t2-t1 entonces si es menor que 0 es porque t1 es más grande que t2 --> t1 es más nueva que t2
	{
		lastDate = (timeBetweenDates<0)?1:2 ;
	}

	return lastDate;
}
//le doy dos fechas, me devuelve la posición de la más reciente y me llena el double con la diferencia entre las fechas

void addPacient(pacient*& listP, int& sizeP, pacient auxP)
{
	if (listP == nullptr)
		return;
	pacient * newListP = new pacient[sizeP + 1];
	int i;
	for (i = 0; 1 < sizeP; i++)
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
	if (listCo == nullptr)
		return;
	contact newListCon = new contact[sizeCon];
	int i;
	for (i = 0; i < sizeCon; i++)
		newListCon[i] = listCon[i];
	newListCon = auxCon;

	sizeCon++;
	delete[] listCon;
	listCon = newListCon;
	return;
}
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
//TODAS RESIZE NORMALITAS 

void writeLists(pacient* totalList, int totalSize, pacient*& listUnrecoverable, int& sizeUnrecoverable, pacient*& listRecoverable, int& sizeRecoverable, int sizeApp, appointment* listApp)
{
	if (totalList == nullptr || listUnrecoverable == nullptr || listRecoverable == nullptr || listApp == nullptr)
		return;

	int i;
	int cat;

	for (i = 0; i < totalSize; i++)
	{
		cat = keepingUpWithThePacients(totalList[i], sizeApp, listApp);
		switch (cat)
		{
		case 1:
		{
			//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			break;
		}
		case 2: //irrecuperable
		{
			addPacient(listUnrecoverable, sizeUnrecoverable, totalList[i]); //lo agrego a la lista de irrecuperables
		}

		}
	}
}
//le paso una lista con todos los pacientes y me devuelve dos listas separadas de recuperables/no recuperables
void generateInsuranceList(pacient* totalList, int sizeTotal, string*& listIn, int& sizeIn)
{
	if (totalList == nullptr || listIn == nullptr)
		return;

	bool first;
	int i;
	for (i=0;i<sizeTotal;i++)
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











