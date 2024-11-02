/*
Наибольшее из пяти чисел
Ввести пять чисел и найти наибольшее из них.
Формат входных данных
Пять целых чисел разделенных пробелом
Формат результата
Одно целое число
Примеры
Входные данные
4    15    9    56    4
Результат работы
56
*/

#include <stdio.h>
#include <math.h>
//#include <locale.h>

int main(void)
{
	int a, b, c, d, e;
	
	scanf ("%d%d%d%d%d", &a, &b, &c, &d, &e);
	if(a<b)
	{
		a=b;
	}
	if(a<c)
	{
	a=c;
	}
	if(a<d)
	{
	a=d;
	}
	if(e>a)
	{
		printf ("%d", e);
	}
	else
	{
		printf ("%d", a);
	}
	
	return 0;
}

