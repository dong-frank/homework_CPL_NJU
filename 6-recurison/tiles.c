//
// Created by Frank on 2023/11/13.
//
#include <stdio.h>

int Tiles(int n);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    printf("%d", Tiles(n));
    return 0;
}

int Tiles(int n) {
    if (n == 2) {
        return 2;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 0) {
        return 0;
    }
    return Tiles(n - 1) + Tiles(n - 2);
}