//
// Created by Frank on 2023/10/9.
//
#include <stdio.h>

int main(void) {
    int n;
    int k;
    char words[10000];

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        words[i] = getchar();
    }
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        printf("%c", words[k - 1 - i]);
    }
    for (int i = k; i < n; i++) {
        printf("%c", words[n - 1 - (i - k)]);
    }
    return 0;
}
