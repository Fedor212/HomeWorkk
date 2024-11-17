/*Сумма чисел от 1 до N
Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N 
Формат входных данных
Одно натуральное число
Формат результата
Сумма чисел от 1 до введенного числа
Примеры
Входные данные
5
Результат работы
15
Входные данные
100
Резултат работы
5050
 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

int a;
int summ = 0;
int rec(int a)
{
    if (a>=1) {
        a--;
        rec(a);
        summ = summ + a +1;
        //printf ("%d __", summ);
    }
    return summ;
}

int main(void)
{
    scanf ("%d", &a);
    printf ("%d", rec(a));
  return 0;
}
