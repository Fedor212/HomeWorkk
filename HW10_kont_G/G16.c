/*Ling заменить на Cao
В файле input.txt дано предложение. Необходимо заменить все имена «Ling» на «Cao» и результат записать в файл output.txt.
Формат входных данных
Строка из английских букв, пробелов и знаков препинания. Не более 1000 символов.
Формат результата
Строка из английских букв, пробелов и знаков препинания.
Примеры
Входные данные в файле input.txt
Ling, Ling, Ling and Ling!!!
Результат работы в файле output.txt
Cao, Cao, Cao and Cao!!! */
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
    char origstring[SIZE]={0}; //строка из первого файла
    long n=0;

    FILE *fp = fopen(filename1, "r");
    FILE *fp2 = fopen(filename2, "w");
    //********считываем в массив, пока не дойдем до переноса строки или EOF
    while (((fscanf(fp, "%[^\n]", origstring)) != 1) && ((fscanf(fp, "%s", origstring)) != EOF)) {}
    //while ((fscanf(fp, "%[^\n]", origstring)) != 1) {}
    //while ((fscanf(fp, "%s", origstring)) != EOF) {}
    while (origstring[n]!=0)//пока символ строки не равен 0, считаем
    {
        n++; //количество символов в строке
    }
    printf("origstring is: %s\n", origstring);
    printf("Mass lenth is: %ld\n", n);
    fclose(fp);
//~ //*********Убираем букву "o"*************
    //~ if (n==1)
    //~ {
       //~ origstring[0] =0;
    //~ }
    //~ printf("New origstring is: %s\n", origstring);

    for (int i = 0; i < 1000; i++)  //Second space search
    {

        if (origstring[i]=='L' && origstring[i+1]=='i' && origstring[i+2]=='n' && origstring[i+3]=='g')
        {

            origstring[i] = 'C';
            origstring[i+1] = 'a';
            origstring[i+2] = 'o';
            for (int j = i+3; j <1000; j++)
            {
                origstring[j] = origstring[j+1];
            }
            origstring[999] = 0;
        }
    }
    printf("%s\n", origstring);


    fprintf(fp2, "%s\n", origstring);
    fclose(fp2);
    return 0;
}

















