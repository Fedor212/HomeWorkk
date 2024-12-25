/*Составить палиндром
Разработать функцию дана строка из маленьких английских букв. Составить из символов палиндром максимальной длинны. При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке. Записать ответ в файл output.txt.
Формат входных данных
Строка из маленьких английских букв. Не более 1000 символов.
Формат результата
Строка из маленьких английских букв.
Примеры
Входные данные в файле input.txt
kazaki
Результат работы в файле output.txt
akika
Входные данные в файле input.txt
knak
Результат работы в файле output.txt
kak
Входные данные в файле input.txt
zzzzbbaaa
Результат работы в файле output.txt
abzzazzba */
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
    char half[501]= {0}; //половина палиндрома
    char poly[SIZE]= {0};
    int z=0;
    long n=0;

    //************ сортировка массива char*************
    void sort_array(int size, char a[])
    {
        for (int i = 0; i < size; i++)
        {
            int temp;
            //printf("~~%c\n", origstring[i]);
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

    int flag=0;
    //int sizeofhalf=0;
    char center = 0;
    //~ int count=0;

    sort_array(n, origstring);
    printf("%s\n", origstring);
    int j=0;
    for (int i = 'a'; i <= 'z'; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (origstring[k] == i)
            {
                j++;
            }
        }
        if (j>=2)
        {
            for (int f = 0; f < (j/2); f++)
            {
                half[z]= i;
                z++; //Размер половины палиндрома
            }
        }
        if ((j%2==1) && (flag == 0))
        {
            center = i;
            flag = 1;
        }
        j=0;
    }

    for (int i = 0; i < z; i++)
    {
        poly[i]=half[i];
    }

    if (flag == 1)
    {
        poly[z]=center;
        for (int i = z+1, y=0; i < n; i++, y++)
        {
            poly[i]=half[z-1-y];
        }
    }
    else
    {
        for (int i = z, y=0; i < n; i++, y++)
        {
            poly[i]=half[z-1-y];
        }
    }

    printf("Center is: %c\n", center);
    printf("%s\n", half);
    printf("Half size is:%d\n", z);
    printf("%s\n", poly);
    fprintf(fp2, "%s\n", poly);
    fclose(fp2);
    return 0;
}

















