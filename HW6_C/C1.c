/*Модуль числа
Составить функцию, модуль числа и привести пример ее использования.
Формат входных данных
Целое число
Формат результата
Целое не отрицательное число */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

	int a, b;
	
int abss (int a)
{
	if (a>=0)	
		return a;
	return -a;
}

int main(void)
{
    scanf ("%d", &a);    
    b = abss(a);
    printf ("%d", b);
    return 0;
}
