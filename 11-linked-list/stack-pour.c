//
// Created by Frank on 2023/12/30.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
typedef struct node {
    int *stack;
    struct node *next;
} NODE;

typedef struct link_list {
    struct node *head;
    struct node *tail;
} LINKLIST;

void Init(LINKLIST *list, int n);

void Pour(LINKLIST *list, int x, int y);

void Free(LINKLIST *list);

void Print(LINKLIST *list);

int main(void) {
    int n = 0; //nums of stacks
    int m = 0; //operations
    scanf("%d%d", &n, &m);
    LINKLIST list;
    Init(&list, n);
    while (m--) {
        int x = 0;
        int y = 0;
        scanf("%d%d", &x, &y);
        Pour(&list, x, y);
    }
    Print(&list);
    Free(&list);
    return 0;
}

void Init(LINKLIST *list, int n) {
    list->head = NULL;
    list->tail = NULL;

    for (int i = 1; i <= n; i++) {
        NODE *new_node = malloc(sizeof *new_node);

        if (new_node == NULL) {
            return;
        }
        new_node->stack = malloc(SIZE * sizeof(int));
        if (new_node->stack == NULL) {
            free(new_node->stack);
            free(new_node);
            return;
        }
        memset(new_node->stack, 0, SIZE);
        new_node->stack[0] = i;

        if (list->head == NULL) {
            list->head = new_node;
            list->tail = new_node;
            list->head->next = list->tail;
            list->tail->next = NULL;
        } else {
            list->tail->next = new_node;
            list->tail = list->tail->next;
            list->tail->next = NULL;
        }
    }
}

void Pour(LINKLIST *list, int x, int y) {
    NODE *ori_node = list->head;
    for (int i = 1; i < x; i++) {
        ori_node = ori_node->next;
    }
    NODE *dst_node = list->head;
    for (int i = 1; i < y; i++) {
        dst_node = dst_node->next;
    }

    int ori_head = 0;
    while (ori_node->stack[ori_head] != 0) {
        ori_head++;
    }
    int dst_head = 0;
    while (dst_node->stack[dst_head] != 0) {
        dst_head++;
    }
    for (int i = ori_head - 1, j = dst_head; i >= 0; i--, j++) {
        dst_node->stack[j] = ori_node->stack[i];
        ori_node->stack[i] = 0;
    }
}

void Print(LINKLIST *list) {
    NODE *node = list->head;
    while (node != NULL) {
        int i = 0;
        if (node->stack[0] == 0) {
            printf("0");
        } else {
            while (node->stack[i] != 0) {
                printf("%d ", node->stack[i]);
                i++;
            }
        }
        printf("\n");
        node = node->next;
    }
}

void Free(LINKLIST *list) {
    NODE *node = list->head;
    while (list->head != list->tail) {
        node = node->next;
        free(list->head->stack);
        free(list->head);
        list->head = node;
    }
}
