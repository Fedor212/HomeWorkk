/*Сумма квадратов маленьких чисел
Ввести два целых числа a и b (a ≤ b) и 
вывести сумму квадратов всех чисел от a до b.
Формат входных данных
Два целых числа по модулю не больше 100
Формат результата
Сумма квадратов от первого введенного числа до второго
Примеры
Входные данные

4 10

Результат работы

371

Входные данные

1 5

Результат работы

55

  */
#include <math.h>
#include <stdio.h>
//#include <math.h>
#include <stdint.h>
//#include <locale.h>

int main(void)
{
    int a, b, sum=0;

    scanf ("%d%d", &a, &b);
    for (; a <= b; a++)
    {
        sum += a*a;  
    }
    
    printf ("%d ", sum); 
    
    return 0;

}
