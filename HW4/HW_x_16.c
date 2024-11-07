/*
В порядке возрастания
Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.
Формат входных данных
Три целых числа
Формат результата
Одно слово YES или NO
Примеры
Входные данные
4 5 17
Результат работы
YES
*/

#include <stdio.h>
#include <math.h>
//#include <locale.h>

int main(void)
{
	int a, b, c;	
	scanf ("%d%d%d", &a, &b, &c);
	
	((a<b) & (b<c)) != 0 ? printf ("YES") : printf ("NO");
	
	/*  Old Rev/
	if((a<b) & (b<c))
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

