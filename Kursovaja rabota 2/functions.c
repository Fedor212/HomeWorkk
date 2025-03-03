#include "functions.h"
#include <stdio.h>
#include <math.h>

float f1(float x)
{    
    return 0.6*x + 3;
}

float f2(float x)
{    
    return (x-2)*(x-2)*(x-2) - 1;
}

float f3(float x)
{    
    return 3/x;
}

float f4(float x) //Функция для поиска пересечения с осью абсцисс
{    
    return 0;
}

float f11(float x)  //Тестовая функция y=x*x*x+2
{    
    return x*x*x+2;
}

float f22(float x)  //Тестовая функция y=-x+2
{    
    return -x+3;
}

void help(void)
    {
             printf( "Command options:\n"
                "<./report -h> for help\n"
                "<./report -e1 0.001 -e2 0.002> for area calculatoin \n"
                "<./report -r 0.001> for root calculation\n"
                "<./report -r> for root test\n"
                "<./report -i> for integral test\n");  
    }


void ErrMes(void)
    {
        printf("Invalid request, enter <./report -h> for hepl\n");
    }
// ######################     Метод Хорд      ################################
float rootFindChord(float xl, float xr, float eps, function f) {
    int stepcount=0;
    while(fabs(xr - xl) > eps) {
        xl = xr - (xr - xl) * f(xr) / (f(xr) - f(xl));
        xr = xl - (xl - xr) * f(xl) / (f(xl) - f(xr));
        stepcount++;
    }
    printf("Find Chord Search root for %d steps\n",stepcount);
    return xr;
}

float calcIntegralTrapec(float xl, float xr, size_t n, function f) {
    float sum = 0;
    float h = (xr-xl)/n;
    for(float x=xl+h; x<xr-h; x+=h) {
        sum += 0.5*h*(f(x)+f(x+h));
    }
    return sum;
}

float root(function f, function g, float a, float b, float eps1)  //С печатью, корень 2-х уравнений в заданном промежутке методом деления отрезка пополам
{
   double c; // Середина интервала
   double rood; //корень
   int count = 0;
    while ((b - a) / 2 > eps1) {
        count++;
        c = (a + b) / 2; // середина интервала
        if ((f(c) - g(c)) == 0.0) { // Если корень найден
            break;
        } else if ((f(a) - g(a)) * (f(c) - g(c)) < 0) { // Если корень в левой половине
            b = c;
        } else { // Если корень в правой половине
            a = c;
        }
    }
    rood = (a + b) / 2;
    printf("Root is: %f, found in %d steps \n", rood, count);
    return rood; // Возвращаем приближенное значение корня
}

float rootnoprint(function f, function g, float a, float b, float eps1)  //Корень 2-х уравнений в заданном промежутке методом деления отрезка пополам
{
   double c; // Середина интервала
   double rood; //корень
   int count = 0;
    while ((b - a) / 2 > eps1) {
        count++;
        c = (a + b) / 2; // середина интервала
        if ((f(c) - g(c)) == 0.0) { // Если корень найден
            break;
        } else if ((f(a) - g(a)) * (f(c) - g(c)) < 0) { // Если корень в левой половине
            b = c;
        } else { // Если корень в правой половине
            a = c;
        }
    }
    rood = (a + b) / 2;    
    return rood; // Возвращаем приближенное значение корня
}

   //##############   Вычисление площади на заданном участке    ##############
float integral(function f, float a, float b, float eps2)  //Вычисление интеграла на заданном участке
{
    float sum = 0;    
    for(float x=a+eps2; x<b-eps2; x+=eps2) {
        sum += 0.5*eps2*(f(x)+f(x+eps2));
    }
    return fabs(sum);
}

void test_root(void) //Поиск корней тестовых функций
    {
        float rooot = 0;
        rooot = rootnoprint(f11, f22, 0, 1, 0.0001); 
        printf("Root test: Goal: 0.6823, result: %.5f\n", rooot);    
    }

void test_integrals(void) //Поиск корней тестовых функций
    {
        float arrea = 0;
        arrea = integral(f22, 0, 3, 0.0001); 
        printf("Integral test: Goal: 4.5, result: %.5f\n", arrea);    
    }
