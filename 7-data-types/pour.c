//
// Created by Frank on 2023/11/26.
//
#include <stdio.h>
#include <stdbool.h>

int a0;
int b0;
int c0;
int Va, Vb, Vc;
bool flag;

void Pour(int k, int a, int b, int c);

int main(void) {
    int k, a, b, c;

    scanf("%d %d %d %d %d %d %d %d %d %d", &k, &Va, &Vb, &Vc, &a, &b, &c, &a0, &b0, &c0);
    Pour(k, a, b, c);
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

void Pour(int k, int a, int b, int c) {
    if (a == a0 && b == b0 && c == c0 && k >= 0) {
        flag = true;
        return;
    }
    if (k < 0) {
        return;
    }
    k = k - 1;
    if (a + b <= Va) Pour(k, a + b, 0, c);
    else Pour(k, Va, 0, c);

    if (b + c <= Vc)Pour(k, a, 0, b + c);
    else Pour(k, a, 0, Vc);

    if (a + b <= Vb)Pour(k, 0, a + b, c);
    else Pour(k, 0, Vb, c);

    if (a + c <= Vc)Pour(k, 0, b, a + c);
    else Pour(k, 0, b, Vc);

    if (b + c <= Vb)Pour(k, a, b + c, 0);
    else Pour(k, a, Vb, 0);

    if (a + c <= Va)Pour(k, a + c, b, 0);
    else Pour(k, Va, b, 0);
}
