/*Сдать решение задачи G3-Последний символ - номера
Имя входного файла: input.txt
Имя выходного файла:    output.txt
Ограничение времени:    1 с
Ограничение реального времени:  5 с
Ограничение памяти: 64M
Последний номер символа
В файле input.txt дана строка из 1000 символов. Показать номера символов,
 совпадающих с последним символом строки. Результат записать в файл output.txt
Формат входных данных
Строка не более 1000 символов___
Формат результата
Целые числа через пробел - номера символа, который совпадает с последним символом строки.
Примеры
Входные данные в файле input.txt
aabbcdb
Результат работы в файле output.txt
2 3 */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 1000
#include <stdio.h>

int main(void)
{

    //~ //************ перевод массива цифр char в число int*************
    //~ int CharMass_to_int (char *string, int len)
    //~ {
        //~ int res=0;
        //~ for (int i = len-1, pow = 1;  i>=0 ; --i, pow*=10)
        //~ {
            //~ res +=  (string[i] - '0' )* pow;
        //~ }
        //~ return res;
    //~ }


    // файл чтения
    char *filename1 = "input.txt";
    char *filename2 = "output.txt";
    char origstring[SIZE]; //строка из первого файла
    char lastsymb;

    int n=0;

    FILE *fp = fopen(filename1, "r");
    FILE *fp2 = fopen(filename2, "w");

    while ((fscanf(fp, "%[^\n]", origstring)) != 1) {}//считываем в массив, пока не дойдем до переноса строки
    while (origstring[n]!=0)//пока символ строки не равен 0, считаем
    {
        n++; //количество символов в строке
    }
    fclose(fp);


    lastsymb=origstring[n-1];
    int overlabnombers[n];
    int j=0;
    for (int i = 0; i < n-1; i++)
        {
            if (origstring[i]==lastsymb)
            {
                   overlabnombers[j]= i;
                   //printf("-%d-   ", overlabnombers[j]);
                   fprintf(fp2, "%d ", i);
                   j++;
            }
        }

    //overlabnombers[j]= 0; //терменируем строку
    //~ printf("%c", overlabnombers);
    //fprintf(fp2, "%s", resstring);
    fclose(fp2);
    return 0;
}
