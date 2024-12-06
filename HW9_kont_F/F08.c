/*Пропущенное число
В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке, но одно из чисел пропущено (остальные встречаются ровно по одному разу). N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число.
Формат входных данных
Последовательность целых чисел от M до N. M, N не превосходит 1000.
Формат результата
Одно целое число
Примеры
Входные данные
2   3   1   4   7   6   9   8  10   0
Результат работы
5
Входные данные
41 40 39 38 37 36 34 33 32 31 50 49 48 47 46 45 44 43 42 30 0
Результат работы 35*/
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
