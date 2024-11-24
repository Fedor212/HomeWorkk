/*Цифры по порядку
Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N.
Формат входных данных
Одно натуральное число N
Формат результата
Цифры через пробел
Примеры
Входные данные
54412
Результат работы
5 4 4 1 2 */

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
        printf ("%d ", arr[i]);
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
    inversion (m, dig);
    printmass (m, dig);

    return 0;
}
