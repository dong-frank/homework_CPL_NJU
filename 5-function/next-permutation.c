//
// Created by Frank on 2023/10/31.
//
#include <stdio.h>

int Sup_i(const int array[], int length);

int Min(const int array[], int length, int sup_i, int pk);


int main(void) {
    int n = 0;
    int array[2005] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int sup_i = Sup_i(array, n);
    //找到最长递减序列之前的数
    int pk = sup_i - 1;
    //在最长递减序列中找到比pk大的数的下标
    int p = Min(array, n, sup_i, array[pk]);
    //交换
    int temp = array[pk];
    array[pk] = array[p];
    array[p] = temp;
    //将交换后的最长递减序列翻转
    for (int i = sup_i; i < (sup_i + n) / 2; i++) {
        temp = array[i];
        array[i] = array[n - 1 - (i - sup_i)];
        array[n - 1 - (i - sup_i)] = temp;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

//找出最长递减后缀开始的下标
int Sup_i(const int array[], int length) {
    int j = length;
    for (int i = length - 1; i > 0; i--) {
        if (array[i] < array[i - 1]) {
            j = i;
        } else {
            break;
        }
    }
    return j - 1;
}

int Min(const int array[], int length, int sup_i, int pk) {
    int j = length - 1;
    for (int i = length - 1; i >= sup_i; i--) {
        if (array[i] > pk) {
            j = i;
            break;
        }
    }
    return j;
}
