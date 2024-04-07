//
// Created by Frank on 2023/11/26.
//
#include <stdio.h>
#include <string.h>

/**
 * 计算每一锤的价值
 * @param d
 * @param row
 * @param col
 * @return
 */
int Value(int d, int row, int col);

/**
 * 计算最大价值
 * @param n
 * @param m
 * @param d
 * @return
 */
int Max(int n, int m, int d);

/**
 * 找出有多少锤能最大价值
 * @param max
 * @param n
 * @param m
 * @param d
 * @return
 */
int find_max(int max, int n, int m, int d);

int map[500][500] = {0};
int value[500][500] = {0};

int main(void) {
    int n;
    int m;
    int d;
    scanf("%d %d %d", &n, &m, &d);
    memset(map, 0, sizeof map);
    memset(value, 0, sizeof value);

    for (int row = d; row < n + d; row++) {
        for (int col = d; col < m + d; col++) { //预先扩充充地图
            scanf("%d", &map[row][col]);
        }
    }

    for (int row = d; row < n + d; row++) {
        for (int col = d; col < m + d; col++) {
            value[row][col] = Value(d, row, col);
        }
    }

    int max = Max(n, m, d);

    int count = find_max(max, n, m, d);

    printf("%d %d\n", max, count);

    for (int row = d; row < n + d; row++) {
        for (int col = d; col < m + d; col++) {
            if (value[row][col] == max) {
                printf("%d %d\n", row - (d - 1), col - (d - 1));//注意还原地图
            }
        }
    }

    return 0;
}

int Value(int d, int row, int col) { //看成中心点的2d-1的正方形+4个
    int eachvalue = 0;
    for (int i = row - (d - 1); i <= row + (d - 1); i++) {
        for (int j = col - (d - 1); j <= col + (d - 1); j++) {
            eachvalue += map[i][j];
        }
    }
    eachvalue += map[row][col - d] + map[row][col + d] + map[row - d][col] + map[row + d][col];
    return eachvalue;
}

int Max(int n, int m, int d) {
    int max = -50000;
    for (int row = d; row < n + d; row++) {
        for (int col = d; col < m + d; col++) {
            if (max <= value[row][col]) {
                max = value[row][col];
            }
        }
    }
    return max;
}

int find_max(int max, int n, int m, int d) {
    int count = 0;
    for (int row = d; row < n + d; row++) {
        for (int col = d; col < m + d; col++) {
            if (value[row][col] == max) {
                count++;
            }
        }
    }
    return count;
}