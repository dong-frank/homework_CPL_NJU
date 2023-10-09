//
// Created by Frank on 2023/9/23.
//
#include <stdio.h>
#include <math.h>

int main (void){
    int p;
    int q;
    double first_number;
    double second_number;
    double x_1;

    scanf("%d%d",&p,&q);

    first_number= cbrt(- (q/2.0) + sqrt((q/2.0) * (q/2.0) + (p/3.0) * (p/3.0) * (p/3.0)));
    second_number= cbrt(- (q/2.0) - sqrt((q/2.0) * (q/2.0) + (p/3.0) * (p/3.0) * (p/3.0)));
    /*
     * (p/3)^3>-(q/2)^2
     */
    x_1= first_number + second_number;

    printf("%.3f",x_1);

    return 0;
}