#include <stdio.h>

int main() {
    const int UP = 'a' - 'A';
    int n = 0;
    char word = 0;

    scanf("%d", &n);
    word = n;
    printf("%d %c\n%d %c", n, word, n + UP, word + UP);
    return 0;
}
