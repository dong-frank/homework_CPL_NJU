//
// Created by Frank on 2023/9/23.
//
#include <stdio.h>

int main(void){
    char month[10];
    char weekday[10];
    int date;
    int year;
    int hour;
    int minute;
    int second;

    scanf("%s%d%d%s%d%d%d",month,&date,&year,weekday,&hour,&minute,&second);

    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d",weekday,month,date,hour,minute,second,year);

    return 0;

}