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
    int j = 1;
    while (live_people > 1) {//i表示报数，j表示编号

        for (int i = 1;; i++) {
            while (is_death[j % n] == 1) {
                j++;
            }
            next[j % n] = i;

            if (next[j % n] % k == 0) {
                live_people--;
                is_death[j % n] = 1;
                break;
            }
            j++;
        }
    }
    for (int m = 1; m <= n; m++) {
        if (is_death[m] == 0) {
            printf("%d\n", m);
        }
    }
    return 0;
}