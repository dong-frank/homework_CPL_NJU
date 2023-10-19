//
// Created by Frank on 2023/10/15.
//
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    //读入n个十进制数
    int digit[10000] = {0};
    char digit_c[10000] = {0};
    int is_illegal[10000] = {0};
    getchar();
    for (int j = 0; j < n; j++) {
        for (int i = 0; (digit_c[i] = getchar()) != '\n'; i++) {
            if ((digit_c[i] < 48 || digit_c[i] > 57) && digit_c[i] != '-') {
                is_illegal[j] = 1;
            }
        }
        digit[j] = atoi(digit_c);
    }

    //检查非法输入

    //将十进制转换为标准三进制

    int length[10000] = {0};
    int is_negative[10000] = {0};
    for (int j = 0; j < n; j++) {
        int std_ternary[10000] = {0};
        //全部转为正数并标记出负数
        if (digit[j] < 0) {
            digit[j] = -digit[j];
            is_negative[j] = 1;
        }
        if (digit[j] == 0) {
            printf("0");
        }
        for (int i = 0; digit[j] > 0; i++) {
            length[j]++;
            std_ternary[i] = digit[j] % 3;
            digit[j] /= 3;
        }
        //将标准三进制处理为平衡三进制
        char b_ternary[10000] = {0};
        for (int i = 0; i <= length[j]; i++) {
            switch (std_ternary[i]) {
                case 0:
                    if (i < length[j]) {
                        b_ternary[i] = '0';
                    }
                    break;
                case 1:
                    b_ternary[i] = '1';
                    break;

                case 2:
                    b_ternary[i] = 'Z';
                    std_ternary[i + 1] += 1;
                    break;
                case 3:
                    b_ternary[i] = '0';
                    std_ternary[i + 1] += 1;
                    break;
                default:
                    break;
            }
            //处理负数
            if (is_negative[j] == 1) {
                switch (b_ternary[i]) {
                    case 'Z':
                        b_ternary[i] = '1';
                        break;
                    case '1':
                        b_ternary[i] = 'Z';
                        break;
                }
            }
        }
        //翻转为正确顺序
        length[j] = strlen(b_ternary);
        for (int i = 0; i < length[j] / 2; i++) {
            char temp;
            temp = b_ternary[length[j] - i - 1];
            b_ternary[length[j] - i - 1] = b_ternary[i];
            b_ternary[i] = temp;
        }
        //输出
        if (is_illegal[j] == 0) {
            for (int i = 0; i < length[j]; i++) {
                printf("%c", b_ternary[i]);
            }
            printf("\n");
        } else {
            printf("Radix Error\n");
        }
    }
    return 0;
}