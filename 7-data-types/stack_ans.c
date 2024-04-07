//
// Created by Frank on 2023/12/8.
//
#include <stdio.h>
#include <string.h>

char operation[10];
int top = 0;
char stack[10004];

void Push(void);

void Pop(void);

void Top(void);

void Print(void);

int main(void) {
    int T = 0;
    scanf("%d", &T);
    while (T > 0) {
        memset(operation, '\0', 10);
        scanf("%s", operation);
        if (operation[0] == 'p' && operation[1] == 'u') {
            Push();
        } else if (operation[0] == 'p' && operation[1] == 'o') {
            Pop();
        } else if (operation[0] == 't') {
            Top();
        } else {
            Print();
        }
        T--;
    }
    return 0;
}

void Push(void) {
    top++;
    char word[1] = {0};
    scanf("%s", word);
    stack[top] = word[0];
}

void Pop(void) {
    if (top == 0) {
        printf("Empty\n");
    } else {
        stack[top] = '\0';
        top--;
    }
}

void Top(void) {
    if (top == 0) {
        printf("Empty\n");
    } else {
        printf("%c\n", stack[top]);
    }
}

void Print(void) {
    if (top == 0) {
        printf("Empty\n");
    } else {
        for (int i = top; i > 0; i--) {
            printf("| %c |\n", stack[i]);
        }
        printf("|===|\n");
    }
}