//
// Created by Frank on 2023/10/30.
//
#include <stdio.h>

int Decimal(int num, int x);

int Unit(int num);

int Ten(int num);

int Max(int a, int b);

int main(void) {
    int p = 0;
    int q = 0;
    int r = 0;
    scanf("%d %d %d", &p, &q, &r);
    for (int x = 2; x <= 40; x++) {
        while (Max(Unit(p), Ten(p)) >= x
               || Max(Unit(q), Ten(q)) >= x
               || Max(Unit(r), Ten(r)) >= x) {
            x++;
        }
        if (Decimal(p, x) * Decimal(q, x) == Decimal(r, x)) {
            printf("%d\n", x);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}

//将x进制数转为十进制
int Decimal(int num, int x) {
    int pow = 1;
    int digit = 0;
    while (num > 0) {
        digit += (num % 10) * pow;
        pow *= x;
        num /= 10;
    }
    return digit;
}

//将第一位分解出来
int Unit(int num) {
    if (num) { return num % 10; }
    else return 0;
}

//将第二位分解出来
int Ten(int num) {
    if (num >= 10) {
        num /= 10;
        return num % 10;
    } else {
        return 0;
    }
}

int Max(int a, int b) {
    if (a >= b) { return a; }
    else { return b; }
}