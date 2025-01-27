/*Извлечение бит

На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
 Требуется взять K младших битов числа N и вывести полученное таким образом число. */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

uint32_t n=0;
char cpace;
int k = 0;

int main(void)
{
    scanf ("%d", &n);
    scanf ("%d", &k);
    n = n << (32 - k);
    n = n >> (32 - k);
    //a = (a>>b)|(a<<(32-b));
    printf ("%u", n);
    return 0;
}
