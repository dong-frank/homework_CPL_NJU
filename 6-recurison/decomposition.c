//
// Created by Frank on 2023/11/22.
//
#include <stdio.h>

int ans[10005];

void findDecomposition(int n, int min, int nFound);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    findDecomposition(n, 1, 0);
    return 0;
}

void findDecomposition(int n, int min, int nFound) {
    if (n == 0) {
        for (int i = 0; i < nFound; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    for (int i = min; i <= n; i++) {
        ans[nFound] = i;
        findDecomposition(n - i, i, nFound + 1);
    }


}