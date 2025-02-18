/*Польская запись
Необходимо вычислить выражение написанное в обратной польской записи.
На вход подается строка состоящая из целых, неотрицательных чисел и
арифметических символов. В ответ единственное целое число - результат.
Более подробно об Обратной польскаязапись числа можно также почитать тут
Examples
Input
3 4 +.
Output
7
Input
1 2 + 4 × 3 +.
Output
15
Input
100 25 + 25 /.
Output
5  */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_SIZE 100

// Структура стека
typedef struct {
    int data[MAX_SIZE];
    int top; //Вершина стека
} Stack;

// Инициализация стека
void initStack(Stack *s) {
    s->top = -1;
}

// Проверка, пуст ли стек
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Проверка, полон ли стек
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Добавление элемента в стек
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Стек переполнен!\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

// Извлечение элемента из стека
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Стек пуст!\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Вычисление выражения в обратной польской записи
int evaluateRPN(char *expression) {
    Stack s;
    initStack(&s);

    char *token = strtok(expression, " "); // Разделяем строку на токены по пробелам

    while (token != NULL) {
        if (isdigit(token[0])) { // Если токен — число
            push(&s, atoi(token));
        } else { // Если токен — оператор
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;

            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Неизвестный оператор: %c\n", token[0]);
                    exit(1);
            }
            push(&s, result);
        }
        token = strtok(NULL, " "); // Переход к следующему токену
    }
    return pop(&s); // Возвращаем результат
}

int main() {
    char expression[MAX_SIZE];

    // Ввод выражения
    //printf("Enter : ");
    fgets(expression, MAX_SIZE, stdin);

    // Удаляем символ новой строки, если он есть
    expression[strcspn(expression, "\n")] = '\0';

    // Вычисление и вывод результата
    int result = evaluateRPN(expression);
    printf("%d\n", result);

    return 0;
}
