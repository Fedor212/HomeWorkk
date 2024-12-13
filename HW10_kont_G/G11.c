/*Заканчивается на a
В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. Ответ записать в файл output.txt.
Формат входных данных
Строка из английских букв и пробелов не более 1000 символов.
Формат результата
Одно целое число
Примеры
Входные данные в файле input.txt
Mama mila ramu
Результат работы в файле output.txt
2 */
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

    int max=0;
    for (int i = 0; i < n; i++)
    {
        if (((origstring[i-1] == 'a') && (origstring[i] == ' ')) || ((i == n-1) && (origstring[i] == 'a') && (max == 0)))
        {
            max++;
        }
    }


    printf("~%d~\n", max);
    fprintf(fp2, "%d", max);
    fclose(fp2);
    return 0;
}

