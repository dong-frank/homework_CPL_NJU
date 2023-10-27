//
// Created by Frank on 2023/10/22.
//
#include <stdio.h>

int main(void) {
    //输入地图大小
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    //输入初始位置
    int x_0 = 0;
    int y_0 = 0;
    scanf("%d %d", &x_0, &y_0);
    getchar();
    //输入轨迹
    char map[51][51] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            map[i][j] = getchar();
        }
        getchar();
    }
    int trace[51][51] = {0};
    int length = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == '#') {
                trace[i][j] = 1;
                length++;
            }
        }
    }
    printf("%d\n", length);
    //开始复原轨迹
    int is_walked[51][51] = {0};
    is_walked[x_0][y_0] = 1;
    for (int i = 0; i < length; i++) {
        printf("%d %d\n", x_0, y_0);
        if (trace[x_0 + 1][y_0] == 1 && is_walked[x_0 + 1][y_0] == 0) {
            is_walked[x_0 + 1][y_0] = 1;
            x_0 += 1;
        } else if (trace[x_0][y_0 + 1] == 1 && is_walked[x_0][y_0 + 1] == 0) {
            is_walked[x_0][y_0 + 1] = 1;
            y_0 += 1;
        } else if (trace[x_0 - 1][y_0] == 1 && is_walked[x_0 - 1][y_0] == 0) {
            is_walked[x_0 - 1][y_0] = 1;
            x_0 -= 1;
        } else if (trace[x_0][y_0 - 1] == 1 && is_walked[x_0][y_0 - 1] == 0) {
            is_walked[x_0][y_0 - 1] = 1;
            y_0 -= 1;
        }
    }
    return 0;
}