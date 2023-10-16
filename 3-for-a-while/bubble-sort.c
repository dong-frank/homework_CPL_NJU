//
// Created by Frank on 2023/10/15.
//
#include <stdio.h>

//最后一个数无法正确排序
//只要检测最后一位是不是最大值
int main(void) {
    int s = 0;
    scanf("%d", &s);
    int is_ok[100000] = {0};
    for (int j = 0; j < s; j++) {
        int a[50000] = {0};
        int n = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int max = a[0];
        for (int i = 0; i < (n - 1); i++) {
            if (max < a[i]) {
                max = a[i];
            }
        }
        if (max <= a[n - 1]) {
            is_ok[j] = 1;
        }
    }
    for (int j = 0; j < s; j++) {
        if (is_ok[j]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}