//~ Три раза
//~ В файле input.txt дана строка. Вывести ее в файл output.txt три раза через
// запятую и показать количество символов в ней.
//~ Формат входных данных
//~ Строка из английских букв и пробелов. Не более 100 символов. В конце
//могут быть незначащие переносы строк.
//~ Формат результата
//~ Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.
//~ Примеры
//~ Входные данные в файле input.txt
//~ aab
//~ Результат работы в файле output.txt
//~ aab, aab, aab 3
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
//#include <locale.h>
#define SIZE 6
#include <stdio.h>

int main(void)
{

    // файл чтения
    char *filename1 = "input.txt";
    char *filename2 = "output.txt";
    char origstring[1000]; //строка из первого файла
    int n=0;
    FILE *fp = fopen(filename1, "r");
    FILE *fp2 = fopen(filename2, "w");
    if(fp)
    {
        while ((fscanf(fp, "%[^\n]", origstring)) != 1) //считываем в массив, пока не дойдем до переноса строки
        {
        }
        while (origstring[n]!=0)//пока символ строки не равен 0, считаем
        {
            n++;
        }

        fclose(fp);
    }

    fprintf(fp2, "%s, %s, %s %d", origstring, origstring, origstring, n);
    fclose(fp2);
    return 0;
}
