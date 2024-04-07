//
// Created by Frank on 2024/1/1.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char word;
    struct node *next;
} Node;

typedef struct linklist {
    Node *head;
    Node *tail;
} Linklist;

void Init(Linklist *words);

void Append(Linklist *words, const char *operation);

void Search_print(const Linklist *words, int k);

void Delete(Linklist *words, Node *node);

void Free(Linklist *words);

int main(void) {
    Linklist words;
    Init(&words);
    int Q = 0;
    scanf("%d", &Q);
    while (Q--) {
        char operation[1000] = {0};
        scanf("%s", operation);
        if (operation[0] == '?') {
            int k = 0;
            scanf("%d", &k);
            Search_print(&words, k);
        } else {
            Append(&words, operation);
        }
    }
    return 0;
}

void Init(Linklist *words) {
    words->tail = NULL;
    words->head = NULL;
}

void Append(Linklist *words, const char *operation) {
    Node *new_node = malloc(sizeof *new_node);
    int len = strlen(operation);
    for (int i = 0; i < len; i++) {
        if (operation[i] != 'M' && operation[i] != 'm') {
            new_node->word = operation[i];
            if (words->head == NULL) {
                words->head = new_node;
                words->tail = new_node;
                words->tail->next = NULL;
            }
            new_node->next = words->head;
            words->head = new_node;
        } else if (operation[i] == 'M') {
            Node *node = words->head;
            if (node == NULL) {
                continue;
            }
            while (!(node->word >= 'A' && node->word <= 'Z')) {
                node = node->next;
            }
            Delete(words, node);
        } else if (operation[i] == 'm') {
            Node *node = words->head;
            if (node == NULL) {
                continue;
            }
            while (!(node->word >= 'a' && node->word <= 'z')) {
                node = node->next;
            }
            Delete(words, node);
        }
    }

}

void Search_print(const struct linklist *words, int k) {
    Node *node = words->head;
    while (k--) {
        printf("%c", node->word);
        node = node->next;
    }
}

void Delete(Linklist *words, Node *node) {
    if (node->next == NULL) {
        return;
    }
    Node *cur = node->next;
    if (cur == words->tail) {
        words->tail = node;
        free(cur);
    } else {
        Node *nxt = cur->next;
        node->next = nxt;
        free(cur);
    }
}
