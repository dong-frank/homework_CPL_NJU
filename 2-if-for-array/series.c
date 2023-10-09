//
// Created by Frank on 2023/10/9.
//
#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    double x;
    double y;
    double pow_of_x;
    scanf("%lf %d", &x, &n);

    for (int i = 0; i <= n; i++) {
        if (i % 2 == 1) {
            pow_of_x = -1.0 * pow(x, 2 * i + 1);
        } else {
            pow_of_x = pow(x, 2 * i + 1);
        }
        y += (pow_of_x / (2.0 * i + 1));
    }
    y *= 4;
    printf("%.10f", y);

    return 0;
}