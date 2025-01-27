/*Циклический сдвиг

На вход программе подается беззнаковое 32-битное целое число N
и натуральное число K (1 ≤ K ≤ 31).
Требуется циклически сдвинуть битычисла N вправо на K битов
и вывести полученное таким образом число.  */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

uint32_t a=0;
char cpace;
int b = 0;

int main(void)
{
    scanf ("%d", &a);
    scanf ("%d", &b);
    a = (a>>b)|(a<<(32-b));
    printf ("%u", a);
    return 0;
}
