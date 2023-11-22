//
// Created by Frank on 2023/11/14.
//
#include <stdio.h>
#include <math.h>

double Integration(double l, double r, const int table[], int p, int n, double E);

double Function_x(double x, const int table[], int p, int n);

int main(void) {
    int n = 0;
    int p = 0;
    scanf("%d %d", &n, &p);
    int num[25] = {0};
    for (int i = 0; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    double a = 0;
    double b = 0;//实数a，b
    scanf("%lf %lf", &a, &b);
    double E = 1e-5;
    double ans = Integration(a, b, num, p, n, E);
    printf("%f", ans);
    return 0;
}

double Function_x(double x, const int table[], int p, int n) {
    double y = 0;
    for (int i = n; i >= 0; i--) {
        y += table[i] * pow(x, i);
    }
    return pow(y, p);
}

double Integration(double l, double r, const int table[], int p, int n, double E) {
    if (l == r) {
        return 0;
    }
    double mid = (l + r) / 2.0;
    double SL = ((4 * Function_x((l + mid) / 2, table, p, n) + Function_x(l, table, p, n) +
                  Function_x(mid, table, p, n)) / 6) * (mid - l);
    double SR = ((4 * Function_x((r + mid) / 2, table, p, n) + Function_x(r, table, p, n) +
                  Function_x(mid, table, p, n)) / 6) * (r - mid);
    double S = ((4 * Function_x((l + r) / 2.0, table, p, n) + Function_x(l, table, p, n) +
                 Function_x(r, table, p, n)) / 6) * (r - l);
    if (fabs(SL + SR - S) <= 15 * E) {
        return (SL + SR + ((SL + SR - S) / 15));
    }
    return Integration(l, (l + r) / 2, table, p, n, E / 2) +
           Integration((l + r) / 2, r, table, p, n, E / 2);//两次调用会缩小为四倍
}
