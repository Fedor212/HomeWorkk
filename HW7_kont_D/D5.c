/*В двоичную систему
Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную функцию.
Формат входных данных
Целое не отрицательное число в десятичной системе счисления
Формат результата
Целое число в двоичной системе счисления
Примеры
Входные данные
5
Результа работы
101
Входные данные
8
Результат работы
1000 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

int a;

void rec(int a)
{
    int b;
    if (((a%10)|(a/10)) != 0) {
        b=a%2;
        a=a/2;
        rec(a);
        printf ("%d", b);
    }

}

int main(void)
{
    scanf ("%d", &a);
    if (a==0)
    {
        printf ("%d", 0);
    }
    else
    {
        rec(a);
    }
    return 0;
}
