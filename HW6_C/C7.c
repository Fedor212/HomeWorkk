/*Перевести число N в систему счисления P
Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.
Формат входных данных
Два целых числа. N ≥ 0 и 2 ≥ P ≥ 9
Формат результата
Одно целое число
Примеры
Входные данные
25 5
Результат работы
100
Входные данные
9 2
Результат работы
1001
Входные данные
11 3
Результат работы
102 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>



int p, a;


int transf (int a, int p)
{
    if (a!=0)
    {
        int j=a;
        int sum=0;
        for (; ((a%p)|(a/p)) != 0;)
        {

            sum++;
            a=a/p;
        }
        int m[sum]; //кол-во элементов массива

        for (int i=sum-1; ((j%p)|(j/p)) != 0; i--)
        {
            m[i]=j%p;
            j=j/p;
        }

        for (int i = 0; i<sum; i++)
        {
            printf("%d", m[i]);
        }
    }
    else
    {
        printf("%d", 0);
    }
    return 0;
}

int main(void)
{
    scanf ("%d%d", &a, &p);
    transf (a, p);
    return 0;
}
