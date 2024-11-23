/* Найти минимум
Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.
Формат входных данных
5 целых чисел через пробел
Формат результата
Одно единственное целое число
 */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>

#define SIZE 5


int m[SIZE] = {0};
int a;


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


int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        scanf ("%d", &a);
        m[i]=a;
    }

    printf ("%d", min(m,SIZE));
    return 0;
}
