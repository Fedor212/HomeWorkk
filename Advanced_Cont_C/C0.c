/*Сколько различных трехзначных чисел можно получить из заданного натурального N,
вычеркивая цифры из его десятичной записи?  */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Функция для подсчета уникальных трехзначных чисел
int countUniqueThreeDigitNumbers(const char *number) {
    int len = strlen(number);
    int count = 0;
    int uniqueNumbers[5000] = {0}; // Массив для хранения уникальных трехзначных чисел
    //int AllNumbers[5000] = {0}; // Массив для хранения уникальных трехзначных чисел
    //int fcount = 0;
    //int bool = 0;

    // Перебираем все возможные комбинации из трех цифр
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                // Формируем трехзначное число
                int threeDigitNumber = (number[i] - '0') * 100 +
                                      (number[j] - '0') * 10 +
                                      (number[k] - '0');


                //~ for (int f = 0; f < 5000; f++)
                //~ {
                   //~ if (AllNumbers[f] == threeDigitNumber)
                        //~ {bool = 1;}
                //~ }
                //~ if ((bool == 0) && (threeDigitNumber > 99))
                //~ {
                    //~ printf("%d\n", threeDigitNumber);
                    //~ AllNumbers[fcount] = threeDigitNumber;
                    //~ fcount++;
                //~ }
                //~ else
                //~ {bool = 0;}



                // Проверяем, было ли такое число уже добавлено
                if ((!uniqueNumbers[threeDigitNumber]) && (threeDigitNumber != 0) && (threeDigitNumber > 99)) {
                    uniqueNumbers[threeDigitNumber] = 1; // Помечаем число как использованное
                    count++; // Увеличиваем счетчик уникальных чисел

                }
            }
        }
    }
    //printf("fcount: %d\n", fcount);
    return count;
}

int main() {
    char N[150]; // Максимальная длина числа — 100 цифр

    // Ввод числа
    scanf("%s", N);

    // Подсчет уникальных трехзначных чисел
    int result = countUniqueThreeDigitNumbers(N);

    // Вывод результата
    printf("%d\n", result);


    return 0;
}
