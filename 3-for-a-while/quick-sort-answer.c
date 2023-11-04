//
// Created by Frank on 2023/10/28.
//
#include <stdio.h>

int main(void) {
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    int a[100005] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int l = 0;
    int r = n - 1;
    int pivot = a[k - 1];
    while (l != r) {
        while (l != r && a[l] < pivot) {
            l++;
        }
        while (l != r && a[r] >= pivot) {
            r--;
        }
        if (l != r) {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
    }
    if (a[l] > pivot) {
        for (int i = 0; i < n; i++) {
            if (a[i] == pivot) {
                int temp = a[l];
                a[l] = pivot;
                a[i] = temp;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}