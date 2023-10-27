//
// Created by Frank on 2023/10/21.
//
#include <stdio.h>

int main(void) {
    int row = 0;
    int cow = 0;
    scanf("%d %d", &row, &cow);
    int formation[3000][3000] = {0};
    //读入第一行（空出第0行和第0列）
    for (int j = 1; j <= cow; j++) {
        scanf("%1d", &formation[1][j]);
    }
    //完成其他行的队形
    for (int i = 2; i <= row; i++) {
        for (int j = 1; j <= cow; j++) {
            formation[i][j] =
                    (formation[i - 1][j - 1] && formation[i - 1][j] && formation[i - 1][j + 1] == 0)
                    || (formation[i - 1][j - 1] && formation[i - 1][j] == 0 && formation[i - 1][j + 1])
                    || (formation[i - 1][j - 1] == 0 && formation[i - 1][j] && formation[i - 1][j + 1])
                    || (formation[i - 1][j - 1] == 0 && formation[i - 1][j] && formation[i - 1][j + 1] == 0)
                    || (formation[i - 1][j - 1] == 0 && formation[i - 1][j] == 0 && formation[i - 1][j + 1]);
        }
    }
    for (int i = 2; i <= row; i++) {
        for (int j = 1; j <= cow; j++) {
            printf("%d ", formation[i][j]);
        }
        printf("\n");
    }
    return 0;
}