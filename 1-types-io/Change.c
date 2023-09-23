//
// Created by Frank on 2023/9/23.
//
#include <stdio.h>

int main(void){
    const int MONEY_1 = 1;
    const int MONEY_2 = 5;
    const int MONEY_3 = 10;
    const int MONEY_4 = 20;
    const int MONEY_5 = 50;
    int n;
    int amount_1;
    int amount_2;
    int amount_3;
    int amount_4;
    int amount_5;

    scanf("%d",&n);

    amount_5 = n / MONEY_5 ;
    n =n- amount_5 * MONEY_5;
    amount_4 = n / MONEY_4;
    n =n- amount_4 * MONEY_4;
    amount_3 = n / MONEY_3;
    n =n- amount_3 * MONEY_3;
    amount_2 = n / MONEY_2;
    n =n- amount_2 * MONEY_2;
    amount_1 = n / MONEY_1;

    printf("%d\n%d\n%d\n%d\n%d\n",amount_5,amount_4,amount_3,amount_2,amount_1);

    return 0;
}