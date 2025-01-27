/*Извлечение бит

На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
 Требуется взять K младших битов числа N и вывести полученное таким образом число. */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

uint32_t n=0;
uint32_t temp=0;
char cpace;
int k = 0;
int max = 0;
int main(void)
{
    scanf ("%d", &n);
    scanf ("%d", &k);
    for (int i = 0; i < 32; i++)
    {
        temp = n << (32 - k);
        temp = temp >> (32 - k);
        if (temp > max)
        {
            max = temp;
        }
        n = n >> 1;
    }

    //a = (a>>b)|(a<<(32-b));
    printf ("%u", max);
    return 0;
}
