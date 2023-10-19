//
// Created by Frank on 2023/10/19.
//
#include <stdio.h>
#include <math.h>

int main(void) {
    int length = 0;
    scanf("%d", &length);
    int n = 0;
    scanf("%d", &n);
    getchar();
    //输入n进制数
    char number[1000] = {' '};
    for (int i = 0; i < length; i++) {
        number[i] = getchar();
    }
    //检测合法性
    int is_legal = 1;
    for (int i = 0; i < length; i++) {
        if (n <= 10) {
            if (number[i] < '0' || number[i] >= n + '0') {
                is_legal = 0;
            }
        } else {
            if (number[i] < '0' || number[i] > n - 11 + 'A') {
                is_legal = 0;
            }
        }
    }
    //转换为10进制
    int digit = 0;
    if (is_legal == 1) {
        for (int i = 0; i < length; i++) {
            if (number[i] >= '0' && number[i] <= '9') {
                digit += (number[i] - '0') * pow(n, length - i - 1);
            } else if (number[i] >= 'A' && number[i] <= 'Z') {
                digit += (number[i] - 'A' + 10) * pow(n, length - i - 1);
            }
        }
        printf("%d", digit);
    } else {
        printf("Error");
    }
    return 0;
}