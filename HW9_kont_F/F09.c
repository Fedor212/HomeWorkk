/*Поменять местами
Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива. Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. Если отрицательных элементов нет - массив не менять.
Прототип функции: void swap_negmax_last(int size, int a[])
Формат входных данных
Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел.
Примеры
Входные данные
1 -2 -3 -4 5 6 7 8 9 10
Результат работы
1 10 -3 -4 5 6 7 8 9 -2 */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 8
int n[SIZE]={4, -3, -5, 1, 8, -2, 13, 7};
int a[SIZE]= {0};
int j=0;
int b=1;
int nn;
int flag = 0;
int maxxx;
// Print Massive
void printmass (int len, int *arr)
{
    for (int i = 0; i < len; i++)
    {
        printf ("%d ", arr[i]);
    }
}

void sort_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        int temp;
        for (int j = 0; j < (size-1); j++)
        {
            if (a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

// Max search
int max (int *arr, int len)
{
    int maxx = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (maxx<arr[i])
            maxx=arr[i];
    }
    return maxx;
}


void swap_negmax_last(int size, int a[])
{
    int negmax = -2147483648;
    int temp;
    int rememberi;
    for (int i = 0; i < size; i++)
    {
        if (a[i]<0 && a[i]>negmax)
        {

            negmax=a[i];
            rememberi=i;
            // printf ("%d\n", negmax);
        }
    }
    if (negmax != -2147483648)
    {
        //printf ("Zahod\n");
        temp=a[size-1];
        //printf ("%d\n", temp);
        a[size-1]=negmax;
        a[rememberi]=temp;
    }
}

int main(void)
{
    printmass (SIZE, n);
    printf ("\n");
    swap_negmax_last(SIZE, n);
    printmass (SIZE, n);
    return 0;
}
