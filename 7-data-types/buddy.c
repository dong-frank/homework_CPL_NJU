//
// Created by Frank on 2023/11/28.
//
#include <stdio.h>
#include <math.h>

int Is_occupied[10005] = {0};

void Allocation(int space[], int *k, int m, int id);

int Cal(int m);

int main(void) {
    int n = 0;
    int q = 0;
    scanf("%d%d", &n, &q);
    int space[10005] = {0}; //下标表示节点号，数据表示空间大小(未分配），应用编号（已分配）
    int k = 1; // k表示节点数
    space[k] = pow(2, n);
    while (q--) {
        getchar();
        char operation;
        scanf("%c", &operation);
        int id = 0;
        int m = 0;
        if (operation == 'A') { //请求空间
            scanf("%d%d", &id, &m);
            Allocation(space, &k, m, id);
        } else if (operation == 'Q') { //查询分配情况
            printf("%d\n", k);
            for (int i = 1; i <= k; i++) {
                printf("%d ", Is_occupied[i]);
            }
            printf("\n");
        }
    }
    return 0;

}

void Allocation(int space[], int *k, int m, int id) {
    int cal = Cal(m);
    while (1) {
        for (int i = 1; i <= *k; i++) { //若有未分配的大小相等的节点，分配最靠前的
            if (space[i] == cal && Is_occupied[i] == 0) {
                Is_occupied[i] = id;
                return;
            }
        }
        for (int i = 1; i <= *k; i++) {
            if (space[i] > m && Is_occupied[i] == 0) {
                //分裂节点i且i后的数组后移一位
                space[i] /= 2;
                for (int j = *k + 1; j >= i + 1; j--) {
                    space[j] = space[j - 1];
                    Is_occupied[j] = Is_occupied[j - 1];
                }
                break;
            }
        }
        (*k)++;

    }
}

int Cal(int m) {
    for (int i = 0;; i++) {
        if (pow(2, i) >= m) {
            return pow(2, i);
        }
    }
}