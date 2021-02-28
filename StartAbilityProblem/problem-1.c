#include <stdio.h>
int main(void)
{
    int N;
    char c;
    scanf("%d %c", &N, &c);
    int layer = 1;
    while (1) {
        int tmp = layer + 1;
        if (2 * layer * layer - 1 <= N && N < 2 * tmp * tmp - 1)
            break;
        layer++;
    }
    for (int i = 0; i < layer; i++) {
        for (int j = 0; j < i; j++)
            printf(" ");
        for (int j = 0; j < 2 * (layer - i) - 1; j++)
            printf("%c", c);
        printf("\n");
    }
    for (int i = 1; i < layer; i++) {
        for (int j = 0; j < layer - i - 1; j++)
            printf(" ");
        for (int j = 0; j < 2 * i + 1; j++)
            printf("%c", c);
        printf("\n");
    }
    printf("%d\n", N - 2 * layer * layer + 1);
    return 0;
}