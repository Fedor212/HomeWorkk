/* Сумма положительных элементов
Считать массив из 10 элементов и посчитать сумму положительных элементов массива.
Формат входных данных
10 целых чисел через пробел
Формат результата
Одно целое число - сумма положительных элементов массива
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0
Результат работы
26
Входные данные
1 -2 3 -4 5 -6 7 -8 9 0
Результат работы
25 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>

#define SIZE 10


int m[SIZE] = {0};
int a;
int summ = 0;

int main(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        scanf ("%d", &a);
        m[i]=a;
    }

    for (int i = 0; i < SIZE; i++)
    {
       if (m[i]>0)
        summ += m[i];
    }
    printf ("%d", summ);

    return 0;
}
