//
// Created by Frank on 2023/10/9.
//
#include <stdio.h>

int main(void) {
    int max_of_fear;
    int numbers_of_level_students[10000];
    int sum_of_standed_students=0;
    int rat = 0;

    scanf("%d", &max_of_fear);
    for (int i = 0; i <= max_of_fear; i++) {
        scanf("%d", &numbers_of_level_students[i]);
        sum_of_standed_students += numbers_of_level_students[i - 1];
    }
    for(;(rat+sum_of_standed_students)<max_of_fear;rat++){
        ;
    }

    printf("%d", rat);
    return 0;
}
