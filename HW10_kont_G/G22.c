/*Soundex
Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет, похожи ли два английских слова по звучанию. На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код. Если коды двух слов совпадают, то слова, как правило, звучат похоже.

Вам требуется реализовать этот алгоритм. Он работает так:

Первая буква слова сохраняется.
В остальной части слова:
буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются; оставшиеся буквы (согласные) заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
1: b, f, p, v
2: c, g, j, k, q, s, x, z
3: d, t
4: l
5: m, n
6: r
Любая последовательность одинаковых цифр сокращается до одной такой цифры. Итоговая строка обрезается до первых четырёх символов. Если длина строки меньше требуемой, недостающие символы заменяются знаком 0.
Примеры:
аmmonium → ammnm → a5555 → a5 → a500
implementation → implmnttn → i51455335 → i514535 → i514
Формат входных данных
Во входном файле input.txt находится одно непустое слово, записанное строчными латинскими буквами. Длина слова не превосходит 20 символов.
Формат результата
Напечатайте четырёхбуквенный код, соответствующий слову в файл output.txt.
Примеры
Входные данные в файле input.txt
ammonium
Результат работы в файле output.txt
a500
Входные данные в файле input.txt
implementation
Результат работы в файле output.txt
i514 */
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#define SIZE 20
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

    for (int i = n; i > 0; i--) //Отбрасываем лишние буквы
    {
        if ((origstring[i] == 'a') || (origstring[i] == 'e') || (origstring[i] == 'h') || (origstring[i] == 'i')
        || (origstring[i] == 'o') || (origstring[i] == 'u') || (origstring[i] == 'w') || (origstring[i] == 'y'))
        {
            for (int j = i; j <= n; j++)
            {
                origstring[j]=origstring[j+1];
            }
            n--;
        }
    }

    for (int i = n; i > 0; i--)
    {
        if ((origstring[i] == 'b') || (origstring[i] == 'f') || (origstring[i] == 'p') || (origstring[i] == 'v'))
        {
            origstring[i]= '1';
        }
        if ((origstring[i] == 'c') || (origstring[i] == 'g') || (origstring[i] == 'j') || (origstring[i] == 'k')
        || (origstring[i] == 'q') || (origstring[i] == 's') || (origstring[i] == 'x') || (origstring[i] == 'z'))
        {
            origstring[i]= '2';
        }
        if ((origstring[i] == 'd') || (origstring[i] == 't'))
        {
            origstring[i]= '3';
        }
        if ((origstring[i] == 'l'))
        {
            origstring[i]= '4';
        }
        if ((origstring[i] == 'm') || (origstring[i] == 'n'))
        {
            origstring[i]= '5';
        }
        if ((origstring[i] == 'r'))
        {
            origstring[i]= '6';
        }
    }
    printf("Do povtorov: %s\n", origstring);
    for (int i = n; i > 1; i--) //Удаляем повторные цыфры
    {
        if (origstring[i] == origstring[i-1])
        {
            for (int j = i; j <= n; j++)
            {
                origstring[j]=origstring[j+1];
            }
            n--;
        }
    }
    printf("n ravno: %ld\n", n);

    if (n>4)
    {
        for (int j = n; j >= 4; j--)
        {
            origstring[j]=0;
        }
    }
    if (n<4)
    {
        for (int j = n; j < 4; j++)
        {
            origstring[j]='0';
        }
    }


    printf("%s\n", origstring);
    fprintf(fp2, "%s\n", origstring);
    fclose(fp2);
    return 0;
}

















