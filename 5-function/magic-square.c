//
// Created by Frank on 2023/10/28.
//
#include <stdio.h>
#include <stdbool.h>

bool Flag1a(int row);//右上方格出界
bool Flag1b(int col, int size);

bool Flag2(int row, int col, int array[][10], int size);//右上方格有数

int main(void) {
    int size = 0;
    scanf("%d", &size);
    int array[10][10] = {0};
    //填幻方
    array[1][(size + 1) / 2] = 1;
    int row = 1;
    int col = (size + 1) / 2;
    for (int k = 2; k <= size * size; k++) {
        if (Flag1a(row)) {
            //从另一边左侧或下面进入
            if (col < size) {
                if (array[size][col + 1] == 0) {
                    row = size;
                    col += 1;
                } else {
                    row += 1;
                }
            } else {
                if (array[size][1] == 0) {
                    row = size;
                    col = 1;
                } else {
                    row += 1;
                }
            }
        } else if (Flag1b(col, size)) {
            if (row > 1) {
                if (array[row - 1][1] == 0) {
                    row -= 1;
                    col = 1;
                } else {
                    row += 1;
                }
            } else {
                if (array[size][1] == 0) {
                    row = size;
                    col = 1;
                } else {
                    row += 1;
                }
            }
        } else if (Flag2(row, col, array, size)) {
            //从该数的下面进入
            row += 1;
        } else {
            //右上方
            row -= 1;
            col += 1;
        }
        array[row][col] = k;
    }
    //打印
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}

bool Flag1a(int row) {
    if (row == 1) {
        return true;
    } else {
        return false;
    }
}

bool Flag1b(int col, int size) {
    if (col == size) {
        return true;
    } else {
        return false;
    }
}

bool Flag2(int row, int col, int array[][10], int size) {
    if (!Flag1a(row) && !Flag1b(col, size) && array[row - 1][col + 1] != 0) {
        return true;
    } else {
        return false;
    }
}