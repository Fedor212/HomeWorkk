/*Сдать решение задачи G2-Строка и цифры
Имя входного файла: input.txt
Имя выходного файла:    output.txt
Ограничение времени:    1 с
Ограничение реального времени:  5 с
Ограничение памяти: 64M
Строка и цифры
Считать число N из файла input.txt.
Сформировать строку из N символов. N четное число, не превосходящее 26.
На четных позициях должны находится четные цифры в порядке возрастания,
кроме 0, на нечетных позициях - заглавные буквы в порядке следования в
нглийском алфавите. Результат записать в файл output.txt
Формат входных данных
Четное N ≤ 26
Формат результата
Строка из английских букв и цифр
Примеры
Входные данные в файле input.txt 10
Результат работы в файле output.txt A2B4C6D8E2
Входные данные в файле input.txt 16
Результат работы в файле output.txt A2B4C6D8E2F4G6H8 */
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
    char origstring[100]; //строка из первого файла
    int n=0;
    int dig;
    FILE *fp = fopen(filename1, "r");
    FILE *fp2 = fopen(filename2, "w");

    while ((fscanf(fp, "%[^\n]", origstring)) != 1) {}//считываем в массив, пока не дойдем до переноса строки
    while (origstring[n]!=0)//пока символ строки не равен 0, считаем
    {
        n++; //количество символов в строке
    }
    fclose(fp);

    dig = CharMass_to_int (origstring, n);  //dig цифра из файла
    //printf ("%d", dig);

    char resstring[dig];

    for (int i = 0, eve=2, odd=0; i < dig;  i++)
    {
        if (i%2==1)
        {
            resstring[i] = eve + '0';
            resstring[i+1] = 0; //Убирает мусор не понятно откуда берущийся
            eve+=2;
        }
        else
        {
            resstring[i] = odd + 'A';
            resstring[i+1] = 0;  //Убирает мусор не понятно откуда берущийся
            odd++;
        }
        if (eve>=9)
            eve=2;
    }

    //printf("%s", resstring);

    fprintf(fp2, "%s", resstring);
    fclose(fp2);
    return 0;
}
