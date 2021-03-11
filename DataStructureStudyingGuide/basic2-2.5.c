#include <stdio.h>

#define MAX 35

int num[MAX] = {0};

void print(int N, int sum);
int next(int N);

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        num[i] = 1;
    }
    int sum = N;
    while (num[0] != sum)
    {
        print(N, sum);
        N = next(N);
    }
    print(1, sum);
    return 0;
}

void print(int N, int sum)
{
    static int cnt = 0;
    printf("%d=", sum);
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf("+");
        printf("%d", num[i]);
    }
    cnt = (cnt + 1) % 4;
    if (N != 1)
        if (cnt)
            printf(";");
        else
            printf("\n");
}

int next(int N)
{
    if (num[N - 1] == num[N - 2] || num[N - 1] - num[N - 2] == 1)
    {
        num[N - 2] = num[N - 2] + num[N - 1];
        num[N - 1] = 0;
        return N - 1;
    }
    else
    {
        num[N - 2] += 1;
        num[N - 1] -= 1;
        while (num[N - 1] - num[N - 2] >= num[N - 2])
        {
            num[N] = num[N - 1] - num[N - 2];
            num[N - 1] = num[N - 2];
            N++;
        }
        return N;
    }
}