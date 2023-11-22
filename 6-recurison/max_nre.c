//
// Created by Frank on 2023/11/22.
//
#include <stdio.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    int a[100005] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int j = 1;
    while (j <= n) {
        int l = j;
        int r = j;
        for (int i = j; i >= 1; i--) {
            if (a[i] <= a[j]) {
                l = i;
            } else {
                break;
            }
        }
        for (int i = j; i <= n; i++) {
            if (a[i] <= a[j]) {
                r = i;
            } else {
                break;
            }
        }
        printf("%d %d\n", l, r);
        j++;
    }
    return 0;
}