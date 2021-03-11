#include <stdio.h>
#include <math.h>

#define MAX 1010

int num[MAX] = {0};
int weight[MAX] = {0};

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < N; i++)
    {
        int j = 1;
        while (weight[j] + num[i] > 100)
            j++;
        printf("%d %d\n", num[i], j);
        weight[j] += num[i];
    }

    int box = 1;
    while (weight[box])
        box++;
    printf("%d\n", box - 1);
    return 0;
}
