#include <stdint.h>
/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h> */

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} temp_sensor;
void Addsnapshot (temp_sensor* info,int number,
uint16_t year,uint8_t month,uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature);
void swap (temp_sensor *info, int i, int j); //меняем местами объекты
float mounth_avarage_temp(temp_sensor info[], int strings, int month);
int8_t mounth_min_temp(temp_sensor info[], int strings, int month);
int8_t mounth_max_temp(temp_sensor info[], int strings, int month);
float year_avarage_temp (temp_sensor *info, int n);
int8_t year_min_temp(temp_sensor info[], int strings);
int8_t year_max_temp(temp_sensor info[], int strings); 
void nopath (void);
void help (void);
void helpm (void);
void ErrMes (void);
void hello_world (void);
void nomonth (void);
void inval (void);
void printstruct (temp_sensor oneshot);
int log_extractor (const char *fileroute, temp_sensor massiv[]);
void month_stat_print(temp_sensor infos[], int stringz, int mounthnumber);
void year_stat_print(temp_sensor infos[], int stringz);
extern int m; //Глоб переменная видна из обоих файлов..