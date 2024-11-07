/*
Существует ли треугольник
Даны стороны треугольника a, b, c. Определить существует ли такой треугольник.
Формат входных данных
Три целых числа. Стороны треугольника a, b, c.
Формат результата
YES или NO 
*/

#include <stdio.h>
#include <math.h>
//#include <locale.h>

int main(void)
{
	int a, b, c;
	
	scanf ("%d%d%d", &a, &b, &c);
	
	(((a+b)>c)&((b+c)>a)&((c+a)>b)) != 0 ? printf ("YES") : printf ("NO");
	/*
	if(((a+b)>c)&((b+c)>a)&((c+a)>b))
	{
		printf ("YES");	
	}	
	else
	{
		printf ("NO");	
	}	
	*/
	return 0;
}

