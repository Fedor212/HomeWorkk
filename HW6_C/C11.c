/*НОД
Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования.
int nod(int a, int b)
Формат входных данных
Два целых положительных числа
Формат результата
Одно целое число - наибольший общий делитель.
Примеры
Входные данные
14 21
Результат работы
7 */

//#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>



int nod(int a, int b)
{
    int c;
    if (a>b)
    {
        c=a;
        a=b;
        b=c;
    }


    for(; b%a !=0;)
    {
        c=b%a;
        b=a;
        a=c;
    }
    return a;
}

int a, b;

int main(void)
{
    scanf("%d%d", &a, &b);
    printf ("%d", nod(a,b));
    return 0;
}
