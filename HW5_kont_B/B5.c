/*Сумма цифр
Ввести целое число и найти сумму его цифр.
Формат входных данных
Одно целое число большее или равное нулю.
Формат результата
Одно число - сумма цифр
Примеры
Входные данные
1234
Результат работы
10
Входные данные
111
Результат работы
3  */
#include <math.h>
#include <stdio.h>
//#include <math.h>
#include <stdint.h>
//#include <locale.h>

int main(void)
{
    int a, b=0, sum=0;

    scanf ("%d", &a);
    for (; ((a%10)|(a/10)) != 0;)
    {
        b = a%10;
        sum += b;
        a /= 10;
    }

    printf ("%d", sum);

    return 0;

}
