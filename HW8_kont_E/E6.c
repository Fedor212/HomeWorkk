/* Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.
Формат входных данных
5 целых не нулевых чисел через пробел
Формат результата
Олно число в формате "%.3f"
 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>

#define SIZE 12


int m[SIZE] = {0};
float summ;
int a;


int main(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        scanf ("%d", &a);
        m[i]=a;
        summ = summ + (float)a;
    }
    summ = summ/SIZE;
  printf ("%.2f", summ);
    return 0;
}
