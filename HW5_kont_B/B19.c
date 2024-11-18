/*Сумма цифр равна 10
Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.
Формат входных данных
Натуральное число
Формат результата
YES или NO
Примеры
Входные данные
1234
Результат работы
YES
Входные данные
1233
Результат работы
NO */
#include <math.h>
#include <stdio.h>
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


     sum == 10 ? printf ("YES") : printf ("NO");
  //  printf ("%d", sum);

    return 0;

}
