//
// Created by Frank on 2023/10/31.
//
#include <stdio.h>

void InputArray(int array[], int size);

void Sup(int arrayt[], const int arraya[], int size, int t);

int Binary_Search(const int array[], int size, int k);

int main(void) {
    int n = 0;
    int m = 0;
    int t = 0;
    scanf("%d %d %d", &n, &m, &t);
    int a[10005] = {0};
    int b[10005] = {0};
    InputArray(a, n);
    InputArray(b, m);
    int t_b[10005] = {0};
    Sup(t_b, b, m, t);
    int c = 0;
    int min = t + 1;
    for (int i = 0; i < m; i++) {
        if (t_b[i] >= 0) {
            c = t_b[i] - Binary_Search(a, n, t_b[i]);
            if (min >= c && c >= 0) {
                min = c;
            }
        }
    }
    if (min == t + 1) {
        printf("-1");
    } else {
        printf("%d", min);
    }
    return 0;
}

void InputArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void Sup(int arrayt[], const int arraya[], int size, int t) {
    for (int i = 0; i < size; i++) {
        arrayt[i] = t - arraya[i];
    }
}

int Binary_Search(const int array[], int size, int k) {
    int l = 0;
    int r = size - 1;
    int mid = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (array[mid] > k) {
            r = mid + 1;
        } else if (array[mid] < k) {
            l = mid + 1;
        } else {
            return k;
        }
    }
    if (k > array[l]) {
        return array[l];
    } else {
        return array[l - 1];
    }
}