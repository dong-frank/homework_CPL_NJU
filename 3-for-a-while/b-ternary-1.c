//
// Created by Frank on 2023/10/14.
//
#include <stdio.h>

int main(void) {
    int nums;
    scanf("%d", &nums);
    int i = 0;
    int length = 0;
    char b_ternary[2000] = {0};

    getchar();
    //读取nums个平衡三进制数
    while (getchar() != '\n') {
        scanf("%c", &b_ternary[i]);
        length++;
        if (b_ternary[i] == 'z') {
            b_ternary[i] = '-1';
        }
        i++;
    }
    for (int j = 0; j < length; j++) {
        printf("%c", b_ternary[i]);
    }
    //将z换为-1

    //计算对应的十进制

    //输出
    return 0;
}
