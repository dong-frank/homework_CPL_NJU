//
// Created by Frank on 2023/10/14.
//
#include<stdio.h>

int main(void) {
    int length;
    scanf("%d", &length);
    int bits[2000] = {0};

    for (int j = 1; j <= length; j++) {
        for (int i = 1; i <= length; i++) {
            if (i % j == 0) {
                bits[i] = !bits[i];
            }
        }
    }

    for (int i = 1; i <= length; i++) {
        if (bits[i] == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}