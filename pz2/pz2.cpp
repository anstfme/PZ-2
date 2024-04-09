//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int value) {
    stack->items[++stack->top] = value;
}

int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}


int main() {
    setlocale(LC_ALL, "ru");
    FILE* in,* out;
    if (fopen_s(&in, "input.txt", "r") != 0) {
        printf_s("Ошибка при открытии файла");
        return 1;
    }
    
    struct Stack stack;
    initialize(&stack);

    int i = 0;
    char c;

    if (fopen_s(&out, "output.txt", "w") != 0) {
        printf_s("Ошибка при открытии файла");
        return 1;
    }

    while ((c = fgetc(in)) != EOF) {
        if (c == '(') {
            push(&stack, i);
        }
        else if (c == ')') {
            if (stack.top != -1) {
                int k = pop(&stack);
                fprintf(out, "Открывающая скобка: %d, Закрывающая скобка: %d\n", k, i);
            }
        }
        i++;
    }

    fclose(in);
    return 0;
}
