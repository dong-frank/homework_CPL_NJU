//
// Created by Frank on 2023/12/20.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Create_rand();

int main() {
    int x = Create_rand();
    printf("%d", x);
    return 0;
}

int Create_rand() {
    srand(time(NULL));
    int random_int = rand();
    return random_int % 3 - 1;
}

