/*Четные в начало
Написать только одну функцию, которая ставит в начало массива все четные элементы,
 а в конец – все нечетные. Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:.
void sort_even_odd(int n, int a[])
Формат входных данных
Функцийя принмате на вход целые числа
Формат результата
Отсортированный исходный массив
Примеры
Входные данные
20 11 25 5 -48 -15 -16 27 43 -22 -1 -39 -16 -28 28 -31 -36 17 17 -39 -50
Результат работы
-48 -16 -22 -16 -28 28 -36 -50 11 25 5 -15 27 43 -1 -39 -31 17 17 -39
Входные данные
1 0 1 0 1
Результат работы
0 0 1 1 1 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 21

//~ int b[SIZE]={20, 11, 25, 5, -48, -15, -16, 27, 43, -22, -1, -39, -16, -28, 28, -31, -36, 17, 17, -39, -50};
//~ // Print Massive
//~ void printmass (int *arr, int len)
//~ {
    //~ for (int i = 0; i < len; i++)
    //~ {
        //~ printf ("%d ", arr[i]);
    //~ }
//~ }

void sort_even_odd(int SIZE, int a[])
{
    for (int i = 0; i < SIZE; i++)
    {
        int temp;
        for (int j = 0; j < (SIZE-1); j++)
        {
            if ((abs(a[j]%2)==1) && ((a[j+1]%2)==0))
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}



//~ int main(void)
//~ {
    //~ printmass (b, SIZE);
    //~ printf ("\n");
    //~ sort_even_odd(SIZE, b);
    //~ printmass (b, SIZE);


    //~ return 0;
//~ }
