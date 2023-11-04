//
// Created by Frank on 2023/10/29.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int Reverse(int num);

bool Prime(int num);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    int num = 2;
    int count = 0;
    while (num <= n) {
        if (Prime(num)) {
            if (Prime(Reverse(num))) {
                count++;
            }
        }
        num++;
    }
    printf("%d", count);
    return 0;
}

int Reverse(int num) {
    int a = 0;
    int digit = 0;
    int num_1 = num;
    while (num_1 > 0) {
        num_1 /= 10;
        digit++;
    }
    for (int i = digit - 1; i >= 0; i--) {
        a += (num % 10) * pow(10, i);
        num /= 10;
    }
    return a;
}

bool Prime(int num) {
    for (int i = 2; i <= sqrt(num + 0.5); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}