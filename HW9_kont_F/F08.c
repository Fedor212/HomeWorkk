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
#define SIZE 1000
//int a[SIZE]={0, 0, 1, 1, 0, 1, 1, 1};
int a[SIZE]= {0};
int j=0;
int b=1;
int nn;
int flag = 0;
int maxxx;
// Print Massive
void printmass (int *arr, int len)
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



int main(void)
{
    while (b !=0)
    {
        scanf("%d", &b);
        a[j]=b;
        j++;
    }
    sort_array(SIZE, a);

    maxxx = max(a, SIZE);
    int count = 0;
    for (int i = maxxx; a[count]!=0; i--)
    {

        if (i != a[count] && (flag == 0))
        {
            printf("%d\n", i);
            flag=1;
        }
        count++;
    }

    return 0;
}
