/*Разобрать на слова
В файле input.txt дано предложение требуется разобрать его на отдельные слова.
 Напечатать каждое слово на отдельной строке в файл output.txt.
Формат входных данных
Одна строка из английских букв и пробелов не более 1000 символов.
Формат результата
Каждое слово на отдельной строке
Примеры
Входные данные в файле input.txt
Mama mila ramu
Результат работы в файле output.txt

Mama
mila
ramu
 */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
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
    //int ct=0;
    int max=0;
    char temp[n];
    for (int i = 0; i < n; i++)
    {


        if (origstring[i] != ' ')
        {

            //fprintf(fp2, "%s\n", temp);
            temp[max]=origstring[i];
            //printf("%d ", max);
            printf("~%c~\n", temp[max]);
            //temp[max+1]='0';
            max++;
        }

        if (((max!=0) && (origstring[i] == ' ') && (origstring[i+1] != ' ')) || (i == n-1))
        {
            printf("%d ~~~~\n", max);
            temp[max]=0;
            fprintf(fp2, "%s\n", temp);
            max=0;
        }
    }
    //~ printf("~%d~\n", max);
    //~ fprintf(fp2, "%d", max);
    fclose(fp2);
    return 0;
}

