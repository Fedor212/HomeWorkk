/*Отсортировать слова
Дана строка, состоящая из английских букв и пробелов. В конце строки символ точка. Все слова разделены одним пробелом. Необходимо составить из слов односвязный список и упорядочить по алфавиту. Список необходимо удалить в конце программы. Для сравнение строк можно использовать strcmp. Необходимо использовать данную структуры организации списка.
struct list {
char word[20];
struct list *next;
}
Необходимо реализовать односвязный список и обслуживающие его функции.
add_to_list
 swap_elements
 print_list
 delete_list
Examples
Input
efg abcd zzz.
Output
abcd efg zzz
Input
fffff kkkkkk a.
Output
a fffff kkkkkk  */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Структура списка
struct list {
    char word[20];
    struct list *next;
};

// Функция для создания нового слова
struct list* createNode(const char *word) {
    struct list *newNode = (struct list*)malloc(sizeof(struct list));
    if (newNode == NULL) {
        //printf("Memory error!\n");
        exit(1);
    }
    strncpy(newNode->word, word, 19);
    newNode->word[19] = '\0'; // Гарантируем завершение строки
    newNode->next = NULL;
    return newNode;
}

// Функция для добавления узла в список
void addNode(struct list **head, const char *word) {
    struct list *newNode = createNode(word);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct list *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функция для сортировки списка по алфавиту
void sortList(struct list **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // Список пуст или содержит один элемент
    }

    int swapped;
    struct list *ptr1;
    struct list *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->word, ptr1->next->word) > 0) {
                // Меняем слова местами
                char temp[20];
                strcpy(temp, ptr1->word);
                strcpy(ptr1->word, ptr1->next->word);
                strcpy(ptr1->next->word, temp);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Функция для вывода списка
void printList(struct list *head) {
    struct list *current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
}

// Функция для удаления списка
void deleteList(struct list **head) {
    struct list *current = *head;
    struct list *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL; // Указываем, что список пуст
}

int main() {
    char input[1000];
    struct list *head = NULL;

    // Ввод строки
    //printf("Enter string : ");
    fgets(input, sizeof(input), stdin);

    // Удаляем точку и символ новой строки
    //Функция strcspn выполняет поиск первого вхождения в строку string1
    // любого из символов строки string2 , и возвращает количество символов до первого вхождения
    input[strcspn(input, ".\n")] = '\0';

    // Разделяем строку на слова
    char *word = strtok(input, " ");
    while (word != NULL) {
        addNode(&head, word); // Добавляем слово в список
        word = strtok(NULL, " ");
    }

    // Сортируем список
    sortList(&head);

    // Выводим отсортированный список
    printList(head);

    // Удаляем список
    deleteList(&head);

    return 0;
}
