//
// Created by Frank on 2023/12/8.
//
#include <stdio.h>

int a[100005];
int ans[100005][2];

void solve(int l, int r);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    solve(1, n);
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}

void solve(int l, int r) {
    if (l > r) {
        return;
    }
    int p = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] > a[p]) {
            p = i;
        }
    }
    ans[p][0] = l;
    ans[p][1] = r;
    solve(l, p - 1);
    solve(p + 1, r);
}