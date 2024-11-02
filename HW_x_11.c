/*
Сумма максимума и минимума
Напечатать сумму максимума и минимума.
Формат входных данных
Пять целых чисел через пробел
Формат результата
Одно целое число - сумма максимума и минимума
Примеры
Входные данные
4    15    9    56    4
Результат работы
60
*/

#include <stdio.h>
#include <math.h>
//#include <locale.h>

int main(void)
{
	int a, b, c, d, e, max, min;
	
	scanf ("%d%d%d%d%d", &a, &b, &c, &d, &e);
	
	if(a>b)
	{
		min=b;
		max=a;
	}
	else
	{
		min=a;
		max=b;
	}
	
	if(c>max)
	{
		max=c;
	}
		
	if(c<min)
	{
		min=c;
	}
	
	if(d>max)
	{
		max=d;
	}		
	if(d<min)
	{
		min=d;
	}
	
	if(e>max)
	{
		max=e;
	}		
	if(e<min)
	{
		min=e;
	}

	printf ("%d", min+max);

	
	return 0;
}

