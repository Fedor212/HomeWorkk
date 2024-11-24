/*Более одного раза
Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более  одного раза. В результирующем массиве эти числа не должны повторяться.
Формат входных данных
10 целых чисел через пробел
Формат результата
Целые числа через пробел, которые встречаются более одного раза в исходном массиве.
Примеры
Входные данные
4 1 2 1 11 2 34 8 9 10
Результат работы
1 2
Входные данные
1 2 3 4 5 1 2 3 4 5
Результат работы
1 2 3 4 5
Входные данные
1 1 1 1 1 1 1 1 1 1
Результат работы
1 */

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

   // babblesort (m,SIZE);



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
        if (c==1)
        {
            n[f]=m[i];
            f++;
        }
    }




    //~ twohalfsort (m,SIZE);
    //~ printf ("\n");
    printmass(n,f);
    //~ printf ("\n");
    //~ printf ("%d", LastDigit(m[1]));
    return 0;
}
