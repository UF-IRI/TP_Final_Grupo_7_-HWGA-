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