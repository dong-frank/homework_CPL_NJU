//
// Created by Frank on 2023/9/23.
//
#include <stdio.h>

int main(void){
    const double G = 6.674e-11;
    const double M = 77.15;
    double m;
    double r;
    double f;

    scanf("%lf%lf",&m,&r);
    f = (G*M*m)/(r*r);

    printf("%.3e",f);

    return 0;
}