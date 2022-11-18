
#include"FUNCIONES.h"

int keepingUpWithThePacients(pacient paux, int sizeListApp, appointment* listApp)
{

}
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


time_t convertDate(string dato)
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
int compareDates(string fDate, string sDate) // le paso una fecha 1 y una fecha 2 y me devuelve el nro de la más reciente
{
	time_t firstD = convertDate(fDate);
	time_t secondD = convertDate(sDate);

	int lastDate;

	double timeBetweenDates = difftime(secondD, firstD);
	if (timeBetweenDates == -1)
		lastDate = -1; //verifico que no me devuelva un error
	else  // hace t2-t1 entonces si es menor que 0 es porque t1 es más grande que t2 --> t1 es más nueva que t2
	{
		lastDate = (timeBetweenDates<0)?1:2 ;
	}

	return lastDate;
}
