#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef float(*function)(float);

float f1(float x);
float f2(float x);
float f3(float x);
float f4(float x);
float f11(float x);
float f22(float x);

float rootFindChord(float xl, float xr, float eps, function f);
float calcIntegralTrapec(float xl, float xr, size_t n, function f);
float root(function f, function g, float a, float b, float eps1);  //Корень 2-х уравнений 
float rootnoprint(function f, function g, float a, float b, float eps1);  //Корень 2-х уравнений 
float integral(function f, float a, float b, float eps2); //Вычисление интеграла на заданном участке
void help (void);
void ErrMes(void);
void test_root(void);
void test_integrals(void);
