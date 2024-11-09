/*Все цифры в порядке возрастания
Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.
Формат входных данных
Целое число
Формат результата
YES или NO
Примеры
Входные данные
1238
Результат работы
YES
Входные данные
1274
Результат работы
NO  */

#include <math.h>
#include <stdio.h>
//#include <math.h>
#include <stdint.h>
//#include <locale.h>

int main(void)
{
    int a;
    scanf ("%d", &a);
    for (; ((a%10)|(a/10)) != 0;)
    {
        if (a%10>((a%100)/10))
        {
            a /= 10;
        }
        else
        {
            printf ("NO");
            goto endd;
        }

    }

    printf ("YES");

endd:
    return 0;

}
