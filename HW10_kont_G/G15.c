/*Cao заменить на Ling
В файле input.txt дано предложение. Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл output.txt.
Формат входных данных
Строка из английский букв, знаков препинания и пробелов. Не более 1000 символов.
Формат результата
Строка из английский букв, знаков препинания и пробелов.
Примеры
Входные данные в файле input.txt
Cao, Cao, Cao and Cao!!!
Результат работы в файле output.txt
Ling, Ling, Ling and Ling!!! */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#define SIZE 1351
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
    printf("Mass lenth is: %ld\n", n);
    fclose(fp);
    origstring[1350]=0;

    for (int i = 0; i < 1350; i++)  //Second space search
    {

        if (origstring[i]=='C' && origstring[i+1]=='a' && origstring[i+2]=='o')
        {
            for (int j = 1350; j >= i+4; j--)
            {
                origstring[j] = origstring[j-1];
            }
            origstring[i+3] = 'g';
            origstring[i+2] = 'n';
            origstring[i+1] = 'i';
            origstring[i+0] = 'L';
        }
    }
    printf("%s\n", origstring);


    fprintf(fp2, "%s\n", origstring);
    fclose(fp2);
    return 0;


   return 0;
}

















