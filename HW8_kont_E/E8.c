/* Инверсия каждой трети
Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
Формат входных данных
12 целых чисел через пробел
Формат результата
12 целых чисел через пробел
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0 5 7
Результат работы
10 3 -5 4 -10 8 -6 -4 7 5 0 1
Входные данные
1 2 3 4 5 6 7 8 9 10 11 12
Результат работы
4 3 2 1 8 7 6 5 12 11 10 9 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>

#define SIZE 12
#define THIRDSIZE 4

int m[SIZE] = {0};
int hs[THIRDSIZE] = {0};
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


// Three part invert
void threepartinv (int *arr, int len)
{
    for (int i = 0; i < THIRDSIZE; i++)
    {
        hs[i]=m[i];
    }
    inversion (hs,THIRDSIZE);
    for (int i = 0; i < THIRDSIZE; i++)
    {
        m[i]=hs[i];
    }
    /////////////////////////////////////////
    for (int i = 0; i < THIRDSIZE; i++)
    {
        hs[i]=m[i+THIRDSIZE];
    }
    inversion (hs,THIRDSIZE);
    for (int i = 0; i < THIRDSIZE; i++)
    {
        m[i+THIRDSIZE]=hs[i];
    }
    //////////////////////////////////////////
    for (int i = 0; i < THIRDSIZE; i++)
    {
        hs[i]=m[i+THIRDSIZE+THIRDSIZE];
    }
    inversion (hs,THIRDSIZE);
    for (int i = 0; i < THIRDSIZE; i++)
    {
        m[i+THIRDSIZE+THIRDSIZE]=hs[i];
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
    threepartinv  (m,SIZE);
    printmass(m,SIZE);

    return 0;
}
