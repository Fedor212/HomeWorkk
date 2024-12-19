/*Пары соседних символов
В файле input.txt записаны символы. Необходимо разработать функцию, которая меняет местами пары соседних символов не обращая внимание на символы пробел. Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. Результат записать в файл output.txt.
Формат входных данных
Строка из английских букв, пробелов и знаков препинания. Не более 1000 символов.
Формат результата
Строка из английских букв, пробелов и знаков препинания.
Примеры
Входные данные в файле input.txt
Hello world!
Результат работы в файле output.txt
eHllw orodl!
Входные данные в файле input.txt
abc   def
Результат работы в файле output.txt
bad   cfe */
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

    int flag1=0;
    int ch1numb=0;
    char cr1 = 0;
    int count=0;

    for (int i = 0; i < 1000; i++)  //Second space search
    {

        if ((origstring[i]>='A' && origstring[i]<='Z' && flag1 == 0) || (origstring[i]>='a' && origstring[i]<='z' && flag1 == 0))
        {
            cr1 = origstring[i];
            //printf("%c\n", origstring[i]);
            ch1numb=i;
            flag1 = 1;
            continue;
        }

        if ((origstring[i]>='A' && origstring[i]<='Z' && flag1 == 1) || (origstring[i]>='a' && origstring[i]<='z' && flag1 == 1))
        {

            //****SWAP***
            origstring[ch1numb]=origstring[i];
            origstring[i]=cr1;

            flag1 = 0;
            ch1numb=0;
        }
        count++;
    }



    //printf("%s\n", origstring);
    fprintf(fp2, "%s\n", origstring);
    fclose(fp2);
    return 0;
}

















