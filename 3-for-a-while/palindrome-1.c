//
// Created by Frank on 2023/10/14.
//
#include <stdio.h>

int main(void) {
    int length;
    scanf("%d", &length);
    char s[2000];
    getchar();
    for (int i = 0; i < length; i++) {
        scanf("%c", &s[i]);
    }
    for (int i = 0; i < length; i++) {
        if (s[i] == '?') {
            s[i] = s[length - 1 - i];
        }
        printf("%c", s[i]);
    }
    return 0;
}