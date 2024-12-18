/*Hello name
В файле input.txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие output.txt, где останутся имя и фамилия
Формат входных данных
Строка состоящая из английских букв и пробелов не более 100 символов. Формат: Фамилия Имя Отчество
Формат результата
Строка состоящая из английских букв и пробелов
Примеры
Входные данные в файле input.txt
Pupkin Vasiliy Ivanovich
Результат работы в файле output.txt
Hello, Vasiliy Pupkin! */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#define SIZE 100
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
    int second_space;
    int first_space;




    for (int i = n-1; i >= 0; i--)  //Second space search
    {
        //printf("i is: %d\n", i);
        if (origstring[i]==' ')
        {
            second_space = i;
            break;
        }
    }
    printf("Second space is: %d\n", second_space);

    for (int i = 0; i < second_space; i++)  //First space search
    {
        //printf("i is: %d\n", i);
        if (origstring[i]==' ')
        {
            first_space = i;
            break;
        }
    }
    printf("First space is: %d\n", first_space);

    char surname[first_space];
    char name[second_space - first_space];

    for (int i = 0; i < second_space; i++)
    {
        surname[i] = origstring[i];
    }
    surname[first_space]=0;
    printf("Surame is: %s\n", surname);


    for (int i = 0; i < (second_space - first_space); i++)
    {
        name[i] = origstring[first_space+1+i];
    }
    name[second_space - first_space]=0;
    printf("Name is: %s\n", name);

    fprintf(fp2, "Hello, %s%s!", name, surname);
    fclose(fp2);
    return 0;
}

