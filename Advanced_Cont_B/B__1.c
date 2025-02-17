/*Всего памяти
Описана структура данных для хранения информации об использованной памяти:
typedef struct list {
void *address;
size_t size;
char comment[64];
struct list *next;
} list;
Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется. Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0.
Прототип функции:
size_t totalMemoryUsage(list *head)
Examples
Input
3
      140525067852320 10
      140525067852350 30
      140525067852900 100
Output

140
 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list *head)
{
    list *lizt = head;
    size_t fullmem = lizt->size;

    while (lizt->next != NULL)
    {
       lizt = lizt -> next;
        fullmem += lizt->size;
    }
    return fullmem;
}

int n =0;

int main(void)
{
    list ccc = {140525067852320U, 10, "3", NULL};
    list bbb = {140525067852350U, 30, "2", &ccc};
    list aaa = {140525067852900U, 100, "1", &bbb};

    list *head = &aaa;
    printf("Full memory is: %zu \n", totalMemoryUsage(head));

    return 0;
}
