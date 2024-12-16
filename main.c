/* Датчик температуры 
Команды:
gcc -c -o main.o main.c
*/
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include "temp_api.h"
#define SIZE 50

int m=64;

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
	uint8_t hour;
	uint8_t minute;
    int8_t temperature;
} sensor;

int main(void)
{
	mounth_max_temp();	
    hello_world();
}

