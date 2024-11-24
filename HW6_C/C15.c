/*Сумма цифр четна
Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу.
Формат входных данных
Одно целое не отрицательное число
Формат результата
Ответ YES или NO
Примеры
Входные данные
136
Результат работы
YES
Входные данные
245
Результат работы
NO */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>


int a;


// grow_up
void grow_up(int a)
{
    int sum=0;
    for (int i = 0; ((a/10)!= 0)||((a%10)!=0); i++)
    {
        if (a%10<=(a%100)/10)
        {
            sum++;
        }
        a=a/10;
    }

    if (sum == 0)
    {
        printf ("YES");
    }
    else
    {
        printf ("NO");
    }
}


int main(void)
{

    scanf ("%d", &a);

    grow_up(a);

    return 0;
}
