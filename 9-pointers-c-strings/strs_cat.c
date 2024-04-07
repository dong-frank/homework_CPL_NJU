//
// Created by Frank on 2023/12/2.
//
#include <stdio.h>
#include <string.h>
#include <stdio.h>

void mystrcat(char *s1, char *s2);

int main(void) {
    int T = 0;
    scanf("%d", &T);
    while (T--) {
        char string1[10005] = {0};
        char string2[10005] = {0};
        memset(string1, '\0', 10005);
        memset(string2, '\0', 10005);
        scanf("%s", string1);
        scanf("%s", string2);
        mystrcat(string1, string2);
    }
    return 0;
}

void mystrcat(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int count = len1 > len2 ? len2 : len1;
    while (1) {
        int flag = 1;
        for (int i = 0; i < count; i++) {
            if (s2[i] != s1[len1 - count + i]) {
                count--;
                flag = 0;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    for (int i = 0; i < len2 - count; i++) {
        s1[len1 + i] = s2[count + i];
    }
    printf("%s\n", s1);
}