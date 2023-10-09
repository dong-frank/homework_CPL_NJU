//
// Created by Frank on 2023/10/8.
//
#include <stdio.h>

int main(void){
    int n=3;
    int factorial=1;
    for(int i =1;i<(n+1);i++){
        factorial*=i;
    }
    printf("%d",factorial);
    return 0;

}