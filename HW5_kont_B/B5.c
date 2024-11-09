/*Ровно три цифры
Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
Формат входных данных
Целое положительное число
Формат результата
Одно слов: YES или NO
Примеры
Входные данные
123
Результат работы
YES
Входные данные
1234
Результат работы
NO
  */
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
