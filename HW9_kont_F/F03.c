/*Цифры по возрастанию
Написать функцию и программу демонстрирующую работу данной функции. Вывести в порядке возрастания цифры, входящие в десятичную запись натурального числа N, не более 1000 цифр. Цифра пробел сколько раз данная цифра встречается в числе.
Формат входных данных
Натуральное число не более 1000 цифр
Формат результата
Цифры входящие в число через пробел в порядке возрастания. От самой младшей цифры до самой старшей и количество.
Примеры
Входные данные
54321
Результат работы
1 1
2 1
3 1
4 1
5 1
Входные данные
22443344
Результат работы
2 2
3 2
4 4 */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 1000
char mass[SIZE];
//~ int b[SIZE]={20, 11, 25, 5, -48, -15, -16, 27, 43, -22, -1, -39, -16, -28, 28, -31, -36, 17, 17, -39, -50};

// Print Massive
void printmass (int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf ("%d", arr[i]);
    }
}

void sort_array(int size, char a[])
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

//~ void sort_even_odd(int SIZE, int a[])
//~ {
    //~ for (int i = 0; i < SIZE; i++)
    //~ {
        //~ int temp;
        //~ for (int j = 0; j < (SIZE-1); j++)
        //~ {
            //~ if ((abs(a[j]%2)==1) && ((a[j+1]%2)==0))
            //~ {
                //~ temp=a[j];
                //~ a[j]=a[j+1];
                //~ a[j+1]=temp;
            //~ }
        //~ }
    //~ }
//~ }



int main(void)
{

    scanf("%s", mass);
    int l=strlen(mass);
    //~ printf("String lenght = %d\n", l);
    //~ sort_array(l, mass);
    //~ printf("%s\n", mass);


    for (int i = 0; i < 10; i++)
    {
        int quantity=0;
        for (int j = 0; j < l; j++)
        {
            if (mass[j]==(i+48))
                quantity++;
        }
        if (quantity>0)
        {
            printf("%d %d\n", i, quantity);
        }
    }
    return 0;
}
