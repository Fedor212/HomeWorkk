/*Количество букв
В файле input.txt считать символьную строку, не более 10 000 символов. Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. Учитывать только английские буквы. Результат записать в файл output.txt.
Формат входных данных
Строка состоящая из английских букв, цифр, пробелов и знаков препинания.
Формат результата
Два целых числа. Количество строчных букв и количество заглавных букв.
Примеры
Входные данные в файле input.txt
aabbAB
Результат работы в файле output.txt
4 2
Входные данные в файле input.txt
HELLO WORLD
Результат работы в файле output.txt
0 10 */
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
    int lowercase = 0, capital = 0;

    for (int i = 0; i < n; i++)
    {
        if (origstring[i] >= 'a' && origstring[i] <= 'z')
            lowercase++;
        if (origstring[i] >= 'A' && origstring[i] <= 'Z')
            capital++;
    }

    printf("%d capitals\n", capital);
    printf("%d lowercases\n", lowercase);
    fprintf(fp2, "%d %d", lowercase, capital);
    fclose(fp2);
    return 0;
}
