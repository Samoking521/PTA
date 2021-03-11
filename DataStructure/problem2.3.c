#include <stdio.h>

#define MAX 100010

int num_a[MAX] = {0};
int num_b[MAX] = {0};

//ans = N / 9 * (10 * (10^M - 1) / 9 - M)
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    if (M == 0)
    {
        printf("0");
    }
    else
    {
        for (int i = 1; i <= M; i++)
        {
            num_a[i] = N;
        }
        num_a[0] = 0;

        int b = N * M;
        int j = 0;
        while (b)
        {
            num_b[j] = b % 10;
            b /= 10;
            j++;
        }

        int c = 0;
        for (int k = 0; k <= j; k++)
        {
            if (num_a[k] - c >= num_b[k])
            {
                num_a[k] = num_a[k] - num_b[k] - c;
                c = 0;
            }
            else
            {
                c = 1;
                num_a[k] = num_a[k] + 10 - num_b[k];
            }
        }

        int k = MAX - 1;
        while (num_a[k] == 0)
            k--;
        int cur = 0;
        for (; k >= 0; k--)
        {
            cur = cur * 10 + num_a[k];
            num_b[k] = cur / 9;
            cur = cur % 9;
        }

        k = MAX - 1;
        while (k >= 0 && num_b[k] == 0)
            k--;
        if (k == -1)
            printf("0");
        else
            for (; k >= 0; k--)
                printf("%d", num_b[k]);
    }
    printf("\n");
    return 0;
}
