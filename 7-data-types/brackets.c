//
// Created by Frank on 2023/11/20.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int capacity = 0;

void push(char stack[], char word);

void pop(char stack[]);

int main(void) {
    int t = 0;
    scanf("%d", &t);
    while (t--) {
        bool Is_legal = true;
        capacity = 0;//栈初始化
        char string[100005] = {};
        scanf("%s", string);
        int length = 0;
        while (string[length] != 0) {
            length++;
        }
        char stack[10000] = {};
        memset(stack, '\0', sizeof stack);

        for (int i = 0; i < length; i++) {
            if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
                push(stack, string[i]);
            } else if ((string[i] == ')' && stack[capacity - 1] == '(') ||
                       (string[i] == ']' && stack[capacity - 1] == '[') ||
                       (string[i] == '}' && stack[capacity - 1] == '{')) {
                pop(stack);
            } else {
                Is_legal = false;
                break;
            }
        }
        if (capacity == length) { //排除只存不取的情况
            Is_legal = false;
        }
        if (Is_legal)
            printf("True\n");
        else
            printf("False\n");
    }
    return 0;
}

void push(char stack[], char word) {
    stack[capacity] = word;
    capacity++;
}

void pop(char stack[]) {
    stack[capacity - 1] = '\0';
    capacity--;
}