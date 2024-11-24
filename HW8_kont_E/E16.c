/*Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.
Формат входных данных
10 целых числе через пробел
Формат результата
Одно число, которое встречается чаще других.
Примеры
Входные данные
4  1  2  1  11  2  34  11  0  11
Результат работы
11
*/

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>

#define SIZE 10
#define HALFSIZE 5

int m[SIZE] = {0};
int n[SIZE] = {0};
int hs[HALFSIZE] = {0};

int a;


//~ int LastDigit (int t)
//~ {
    //~ return t%10;
//~ }

// Brik sort
void bricksort (int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int temp;
        for (int j = 0; j < (len-1); j++)
        {
            if (arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


// babblesort
void babblesort (int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int temp;
        for (int j = 0; j < (len-1); j++)
        {
            if (arr[j]>arr[j+1])
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

    int oft;
    int f = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int c = 0;
        for (int j = i+1 ; j < SIZE; j++)
        {
            if (m[i] == m[j])
            {
                c++;
            }
        }
        if (c>0)
        {
            if(c>f)
            {
            oft=m[i];
            f=c;
            }
        }
    }

    printf ("%d", oft);
    return 0;
}
