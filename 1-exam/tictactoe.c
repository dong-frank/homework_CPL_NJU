//
// Created by Frank on 2023/11/5.
//
#include <stdio.h>
#include <string.h>

int table[25][25];
int ans[25][25];

//开在全局变量下自动初始化


int main(void) {
    int t = 0;// 棋盘数
    int x = 0;// 获胜条件
    scanf("%d %d", &t, &x);
    int n = 0;
    int offset = x; //避免溢出,设置偏移量
    while (t--) {
        memset(table, 0, sizeof(table));
        memset(ans, 0, sizeof(ans));// 清空数组
        scanf("%d", &n);//每个棋盘的大小

        for (int i = offset; i < n + offset; i++) {
            for (int j = offset; j < n + offset; j++) {
                scanf("%d", &table[i][j]);
                ans[i][j] = table[i][j];
            }
        }

        for (int i = offset; i < n + offset; i++) {
            for (int j = offset; j < n + offset; j++) {
                if (ans[i][j] == 0) {
                    continue;// 只检查有棋子的位置
                }
                int row = ans[i][j];
                int col = ans[i][j];
                int left_bottom = ans[i][j];
                int right_bottom = ans[i][j];

                for (int k = 1; k < x; k++) {// 依次按位与 共x-1个棋子
                    row &= ans[i][j + k];
                    col &= ans[i + k][j];
                    left_bottom &= ans[i + k][j - k];
                    right_bottom &= ans[i + k][j + k];
                }
                ans[i][j] = row | col | left_bottom | right_bottom; //统计四个方向
            }
        }
        int right = 0;
        for (int i = offset; i < n + offset; i++) {
            for (int j = offset; j < n + offset; j++) {
                right |= ans[i][j];// 统计全局结果
            }
        }
        if (right == 1 || right == 2 || right == 4) { //判断赢还是平，如果平肯定不是1 2 4
            printf("%d\n", right);
        } else {
            printf("draw\n");
        }

    }
    return 0;
}

