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
#define SIZE 520000
temp_sensor snapshots[SIZE] = {0};  //Массив показаний датчика температуры

char *route = NULL; //путь к файлу 
char *argv3 = NULL;
int m = 64;
int mounthnum = 0;
int main( int argc, char *argv[])
{      
        char *argv1=argv[1]; 
        argv3=argv[3]; 
        
        //printf("argv3 is: %s\n", argv[3]);
        //printf("argv3[0] is: %c\n", argv3[0]);
        //printf("argv3[1] is: %c\n", argv3[1]);
        if (argc == 1)
        {
               help();   
        }

        else if ((argc == 2) )
        {
                if ((argv1[0] == '-') && (argv1[1] == 'h'))
                {
                help();
                }
                else
                {
                        inval();         
                }
        }  
        else if (argc == 3)
        {                
                if ((argv1[0] == '-') && (argv1[1] == 'f'))
                {
                route = argv[2];     

                int y = log_extractor (route, snapshots); //Чтение строк из файла в массив snapshots и печать номеров битых строк, z - количество валидных строк,
                
                year_stat_print(snapshots, y);    

                for (int i = 1; i<=12; i++)
                {
                        month_stat_print(snapshots, y, i); 
                }
                }
                else
                {
                        inval();      
                }

        }   
        else if (argc == 4)
        {
                 inval(); 
        }
        else if (argc == 5)
        {
                if ((argv3[0] == '-') && (argv3[1] == 'm') && (atoi(argv[4])>0) && (atoi(argv[4])<13))
                {
                        mounthnum = atoi(argv[4]);
                        route = argv[2];
                        int z = log_extractor (route, snapshots); //Чтение строк из файла в массив snapshots и печать номеров битых строк, z - количество валидных строк,
                        
                        month_stat_print(snapshots, z, mounthnum);
/*                      printf("Month #%d ", mounthnum); 
                        printf("Avg temp: %0.2f, ", mounth_avarage_temp (snapshots, z, mounthnum));
                        printf("Min temp: %d, ", mounth_min_temp(snapshots, z, mounthnum));
                        printf("Max temp: %d\n", mounth_max_temp(snapshots, z, mounthnum));    */
                }
                else
                {
                      inval();  
                }
        }   
        else if(argc > 5)
        {
                inval();  
        }
        printf("\n");       
}
