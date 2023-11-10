//
// Created by Frank on 2023/11/5.
//
#include <stdio.h>

int main() {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    getchar();
    int chuan1[20000] = {0};
    int chuan2[20000] = {0};
    int chuan3[20000] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        chuan1[i] = x;
        getchar();
    }
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        chuan2[i] = x;
        getchar();
    }
    int w = 0;
    int z = -1;
    for (int i = 0; i < m; i++) {
        int c = t - chuan2[i];
        int k = (n - 1) / 2;
        int low = 0;
        int high = n - 1;

        while (low < high) {
            if (chuan1[high] <= c) {
                chuan3[w] = c - chuan1[high];
                z = 0;
                w++;
                break;
            }
            if (chuan1[k] < c && chuan1[k + 1] > c) {
                chuan3[w] = c - chuan1[k];
                w++;
                z = 0;
                break;
            }
            if (chuan1[k] == c) {
                chuan3[w] = 0;
                w++;
                z = 0;
                break;
            }
            if (chuan1[k] > c) {
                high = k;
                k = (high + low) / 2;
            }
            if (chuan1[k] < c && chuan1[k + 1] <= c) {
                low = k + 1;
                k = (low + high) / 2;
            }
        }
    }
    if (z == 0) {
        int min = chuan3[0];
        for (int i = 1; i < w; i++) {
            if (chuan3[i] < min) {
                min = chuan3[i];
            }
        }
        printf("%d", min);
    } else {
        printf("%d", z);
    }
}