//
// Created by Frank on 2023/11/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    char *S = malloc(100005);
    char *T = malloc(100005);
    scanf("%s", S);
    scanf("%s", T);
    int len = strlen(S);
    int sub_len = strlen(T);
    int i = 0;

    while (i < len) {
        int is_sub = 0;
        for (int j = 0; j < sub_len; j++) {
            if (*(S + i + j) != *(T + j)) {
                is_sub = 0;
                break;
            } else {
                is_sub = 1;
            }
        }
        if (is_sub) {
            printf("%d ", i);
        }
        i++;
    }

    free(S);
    free(T);
    return 0;
}

