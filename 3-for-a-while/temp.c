//
// Created by Frank on 2023/10/14.
//
#include <stdio.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    int a[1000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 2; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}