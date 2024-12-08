//~ Три раза
//~ В файле input.txt дана строка. Вывести ее в файл output.txt три раза через
// запятую и показать количество символов в ней.
//~ Формат входных данных
//~ Строка из английских букв и пробелов. Не более 100 символов. В конце 
//могут быть незначащие переносы строк.
//~ Формат результата
//~ Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.
//~ Примеры
//~ Входные данные в файле input.txt
//~ aab
//~ Результат работы в файле output.txt
//~ aab, aab, aab 3
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
	
	//~ FILE *f;
    //~ int sum = 0, n;
    //~ f = fopen("test.txt", "r");
    //~ while (fscanf (f, "%d", &n) == 1)
        //~ sum += n;
    //~ fclose (f);
    //~ printf ("%d\n", sum);
	
	
    // файл чтения
    char *filename1 = "input.txt";
    char *filename2 = "output.txt";
    // буфер для считавания данных из файла
    char buffer[2];
    char count[0]; //строка для записи в файл
    int n=0;
    // чтение из файла
    FILE *fp = fopen(filename1, "r");
    FILE *fp2 = fopen(filename2, "w");
    if(fp)
    {
        // пока не дойдем до конца, считываем по 256 байт
        while((fgets(buffer, 2, fp))!=NULL)
        {
            printf("zahod   ");
            printf("%s \n", buffer);
            n++;
        }
        fclose(fp);
    } 
		printf("%d ", n);
		count[0]=n +'0';
		//printf("%s------- \n", count);
		fputs(count, fp2);		
		fclose(fp2);
	
	//~ //********** Запись строки в Файл!
	//~ // строка для записи
    //~ char *message = "Hello\n the doctor away"; // указатель на char - фактически строка 
    //~ // файл для записи
    //~ char *filename = "test.txt";
    //~ // запись в файл
    //~ FILE *fp = fopen(filename, "w");
    //~ if(fp)
    //~ {
        //~ // записываем строку
        //~ fputs(message, fp);
        //~ fclose(fp);
        //~ printf("File has been written\n");
    //~ }
	
	
	
	
    //~ FILE *f;
    //~ f = fopen("in.txt","w"); // открытие файла in.txt на запись
    //~ fclose(f);  //Закрытие файла.
//~ //После окончания работы с файлом необходимо убедиться,
//~ //что все записанные данные попали на диск, и освободить все ресурсы, связанные с ним.
    return 0;
}
