/*Написать только одну функцию, которая сортирует массив по возрастанию.
 * Необходимо реализовать только одну функцию, всю программу составлять не надо.
Строго согласно прототипу. Имя функции и все аргументы должны быть:
 void sort_array(int size, int a[]).
Всю программу загружать не надо, только одну эту функцию.
 Можно просто закомментировать текст всей программы, кроме данной функции */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 5

//~ int b[SIZE]={3, 5, 12, 8, 1};
//~ // Print Massive
//~ void printmass (int *arr, int len)
//~ {
    //~ for (int i = 0; i < len; i++)
    //~ {
        //~ printf ("%d ", arr[i]);
    //~ }
//~ }

void sort_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        int temp;
        for (int j = 0; j < (size-1); j++)
        {
            if (a[j]>a[j+1])
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
    //~ sort_array(SIZE, b);
    //~ printmass (b, SIZE);


    //~ return 0;
//~ }
