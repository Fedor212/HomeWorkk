/*Сколько раз встречается максимум
На стандартном потоке ввода задаётся натуральное число N (N > 0),
 после которого следует последовательность из N целых чисел.
 На стандартный поток вывода напечатайте, сколько раз в этой
 последовательности встречается максимум.
  Указание: использовать массивы запрещается.
Examples
Input
6 1 2 3 2 0 3
Output
2
Input
3 5 2 -1
Output
1
*/

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

int a=0, b=0;
int max = -2147483648, count = 0;
int main(void)
{
    scanf ("%d", &a);

    for (int i = 0; i < a; i++)
    {
        scanf ("%d", &b);
        if (b > max)
        {
            count = 1;
            max = b;
        }
        else if (b == max)
        {
            count++;
        }

    }

    printf ("%d", count);
    return 0;

}
