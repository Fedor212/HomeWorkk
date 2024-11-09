/*Все цифры четные
Ввести целое число и определить, верно ли, что все его цифры четные.
Формат входных данных
Одно целое число
Формат результата
YES или NO
Примеры
Входные данные
2684
Результат работы
YES
Входные данные
2994
Результат работы
NO  */

#include <math.h>
#include <stdio.h>
//#include <math.h>
#include <stdint.h>
//#include <locale.h>

int main(void)
{
    int a, sum=0;
    scanf ("%d", &a);
    for (; ((a%10)|(a/10)) != 0;)
    {
        sum = sum + ((a%10)%2);
        a /= 10;
    }

    sum==0 ? printf ("YES") : printf ("NO");

    return 0;

}
