//
// Created by Frank on 2023/10/29.
//
#include<stdio.h>

int main(void) {
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    int is_live[1000] = {0};
    for (int i = 1; i <= n; i++) {
        is_live[i] = 1;
    }
    int pos = 0;
    for (int i = 1; i <= n - 1; i++) { //进行n-1轮杀死n-1个人
        for (int j = 1; j <= k; j++) { //报数报到第k个人
            pos++;
            if (pos > n) {
                pos = 1;
            }
            while (is_live[pos] == 0) {
                pos++;
                if (pos > n) {
                    pos = 1;
                }
            }

        }
        is_live[pos] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (is_live[i]) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}