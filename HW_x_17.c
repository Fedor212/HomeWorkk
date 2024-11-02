/*
Какое время года
Ввести номер месяца и вывести название времени года.
Формат входных данных
Целое число от 1 до 12 - номер месяца.
Формат результата
Время года на английском: winter, spring, summer, autumn
Примеры
Входные данные
4
Результат работы
spring
Входные данные
1
Результат работы
winter
*/

#include <stdio.h>
#include <math.h>
//#include <locale.h>

int main(void)
{
	int a;
	
	scanf ("%d", &a);
	
	if((a==12) | (a==1) | (a==2))
	{
		printf ("winter");	
	}
	if((a==3) | (a==4) | (a==5))
	{
		printf ("spring");	
	}
	if((a==6) | (a==7) | (a==8))
	{
		printf ("summer");	
	}
	if((a==9) | (a==10) | (a==11))
	{
		printf ("autumn");	
	}
	
	return 0;
}

