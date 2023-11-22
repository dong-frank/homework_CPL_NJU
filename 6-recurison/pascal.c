//
// Created by Frank on 2023/11/13.
//
#include <stdio.h>

int Pascal(int a, int b); //返回a，b的系数 C(a-1)(b-1)
int main(void) {
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    printf("%d", Pascal(a - 1, b - 1));
    return 0;
}

int Pascal(int a, int b) {
    if (a == b || b == 0) {
        return 1;
    }
    return (Pascal(a - 1, b - 1) + Pascal(a - 1, b));
}