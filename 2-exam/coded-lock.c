//
// Created by Frank on 2023/12/9.
//
#include <stdio.h>
#include <stdbool.h>

int min(int k1, int k2);

bool repeat(int n, int d, int i, int j);

int main() {
    int w = 0;//总共位数
    int n = 0;//数字轮盘的最大数
    int d = 0;//一次拨动几位
    scanf("%d%d%d", &w, &n, &d);
    int secret[1003] = {0};
    for (int i = 0; i < w; i++) {
        scanf("%d", &secret[i]);
    }
    bool flag = true;
    int count = 0;

    for (int i = 0; i < w / 2; i++) {
        //第i位和第w-i-1位要对称
        //找不能对称打乱的条件
        if (repeat(n, d, secret[i], secret[w - i - 1])) {
            flag = false;
            goto end;
        }
        //先算出向前拨的k1
        int k1 = 0;
        while (1) {
            k1++;
            secret[i] = secret[i] + d;
            int secret_fin = 0;
            if (secret[i] % n == 0) {
                secret_fin = n;
            } else {
                secret_fin = secret[i] % n;
            }
            if (secret_fin == secret[w - i - 1]) {
                break;
            }
        }
        //根据规律算出k2
        int k2 = 0;
        while (1) {
            k2++;
            if ((k1 * d + k2 * d) % n == 0) {
                break;
            }
        }
        count += min(k1, k2);
    }

    end:
    if (flag) {
        printf("%d\n", count);
    } else {
        printf("Impossible\n");
    }
    return 0;
}

int min(int k1, int k2) {
    if (k1 <= k2) {
        return k1;
    } else {
        return k2;
    }
}

bool repeat(int n, int d, int i, int j) {
    int num[100005] = {0};
    while (1) {
        i += d;
        if (i % n == 0) {
            i = n;
        } else {
            i %= n;
        }
        if (num[i] == 1) {
            break;
        } else {
            num[i] = 1;
        }
    }
    if (num[j] == 0) {
        return true;
    } else {
        return false;
    }
}