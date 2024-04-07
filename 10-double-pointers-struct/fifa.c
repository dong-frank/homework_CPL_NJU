//
// Created by Frank on 2023/12/21.
//
#include <stdio.h>
#include <stdlib.h>

#define MEMBERS 11

int Sum(const int nums[]);

int Max(const int nums[], int n, int index);

void PubbleSort(int nums[], int n);

int main(void) {
    int n = 0;//numbers of teams
    scanf("%d", &n);
    int sum_of_attack[1005] = {0};
    int sum_of_defence[1005] = {0};
    int sum_of_organization[1005] = {0};

    char (*name_of_team)[1005] = malloc(1005 * 20 * sizeof(**name_of_team));
    //input each team
    for (int i = 0; i < n; i++) {
        int attack[MEMBERS] = {0};
        int defence[MEMBERS] = {0};
        int organization[MEMBERS] = {0};
        char individual_name[100] = {0};
        scanf("%s", name_of_team[i]);
        for (int j = 0; j < MEMBERS; j++) {
            scanf("%s%d%d%d", individual_name, &attack[j], &defence[j], &organization[j]);
        }
        sum_of_attack[i] = Sum(attack);
        sum_of_defence[i] = Sum(defence);
        sum_of_organization[i] = Sum(organization);
    }
    //sort
    PubbleSort(sum_of_attack, n);
    PubbleSort(sum_of_defence, n);
    PubbleSort(sum_of_organization, n);

    //print

    for (int i = 0; i < n; i++) {
        printf("%s ", name_of_team[sum_of_attack[i]]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%s ", name_of_team[sum_of_defence[i]]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%s ", name_of_team[sum_of_organization[i]]);
    }
    printf("\n");

    free(name_of_team);

    return 0;
}

int Sum(const int nums[]) {
    int sum = 0;
    for (int i = 0; i < MEMBERS; i++) {
        sum += nums[i];
    }
    return sum;
}

int Max(const int nums[], int n, int index) {
    int max = nums[index];
    int j = index;
    for (int i = index; i < n; i++) {
        if (max < nums[i]) {
            max = nums[i];
            j = i;
        }
    }
    return j;
}

void PubbleSort(int nums[], int n) {
    int temp = 0;
    int max_index = 0;
    int nums_copy[1005] = {0};
    for (int i = 0; i < n; i++) {
        nums_copy[i] = nums[i];
    }
    for (int i = 0; i < n; i++) {
        temp = nums[i];
        max_index = Max(nums, n, i);
        nums[i] = nums[max_index];
        nums[max_index] = temp;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[i] == nums_copy[j]) {
                nums[i] = j;
                break;
            }
        }
    }
}
