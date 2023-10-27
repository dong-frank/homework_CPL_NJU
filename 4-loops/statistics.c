//
// Created by Frank on 2023/10/26.
//
#include <stdio.h>

int main(void) {
    int length = 0;
    scanf("%d", &length);
    char words[100] = "";
    scanf("%s", words);
    // 计数
    int sums[130] = {0};

    for (int i = 0; i < length; i++) {
        sums[words[i]]++;
    }
    //格式化输出
    char table[50][50] = {""};
    for (int i = 97; i < 123; i++) {
        if (sums[i] != 0) {
            for (int j = 49; j > 49 - sums[i]; j--) {
                table[j][(i - 97) * 2] = '=';
            }
        }
        if (sums[i - 32] != 0) {
            for (int j = 49; j > 49 - sums[i - 32]; j--) {
                table[j][(i - 97) * 2 + 1] = '=';
            }
        }
    }
    int is_space[100] = {0};
    for (int i = 97, j = 0; i < 123; i++) {
        if (sums[i] != 0) {
            j++;
        }
        if (sums[i - 32] != 0) {
            j++;
        }
        if (sums[i] != 0 || sums[i - 32] != 0) {
            j++;
            is_space[j] = 1;
        }
    }
    for (int i = 0; i < 50; i++) {
        for (int j = 0, t = 1; j < 50; j++, t++) {
            while (is_space[t] == 1 && is_space[t + 1] == 0) {
                j++;
            }
            printf("%c", table[i][j]);
        }
        printf("\n");
    }
    for (int i = 97; i < 123; i++) {
        if (sums[i] != 0) {
            printf("-");
        }
        if (sums[i - 32] != 0) {
            printf("-");
        }
        if (sums[i] != 0 || sums[i - 32] != 0) {
            printf("-");
        }
    }
    printf("\n");
    for (int i = 97; i < 123; i++) {
        if (sums[i] != 0) {
            printf("%c", i);
        }
        if (sums[i - 32] != 0) {
            printf("%c", i - 32);
        }
        if (sums[i] != 0 || sums[i - 32] != 0) {
            printf(" ");
        }
    }
    return 0;
}