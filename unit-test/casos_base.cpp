#include "gmock/gmock.h"
#include "FUNCIONES.h"
namespace Casos_Base::tests 
	
{
	/*TEST(convertDateToTimeT, C1)
	{
		tm day;//la inicializo en tm parra pasarla a time_t y es string para verificar que me den lo mismo
		day.tm_year = 2022;
		day.tm_mon = 11; //dic
		day.tm_mday = 18; 

		string daySTR = "18/11/2022";

		time_t seg = mktime(&day);

		EXPECT_THAT(convertDateToTimeT(daySTR), seg);

	}
	
	
	TEST(compareDates, normal) //normalito
	{
	
		time_t todayt = time(0);

		string sod = "12/11/2022";
		time_t sodT = convertDateToTimeT(sod);

		EXPECT_THAT(compareDates(todayt, sodT), 1);
	}

	TEST(compareDates, sameday)
	{
		string sameD = "12/11/2006";
		time_t sameDT = convertDateToTimeT(sameD);

		EXPECT_THAT(compareDates(sameDT, sameDT), 2);

	}*/
}