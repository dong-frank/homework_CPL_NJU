//
// Created by Frank on 2023/12/23.
//
#include <stdio.h>
#include <string.h>

typedef struct polynlist {
    int order;
    char name_of_x[15];
    int coefficient[10005];
} Polynlist;

void sum(const Polynlist *p1, const Polynlist *p2, Polynlist *result);

void sup(const Polynlist *p1, const Polynlist *p2, Polynlist *result);

void multipy(const Polynlist *p1, const Polynlist *p2, Polynlist *result);


void Print(const Polynlist *result);

int main(void) {
    Polynlist p1;
    Polynlist p2;
    memset(&p1, 0, sizeof p1);
    memset(&p2, 0, sizeof p2);
    scanf("%d%d", &p1.order, &p2.order);
    scanf("%s", p1.name_of_x);
    strcpy(p2.name_of_x, p1.name_of_x);
    for (int i = 0; i <= p1.order; i++) {
        scanf("%d", &p1.coefficient[i]);
    }
    for (int i = 0; i <= p2.order; i++) {
        scanf("%d", &p2.coefficient[i]);
    }
    Polynlist result;
    memset(&result, 0, sizeof(result));
    sum(&p1, &p2, &result);
    Print(&result);

    memset(&result, 0, sizeof(result));
    sup(&p1, &p2, &result);
    Print(&result);
    memset(&result, 0, sizeof(result));

    multipy(&p1, &p2, &result);
    Print(&result);
    memset(&result, 0, sizeof(result));
    return 0;
}


void sum(const Polynlist *p1, const Polynlist *p2, Polynlist *result) {

    strcpy(result->name_of_x, p1->name_of_x);
    if (p1->order > p2->order) {
        result->order = p1->order;
        int k = 0;
        while (k <= result->order) {
            if (k < p1->order - p2->order) {
                result->coefficient[k] = p1->coefficient[k];
            } else {
                result->coefficient[k] = p1->coefficient[k] + p2->coefficient[k - (p1->order - p2->order)];
            }
            k++;
        }
    } else if (p1->order < p2->order) {
        result->order = p2->order;
        int k = 0;
        while (k <= result->order) {
            if (k < p2->order - p1->order) {
                result->coefficient[k] = p2->coefficient[k];
            } else {
                result->coefficient[k] = p2->coefficient[k] + p1->coefficient[k - (p2->order - p1->order)];
            }
            k++;
        }
    } else {
        result->order = p1->order;
        int k = 0;
        while (k <= result->order) {
            result->coefficient[k] = p1->coefficient[k] + p2->coefficient[k];
            k++;
        }
    }

}

void sup(const Polynlist *p1, const Polynlist *p2, Polynlist *result) {

    strcpy(result->name_of_x, p1->name_of_x);
    if (p1->order > p2->order) {
        result->order = p1->order;
        int k = 0;
        while (k <= result->order) {
            if (k < p1->order - p2->order) {
                result->coefficient[k] = p1->coefficient[k];
            } else {
                result->coefficient[k] = p1->coefficient[k] - p2->coefficient[k - (p1->order - p2->order)];
            }
            k++;
        }
    } else if (p1->order < p2->order) {
        result->order = p2->order;
        int k = 0;
        while (k <= result->order) {
            if (k < p2->order - p1->order) {
                result->coefficient[k] = -p2->coefficient[k];
            } else {
                result->coefficient[k] = -p2->coefficient[k] + p1->coefficient[k - (p2->order - p1->order)];
            }
            k++;
        }
    } else {
        result->order = p1->order;
        int k = 0;
        while (k <= result->order) {
            result->coefficient[k] = p1->coefficient[k] - p2->coefficient[k];
            k++;
        }
    }

}

void multipy(const Polynlist *p1, const Polynlist *p2, Polynlist *result) {

    strcpy(result->name_of_x, p1->name_of_x);
    result->order = p1->order + p2->order;
    if (p1->order > p2->order) {
        int k = 0;
        while (k <= result->order) {
            for (int i = 0, j = k; j >= 0; i++, j--) {
                result->coefficient[k] += p1->coefficient[i] * p2->coefficient[j];
            }
            k++;
        }
    } else {
        int k = 0;
        while (k <= result->order) {
            for (int i = 0, j = k; j >= 0; i++, j--) {
                result->coefficient[k] += p1->coefficient[j] * p2->coefficient[i];
            }
            k++;
        }
    }
}

void Print(const Polynlist *result) {
    int k = 0;
    if (result->coefficient[k] == 1) {
        printf("%s", result->name_of_x);
    } else if (result->coefficient[k] == -1) {
        printf("-%s", result->name_of_x);
    }
    printf("%d%s", result->coefficient[k], result->name_of_x);
    if (result->order > 1) {
        printf("^%d", result->order - k);
    }
    k++;

    while (k <= result->order) {
        if (result->coefficient[k] > 0) {
            printf("+");
        } else if (result->coefficient[k] == 0) {
            k++;
            continue;
        }
        if (result->coefficient[k] != 1 && result->coefficient[k] != -1 && k < result->order) {
            printf("%d", result->coefficient[k]);
        } else if (result->coefficient[k] == -1 && k < result->order) {
            printf("-");
        }
        if ((result->order - k) > 1) {
            printf("%s^%d", result->name_of_x, result->order - k);
        } else if ((result->order - k) == 1) {
            printf("%s", result->name_of_x);
        } else {
            printf("%d", result->coefficient[k]);
        }
        k++;
    }
    printf("\n");
}
