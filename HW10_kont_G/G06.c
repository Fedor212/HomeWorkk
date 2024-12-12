/*Проверка на палиндром
В файле input.txt символьная строка не более 1000 символов. Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях). Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.
Формат входных данных
Строка из заглавных английских букв
Формат результата
YES или NO
Примеры
Входные данные в файле input.txt
ABCDEF
Результат работы в файле output.txt
NO
Входные данные в файле input.txt
KAZAK
Результат работы в файле output.txt
YES */
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
    char reversestring[n]; //строка из первого файла
    reversestring[n+1] = 0;
    //***********запись зеркального массива**********
    int rv=n-1;
    for (int i = 0; i < n; i++)
    {
        reversestring[rv]=origstring[i];
        rv--;
    }
    printf("reversestring is: %s\n", reversestring);

    rv=0;
    for (int i = 0; i < n; i++)
    {
        if (origstring[i]==reversestring[i])
        {
            rv++;
        }
    }

    if (rv==n)
    {
        fprintf(fp2, "%s", "YES");
        printf("YES\n");
    }
    else
    {
       fprintf(fp2, "%s", "NO");
       printf("NO\n");
    }

    //~ printf("All overlaps: %s\n", overlaps);
    //~ printf("\n");
    //fprintf(fp2, "%s", reversestring);
    fclose(fp2);
    return 0;
}
