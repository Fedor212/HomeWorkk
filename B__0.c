/*Максимальный блок
Описана структура данных
typedef struct list {
uint64_t address;
size_t size;
char comment[64];
struct list *next;
} list;
Требуется реализовать только одну функцию, которая в данном списке находит адрес блока памяти занимающий больше всего места.
Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0. Если есть несколько таких блоков, то вернуть адрес любого из них.
Прототип функции:
uint64_t findMaxBlock(list *head)
Examples
Input
3
      140525067852320 10
      140525067852350 30
      140525067852900 100

Output
140525067852900 */

#include <math.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

typedef struct list {
uint64_t address;
size_t size;
char comment[64];
struct list *next;
} list;

uint64_t findMaxBlock(list *head)
{
    uint64_t maxadr = 0;
    size_t maxsize = 0;
    while (head)
    {
        if (head->size > maxsize)  //сравниваем новый адрес с максимальным
        {
            maxsize = head->size;
            maxadr = head->address;
        }
        head = head->next;
    }
    return maxadr;
}

int n =0;

int main(void)
{
    list ccc = {140525067852320U, 10, "3", NULL};
    list bbb = {140525067852350U, 30, "2", &ccc};
    list aaa = {140525067852900U, 100, "1", &bbb};

    list *head = &aaa;
    printf("Max Block size is::%" PRId64 "\n", findMaxBlock(head));

    return 0;
}

