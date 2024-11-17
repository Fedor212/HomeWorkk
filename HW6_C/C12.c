/*Вычислить sin
Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)
float sinus(float x)
Формат входных данных
Одно число от 0 до 90
Формат результата
Вещественное число в формате "%.3f"
Примеры
Входные данные
45
Результат работы
0.707
Входные данные
30
Результат работы
0.500
Входные данные
0
Результат работы
0.000 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>

int a;
int x;
const double pi = 3.14159265358979323846;
float sinn(int x)
{

    float summ=0;
    //float si;

    for (int j=1; j<=9; j=j+2)
    {


        float f=1;
        float p;
        //float c;
        for (int i = 1; i <=j; i++)  // Факториал
            {
                f*=i;
            }
        printf("%.3f    ", f);




        p=pow(x, j);          //Степень
        if(j%4==3)
            p=-p;
        printf("%.3f\n ", p);


        summ = summ+p/f;
        printf("%.3f\n", summ);
        //summ = summ + f;
        // printf ("%.2f ", summ);


    }
    //~ si=x-summ;

    return summ;
}



int main(void)
{
    scanf("%d", &a);
    sinn(a);
    //printf ("%.3f", sinn(a));
    return 0;
}
