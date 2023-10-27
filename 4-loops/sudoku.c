//
// Created by Frank on 2023/10/21.
//
#include <stdio.h>

#define SIZE 9

int main(void) {
    //输入9*9的数独
    int table[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &table[i][j]);
        }
    }
    //判断数独是否正确
    int is_correct = 1;

    //判断每一列
    for (int cow = 0; cow < SIZE; cow++) {
        int repid_cow[10] = {0};
        for (int row = 0; row < SIZE; row++) {
            if (repid_cow[table[row][cow]] == 0) {
                repid_cow[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    //判断每一行
    for (int row = 0; row < SIZE; row++) {
        int repid_row[10] = {0};
        for (int cow = 0; cow < SIZE; cow++) {
            if (repid_row[table[row][cow]] == 0) {
                repid_row[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    //判断每一个九宫格
    int repid_1[10] = {0};
    for (int row = 0; row < 3; row++) {
        for (int cow = 0; cow < 3; cow++) {
            if (repid_1[table[row][cow]] == 0) {
                repid_1[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    int repid_2[10] = {0};
    for (int row = 0; row < 3; row++) {
        for (int cow = 3; cow < 6; cow++) {
            if (repid_2[table[row][cow]] == 0) {
                repid_2[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    int repid_3[10] = {0};
    for (int row = 0; row < 3; row++) {
        for (int cow = 6; cow < 9; cow++) {
            if (repid_3[table[row][cow]] == 0) {
                repid_3[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    int repid_4[10] = {0};
    for (int row = 3; row < 6; row++) {
        for (int cow = 0; cow < 3; cow++) {
            if (repid_4[table[row][cow]] == 0) {
                repid_4[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    int repid_5[10] = {0};
    for (int row = 3; row < 6; row++) {
        for (int cow = 3; cow < 6; cow++) {
            if (repid_5[table[row][cow]] == 0) {
                repid_5[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    int repid_6[10] = {0};
    for (int row = 3; row < 6; row++) {
        for (int cow = 6; cow < 9; cow++) {
            if (repid_6[table[row][cow]] == 0) {
                repid_6[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    int repid_7[10] = {0};
    for (int row = 6; row < 9; row++) {
        for (int cow = 0; cow < 3; cow++) {
            if (repid_7[table[row][cow]] == 0) {
                repid_7[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    int repid_8[10] = {0};
    for (int row = 6; row < 9; row++) {
        for (int cow = 3; cow < 6; cow++) {
            if (repid_8[table[row][cow]] == 0) {
                repid_8[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    int repid_9[10] = {0};
    for (int row = 6; row < 9; row++) {
        for (int cow = 6; cow < 9; cow++) {
            if (repid_9[table[row][cow]] == 0) {
                repid_9[table[row][cow]] = 1;
            } else {
                is_correct = 0;
                goto end;
            }
        }
    }
    end:
    if (is_correct) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}