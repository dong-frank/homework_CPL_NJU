//
// Created by Frank on 2023/10/8.
//
#include <stdio.h>

#define NUM 10000

int main(void) {
    int num;
    int number_array[NUM];
    int repeat_array[NUM] = {0};
    scanf("%d", &num);

    for (int i = 0; i < (2 * num - 1); i++) {
        scanf("%d", &number_array[i]);
        repeat_array[number_array[i]] += 1;

    }
    for (int i = 0; i < NUM; i++) {
        if (repeat_array[i] == 1) {
            printf("%d", i);
        }
    }

    return 0;
}