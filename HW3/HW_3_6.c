/*
Ввести два числа и найти их разность
Нужно напечатать разность двух чисел
Данные на входе:       Два целых числа через пробел
Данные на выходе:    Одно целое число
Пример №1: 
Данные на входе:        4 5
Данные на выходе:     -1 
Пример №2:     
Данные на входе:        100 49
Данные на выходе:     51
*/

#include <stdio.h>
#include <math.h>
//#include <locale.h>

int main(void)
{
	int a, b;
	
	scanf ("%d%d", &a, &b);
	printf ("%d", a-b);

	return 0;
}

