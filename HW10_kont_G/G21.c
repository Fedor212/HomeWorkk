/*Во входном файле input.txt записано некоторое количество символов * (камней). Необходимо построить равносторонний треугольник используя все символы * и символ пробел, записать ответ в выходной файл output.txt. Между соседними символами * строго один пробел. Если треугольник невозможно составить, используя все камни, то необходимо записать единственное слово NO в файл output.txt.
Формат входных данных
Текстовый файл состоит из различных символов и символов *.
Формат результата
Равносторонний треугольник составленный из символов *, символов пробела и символов переноса строк или слово NO.
Примеры
Входные данные в файле input.txt
***
Результат работы в файле output.txt
 *
* *
Входные данные в файле input.txt
** hello world ***    *
Результат работы в файле output.txt
  *
 * *
* * *
Входные данные в файле input.txt
****
Результат работы в файле output.txt
NO */
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
    char origstring[SIZE]= {0}; //строка из первого файла
    int z=0;
    long n=0;
    int flag=0;
    int raws = 0;
    int resultraws = 0;
    FILE *fp = fopen(filename1, "r");
    FILE *fp2 = fopen(filename2, "w");
    //********считываем в массив, пока не дойдем до переноса строки или EOF
    //while (((fscanf(fp, "%[^\n]", origstring)) != 1) && ((fscanf(fp, "%s", origstring)) != EOF)) {}
    while (fscanf(fp, "%s", origstring) != EOF) {
        while (origstring[n]!=0)//пока символ строки не равен 0, считаем
        {
            n++; //количество символов в строке
        }

        for (int i = 0; i < n; i++)
        {
            if (origstring[i] == '*')
            {
                z++;  // количество *
            }

        }
        n=0;
    }


    printf("Mass lenth is: %ld\n", n);

    fclose(fp);
    int h=3;
    for (int i = 2; i <= 100; i++)
    {
        raws = i + 1;
        h=h+i+1;
        printf("h: ~%d~\n", h);
        if (h==z || z==3)
        {
            flag = 1;

            if (z==3)
            {
                resultraws=2;
            }
            else
            {
                resultraws = raws;
            }
        }
    }

    printf("* quantity is: %d\n", z);
    printf("resultraws is: %d\n", resultraws);
    printf("flag is: %d\n", flag);

    int spaces = resultraws - 1; // 3 пробела
    int asterisks = 1;
    //~ char string[z];  //Объявление массива длинной  в переменную
    //~ memset(string, 0, sizeof string); //Потом его обнуление


    for (int i = resultraws; i > 0; i--)
    {

        for (int r = spaces; r > 0; r--)
        {
            fprintf(fp2, " ");
            printf(" ");

        }

        for (int j = asterisks; j > 0; j--)
        {
            fprintf(fp2, "* ");
            printf("* ");
        }
        fprintf(fp2, "\n");
        printf("\n");
        spaces--;
        asterisks++;
    }
    if (flag == 0)
    {
        fprintf(fp2, "NO");
        printf("NO");
    }

    fclose(fp2);
    return 0;
}

















