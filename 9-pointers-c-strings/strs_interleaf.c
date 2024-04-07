//
// Created by Frank on 2023/12/5.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int T = 0;
    scanf("%d", &T);
    while (T--) {
        char string[2005] = {0};
        scanf("%s", string);
        char *s1 = strtok(string, ";");
        char *s2 = strtok(NULL, ";");
        int d1 = atoi(strtok(NULL, ";"));
        int d2 = atoi(strtok(NULL, ";"));
        int size = atoi(strtok(NULL, ";"));
        char *s3 = malloc(size);
        memset(s3, '\0', size);
        int count = 0;
        while (count < size) {
            for (int i = 1; i <= d1 && (*s1 != '\0') && (count < size); i++) { //注意条件的完备性
                s3[count] = *s1;
                count++;
                s1++;
            }
            if (count >= size) {
                break;
            }
            for (int i = 1; i <= d2 && (*s2 != '\0') && (count < size); i++) {
                s3[count] = *s2;
                count++;
                s2++;
            }
            if ((*s1 == '\0') && (*s2 == '\0')) {
                break;
            }
        }
        s3[size - 1] = '\0';
        printf("%s\n", s3);
        free(s3);

    }
    return 0;
}
