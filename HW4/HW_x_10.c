/*
Наименьшее из пяти чисел
Ввести пять чисел и найти  наименьшее из них.
Формат входных данных
Пять целых чисел
Формат результата
Одно целое число
Примеры
Входные данные
4    15    9    56    4
Результат работы
4
*/

#include <stdio.h>
#include <math.h>
//#include <locale.h>

int main(void)
{
	int a, b, c, d, e;
	
	scanf ("%d%d%d%d%d", &a, &b, &c, &d, &e);
	
	a = a>b ? b : a;
	a = a>c ? c : a;
	a = a>d ? d : a;
	a>e ? printf ("%d", e) : printf ("%d", a);
	
	/*     Old Rev
	 
	if(a>b)
	{
		a=b;
	}
	
	if(a>c)
	{
	a=c;
	}
	if(a>d)
	{
	a=d;
	}
	if(a>e)
	{
		printf ("%d", e);
	}
	else
	{
		printf ("%d", a);
	}
	*/
	return 0;
}
