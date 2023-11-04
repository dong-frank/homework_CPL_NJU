#include<stdio.h>

#define th 2001

int main() {
    int year, leap, i, n = 0;
    scanf("%d", &year);
    if (year >= 2000 && year < 2100) {
        for (i = th; i <= year; i = i + 1) {
            if (i % 4 == 0) {
                if (i % 100 == 0) {
                    if (i % 400 == 0)
                        leap = 1, n = n + 1;

                    else
                        leap = 0;
                } else
                    leap = 1, n = n + 1;
            } else
                leap = 0;

            if (leap)
                printf("%d\n", i);

        }
        if (n == 0)
            printf("None");
    } else
        printf("Invalid year!");

    return 0;
}