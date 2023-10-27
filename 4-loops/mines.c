//
// Created by Frank on 2023/10/22.
//
#include <stdio.h>

#define NUM 48

int main(void) {
    //输入行数
    int n = 0;
    scanf("%d", &n);
    getchar();
    //输入地图
    char map[200][200] = {};
    int mines[200][200] = {0};
    for (int row = 1; row <= n; row++) {
        for (int cow = 1; cow <= n; cow++) {
            map[row][cow] = getchar();
        }
        getchar();
    }
    for (int row = 1; row <= n; row++) {
        for (int cow = 1; cow <= n; cow++) {
            mines[row][cow] = (map[row][cow] == '*');
        }
    }
    //标出数字
    for (int row = 1; row <= n; row++) {
        for (int cow = 1; cow <= n; cow++) {
            if (mines[row][cow] == 0) {
                map[row][cow] =
                        (mines[row - 1][cow - 1] + mines[row - 1][cow] + mines[row - 1][cow + 1] +
                         mines[row][cow - 1] + mines[row][cow + 1] +
                         mines[row + 1][cow - 1] + mines[row + 1][cow] + mines[row + 1][cow + 1]) + NUM;
            }
        }
    }
    for (int row = 1; row <= n; row++) {
        for (int cow = 1; cow <= n; cow++) {
            printf("%c", map[row][cow]);
        }
        printf("\n");
    }

    return 0;
}