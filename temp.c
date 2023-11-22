//
// Created by asus on 2023/11/19.
//
#include <stdio.h>

int SUM(int p, int n);


int main() {
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = SUM(a - 1, b - 1);
    printf("%d", c);
    return 0;
}

int SUM(int p, int n) {

    if (n == 1) {
        return 1;
    }
    return SUM(p - 1, n - 1) + SUM(p - 1, n);
}
