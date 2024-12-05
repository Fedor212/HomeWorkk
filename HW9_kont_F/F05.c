/*Максимум в массиве
Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
Прототип функции: int find_max_array(int size, int a[])
Формат входных данных
Массив состоящий из целых чисел. Первый аргумент, размер массива, второй аргумент адрес нулевого элемента.
Формат результата
Одно целое число
Примеры
Входные данные
773 307 371 548 531 765 402 27 573 591 217 859 662 493 173 174 125 591 324 231 130 394 573 65 570 258 343 3 586
 14 785 296 140 726 598 262 807 794 510 465 66 895 182 218 302 34 205 252 687 660 952 737 2 32 310 680 36 139 346
 139 489 217 767 544 158 774 883 154 802 136 569 377 867 423 224 176 118 660 513 734 45 978 983 749 909 601 270 147
  433 737 789 304 842 769 815 503 190 399 3
Результат работы
983 */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 100
char s[SIZE];
int b[SIZE]={20, 11, 25, 5, -48, -15, -16, 27, 43, -22, -1, -39, -16, -28, 28, 983, -36, 17, 17, -39, -50};



int find_max_array(int size, int a[])
{
    int temp =-2147483648;
    for (int i = 0; i < size; i++)
    {

        if (a[i]>temp)
            {
                temp=a[i];
            }
    }
    return temp;
}


int main(void)
{


            printf("%d", find_max_array(SIZE, b));

    return 0;
}