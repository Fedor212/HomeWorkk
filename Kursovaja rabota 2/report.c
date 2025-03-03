/* Датчик температуры
Команды:
gcc -c -o main.o main.c
*/
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include "functions.h"



//char *argv3 = NULL;
int m = 64;
double eps1 = 0;
double eps2 = 0;
double k1 = 0;  //Обсциссы пересесчения кривых на графике
double k2 = 0;
double k3 = 0;
double k4 = 0;
double k5 = 0;
double area1; //площадь участка А1
double area2; //площадь участка А2
double area3; //площадь участка А3
double area4; //площадь участка А4
double area5; //площадь участка А5
double Summ_area; //Суммарная площадь
double root1 = 0;
double root2 = 0;
int main( int argc, char *argv[])
{      
        char *argv1=argv[1]; // -e1
        char *argv2=argv[2]; // -r
        char *argv3=argv[3]; // -e2       

        if ((argc == 2) && (argv1[0] == '-') && (argv1[1] == 'h'))
        {
               help();   
        }

        else if ((argc == 2) && (argv1[0] == '-') && (argv1[1] == 'r'))
        {
                test_root();   
        }

        else if ((argc == 2) && (argv1[0] == '-') && (argv1[1] == 'i'))
        {
                test_integrals();   
        }

        else if ((argc == 3) && (argv1[0] == '-') && (argv1[1] == 'r'))
        {
                eps1 = atof(argv[2]); //Точность корней
                root(f1, f3, -6, -5.7, eps1); 
                root(f1, f4, -5.1, -4.9, eps1); 
                root(f2, f3, -0.3, -0.2, eps1); 
                root(f2, f4, 2.9, 3.1, eps1); 
                root(f1, f2, 3.8, 3.9, eps1);   
        }

        else if ((argc == 5) )
        {
                if ((argv1[0] == '-') && (argv1[1] == 'e') && (argv1[2] == '1') && (argv3[0] == '-') && (argv3[1] == 'e') && (argv3[2] == '2'))
                {
                eps1 = atof(argv[2]); //Точность корней
                eps2 = atof(argv[4]); //Точность интегралов
                printf("\n");                  
         //############  Находим корни  ##################
                k1 = rootnoprint(f1, f3, -6, -5.7, eps1); 
                k2 = rootnoprint(f1, f4, -5.1, -4.9, eps1); 
                k3 = rootnoprint(f2, f3, -0.3, -0.2, eps1); 
                k4 = rootnoprint(f2, f4, 2.9, 3.1, eps1); 
                k5 = rootnoprint(f1, f2, 3.8, 3.9, eps1); 
        //############# Вся площадь делится на 5 участков  ###############
        //############  Находим интегралы (площади) каждого участка  #####    
                area1 = integral(f3, k1, k2, eps2) - integral(f1, k1, k2, eps2);
                area2 = integral(f3, k2, k3, eps2);
                area3 = integral(f2, k3, k4, eps2);
                area4 = integral(f1, k2, k4, eps2);
                area5 = integral(f1, k4, k5, eps2) - integral(f2, k4, k5, eps2);
                Summ_area = area1 + area2 + area3 + area4 + area5;
                printf("Summ_area: %f\n", Summ_area);                 

                }
                else
                {
                ErrMes();      
                }
        }  

        else
        {
               ErrMes();   
        }

        printf("\n");       
}
