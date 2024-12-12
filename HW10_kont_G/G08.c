/*Числа в массив
В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести массив по возрастанию в файл output.txt.
Формат входных данных
Строка из английских букв, цифр и знаков препинания
Формат результата
Последовательность целых чисел отсортированная по возрастанию
Примеры
Входные данные в файле input.txt
data 48 call 9 read13 blank0a
Результат работы в файле output.txt
0 9 13 48 */
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

    void sort_array(int size, int a[])
    {
        for (int i = 0; i < size; i++)
        {
            int temp;
            for (int j = 0; j < (size-1); j++)
            {
                if (a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    }

    //************ перевод массива цифр char в число int*************
    int CharMass_to_int (char *string, int len)
    {
        int res=0;
        for (int i = len-1, pow = 1;  i>=0 ; --i, pow*=10)
        {
            res +=  (string[i] - '0' )* pow;
        }
        return res;
    }

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
    char digit[100];
    int digits[999];
    int dc=0, dcs=0, example = 0;

    for (int i = 0; i < n; i++)
    {
        if (origstring[i] >= '0' && origstring[i] <= '9')
        {
            dc=0;
            while (origstring[i] >= '0' && origstring[i] <= '9')
            {
                digit[dc]=origstring[i];
                digit[dc+1]=0;
                dc++, i++;
            }
            printf("%s\n", digit);
            example = CharMass_to_int (digit, dc);
            //printf("~%d~\n", example);
            digits[dcs]=example; //массив  с цифрами
            dcs++;
            //printf("~%d~\n", CharMass_to_int(*digit, dc+1));
            //digits[dcs] = CharMass_to_int(*digit, dc+1);
        }
    }

    for (int i = 0; i < dcs; i++)
    {
        printf("%d\n", digits[i]);  //print unsorted mass
    }

    sort_array(dcs, digits);  //сортировка массива

    for (int i = 0; i < dcs; i++)
    {
        printf("~%d~\n", digits[i]);  //print unsorted mass
        fprintf(fp2, "%d ", digits[i]);
    }


    //printf("~~~%s~~~\n", digits);
    //~ printf("%d capitals\n", capital);
    //~ printf("%d lowercases\n", lowercase);
    //~ fprintf(fp2, "%d %d", lowercase, capital);
    fclose(fp2);
    return 0;
}
