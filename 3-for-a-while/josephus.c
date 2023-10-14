//
// Created by Frank on 2023/10/14.
//
#include<stdio.h>

int main(void) {
    int n;
    int k;
    scanf("%d %d", &n, &k);
    int sum = n;
    int is_live[500] = {0};

    //模拟报数的过程
    while (sum > 1) {
        for (int i = 1, j = 1; j <= sum; j++) {
            while (is_live[i] == 1) {
                i++;
            }
            if (j % k == 0) {
                is_live[i] = 1;
                sum--;
                i++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (is_live[i] == 0) {
            printf("%d", i);
        }
    }
    return 0;
}