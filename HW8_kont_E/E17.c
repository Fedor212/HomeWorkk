/*Только один раз
Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.
Формат входных данных
10 целых чисел через пробел
Формат результата
Элементы которые встречаются только один раз через пробел
Примеры
Входные данные
5   -4   0  1   4  -3  -3  3  0  2
Результат работы
5  -4  1  4  3  2 */

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

    //~ int oft;
    //~ int f = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int c = 0;
        for (int j = 0 ; j < SIZE; j++)
        {
            if (m[i] == m[j])
            {
                c++;
            }
        }
        if (c==1)
        {
            printf ("%d ", m[i]);
        }
    }
    return 0;
}
