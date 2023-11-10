//
// Created by Frank on 2023/11/5.
//
#include <stdio.h>

int main(void) {
    const int UP = 'a' - 'A';
    int len = 0;
    scanf("%d", &len);
    char string[100005] = {""};
    scanf("%s", string);
    for (int i = 0; i < len; i++) {
        if (string[i] < 'a' && string[i] >= 'A') {
            string[i] += UP;
        } else if (string[i] >= 'a') {
            string[i] -= UP;
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        //注意字符串的空白符问题 \0
        printf("%c", string[i]);
    }
    return 0;
}