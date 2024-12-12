/*Заменить a на b
В файле input.txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.
Формат входных данных
Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Формат результата
Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Примеры
Входные данные в файле input.txt
aabbccddABCD
Результат работы в файле output.txt
bbaaccddBACD */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 201
#include <stdio.h>

int main(void)
{

    // файл чтения
    char *filename1 = "input.txt";
    char *filename2 = "output.txt";
    char origstring[SIZE]; //строка из первого файла

    //char lastsymb;

    int n=0;

    FILE *fp = fopen(filename1, "r");
    FILE *fp2 = fopen(filename2, "w");

    while ((fscanf(fp, "%[^\n]", origstring)) != 1) {}//считываем в массив, пока не дойдем до переноса строки
    while (origstring[n]!=0)//пока символ строки не равен 0, считаем
    {
        n++; //количество символов в строке
    }
    printf("origstring is: %s\n", origstring);
    printf("\n");
    fclose(fp);

    //***********поиск пробела**********
    for (int i = 0; i < n; i++)
    {
        if (origstring[i]=='a')
        {
            origstring[i]='b';
            continue;
        }
        if (origstring[i]=='b')
        {
            origstring[i]='a';
            continue;
        }
        if (origstring[i]=='A')
        {
            origstring[i]='B';
            continue;
        }
        if (origstring[i]=='B')
        {
            origstring[i]='A';
            continue;
        }
    }
    printf("origstring is: %s\n", origstring);


    //~ printf("All overlaps: %s\n", overlaps);
    //~ printf("\n");




    fprintf(fp2, "%s", origstring);
    fclose(fp2);
    return 0;
}
