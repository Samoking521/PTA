#include <stdio.h>
#include <math.h>

#define MAX 20

int num[MAX] = {0};

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            sum += num[i] * 10 + num[j];
            sum += num[j] * 10 + num[i];
        }
    printf("%d\n", sum);
    return 0;
}
