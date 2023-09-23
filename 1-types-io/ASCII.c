#include <stdio.h>

int main() {
    const int UP = 'a'-'A';
    int n;
    char word;

    scanf("%d",&n);
    word = n;
    printf("%d %c\n%d %c",n,word,n + UP,word + UP);
    return 0;
}
