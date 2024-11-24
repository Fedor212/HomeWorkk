/*Положительные и отрицательные
Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.
Формат входных данных
10 целых чисел через пробел.
Формат результата
Сперва положительные числа, потом отрицательыне числа, через пробел.
Примеры
Входные данные
5 -4 0 1 4 -3 -3 3 0 2
Результат работы
5 1 4 3 2 -4 -3 -3 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>

#define SIZE 10
#define HALFSIZE 5

int poz[SIZE] = {0};
int neg[SIZE] = {0};
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
int p=0;
int n=0;

int main(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        scanf ("%d", &a);
        if (a!=0)
        {
            if (a>0)
            {
                poz[p]=a;
                p++;
            }
            else
            {
                neg[n]=a;
                n++;
            }
        }
    }

    // babblesort (m,SIZE);







    //~ twohalfsort (m,SIZE);
    //~ printf ("\n");
    printmass(poz,p);
    printmass(neg,n);
    //~ printf ("\n");
    //~ printf ("%d", LastDigit(m[1]));
    return 0;
}
