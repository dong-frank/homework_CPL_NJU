//
// Created by Frank on 2023/9/23.
//
#include <stdio.h>
#include <math.h>

int main(void){
    double pi_1;
    double pi_2;
    double numerator;
    double denominator;
    double fraction_1,fraction_2;

    numerator= log((640320.0*640320*640320) + 744);
    denominator= sqrt(163);
    pi_1 = numerator/denominator;

    fraction_1 = 1/5.0;
    fraction_2 = 1/239.0;
    pi_2 = 16 * atan(fraction_1) - 4 * atan(fraction_2);
    printf("%.15f\n%.15f",pi_1,pi_2);
    return 0;
}
