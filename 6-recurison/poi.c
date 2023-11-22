//
// Created by Frank on 2023/11/13.
//
#include <stdio.h>

int Poi(const int a[], int i);

int main(void) {
    int n = 0;
    int a[100005] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int b[100005] = {0};
    for (int i = 1; i <= n; i++) {
        b[i] = Poi(a, i);
        printf("%d ", b[i]);
    }

    return 0;
}

int Poi(const int a[], int i) { //返回编号为i的犯罪主使编号
    if (a[i] == i) {
        return i;
    }
    int partial_poi = Poi(a, a[i]);
    return partial_poi;
}