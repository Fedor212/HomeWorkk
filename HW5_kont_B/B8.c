/*Ровно одна цифра 9
Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».
Формат входных данных
Одно целое число
Формат результата
Ответ: YES или NO
Примеры
Входные данные
193
Результат работы
YES
Входные данные
1994
Результат работы
NO  */

#include <math.h>
#include <stdio.h>
//#include <math.h>
#include <stdint.h>
//#include <locale.h>

int main(void)
{
    int a, c=0;
    int d1=0, d2=0, d3=0, d4=0, d5=0, d6=0, d7=0, d8=0, d9=0, d0=0;
    scanf ("%d", &a);
    for (; ((a%10)|(a/10)) != 0;)
    {
        a%10 == 1 ? d1++ : c++;
        a%10 == 2 ? d2++ : c++;
        a%10 == 3 ? d3++ : c++;
        a%10 == 4 ? d4++ : c++;
        a%10 == 5 ? d5++ : c++;
        a%10 == 6 ? d6++ : c++;
        a%10 == 7 ? d7++ : c++;
        a%10 == 8 ? d8++ : c++;
        a%10 == 9 ? d9++ : c++;
        a%10 == 0 ? d0++ : c++;
        a /= 10;
    }

    d9==1 ? printf ("YES") : printf ("NO");


	
	
	
	
	
	
	
            return 0;

}
