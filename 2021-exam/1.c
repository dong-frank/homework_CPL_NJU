//
// Created by Frank on 2023/12/27.
//
#include <stdio.h>
#include <stdbool.h>

bool Up(const int *nums, int len);

int main(void) {
    int T = 0;
    scanf("%d", &T);
    while (T--) {
        int len = 0;
        int count = 0;
        scanf("%d%d", &len, &count);
        int nums[1005] = {0};
        for (int i = 1; i <= len; i++) {
            scanf("%d", &nums[i]);
        }
        int operation[1005] = {0};
        for (int i = 0; i < count; i++) {
            scanf("%d", &operation[i]);
        }

        bool flag = false;
        for (int i = 0; i < count; i++) {
            //取出下标为operation[i]的元素
            //数列往后移动一位
            int temp = nums[operation[i]];
            for (int j = operation[i] - 1; j >= 1; j--) {
                nums[j + 1] = nums[j];
            }
            nums[1] = temp;
        }
        flag = Up(nums, len);
        //print
        if (!flag) {
            printf("mayi is a good teacher\n");
        } else {
            printf("I love C programming language\n");
        }
    }
    return 0;
}

bool Up(const int *nums, int len) {
    for (int i = 1; i < len; i++) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }
    return true;
}
