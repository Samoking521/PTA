#include <stdio.h>

#define MAX 20

int num[MAX] = {0};
int fact[] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

void print(int N);
void next(int N);
void swap(int *a, int *b);

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        num[i] = i + 1;
    }
    int cnt = fact[N];
    while (cnt--)
    {
        print(N);
        next(N);
    }
    return 0;
}

void print(int N)
{
    printf("{");
    for (int i = 0; i < N; i++)
        if (i == 0)
            printf("%d", num[i]);
        else
            printf(",%d", num[i]);
    printf("},");
    printf("\n");
}

void next(int N)
{
    int i = N - 2;
    while (i >= 0 && num[i] > num[i + 1])
        i--;
    int t = i + 1;
    while (t <= N - 1 && num[i] < num[t])
        t++;
    swap(&num[i], &num[t - 1]);

    int j = i + 1;
    int k = N - 1;
    while (j < k)
    {
        swap(&num[j], &num[k]);
        j++;
        k--;
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}