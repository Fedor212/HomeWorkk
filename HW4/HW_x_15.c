/*
Уравнение прямой
Определить уравнение прямой по координатам двух точек. Уравнение вида y=k*x+b
Формат входных данных
Четыре целых числа через пробел. Координаты X1 Y1 X2 Y2
Формат результата
Два числа K,B в формате "%.2f %.2f"
Примеры
Входные данные
6 9 -1 3
Результат работы
0.86 3.86
Входные данные
1 2 3 4
Результат работы
1.00 1.00
*/

#include <stdio.h>
#include <math.h>
//#include <locale.h>

int main(void)
{
	int x1, y1, x2, y2;
	float k, b;
	float xx1, yy1, xx2, yy2;
	scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
	xx1 = x1, xx2 = x2, yy1 = y1, yy2 = y2;
	k=(yy2-yy1)/(xx2-xx1);
	b= yy1-xx1*(yy2-yy1)/(xx2-xx1);
	printf ("%.2f %.2f", k, b);
	return 0;
}

