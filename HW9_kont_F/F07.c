/*Два одинаковых
Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых. Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
int is_two_same(int size, int a[]);
Формат входных данных
Массив из целых чисел
Формат результата
Функция возвращает 1 или 0
Примеры
Входные данные
1 2 1 4 5
Результат работы
YES */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 8
int a[SIZE]={0, 0, 1, 1, 0, 1, 1, 1};
int b[]={0};
int fp[]={0};
int nn;

// Print Massive
void printmass (int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf ("%d ", arr[i]);
    }
}


int compression(int a[], int b[], int N)
{
    int summ0=0;
    int summ1=0;
    int j=0;
    int i;
    int booll=0;

     for (i = 0; i < N; )
     {

         if(booll==0)
         {
            for (; a[i]==0; i++)
            {
                summ0++;
            }
            b[j]=summ0;
            printf ("%d\n", b[j]);
            summ0=0;
            j++;
            booll=1;
         }

        if(booll==1)
         {
            for (; a[i]==1; i++)
            {
                summ1++;
            }
            b[j]=summ1;
            summ1=0;
            j++;
            booll=0;
         }
     }
    nn=j;
        int res[]={0};
        for (int f = 0; f < j; f++)
            {
                res[f]=b[f];
            }
        //~ int bbb = sizeof(res)/sizeof(res[0]);
        //~ printf ("%d\n", bbb);
    return *res;
}


int main(void)
{
        compression(a, b, SIZE);

        printmass (b, SIZE);

    return 0;
}
