/*Сдать решение задачи G4-Совпадения букв
Имя входного файла: input.txt
Имя выходного файла:    output.txt
Ограничение времени:    1 с
Ограничение реального времени:  5 с
Ограничение памяти: 64M
По одному разу
В файле input.txt даны два слова не более 100 символов каждое,
разделенные одним пробелом. Найдите только те символы слов,
 которые встречаются в обоих словах только один раз.
 Напечатайте их через пробел в файл output.txt в лексикографическом порядке.
Формат входных данных
Два слова из маленьких английских букв через пробел.
 Длинна каждого слова не больше 100 символов.
Формат результата
Маленькие английские буквы через пробел.
Примеры
Входные данные в файле input.txt
hello world
Результат работы в файле output.txt
o
Входные данные в файле input.txt
aabcd bcef
Результат работы в файле output.txt
b c */
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
    int spacenumb;
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
        if (origstring[i]==' ')
            spacenumb=i;
    }
    printf("space position: %d\n", spacenumb);

    //***********поиск совпадений и запись их в массив**********
    char overlaps[100];
    int m=0;
    int ov=0;
    for (int i = 0; i <=(spacenumb-1); i++)
    {
        //printf("~%c~\n", origstring[i]);
        for (int j = spacenumb+1; j <= n-1; j++)
        {

            if(origstring[i]==origstring[j])
            {
                ov++;
            }
        }
        //printf("-%d-\n", ov);
        if(ov==1)
        {
            //printf("-%c-\n", origstring[i]);
            overlaps[m] = origstring[i];  //строка с совпадениями
            overlaps[m+1]=0;
            m++;

        }
        ov=0;
    }


    printf("All overlaps: %s\n", overlaps);
    printf("\n");


//************формируем массив только из единичных совпадений *********
//**********сортировка происходит автоматически************************
    ov=0;
    char singleoverlaps[100];
    int so=0;
    for (int az = 97; az <= 122; az++)
    {
        for (int i = 0; i < m; i++)
        {
            if(overlaps[i]==az)
                ov++;
        }

        if(ov==1)
        {
            singleoverlaps[so]=az;
            singleoverlaps[so+1]=0;
            fprintf(fp2, "%c ", singleoverlaps[so]);
            so++;
        }
        ov=0;
    }

    printf("-%s-\n", singleoverlaps);
    //~ fprintf(fp2, "%s", singleoverlaps);
    fclose(fp2);
    return 0;
}
