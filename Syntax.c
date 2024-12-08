Geany IDE:
https://www.geany.org/download/releases/

GCC-компилятор
https://jmeubank.github.io/tdm-gcc/download/

Строки можно объявлять и так и так:
	char *message = "Hello\n the doctor away"; // указатель на char - фактически строка
	char message[30] = "abcFFFF \n new line";

	

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




//  Cycles
for (int i=11; i<=a; i++)
{
	
}

//  Cycles
for (; i<=a;)  //Без некоторых аргументов
{
	
}

 // Ternarnik
 min = a%10 < min ? a%10 : min;
 
 sum==0 ? printf ("YES") : printf ("NO");
