/*Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.
Формат входных данных
Одно целое положительное число N
Формат результата
Целое число - сумма чисел от 1 до N
Примеры
Входные данные
100
Результат работы
5050 */

//#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>



void print_simple(int n)
{
    int m[10]= {0};
    int c = 0;

    for (int i=2; i<=n;)
    {
        if ((n%i)==0)
        {
            m[c]=i;
            printf ("%d ", m[c]);
            c++;
            n=n/i;
            continue; //перейти к след итерации
        }
        i++;
    }
    //printf ("%d %d %d %d %d", m[0], m[1], m[2], m[3], m[4]);
    
}

int n;

int main(void)
{
    scanf("%d", &n);
    print_simple(n);    
    return 0;
}
