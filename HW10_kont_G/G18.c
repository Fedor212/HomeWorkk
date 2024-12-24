/*Удалить пробелы из текста
В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы). Для решения задачи разработать функцию. Результат записать в output.txt.
Формат входных данных
Строка из английских букв, знаков препинания и пробелов. Не более 1000 символов.
Формат результата
Строка из английских букв, знаков препинания и пробелов.
Примеры
Входные данные в файле input.txt
    Hello     world!
Результат работы в файле output.txt
Hello world!
 */
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
    //char result[SIZE]= {0}; //строка из первого файла
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

    //~ int flag1=0;
    //~ int ch1numb=0;
    //~ char cr1 = 0;
    //~ int count=0;



    while (origstring[0]==' ')
    {
        for (int i = 0; i < 1000; i++)
        {
            origstring[i] = origstring[i+1];
        }
    }


    for (int i = 1; i < 1000; i++)  //Удаляем пробелы в начале
    {
        if ((origstring[i] == ' ') && (origstring[i+1] == ' '))
        {
            for (int j = i+1; j < 1000; j++)
            {
                origstring[j] = origstring[j+1];
                i--;
            }
        }
    }

    printf("%s\n", origstring);
    fprintf(fp2, "%s\n", origstring);
    fclose(fp2);
    return 0;
}

















