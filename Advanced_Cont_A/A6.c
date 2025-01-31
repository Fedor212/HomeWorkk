/*Извлечение бит
Инверсия старших
На вход программе подается беззнаковое 32-битное целое число N.
Требуется изменить значения всех битов старшего байта числа на
противоположные и вывести полученное таким образом число. */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

uint32_t n=0;
uint32_t temp=4278190080; //0xFF000000
int k = 0;
int count = 0;
int main(void)
{
    //Проинвертировать - поXORить с единицами
    scanf ("%u", &n);
    //printf ("n: %x\n", n);
    //printf ("temp: %x\n", temp);
    //n = n ^ temp;
    printf ("%u", n ^ temp);
    return 0;
}
