/*Квадраты чисел
Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.
Формат входных данных
Два целых числа по модулю не больше 100
Формат результата
Квадраты чисел от a до b.
Примеры
Входные данные
4 5
Результат работы
16 25
Входные данные
1 5
Результат работы
1 4 9 16 25
  */
#include <math.h>
#include <stdio.h>
//#include <math.h>
#include <stdint.h>
//#include <locale.h>

int main(void)
{
    int a, b;

    scanf ("%d%d", &a, &b);
    for (; a <= b; a++)
    {
        printf ("%d ", a*a);


    }
    return 0;

}