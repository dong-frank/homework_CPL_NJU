//
// Created by Frank on 2023/10/19.
//
#include <stdio.h>

int reverse(int num) {
    int a = 0;
    int b = 0;
    if (num != 0) {
        a = num % 10;
        b = num / 10;
    } else {
        a = 0;
        b = 0;
    }
    return (10 * a + b);
}

int main(void) {
    int length = 0;
    scanf("%d", &length);
    char string[100000] = "";
    scanf("%s", string);
    //创建一个数组存储二位数
    int table_of_numbers[100] = {0};
    for (int i = 0; i < 100; i++) {
        table_of_numbers[i] = i;
    }
    //输出字符串，保留未消去的？
    //未消去的？输出一个二位数
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (string[i] == '?') {
            string[i] = string[length - i - 1];
        }
        if (string[i] == '?') {
            if (i < length / 2) {
                printf("%.2d", table_of_numbers[j++]);
            } else {
                printf("%.2d", reverse(table_of_numbers[--j]));
            }
        } else {
            printf("%c", string[i]);
        }
    }
    return 0;
}
