//
// Created by Frank on 2023/11/27.
//
#include <stdio.h>

#define SIZE 100

int n = 0;
int m = 0; //n行m列的地图
int d = 0;
int map[SIZE][SIZE] = {0};

int Differ(int row, int col);

int Value(int row, int col);

int main(void) {

    scanf("%d%d%d", &n, &m, &d);
    //读入地图，注意地图边界扩展
    for (int row = d; row < n + d; row++) {
        for (int col = d; col < m + d; col++) {
            scanf("%d", &map[row][col]);
        }
    }
    //填入差量并找出最大差量
    int max = -50001;
    int value_differ[SIZE][SIZE] = {0};
    value_differ[d][d] = 0;
    for (int row = d; row < n + d; row++) {
        if ((row - (d - 1)) % 2 == 1 && row > d) { //奇数行
            for (int col = d; col < m + d; col++) {
                if (col - d >= 1) {
                    value_differ[row][col] = value_differ[row][col - 1] + Differ(row, col - 1);
                } else if (col == d) {
                    value_differ[row][col] = value_differ[row - 1][col] + Differ(row - 1, col);
                }
                if (max <= value_differ[row][col]) {
                    max = value_differ[row][col];
                }
            }
        } else if ((row - (d - 1)) % 2 == 0) { //偶数行
            for (int col = m + (d - 1); col >= d; col--) {
                if (col < m + (d - 1)) {
                    value_differ[row][col] = value_differ[row][col + 1] + Differ(row, col + 1);
                } else if (col == m + d - 1) {
                    value_differ[row][col] = value_differ[row - 1][col] + Differ(row - 1, col);
                }
                if (max <= value_differ[row][col]) {
                    max = value_differ[row][col];
                }
            }
        }
    }
    //for (int i = d; i < n + d; i++) {
    //for (int j = d; j < m + d; j++) {
    //printf("%d ", value_differ[i][j]);
    //}
    //printf("\n");
    //}

    //记下最大差量的坐标
    int coordinate[SIZE][2] = {0};
    int count = 0;
    for (int row = d; row < n + d; row++) {
        for (int col = d; col < m + d; col++) {
            if (max == value_differ[row][col]) {
                count++;
                coordinate[count][0] = row;
                coordinate[count][1] = col;
            }
        }
    }
    int max_value = Value(coordinate[count][0], coordinate[count][1]);
    printf("%d %d\n", max_value, count);
    for (int i = 1; i <= count; i++) {
        printf("%d %d\n", coordinate[i][0] - d + 1, coordinate[i][1] - d + 1);
    }
    return 0;
}

int Differ(int row, int col) {
    int old_value = 0;
    int new_value = 0;
    if ((col == d && (row - (d - 1)) % 2 == 0) || (col == m + (d - 1) && (row - (d - 1)) % 2 == 1)) {
        for (int i = row, j = col - d; i >= row - d; i--, j++) {
            old_value += map[i][j];
        }
        for (int i = row, j = col + d; i > row - d; i--, j--) {
            old_value += map[i][j];
        }

        int row1 = row + 1;

        for (int i = row1, j = col - d; i <= row1 + d; i++, j++) {
            new_value += map[i][j];
        }
        for (int i = row1, j = col + d; i < row1 + d; i++, j--) {
            new_value += map[i][j];
        }
    } else if ((row - (d - 1)) % 2 == 1) { //单行的滑动
        for (int i = row - d, j = col; i <= row; i++, j--) {
            old_value += map[i][j];
        }
        for (int i = row + d, j = col; i > row; i--, j--) {
            old_value += map[i][j];
        }

        int col1 = col + 1;

        for (int i = row - d, j = col1; i <= row; i++, j++) {
            new_value += map[i][j];
        }
        for (int i = row + d, j = col1; i > row; i--, j++) {
            new_value += map[i][j];
        }
    } else if ((row - (d - 1)) % 2 == 0) {
        for (int i = row - d, j = col; i <= row; i++, j++) {
            old_value += map[i][j];
        }
        for (int i = row + d, j = col; i > row; i--, j++) {
            old_value += map[i][j];
        }

        int col2 = col - 1;

        for (int i = row - d, j = col2; i <= row; i++, j--) {
            new_value += map[i][j];
        }
        for (int i = row + d, j = col2; i > row; i--, j--) {
            new_value += map[i][j];
        }
    }

    return new_value - old_value;
}

int Value(int row, int col) {
    int each_value = 0;
    for (int i = row - d; i <= row; i++) {
        for (int j = col - (i - (row - d)); j <= col + (i - (row - d)); j++) {
            each_value += map[i][j];
        }
    }
    for (int i = row + d; i > row; i--) {
        for (int j = col + (i - (row + d)); j <= col - (i - (row + d)); j++) {
            each_value += map[i][j];
        }
    }
    return each_value;
}

//1. 输入时地图的扩充（下标会变化） 输出时注意下标减回去！！！
//2. 锤子的图形一定要注意，找出正确的通项f（d），我这里错了两次，/(ㄒoㄒ)/~~
//3. 如果是策略1的Z型，注意奇数行和偶数行的区别，一个从左到右，一个从右到左，而且往下走的位置不同
//4. 注意求出差量后怎么将差量转化为相对值的大小，并记录下最大的相对值
//5. 宝宝是最棒的，fighting！！！