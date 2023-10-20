//
// Created by Frank on 2023/10/20.
//
#include <stdio.h>

int main(void) {
    int length = 0;
    int pivot = 0;
    scanf("%d %d", &length, &pivot);
    //初始化数组
    int numbers[10000] = {0};
    for (int i = 0; i < length; i++) {
        scanf("%d", &numbers[i]);
    }
    //排序过程
    int temp = 0;
    int A = numbers[pivot];
    int is_finish = 1;
    while (is_finish) {
        is_finish = 0;
        int is_l = 0;
        int is_r = 0;
        int l = 0;
        int r = length - 1;
        while (l != r) {
            if (numbers[l] >= numbers[pivot]) {
                temp = numbers[l];
                numbers[l] = numbers[r];
                numbers[r] = temp;
                is_l = 1;
            } else if (numbers[r] < numbers[pivot]) {
                temp = numbers[l];
                numbers[l] = numbers[r];
                numbers[r] = temp;
                is_r = 1;
            }
            l++;
            r--;
        }
        if (is_l == 0) {
            temp = numbers[r];
            numbers[r] = numbers[pivot];
            numbers[pivot] = temp;
        }
        if (is_r == 0) {
            temp = numbers[l];
            numbers[l] = numbers[pivot];
            numbers[pivot] = temp;
        }
        //找出当次循环结束后的pivot
        for (int i = 0; i < length; i++) {
            if (numbers[i] == A) {
                pivot = i;
                break;
            }
        }
        for (int i = 0; i < length; i++) {
            if (i < pivot) {
                is_finish = numbers[i] > numbers[pivot];
            } else {
                is_finish = numbers[i] < numbers[pivot];
            }
        }
    }
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}