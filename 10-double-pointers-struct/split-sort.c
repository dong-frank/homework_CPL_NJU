//
// Created by Frank on 2023/12/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Comp(const void *, const void *);

int main(void) {
    char string[1005] = {0};
    scanf("%s", string);
    char delim[100] = {0};
    scanf("%s", delim);
    char *spilt_str[105] = {0};
    spilt_str[0] = strtok(string, delim);
    int i = 1;
    while ((spilt_str[i] = strtok(NULL, delim)) != NULL) {
        i++;
    }
    qsort(spilt_str, i, sizeof(*spilt_str), Comp);
    while (i--) {
        printf("%s\n", spilt_str[i]);
    }
    return 0;
}

int Comp(const void *a, const void *b) {
    const char *const *char_a = a;
    const char *const *char_b = b;
    return -strcmp(*char_a, *char_b);
}
