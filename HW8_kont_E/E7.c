/* Инверсия половинок
Считать массив из 10 элементов и выполнить инверсию
отдельно для 1-ой и 2-ой половин массива. Необходимо
 изменить считанный массив и напечатать его одним циклом.
Формат входных данных
10 целых элементов массива через пробел.
Формат результата
10 целых элементов массива через пробел.
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0
Результат работы
-4 10 3 -5 4 0 1 -10 8 -6
Входные данные
1 2 3 4 5 6 7 8 9 10
Результат работы
5 4 3 2 1 10 9 8 7 6 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>

#define SIZE 10
#define HALFSIZE 5

int m[SIZE] = {0};
int hs[HALFSIZE] = {0};
float summ;
int a;

void inversion (int *arr, int len)
{
    int temp[len];
    int j=len-1;
    for (int i = 0; i < len; i++)
    {
        temp[j]=arr[i];
        j--;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i]=temp[i];
    }
}


// Two Half invert
void twohalfinv (int *arr, int len)
{
    for (int i = 0; i < HALFSIZE; i++)
    {
        hs[i]=m[i];
    }
    inversion (hs,HALFSIZE);
    for (int i = 0; i < HALFSIZE; i++)
    {
        m[i]=hs[i];
    }

    for (int i = 0; i < HALFSIZE; i++)
    {
        hs[i]=m[i+HALFSIZE];
    }
    inversion (hs,HALFSIZE);
    for (int i = 0; i < HALFSIZE; i++)
    {
        m[i+HALFSIZE]=hs[i];
    }
}



// Print Massive
void printmass (int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf ("%d ", arr[i]);
    }
}


int main(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        scanf ("%d", &a);
        m[i]=a;
    }

    //~ printmass(m,SIZE);
    //~ printf ("\n");
    twohalfinv (m,SIZE);
    printmass(m,SIZE);

    return 0;
}
