/*Сумма цифр четна
Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу.
Формат входных данных
Одно целое не отрицательное число
Формат результата
Ответ YES или NO
Примеры
Входные данные
136
Результат работы
YES
Входные данные
245
Результат работы
NO */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 5

int b[SIZE]={3, 5, 12, 8, 45};
// Print Massive
void printmass (int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf ("%d ", arr[i]);
    }
}
//void bricksort (int *arr, int len)
// grow_up
void sort_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        int temp;
        for (int j = 0; j < (size-1); j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}



int main(void)
{
    printmass (b, SIZE);
    sort_array(SIZE, b);
    printmass (b, SIZE);


    return 0;
}
