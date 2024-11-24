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


// even
void even (int b)
{
    int sum=0;
    for (int i = 0; ((a/10)!= 0)||((a%10)!=0); i++)
    {
        sum=sum+a%10;
        a = a/10;
    }

    if (sum%2 == 0)
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

    even(a);

    return 0;
}
