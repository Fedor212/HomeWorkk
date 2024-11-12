/*Возвести в степень
Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.
Формат входных данных
Два целых числа: N по модулю не превосходящих 1000 и P ≥ 0
Формат результата
Одно целое число
Примеры
Входные данные
8 3
Результат работы
512
Входные данные
-5 2
Результат работы
25 */

//#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

int a, b, p;

int power (int a, int p)
{
    if (p>0)
    {
		int c =1;
        for (int i=1; i<=p; i++)
            c = c*a;
                return c;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    scanf ("%d%d", &a, &p);
    b = power(a, p);
    printf ("%d", b);
    return 0;
}
