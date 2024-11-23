/*Циклический сдвиг массива вправо
Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.
Формат входных данных
10 целых чисел через пробел
Формат результата
10 целых чисел через пробел сдвинутых вправо на 1 элемент циклически
Примеры
Входные данные
4   -5   3  10  -4  -6  8  -10  1  0
Результат работы
0   4   -5   3  10  -4  -6  8  -10  1
Входные данные
1 2 3 4 5 6 7 8 9 10
Результат работы
10 1 2 3 4 5 6 7 8 9 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>

#define SIZE 10
#define THIRDSIZE 4

int m[SIZE] = {0};
int hs[THIRDSIZE] = {0};
float summ;
int a;


// Print Massive
void printmass (int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf ("%d ", arr[i]);
    }
}

// Right Shift
void rightshift (int *arr, int len)
{
    int temp = arr[len-1];
    for (int i = (len-1); i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}


int main(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        scanf ("%d", &a);
        m[i]=a;
    }

    //~ printmass(m,SIZE);
    //~ printf ("\n");
    rightshift   (m,SIZE);
    printmass(m,SIZE);

    return 0;
}
