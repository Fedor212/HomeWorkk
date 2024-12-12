/*Удалить повторяющиеся символы
В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов. Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.
Формат входных данных
Строка из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 сивмолов.
Формат результата
Строка из меленьких и больших английских букв.
Примеры
Входные данные в файле input.txt
abc cde def
Результат работы в файле output.txt
abcdef */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 2000
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

    char uniquemass[2000]={'0'}; //формируемый массив
    int masscount=0;
    int counter=0;

    for (int i = 0; i < n; i++)
    {
        int summ=0;
        for (int x = 0; x < n; x++) //проверка, что в массиве нет этого символа
        {
            if (uniquemass[x]==origstring[i])
                summ++;
        }

        counter=0;
        for (int j = 0; j < n; j++)
        {
            if (origstring[i]==origstring[j])
                counter++;
        }
         //printf("%d\n", counter);
        if((counter==1 || summ==0)&&(origstring[i]!=' '))
        {
            fprintf(fp2, "%c", origstring[i]);
            uniquemass[masscount] = origstring[i];
            masscount++;
        }
    }

    for (int i = 0; i < masscount; i++)
    {
        printf("~%c~\n", uniquemass[i]);  //print unsorted mass
    }

    //printf("origstring is: %s\n", origstring);
    //~ printf("All overlaps: %s\n", overlaps);
    //~ printf("\n");




    //fprintf(fp2, "%s", origstring);
    fclose(fp2);
    return 0;
}

