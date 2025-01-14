#include "functions.h"
#include <stdio.h>



void swap(temp_sensor info[], int i, int j) //меняем местами объекты..
{
    temp_sensor memory;
        memory=info[i];
        info[i]=info[j];
        info[j]=memory;
}

void Addsnapshot(temp_sensor* info,int number,
uint16_t year,uint8_t month,uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature)
    {
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].temperature = temperature;
    }       

void printstruct(temp_sensor oneshot)
    {
        printf("Year month day hour minute temperature\n");
        printf("%d   %d   %d   %d      %d      %d\n", oneshot.year, oneshot.month, oneshot.day, oneshot.hour, oneshot.minute, oneshot.temperature);
    }

float mounth_avarage_temp(temp_sensor info[], int strings, int month) //среднемесячная температура
    {   
        float temp = 0;
        int strcount = 0;
            for(int i=0; i<strings; i++)
            {
                if (info[i].month == month)           
                {
                    strcount++; 
                    temp = temp + info[i].temperature; 
                }
            }    
        return temp/strcount;
    }

///////////////////////////////////////////// Month Min//////////////////////////////////////////////////
int8_t mounth_min_temp(temp_sensor info[], int strings, int month) //минимальная температура в текущем месяце
    {
        int8_t min = 99;
        for(int i=0; i<strings; i++)
            {
                if (info[i].month == month)           
                {
                    if(info[i].temperature<min)
                    {
                        min = info[i].temperature;
                    }
                }
            }  
        return min;      
    }
///////////////////////////////////////////// Month Max//////////////////////////////////////////////////
int8_t mounth_max_temp(temp_sensor info[], int strings, int month) //минимальная температура в текущем месяце
    {
        int8_t max = -99;
        for(int i=0; i<strings; i++)
            {
                if (info[i].month == month)           
                {
                    if(info[i].temperature>max)
                    {
                        max = info[i].temperature;
                    }
                }
            }  
        return max;      
    }
float year_avarage_temp(temp_sensor info[], int strings) //среднегодовая температура
    {   
        float temp = 0;        
            for(int i=0; i<strings; i++)
            {
                temp = temp + info[i].temperature; 
            }   
        return temp/strings;
    }

int8_t year_min_temp(temp_sensor info[], int strings) //минимальная температура за год
    {
        int8_t min = 99;        
            for(int i=0; i<strings; i++)
            {
                if(info[i].temperature<min)
                {
                    min = info[i].temperature;
                }                 
            }   
        return min;
    }

int8_t year_max_temp(temp_sensor info[], int strings) //минимальная температура за год
    {
        int8_t max = -99;        
            for(int i=0; i<strings; i++)
            {
                if(info[i].temperature>max)
                {
                    max = info[i].temperature;
                }                 
            }   
        return max;
    }

void help(void)
    {
        printf( "Temp statistic application\n"
                "-h for help\n"
                "-f filename.csv all statistics from data file\n"
                "-f filename.csv -m xx statistics for the specified xx month\n");
    }

void nopath (void)
    {
        printf("No path was found, enter <./report -h> for help\n");
    }
void helpm(void)
    {
        printf("You entered: -m\n");
    }
void ErrMes(void)
    {
        printf("Arguments not found, enter <./report -h> for hepl\n");
    }
void hello_world(void)
    {
        printf("End of Main\n");        
    }
void nomonth(void)
    {
        printf("Arguments a not correct, enter <./report -h> for hepl\n");
    }
    void inval(void)
    {
        printf("Invalid request, enter <./report -h> for hepl\n");
    }


int log_extractor (const char *fileroute, temp_sensor massiv[])
    {
        FILE *datafile = fopen(fileroute, "r");
        if (datafile == NULL)
        {
                printf("File not found\n");
                return 1;
        }
        int validcolumns = 0;
        temp_sensor shot;
        char string[30];
        int count = 0;
        int orig_str_count = 1;
        int inv=0;
        while (fgets(string, sizeof(string), datafile) != NULL)  //fgets считывает из файла одну строку
        {
                              
                validcolumns = sscanf(string,"%d;%d;%d;%d;%d;%d", &shot.year, &shot.month, &shot.day, &shot.hour, &shot.minute, &shot.temperature);
                //printf("Temp is:%d\n", shot.temperature); 
                //printf("Valid columns is:%d\n", validcolumns);  
                if((validcolumns != 6) || (shot.year < 2000) || (shot.year > 2025) || (shot.month < 1) || (shot.month > 12)
                || (shot.day < 1) || (shot.day > 31) || (shot.hour < 0) || (shot.hour > 23) || (shot.minute < 0) || (shot.minute > 59) 
                ||(shot.temperature > 99) || (shot.temperature < -99))
                {
                    if (inv == 0) {printf("Invalid data strings: ");}
                    printf("%d, ", orig_str_count);   
                    //printf("\n");
                    orig_str_count++;  
                    inv = 1;             
                }
                else
                {                       
                        //printf("%d - %s\n", count, string); 
                        massiv[count] = shot;                             
                        count++;  
                        orig_str_count++; 
                }
                      
        }
        printf("\n"); 
        return count; //Количество валидных строк
    }
void month_stat_print(temp_sensor infos[], int stringz, int mounthnumber)
    {
    printf("Month #%d ", mounthnumber); 
    printf("Avg temp: %0.2f, ", mounth_avarage_temp (infos, stringz, mounthnumber));
    printf("Min temp: %d, ", mounth_min_temp(infos, stringz, mounthnumber));
    printf("Max temp: %d\n", mounth_max_temp(infos, stringz, mounthnumber));   
    }

void year_stat_print(temp_sensor infos[], int stringz)
    {
    printf("Year stats: ");                
    printf("Avg temp: %0.2f, ", year_avarage_temp(infos, stringz));                
    printf("Min temp: %d, ", year_min_temp(infos, stringz));                
    printf("Max temp: %d\n", year_max_temp(infos, stringz));
    }    
