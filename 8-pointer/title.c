//
// Created by Frank on 2023/12/2.
//
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char *sentence = malloc(5000);
    gets(sentence);
    int len = strlen(sentence);
    *sentence = toupper(*sentence);
    for (int i = 1; i < len; i++) {
        if (*(sentence + i - 1) == ' ') {
            *(sentence + i) = toupper(*(sentence + i));
        } else {
            *(sentence + i) = tolower(*(sentence + i));
        }
    }
    printf("%s", sentence);
    free(sentence);
    return 0;
}