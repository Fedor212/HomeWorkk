/* От 1 до N
Составить рекурсивную функцию, печать всех чисел от 1 до N
Формат входных данных
Одно натуральное число
Формат результата
Последовательность чисел от 1 до введенного числа
Примеры
Входные данные
5
Результат работы 1 2 3 4 5
 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

int a;

void rec(int a)
{
    if (a>=1) {
        a--;
        rec(a);
        printf ("%d ", a+1);
    }

}

int main(void)
{
    scanf ("%d", &a);
    rec(a);
  return 0;
}
