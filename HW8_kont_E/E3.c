/* Максимум и минимум
Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
Формат входных данных
10 целых чисел через пробел
Формат результата
4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0
Результат работы
4 10 8 -10
Входные данные
1 2 3 4 5 6 7 8 9 10
Результат работы
10 10 1 1 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>

#define SIZE 10


int m[SIZE] = {0};
int a;

// Max search
int max (int *arr, int len)
{
    int maxx = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (maxx<arr[i])
            maxx=arr[i];
    }
    return maxx;
}

// MaxPosition search
int maxpos (int *arr, int len)
{
    int maxp = 0;
    int maxx = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (maxx<arr[i])
        {
            maxx=arr[i];
            maxp = i;
        }
    }
    return maxp+1;
}

// Min search
int min (int *arr, int len)
{
    int minn = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (minn>arr[i])
            minn=arr[i];
    }
    return minn;
}

// MinPosition search
int minpos (int *arr, int len)
{
    int minp = 0;
    int minn = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (minn>arr[i])
        {
            minn=arr[i];
            minp = i;
        }
    }
    return minp+1;
}

int main(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        scanf ("%d", &a);
        m[i]=a;
    }

    printf ("%d ", maxpos(m,SIZE));
    printf ("%d ", max(m,SIZE));
    printf ("%d ", minpos(m,SIZE));
    printf ("%d", min(m,SIZE));
    return 0;
}
