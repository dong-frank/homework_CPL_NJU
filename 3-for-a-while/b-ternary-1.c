//
// Created by Frank on 2023/10/14.
//SO UGLY!!!
#include <stdio.h>
#include <math.h>

int main(void) {
    const int Z = 89;
    const int NUM = 48;
    int nums;
    scanf("%d", &nums);
    int length = 0;
    int is_allowed[10000] = {0};

    int digt[10000] = {0};
    getchar();
    //读取nums个平衡三进制数
    for (int j = 0; j < nums; j++) {
        int b_ternary[17] = {0};
        length = 0;
        for (int i = 1; (b_ternary[i] = getchar()) != '\n'; i++) {
            length++;
            if (b_ternary[i] != '0' && b_ternary[i] != '1' && b_ternary[i] != 'Z') {
                is_allowed[j] = 1;
            }
        }
        //计算对应的十进制
        for (int i = 1; i <= length; i++) {
            //将z换为-1
            if (is_allowed[j] == 0 && b_ternary[i] == 'Z') {
                digt[j] += (-b_ternary[i] + Z) * pow(3, (length - i));
            } else if (is_allowed[j] == 0 && (b_ternary[i] == '0' || b_ternary[i] == '1')) {
                digt[j] += (b_ternary[i] - NUM) * pow(3, (length - i));
            }
        }
    }
    //输出
    for (int i = 0; i < nums; i++) {
        if (is_allowed[i] == 0) {
            printf("%d\n", digt[i]);
        } else {
            printf("Radix Error\n");
        }
    }
    return 0;
}
