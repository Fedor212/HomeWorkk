/*Сумма цифр равна произведению
Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению.
int is_happy_number(int n)
Формат входных данных
Целое не отрицательное число
Формат результата
YES или NO
Примеры
Входные данные
123
Результат работы
YES
Входные данные
528
Результат работы
NO */

//#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>



void isprodequalsum(int n)
{

    int summ = 0;
    int prod = 1;
    for ( ;((n%10)|(n/10)) != 0; n/=10)
    {
        summ+=n%10;
        prod*=n%10;
    }


    if(summ==prod)
        printf ("YES");
    else
        printf ("NO");

}

int n;

int main(void)
{
    scanf("%d", &n);
    isprodequalsum(n);
    return 0;
}
