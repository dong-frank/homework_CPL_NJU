//
// Created by Frank on 2023/11/13.
//
#include <stdio.h>

int Max(const int array[], int l, int r);

void Maxseg(const int array[], int l, int r, int i);

int ans[100005][2];

int main(void) {
    int length = 0;
    int a[100005] = {0};
    scanf("%d", &length);
    for (int i = 1; i <= length; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= length; i++) {
        Maxseg(a, 1, length, i);
    }
    for (int i = 1; i <= length; i++) {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}

int Max(const int array[], int l, int r) {
    int j = 0;
    for (int k = l; k <= r; k++) {
        if (array[j] < array[k]) {
            j = k;
        }
    }
    return j;
}

void Maxseg(const int array[], int l, int r, int i) {
    int p = Max(array, l, r);
    if (l == r || i == p) {
        ans[i][0] = l;
        ans[i][1] = r;
        return;
    }
    if (i >= l && i <= p - 1) {
        Maxseg(array, l, p - 1, i);
    } else {
        Maxseg(array, p + 1, r, i);
    }
}
