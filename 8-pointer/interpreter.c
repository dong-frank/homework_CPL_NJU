//
// Created by Frank on 2023/11/29.
//
#include <stdio.h>

int main(void) {
    int num = 0;
    scanf("%x", &num);
    printf("%d\n", num);
    printf("%u\n", num);
    float *num1 = &num;
    printf("%.6f\n", *num1);
    printf("%.3e", *num1);
    return 0;
}