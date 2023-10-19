//
// Created by Frank on 2023/10/14.
//
#include<stdio.h>


int main(void) {
    int n;
    int k;
    scanf("%d %d", &n, &k);
    //n 表示总人数
    //k表示第k个报数的人死亡
    int next[1000] = {0};
    int live_people = n;
    int is_death[1000] = {0};
    int i;
    int temp = 0;
    while (live_people > 1) {//i表示报数，j表示编号
        i = temp + 1;
        //模拟报数过程
        for (int j = 1;; j++, i++) {
            while (is_death[j] == 1) {
                j++;
            }
            if (j > n) {
                temp = i - 1;
                break;
            }
            next[j] = i;

            if (next[j] % k == 0) {
                live_people--;
                is_death[j] = 1;
                i = 0;
            }
            if (j == n) {
                temp = i;
                break;
            }
        }
    }
    for (int m = 1; m <= n; m++) {
        if (is_death[m] == 0) {
            printf("%d\n", m);
        }
    }
    return 0;
}