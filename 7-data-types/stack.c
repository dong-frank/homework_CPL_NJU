//
// Created by Frank on 2023/11/19.
//
#include<stdio.h>
#include <string.h>

void push(char array[], char word);

void pop(char array[]);

void top(const char array[]);

void print(const char array[]);

int capacity = 0;

int main(void) {
    int n = 0;
    scanf("%d", &n);
    char stack[10005] = {};

    while (n > 0) {
        char operation[10] = {};
        scanf("%3s", operation);
        if (strcmp(operation, "pus") == 0) {
            getchar();
            getchar();
            char word;
            scanf("%c", &word);
            push(stack, word);
        } else if (strcmp(operation, "pop") == 0) {
            pop(stack);
        } else if (strcmp(operation, "top") == 0) {
            top(stack);
        } else if (strcmp(operation, "pri") == 0) {
            print(stack);
            getchar();
            getchar();//清空缓冲区
        }
        n--;
    }
    return 0;
}

void push(char array[], char word) {
    array[capacity] = word;
    capacity++;
}

void pop(char array[]) {
    if (capacity == 0) {
        printf("Empty\n");
    } else {
        array[capacity - 1] = '\0';
        capacity--;
    }
}

void top(const char array[]) {
    if (capacity == 0) {
        printf("Empty\n");
    } else {
        printf("%c\n", array[capacity - 1]);
    }
}

void print(const char array[]) {
    if (capacity == 0) {
        printf("Empty\n");
    } else {
        for (int i = capacity - 1; i >= 0; i--) {
            printf("| %c |\n", array[i]);
        }
        printf("|===|\n");
    }
}