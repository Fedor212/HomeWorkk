/*Проверка на простоту
Составить функцию логическую функцию, которая определяет, верно ли, что число простое.
Используя функцию решить задачу.
int is_prime(int n)
Формат входных данных
Одно целое не отрицательное число.
Формат результата
YES или NO
Примеры
Входные данные
13
Результат работы
YES
Входные данные
136
Результат работы
NO */

//#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>



void is_simple(int n)
{

    int c = 0;
    for (int i=2; i<=n; i++)
    {
        if ((n%i)==0)
        {
            c++;
            //~ continue; //перейти к след итерации
        }
    }
    if(c==1)
        printf ("YES");
    else
        printf ("NO");

}

int n;

int main(void)
{
    scanf("%d", &n);
    is_simple(n);
    return 0;
}
