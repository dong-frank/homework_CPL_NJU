//
// Created by Frank on 2023/10/21.
//
#include <stdio.h>

int main(void) {
    int m = 0;
    int n = 0;
    int p = 0;
    scanf("%d %d %d", &m, &n, &p);
    int a[100][100] = {0};
    int b[100][100] = {0};
    int c[100][100] = {0};
    //输入矩阵a和b
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    //计算矩阵c=a*b
    for (int row = 1; row <= m; row++) {
        for (int cow = 1; cow <= p; cow++) {
            for (int i = 1; i <= n; i++) {
                c[row][cow] += (a[row][i] * b[i][cow]);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}