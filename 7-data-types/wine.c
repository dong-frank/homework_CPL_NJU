//
// Created by Frank on 2023/11/19.
//
#include <stdio.h>

/**
 * 数列由大到小排序
 * @param array
 * @param n
 */
void Sort(int array1[], int array2[], int n);

int main(void) {
    int n = 0;
    int l = 0;
    scanf("%d %d", &n, &l);
    int value[10005] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }
    int max[10005] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &max[i]);
    }
    Sort(value, max, n);
    int j = 0;
    for (int i = 0; i < n && l > 0; i++) {
        if (max[i] < l) {
            l -= max[i];
        } else {
            max[i] = l;
            l = 0;
            j = i;
        }
    }
    int money = 0;
    for (int i = 0; i <= j; i++) {
        money += value[i] * max[i];
    }
    printf("%d", money);
    return 0;
}

void Sort(int array1[], int array2[], int n) {
    int i = 0;
    while (i < n) {
        int max = 0;
        for (int j = i; j < n; j++) {
            if (max < array1[j]) {
                max = array1[j];
            }
        }
        for (int j = i; j < n; j++) {
            if (max == array1[j]) {
                int temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
                temp = array2[i];
                array2[i] = array2[j];
                array2[j] = temp;
                break;
            }
        }
        i++;
    }
}