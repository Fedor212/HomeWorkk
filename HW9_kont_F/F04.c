/*Цифры в строке
Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. Функция должно строго соответствовать прототипу:
void print_digit(char s[])
Формат входных данных
Строка из английских букв, пробелов, знаков препинания и цифр
Формат результата
Функция должна принмать на вход строку и выводить на печать по формату: Цифра пробел количество.
Примеры
Входные данные
Hello123 world77.
Результат работы
1 1
2 1
3 1
7 2 */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 1000
char s[SIZE];


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

void print_digit(char s[])
{
    for (int i = 0; i < 10; i++)
    {
        int l=strlen(s);
        int quantity=0;
        for (int j = 0; j < l; j++)
        {
            if (s[j]==(i+48))
                quantity++;
        }
        if (quantity>0)
        {
            printf("%d %d\n", i, quantity);
        }
    }
}


int main(void)
{

    scanf("%s", s);
    //int l=strlen(s);
    //~ printf("String lenght = %d\n", l);
    //~ sort_array(l, mass);
    //~ printf("%s\n", mass);
    print_digit(s);

    //~ for (int i = 0; i < 10; i++)
    //~ {
        //~ int quantity=0;
        //~ for (int j = 0; j < l; j++)
        //~ {
            //~ if (mass[j]==(i+48))
                //~ quantity++;
        //~ }
        //~ if (quantity>0)
        //~ {
            //~ printf("%d %d\n", i, quantity);
        //~ }
    //~ }
    return 0;
}
