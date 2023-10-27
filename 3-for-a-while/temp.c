//
// Created by asus on 2023/10/22.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, a, len;

    scanf("%d", &n);
    while (n--) {
        char str[150] = "";
        char sjz[150] = "";
        int i = 0;
        int is_legal = 1;
        int count = 0;
        scanf("%s", str);
        len = strlen(str);

        a = atoi(str);
        if (a == 0) {
            if (len == 1 && str[0] != '0') {
                is_legal = 0;
            }
            if (len == 1 && str[0] == '0') {
                is_legal = 1;
            }

        }

        if (a <= 0) {
            count = 1;
        }
        while (a != 0) {
            a /= 10;
            count++;
        }
        if (count != len) {
            is_legal = 0;
        }
        if (is_legal == 0) {
            printf("Radix Error\n");
        }
        if (is_legal == 1) {
            if (str[0] != '-') {
                a = atoi(str);

                do {
                    if (a % 3 == 1) {
                        sjz[i] = '1';
                        a /= 3;
                    } else if (a % 3 == 2) {
                        sjz[i] = 'Z';
                        a = a / 3 + 1;
                    } else {
                        sjz[i] = '0';
                        a /= 3;

                    }
                    i++;
                } while (a != 0);
                for (i = i - 1; i >= 0; i--) {
                    printf("%c", sjz[i]);
                }
                printf("\n");
            } else {
                a = atoi(str);
                a = -a;
                while (a != 0) {

                    if (a % 3 == 1) {
                        sjz[i] = 'Z';
                        a /= 3;
                    } else if (a % 3 == 2) {
                        sjz[i] = '1';
                        a = a / 3 + 1;
                    } else {
                        sjz[i] = '0';
                        a /= 3;
                    }
                    i++;
                }
                printf("-");
                for (i = i - 1; i >= 0; i--) {
                    printf("%c", sjz[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}