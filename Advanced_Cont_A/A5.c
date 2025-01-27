/*Извлечение бит

Подсчет битов

На вход программе подается беззнаковое 32-битное целое число N.
 Требуется найти количество единичных битов в двоичном представлении данного числа. */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

uint32_t n=0;
uint32_t temp=0;
char cpace;
int k = 0;
int count = 0;
int main(void)
{
    scanf ("%d", &n);
    //scanf ("%d", &k);
    for (int i = 0; i < 32; i++)
    {

        if (n & 0x00000001)
        {
            count++;
        }
        n = n >> 1;
    }
    printf ("%d", count);
    return 0;
}
