#include <stdio.h>

#define AUGMENT(x) ((x) + 1)
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MAX_AND_AUGMENT(x, y) (AUGMENT(MAX(x, y)))
#define SING_IF_YOU_LIKE(condition) if (condition) { \
    printf("mymymymyqtddt\n");                         \
}

/* below are the simplest applications */
int main(void) {
    int two = AUGMENT(1);
    int six = MAX(5, 6);
    int one = MAX_AND_AUGMENT(-2, 0);
    SING_IF_YOU_LIKE(one)
    return 0;
}