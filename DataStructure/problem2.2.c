#include <stdio.h>

#define MAX 1010

int num[MAX];
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }
    int tmp;
    for (int i = 0; i < M; i++)
    {
        tmp = num[0];
        for (int j = 1; j < N; j++)
            num[(j - 1 + N) % N] = num[(j + N) % N];
        num[N - 1] = tmp;
    }
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    return 0;
}