/*Большими буквами
Составить функцию, которая переводит латинскую строчную букву в заглавную. И показать пример ее использования.
Формат входных данных
Строка состоящая из английских букв, пробелов и запятых. В конце строки символ точка.
Формат результата
Исходная строка в которой маленькие английские буквы заменены заглавными.
Примеры
Входные данные
hello World!.
Результат работы
HELLO WORLD!
Входные данные
abc, def.
Результат работы
ABC, DEF */

//#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <locale.h>


int main(void)
{
	char c;
	while( (c=getchar())!='.')
		if(c>='a' && c<='z')
		{ putchar('A' + (c-'a'));
		}
		else
		{ putchar(c);
		}	    
    return 0;
}
