#include <stdio.h>
#include <string.h>
int num[1000];
int main(void)
{
    memset(num, 0, sizeof(num));
    int N, M;
    scanf("%d %d", &N, &M);
    M = M % N;
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    for (int i = 0; i < N; i++) {
        printf("%d", num[(i + N - M) % N]);
        if (i + 1 != N)
            printf(" ");
    }
    return 0;
}