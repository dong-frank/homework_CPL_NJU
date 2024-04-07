//
// Created by Frank on 2023/12/27.
//
#include <stdio.h>

#define SIZE 1005

int Bsearch(const int nums[], int x, int len);

int main(void) {
    int len = 0;
    int count = 0;
    scanf("%d%d", &len, &count);
    int nums[SIZE] = {0};
    for (int i = 0; i < len; i++) {
        scanf("%d", &nums[i]);
    }

    while (count--) {
        int x = 0;
        scanf("%d", &x);
        printf("%d\n", Bsearch(nums, x, len));
    }
    return 0;
}

int Bsearch(const int nums[], int x, int len) {
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > x) {
            right = mid - 1;
        } else if (nums[mid] < x) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}