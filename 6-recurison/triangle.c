//
// Created by Frank on 2023/11/15.
//
#include <stdio.h>
#include <math.h>
#include <string.h>

void paint(int n, int x, int y);

char map[1000][1000];

int main(void) {
    int n = 0;
    scanf("%d", &n);
    //画布尺寸 pow(2,n)*pow(2,n+1)
    memset(map, ' ', sizeof map);

    paint(n, 1, pow(2, n));

    for (int i = 1; i <= pow(2, n); i++) {
        for (int j = 1; j <= pow(2, n + 1); j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void paint(int n, int x, int y) {
    if (n == 1) {
        map[x][y] = '/';
        map[x][y + 1] = '\\';
        map[x + 1][y - 1] = '/';
        map[x + 1][y] = '_';
        map[x + 1][y + 1] = '_';
        map[x + 1][y + 2] = '\\';
        return;
    }
    paint(n - 1, x, y);
    paint(n - 1, x + pow(2, n - 1), y - pow(2, n - 1));
    paint(n - 1, x + pow(2, n - 1), y + pow(2, n - 1));
}