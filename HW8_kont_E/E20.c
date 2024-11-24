/*Переставить цифры
Переставить цифры в числе так, что бы получилось максимальное число.
Формат входных данных
Одно целое не отрицательное число
Формат результата
Целое не отрицательное число
Примеры
Входные данные
1229
Результат работы
9221
Входные данные
19
Результат работы
91 */

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
int dig;
int a;

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

//inversion
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

// Print Massive
void printmass (int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf ("%d", arr[i]);
    }
}


int main(void)
{

    scanf ("%d", &a);

   for (int i = 0; ((a/10)!= 0)||((a%10)!=0); i++)
    {
        m[i]=a%10;
        dig=i+1;
        a = a/10;
    }

    bricksort(m, dig);
    printmass (m, dig);

    return 0;
}
