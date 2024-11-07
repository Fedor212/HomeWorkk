/*
Наибольшее из трех чисел
Ввести три числа и найти наибольшее из них
Формат входных данных
Три целых числа через пробел
Формат результата
Одно наибольшее целое число
Примеры
Входные данные
4 15 9
Результат работы
15
*/

#include <stdio.h>
#include <math.h>
//#include <locale.h>

int main(void)
{
	int a, b, c;
	
	scanf ("%d%d%d", &a, &b, &c);
	
	
	if(a<b)
	{
		a=b;
	}
	
	c>a ? printf ("%d", c) : printf ("%d", a);
	
	
	// Old Rev. 
	/*
	if(a<b)
	{
		a=b;
	}
	if(c>a)
	{
		printf ("%d", c);
	}
	else
	{
		printf ("%d", a);
	}
	*/
	return 0;
}
