//
// Created by Frank on 2023/10/8.
//
#include <stdio.h>

int main(void) {
    int n;
    const int m = 10007;
    scanf("%d", &n);
    int factorial = 1;
    int sum_of_factorial = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            factorial *= j;
            factorial %= m;
        }

        sum_of_factorial += factorial;
        factorial = 1;
    }
    sum_of_factorial %= m;
    printf("%d", sum_of_factorial);
    return 0;
}