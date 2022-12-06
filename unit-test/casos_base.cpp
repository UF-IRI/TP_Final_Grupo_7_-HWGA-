#include "gmock/gmock.h"
#include "FUNCIONES.h"
#include "iri.cpp"
namespace Casos_Base::tests 

{
	
	TEST(convertDateToTimeT, test)
	{
		tm day{};//la inicializo en tm para pasarla a time_t y es string para verificar que me den lo mismo
		day.tm_year = 122; //2022-1900
		day.tm_mon = 11; //12-1
		day.tm_mday = 18; 

		string daySTR = "18/12/2022";

		time_t seg = mktime(&day);

		EXPECT_THAT(convertDateToTimeT(daySTR), seg);

	}
	
	
	TEST(compareDates, caso1)
	{
		double dummy;
	
		time_t todayt = time(0);

		string sod = "12/11/2022";
		time_t sodT = convertDateToTimeT(sod);

		EXPECT_THAT(compareDates(todayt, sodT, dummy), 1);
	}

	TEST(compareDates, caso2)
	{
		string sameD = "12/11/2006";
		time_t sameDT = convertDateToTimeT(sameD);

		double dummy2;

		EXPECT_THAT(compareDates(sameDT, sameDT, dummy2), 2);

	}

	TEST(convertDateToString, test1)
	{
		string hoy = "3/12/2022";
		time_t today = convertDateToTimeT(hoy);//de paso corroboro que convertDateToTimeT funciona
		string aver;

		EXPECT_EQ(aver = convertDateToString(today), hoy);
	}

	TEST(convertDateToString, test2)
	{
		string cumpleAlma = "11/9/2003";
		time_t almasBday = convertDateToTimeT(cumpleAlma);
		string aver;

		EXPECT_EQ(aver = convertDateToString(almasBday), cumpleAlma);
	}

	TEST(keepingUpWithThePacients, irrecuperable)
	{
		pacient aux;
		aux.dni = 10242590;
		aux.dateBirth ="28/8/1971";
		aux.idInsurance = "Medicus";
		aux.lastNAmePacient = "Tilley";
		aux.namePacient ="Johannes";
		aux.sex='F';
		aux.state = "fallecido";

		//para que me llene la lista de appointments
		int sizeApp = 0;
		appointment* list = new appointment[sizeApp];

		string archivoCons = (BASE_PATH + "../data_files/input/Consultas.csv");
		fstream fpApp;
		fpApp.open(archivoCons, ios::in);
		readApp(fpApp, list, sizeApp);
		fpApp.close();

		EXPECT_THAT(keepingUpWithThePacients(aux, sizeApp, list), 2);

		delete[]list;
		list = NULL;

	}

	TEST(keepingUpWithThePacients, recuperable)
	{
		pacient aux;
		aux.dni = 18902838;
		aux.dateBirth = "8/10/2019";
		aux.idInsurance = "Espanyol";
		aux.lastNAmePacient = "Rose";
		aux.namePacient = "Merita";
		aux.sex = 'F';
		aux.state = "n/c";

		int sizeApp = 0;
		appointment* list = new appointment[sizeApp];

		string archivoCons = (BASE_PATH + "../data_files/input/Consultas.csv");
		fstream fpApp;
		fpApp.open(archivoCons, ios::in);
		readApp(fpApp, list, sizeApp);
		fpApp.close();

		EXPECT_THAT(keepingUpWithThePacients(aux, sizeApp, list), 1);

		delete[]list;
		list = NULL;

	}

	TEST(keepingUpWithThePacients, noMeImporta)
	{
		pacient aux;
		aux.dni = 48363883;
		aux.dateBirth = "13/3/1971";
		aux.idInsurance = "Medicus";
		aux.lastNAmePacient = "Jimenez";
		aux.namePacient = "Blandine";
		aux.sex = 'M';
		aux.state = "internado";

		int sizeApp = 0;
		appointment* list = new appointment[sizeApp];

		string archivoCons = (BASE_PATH + "../data_files/input/Consultas.csv");
		fstream fpApp;
		fpApp.open(archivoCons, ios::in);
		readApp(fpApp, list, sizeApp);
		fpApp.close();

		EXPECT_THAT(keepingUpWithThePacients(aux, sizeApp, list), 3);

		delete[]list;
		list = NULL;

	}
	

	TEST(generateInsuranceList, test)
	{
		int sizeIL = 0;
		string* InsuranceList = new string[sizeIL];

		//para que me llene la lista de pacientes
		int sizePac = 0;
		pacient* listPacients = new pacient[sizePac];

		string archivoPac=(BASE_PATH + "../data_files/input/Pacientes.csv");
		fstream fpPac;
		fpPac.open(archivoPac, ios::in);
		readPac(fpPac, listPacients, sizePac);
		fpPac.close();

		generateInsuranceList(listPacients, sizePac, InsuranceList, sizeIL);

		//si todo salio bien tendrian que estar las 6 obras sociales en la lista
		int cont = 0;
		bool found1, found2, found3, found4, found5, found6;
		found1 = found2 = found3 = found4 = found5 = found6 = false;

		for (int i = 0; i < sizeIL; i++)
		{
			if (InsuranceList[i] == "Medicus" && !(found1))
			{
				cont++;
				found1 = true;
			}
			else if (InsuranceList[i] == "Italiano" && !(found2))
			{
				cont++;
				found2 = true;
			}
			else if (InsuranceList[i] == "Espanyol" && !(found3))
			{
				cont++;
				found3 = true;
			}
			else if (InsuranceList[i] == "Aleman" && !(found4))
			{
				cont++;
				found4 = true;
			}
			else if (InsuranceList[i] == "IOSFA" && !(found5))
			{
				cont++;
				found5 = true;
			}
			else if (InsuranceList[i] == "OSDE" && !(found6))
			{
				cont++;
				found6 = true;
			}
		}

		EXPECT_THAT(cont, 6);

		delete[]InsuranceList;
		InsuranceList = NULL;
		delete[]listPacients;
		listPacients = NULL;
	}
	
	
	TEST(convertToSecretary, test1)
	{
		//lleno la lista de appointments
		int sizeApp = 0;
		appointment* listApp = new appointment[sizeApp];

		string archivoCons = (BASE_PATH + "../data_files/input/Consultas.csv");
		fstream fpApp;
		fpApp.open(archivoCons, ios::in);
		readApp(fpApp, listApp, sizeApp);
		fpApp.close();
	
		//lleno la lista de contactos
		int sizeCon = 0;
		contact* listCon = new contact[sizeCon];

		string archivoCon = (BASE_PATH + "../data_files/input/Contactos.csv");
		fstream fpCon;
		fpCon.open(archivoCon, ios::in);
		readCon(fpCon, listCon, sizeCon);
		fpCon.close();

		pacient aux;
		aux.dni = 18902838;
		aux.dateBirth = "8/10/2019";
		aux.idInsurance = "Espanyol";
		aux.lastNAmePacient = "Rose";
		aux.namePacient = "Merita";
		aux.sex = 'F';
		aux.state = "n/c";

		secretaryList auxSec = convertToSecretary(aux, listApp, sizeApp,listCon, sizeCon);
		appointment lastAppDate = lastApp(aux.dni, sizeApp, listApp); //de paso pruebo que funcione lastApp

		EXPECT_THAT(auxSec.dniSecL, aux.dni);
		EXPECT_EQ(auxSec.medicalInsuranceSecL, aux.idInsurance);
		EXPECT_EQ(auxSec.namePacientSecL, aux.namePacient);
		EXPECT_EQ(auxSec.lastNamePacientSecL, aux.lastNAmePacient);
		EXPECT_EQ(auxSec.cellphoneNumberSecL, "+54(754)14065272");
		EXPECT_EQ(auxSec.idDoctorSecL, lastAppDate.idDoctor);

		delete[]listApp;
		listApp = NULL;
		delete[]listApp;
		listApp = NULL;
	}

	TEST(convertToSecretary, test2)
	{
		int sizeApp = 0;
		appointment* listApp = new appointment[sizeApp];

		string archivoCons = (BASE_PATH + "../data_files/input/Consultas.csv");
		fstream fpApp;
		fpApp.open(archivoCons, ios::in);
		readApp(fpApp, listApp, sizeApp);
		fpApp.close();

		int sizeCon = 0;
		contact* listCon = new contact[sizeCon];

		string archivoCon = (BASE_PATH + "../data_files/input/Contactos.csv");
		fstream fpCon;
		fpCon.open(archivoCon, ios::in);
		readCon(fpCon, listCon, sizeCon);
		fpCon.close();

		pacient aux;
		aux.dni = 48363876;
		aux.dateBirth = "11/10/1998";
		aux.idInsurance = "IOSFA";
		aux.lastNAmePacient = "Maldonado";
		aux.namePacient = "Domino";
		aux.sex = 'F';
		aux.state = "n/c";

		secretaryList auxSec = convertToSecretary(aux, listApp, sizeApp, listCon, sizeCon);
		appointment lastAppDate = lastApp(aux.dni, sizeApp, listApp); 

		EXPECT_THAT(auxSec.dniSecL, aux.dni);
		EXPECT_EQ(auxSec.medicalInsuranceSecL, aux.idInsurance);
		EXPECT_EQ(auxSec.namePacientSecL, aux.namePacient);
		EXPECT_EQ(auxSec.lastNamePacientSecL, aux.lastNAmePacient);
		EXPECT_EQ(auxSec.cellphoneNumberSecL, "+54(221)19935438");
		EXPECT_EQ(auxSec.idDoctorSecL, lastAppDate.idDoctor);

		delete[]listApp;
		listApp = NULL;
		delete[]listApp;
		listApp = NULL;
	}
	

}