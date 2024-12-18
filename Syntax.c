Geany IDE:
https://www.geany.org/download/releases/

GCC-компилятор
https://jmeubank.github.io/tdm-gcc/download/

Строки можно объявлять и так и так:
	char *message = "Hello\n the doctor away"; // указатель на char - фактически строка
	char message[30] = "abcFFFF \n new line";
 while ((fscanf(fp, "%[^\n]", origstring)) != 1) {}//считываем в массив origstring, пока не дойдем до переноса строки

//********считываем в массив, пока не дойдем до переноса строки или EOF
while (((fscanf(fp, "%[^\n]", origstring)) != 1) && ((fscanf(fp, "%s", origstring)) != EOF)) {}
while (origstring[n]!=0)//пока символ строки не равен 0, считаем
{
n++; //количество символов в строке
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

//********************Чтение из файла по символу и вывод их на печать в консоль*********************************
 // файл чтения
    char * filename = "data.txt";
    // буфер для считавания данных из файла
    char buffer[20];
    // чтение из файла
    FILE *fp = fopen(filename, "r");
    if(fp)
    {      
        while((fgets(buffer, 20, fp))!=NULL)
        {
            printf("%s \n", buffer);
        }
        fclose(fp);
    } 

//********** Запись строки в Файл!  ************************************************************************
	// строка для записи
    char *message = "Hello\n the doctor away"; // указатель на char - фактически строка 
    // файл для записи
    char *filename = "test.txt";
    // запись в файл
    FILE *fp = fopen(filename, "w");
    if(fp)
    {
        // записываем строку
        fputs(message, fp);
        fclose(fp);
        printf("File has been written\n");
    }
	
************ сортировка массива int *************

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

//************ сортировка массива char*************
    void sort_array(int size, char a[])
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





// Min search
int min (int *arr, int len)
{
    int minn = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (minn>arr[i])
            minn=arr[i];
    }
    return minn;
}

// Max search
int max (int *arr, int len)
{
    int maxx = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (maxx<arr[i])
            maxx=arr[i];
    }
    return maxx;
}


if (((a%10)|(a/10)) != 0) {
        b=a%2;

        rec(a);
        printf ("%d", b);
	a=a/10;
    }




// Functions
int abss (int a)
{
	if (a>=0)	
	return a;
	return -a;
}

int a, b, p;  // Сначала объявить
int power (int a, int p)
{
    if (p>0)
    {
		int c =1;
        for (int i=1; i<=p; i++)
            c = c*a;
                return c;
    }
    else
    {
        return 1;
    }
}




//  Cycles с несколькими аргументами
for (int i = len-1, pow = 1;  i>=0 ; --i, pow*=10) 
{
	
}

//  Cycles
for (; i<=a;)  //Без некоторых аргументов
{
	
}

 // Ternarnik
 min = a%10 < min ? a%10 : min;
 
 sum==0 ? printf ("YES") : printf ("NO");


 • программа должна выводить тот текст, который указан в задании. Исключение - 
	 в конце вывода для удобства чтения при отладке можно выводить перевод строки. 
	 Например, если указано, что нужно вывести число, то кроме этого числа не должно быть вообще ничего. 
	 Любой вспомогательный тест (типа «Введите число», «A=») будет считаться ошибкой;
• 90% ошибок типа «дома работает, а тесты не проходят» связано с неинициализированными переменными;
• ещё 9 % ошибок такого рода связано с неправильной работой с памятью. Тесты более строгие, чем домашняя ЭВМ. 
	Помогает добавить опцию -fstack-protector;
• 0,9% — небрежность в отношении функций ввода (gets, %[^\n]s и т.п.): не забываем, что в тестах могут быть,
	а могут не быть переводы строки и они могут попасть или не попасть в прочитанную строку;
• 0,1% оставил  на ошибки в тестах.
