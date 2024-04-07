//
// Created by Frank on 2023/12/19.
//
#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @param array
 * @return index of num in array
 */
int Search(int array[], int n);

int IntComp(const void *, const void *);

int main(void) {
    int n = 0;// size of array
    int q = 0;// times of asking q<=1e6
    scanf("%d%d", &n, &q);

    int array[10005] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    while (q--) {
        printf("%d\n", Search(array, n));
    }
    return 0;
}

int Search(int array[], int n) {
    int num = 0;
    scanf("%d", &num);

    if (bsearch(&num, array, n,
                sizeof(int), IntComp) == NULL) {
        return -1;
    } else {
        return (int *) bsearch(&num, array, n,
                               sizeof(int), IntComp) - array;
    }
}


int IntComp(const void *a, const void *b) {
    int int_a = *(const int *) a;
    int int_b = *(const int *) b;
    if (int_a < int_b) {
        return -1;
    } else if (int_a > int_b) {
        return 1;
    } else {
        return 0;
    }
}
