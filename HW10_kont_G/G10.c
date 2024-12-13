/*Самое длинное слово
В файле input.txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл output.txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать.
Формат входных данных
Строка из английских букв и пробелов. Не более 1000 символов.
Формат результата
Одно слово из английских букв.
Примеры
Входные данные в файле input.txt
Hello beautiful world
Результат работы в файле output.txt
beautiful */
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

    // файл чтения
    char *filename1 = "input.txt";
    char *filename2 = "output.txt";
    char origstring[SIZE]; //строка из первого файла

    //char lastsymb;

    long n=0;

    FILE *fp = fopen(filename1, "r");
    FILE *fp2 = fopen(filename2, "w");

    while ((fscanf(fp, "%[^\n]", origstring)) != 1) {}//считываем в массив, пока не дойдем до переноса строки
    while (origstring[n]!=0)//пока символ строки не равен 0, считаем
    {
        n++; //количество символов в строке
    }
    printf("origstring is: %s\n", origstring);
    fclose(fp);



    char temp[1000]={'0'}; //формируемый массив
    //~ int masscount=0;
    //~ int counter=0;
    int summ=0;
    int max=0;
    char maxword[1000]={'0'};

    for (int i = 0; i < n; i++)
    {
        if (origstring[i] != ' ')
        {
            temp[summ]=origstring[i];
            //printf ("%c", temp[i]);
            summ++;
        }

        if (((summ>max) && (origstring[i] == ' ')) || ((max == 0) && (i == (n-1))))
        {
            memcpy(maxword, temp, 1000);
            max=summ;
            summ=0;
        }
    }

    for (int i = 0; i < max; i++)
    {
        printf("~%c~\n", maxword[i]);  //print unsorted mass
    }

    //printf("origstring is: %s\n", origstring);
    //~ printf("All overlaps: %s\n", overlaps);
    //~ printf("\n");




    fprintf(fp2, "%s", maxword);
    fclose(fp2);
    return 0;
}

