/* Проверка на простоту
Проверить число на простоту.
Формат входных данных
Натуральное число
Формат результата
Если число является простым напечатать YES, иначе NO
Примеры
Входные данные
10
Результат работы
NO
Входные данные
7
Результат работы YES
 */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

int main(void)
{
    int a, sum=0, v=0;
    scanf ("%d", &a);

    for (int i=1; i<=a ; i++)
    {
        a%i==0 ? sum++ : v++ ;
    }
    sum == 2 ? printf ("YES") : printf ("NO");
    return 0;

}
