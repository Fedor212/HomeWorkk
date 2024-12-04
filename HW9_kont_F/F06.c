/*Два одинаковых
Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых. Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
int is_two_same(int size, int a[]);
Формат входных данных
Массив из целых чисел
Формат результата
Функция возвращает 1 или 0
Примеры
Входные данные
1 2 1 4 5
Результат работы
YES */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 6
char s[SIZE];
int b[SIZE]={20, 11, 25, 5, 20, -50};


int is_two_same(int size, int a[])
{
    int summ=0;
    for (int i = 0; i < size; i++)
    {
        int temp=0;
        for (int j = 0; j < size; j++)
        {
            if (a[i]==a[j])
            {
                temp++;
            }

        }
        if (temp>1)
        {
            summ++;
        }

    }
    if (summ>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


int main(void)
{
            printf("%d", is_two_same(SIZE, b));

    return 0;
}
