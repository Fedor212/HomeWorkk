/*Проверка на палиндром
Считать предложение из файла input.txt и определить можно ли из английских букв предложения записанного в файле получить одно слово - палиндром. Ответ напечатать на стандартный поток вывода. Требуется реализовать логическую функцию и применить ее.
is_palindrom(string)
Формат входных данных
Строка из маленьких английских букв и пробелов. Не более 1000 символов.
Формат результата
YES или NO
Примеры
Входные данные в файле input.txt
kak za
Результат работы
YES
Входные данные в файле input.txt
abc
Результат работы
NO
Входные данные в файле input.txt
car race
Результат работы
YES  */
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
    //char *filename2 = "output.txt";
    char origstring[SIZE]= {0}; //строка из первого файла
    //~ char half[501]= {0}; //половина палиндрома
    //~ char poly[SIZE]= {0};

    long n=0;





    FILE *fp = fopen(filename1, "r");
    //********считываем в массив, пока не дойдем до переноса строки или EOF
    while (((fscanf(fp, "%[^\n]", origstring)) != 1) && ((fscanf(fp, "%s", origstring)) != EOF)) {}
    //while ((fscanf(fp, "%[^\n]", origstring)) != 1) {}
    //while ((fscanf(fp, "%s", origstring)) != EOF) {}
    while (origstring[n]!=0)//пока символ строки не равен 0, считаем
    {
        n++; //количество символов в строке
    }
    //printf("origstring is: %s\n", origstring);
    //printf("Mass lenth is: %ld\n", n);
    fclose(fp);

    void is_palindrom (char *origstring1)
    {
        int flag=0;
        int j=0;
        for (int i = 'a'; i <= 'z'; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (origstring1[k] == i)
                {
                    j++;
                }
            }
            if (j%2==1)
            {
                flag++;
            }
            j=0;
        }
        if (flag>1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    is_palindrom(origstring);

    return 0;
}

















