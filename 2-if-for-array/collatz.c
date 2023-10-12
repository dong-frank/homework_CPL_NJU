//
// Created by Frank on 2023/10/9.
//
#include <stdio.h>

int main(void) {
    int num;
    int steps = 0;
    int max;

    scanf("%d", &num);
    max = num;
    for (; num > 1;) {
        if (num % 2 == 0) {
            num /= 2;
            steps += 1;
        } else {
            num = 3 * num + 1;
            steps += 1;
        }
        if (num > max) {
            max = num;
        }

    }
    printf("%d %d", steps, max);
    return 0;
}