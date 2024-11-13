/*Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.
Формат входных данных
Одно целое положительное число N
Формат результата
Целое число - сумма чисел от 1 до N
Примеры
Входные данные
100
Результат работы
5050 */

//#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

int a, b;

int fact (int a)
{
		int c =0;
        for (int i=1; i<=a; i++)
            c+=i;
                return c;
    
   
}

int main(void)
{
    scanf ("%d", &a);
    b = fact(a);
    printf ("%d", b);
    return 0;
}
