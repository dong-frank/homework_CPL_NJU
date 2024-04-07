//
// Created by Frank on 2023/11/26.
//
#include <stdio.h>
#include <string.h>

void W(int x[], int y[]);

void S(int x[], int y[]);

void A(int x[], int y[]);

void D(int x[], int y[]);

int a;
int b;
int c;

int main(void) {
    scanf("%d%d%d", &a, &b, &c);
    int x[2] = {0, a};
    int y[2] = {0, b};
    char vector;
    getchar();
    while ((vector = getchar()) != '\n') {
        switch (vector) {
            case 'W':
                W(x, y);
                break;
            case 'S':
                S(x, y);
                break;
            case 'A':
                A(x, y);
                break;
            case 'D':
                D(x, y);
                break;
        }

    }
    printf("%d %d %d %d", x[0], x[1], y[0], y[1]);

    return 0;
}

void W(int x[], int y[]) {
    if ((x[1] - x[0] == a && y[1] - y[0] == b) ||
        (x[1] - x[0] == b && y[1] - y[0] == a)) {
        x[1] = x[0];
        x[0] -= c;
    } else if ((x[1] - x[0] == a && y[1] - y[0] == c) || (x[1] - x[0] == c && y[1] - y[0] == a)) {
        x[1] = x[0];
        x[0] -= b;
    } else if ((x[1] - x[0] == b && y[1] - y[0] == c) || (x[1] - x[0] == c && y[1] - y[0] == b)) {
        x[1] = x[0];
        x[0] -= a;
    }
}

void S(int x[], int y[]) {
    if ((x[1] - x[0] == a && y[1] - y[0] == b) ||
        (x[1] - x[0] == b && y[1] - y[0] == a)) {
        x[0] = x[1];
        x[1] += c;
    } else if ((x[1] - x[0] == a && y[1] - y[0] == c) || (x[1] - x[0] == c && y[1] - y[0] == a)) {
        x[0] = x[1];
        x[1] += b;
    } else if ((x[1] - x[0] == b && y[1] - y[0] == c) || (x[1] - x[0] == c && y[1] - y[0] == b)) {
        x[0] = x[1];
        x[1] += a;
    }
}

void A(int x[], int y[]) {
    if ((x[1] - x[0] == a && y[1] - y[0] == b) ||
        (x[1] - x[0] == b && y[1] - y[0] == a)) {
        y[1] = y[0];
        y[0] -= c;
    } else if ((x[1] - x[0] == a && y[1] - y[0] == c) || (x[1] - x[0] == c && y[1] - y[0] == a)) {
        y[1] = y[0];
        y[0] -= b;
    } else if ((x[1] - x[0] == b && y[1] - y[0] == c) || (x[1] - x[0] == c && y[1] - y[0] == b)) {
        y[1] = y[0];
        y[0] -= a;
    }
}

void D(int x[], int y[]) {
    if ((x[1] - x[0] == a && y[1] - y[0] == b) ||
        (x[1] - x[0] == b && y[1] - y[0] == a)) {
        y[0] = y[1];
        y[1] += c;
    } else if ((x[1] - x[0] == a && y[1] - y[0] == c) || (x[1] - x[0] == c && y[1] - y[0] == a)) {
        y[0] = y[1];
        y[1] += b;
    } else if ((x[1] - x[0] == b && y[1] - y[0] == c) || (x[1] - x[0] == c && y[1] - y[0] == b)) {
        y[0] = y[1];
        y[1] += a;
    }
}