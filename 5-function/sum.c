//
// Created by Frank on 2023/10/28.
//
#include <stdio.h>
#include <math.h>

int number(int t, int i);

int main(void) {
    int n = 0;
    int t = 0;
    scanf("%d %d", &n, &t);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += number(t, i);
    }
    printf("%d", sum);
    return 0;
}

int number(int t, int i) {
    int number = 0;
    for (int j = 0; j <= i; j++) {
        number += t * pow(10, j);
    }
    return number;
}