/*Отсортировать по последней цифре
Считать массив из 10 элементов и отсортировать его по последней цифре.
Формат входных данных
10 целых чисел через пробел
Формат результата
Этот же массив отсортированный по последней цифре
Примеры
Входные данные
14  25  13  30  76  58  32  11  41  97
Результат работы
30  11  41  32  13  14  25  76  97  58
Входные данные
109 118 100 51 62 73 1007 16 4 555
Результат работы
100 51 62 73 4 555 16 1007 118 109  */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>

#define SIZE 10
#define THIRDSIZE 4

int m[SIZE] = {0};
int hs[THIRDSIZE] = {0};
float summ;
int a;


//~ int LastDigit (int t)
//~ {
    //~ return t%10;
//~ }

// Sort last Digit
void sortlastdig (int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int temp;
        for (int j = 0; j < (len-1); j++)
        {
            if ((arr[j]%10)>(arr[j+1]%10))
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    sortlastdig (m,SIZE);
    printf ("\n");
    printmass(m,SIZE);
    //~ printf ("\n");
    //~ printf ("%d", LastDigit(m[1]));
    return 0;
}
